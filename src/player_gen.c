#include "player_gen.h"
#include "main_menu.h"

#include "gba/types.h"
#include "gba/defines.h"
#include "global.h"
#include "main.h"
#include "bg.h"
#include "text_window.h"
#include "window.h"
#include "constants/characters.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "pokedex.h"
#include "gpu_regs.h"
#include "random.h"
#include "naming_screen.h"
#include "field_weather.h"
#include "trainer_pokemon_sprites.h"
#include "trainer.h"

struct PlayerGenState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 mode;
};

enum BgIds
{
    BG_TEXT = 0,
    BG_ONE,
    BG_COUNT,
};

enum WindowIds
{
    WINDOW_TEXT = 0,
};

#define tPlayerSpriteId data[2]
#define tTimer data[3]
#define tIsDoneFadingSprites data[4]
#define tPlayerGender data[5]
#define tBrendanSpriteId data[6]
#define tMaySpriteId data[7]
#define tKrisSpriteId data[8]

static EWRAM_DATA struct PlayerGenState *sPlayerGenState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const struct BgTemplate sPlayerGenBgTemplates[] =
{
    {
        .bg = BG_TEXT,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = BG_ONE,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    }
};

static const struct WindowTemplate sPlayerGenTextWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 5,
        .width = 10,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x6D
    },
    DUMMY_WIN_TEMPLATE
};

static const u32 sPlayerGenTiles[] = INCBIN_U32("graphics/player_gen/tiles.4bpp.smol");

static const u32 sPlayerGenTilemap[] = INCBIN_U32("graphics/player_gen/tilemap.bin.smol");

static const u16 sPlayerGenPalette[] = INCBIN_U16("graphics/player_gen/tiles.gbapal");

enum FontColor
{
    FONT_WHITE,
    FONT_RED
};
static const u8 sPlayerGenWindowFontColors[][3] =
{
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
};

static const struct MenuAction sMenuActions_Gender[] = {
    {COMPOUND_STRING("Masculine"), {NULL}},
    {COMPOUND_STRING("Feminine"), {NULL}},
    {COMPOUND_STRING("Androgynous"), {NULL}},
};

static const u8 *const sMascPresetNames[] = {
    COMPOUND_STRING("Damien"),
    COMPOUND_STRING("Viktor"),
};

static const u8 *const sFemmePresetNames[] = {
    COMPOUND_STRING("Bridget"),
    COMPOUND_STRING("Mae"),
};

static const u8 *const sAndroPresetNames[] = {
    COMPOUND_STRING("Kris"),
    COMPOUND_STRING("Nimona")
};

// The number of male vs. female names is assumed to be the same.
// If they aren't, the smaller of the two sizes will be used and any extra names will be ignored.
#define NUM_PRESET_NAMES_MF min(ARRAY_COUNT(sMascPresetNames), ARRAY_COUNT(sFemmePresetNames))
#define NUM_PRESET_NAMES min(NUM_PRESET_NAMES_MF, ARRAY_COUNT(sAndroPresetNames))

// Callbacks for the menu
static void PlayerGen_SetupCB(void);
static void PlayerGen_MainCB(void);
static void PlayerGen_VBlankCB(void);
static void PlayerGen_ShowGenderMenu(u32);
static void PlayerGen_StartFadeInTarget1OutTarget2(u8 taskId, u8 delay);
static void PlayerGen_StartFadeOutTarget1InTarget2(u8 taskId, u8 delay);
static s8 PlayerGen_ProcessGenderMenuInput(void);

// Tasks
static void Task_PlayerGen_WaitFadeIn(u8 taskId);
static void Task_PlayerGen_StartPlayerFadeIn(u8 taskId);
static void Task_PlayerGen_WaitForPlayerFadeIn(u8 taskId);
static void Task_PlayerGen_BoyOrGirl(u8 taskId);
static void Task_PlayerGen_WaitToShowGenderMenu(u8 taskId);
static void Task_PlayerGen_ChooseGender(u8 taskId);
static void Task_PlayerGen_SlideOutOldGenderSprite(u8 taskId);
static void Task_PlayerGen_SlideInNewGenderSprite(u8 taskId);
static void Task_PlayerGen_WaitFadeAndBail(u8 taskId);
static void Task_PlayerGen_WaitFadeAndExitGracefully(u8 taskId);
static void Task_PlayerGen_FadeInTarget1OutTarget2(u8 taskId);
static void Task_PlayerGen_FadeOutTarget1InTarget2(u8 taskId);
static void Task_PlayerGen_Cleanup(u8 taskId);

// Helper functions
static void PlayerGen_Init(MainCallback callback);
static void PlayerGen_ResetGpuRegsAndBgs(void);
static bool8 PlayerGen_InitBgs(void);
static void PlayerGen_FadeAndBail(void);
static bool8 PlayerGen_LoadGraphics(void);
static void PlayerGen_InitWindows(void);
static void PlayerGen_FreeResources(void);

void Task_OpenPlayerGen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        PlayerGen_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void PlayerGen_Init(MainCallback callback)
{
    sPlayerGenState = AllocZeroed(sizeof(struct PlayerGenState));
    if (sPlayerGenState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sPlayerGenState->loadState = 0;
    sPlayerGenState->savedCallback = callback;

    SetMainCallback2(PlayerGen_SetupCB);
}

// Credit: Jaizu, pret
static void PlayerGen_ResetGpuRegsAndBgs(void)
{
    /*
     * TODO : these settings are overkill, and seem to be clearing some
     * important values. I need to come back and investigate this. For now, they
     * are disabled. Note: by not resetting the various BG and GPU regs, we are
     * effectively assuming that the user of this UI is entering from the
     * overworld. If this UI is entered from a different screen, it's possible
     * some regs won't be set correctly. In that case, you'll need to figure
     * out which ones you need.
     */
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static u32 CreatePlayerTrainerSprite(enum PlayerGender gender)
{
    u32 spriteId = CreateTrainerPicSprite(GetPlayerTrainerPic(gender, VERSION_EMERALD), TRUE, 32, 32, gender, TAG_NONE);
    if (spriteId != SPRITE_NONE)
    {
        gSprites[spriteId].invisible = TRUE;
    }

    return spriteId;
}

static void PlayerGen_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        PlayerGen_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (PlayerGen_InitBgs())
        {
            sPlayerGenState->loadState = 0;
            gMain.state++;
        }
        else
        {
            PlayerGen_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (PlayerGen_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        PlayerGen_InitWindows();
        gMain.state++;
        break;
    case 5:
        gMain.state++;
        u32 taskId = CreateTask(Task_PlayerGen_WaitFadeIn, 0);
        if (taskId != TASK_NONE)
        {
            gTasks[taskId].tBrendanSpriteId = CreatePlayerTrainerSprite(GENDER_MASCULINE);
            gTasks[taskId].tMaySpriteId = CreatePlayerTrainerSprite(GENDER_FEMININE);
            gTasks[taskId].tKrisSpriteId = CreatePlayerTrainerSprite(GENDER_ANDROGYNOUS);
        }
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(PlayerGen_VBlankCB);
        SetMainCallback2(PlayerGen_MainCB);
        break;
    }
}

static void PlayerGen_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void PlayerGen_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_PlayerGen_WaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_PlayerGen_StartPlayerFadeIn;
    }
}

static void Task_PlayerGen_StartPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tTimer)
    {
        gTasks[taskId].tTimer--;
    }
    else
    {
        u8 spriteId = gTasks[taskId].tMaySpriteId;

        gSprites[spriteId].x = 180;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        gTasks[taskId].tPlayerGender = GENDER_FEMININE;
        PlayerGen_StartFadeInTarget1OutTarget2(taskId, 2);
        gTasks[taskId].func = Task_PlayerGen_WaitForPlayerFadeIn;
    }
}

static void Task_PlayerGen_WaitForPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        gTasks[taskId].func = Task_PlayerGen_BoyOrGirl;
    }
}

static void Task_PlayerGen_BoyOrGirl(u8 taskId)
{
    if (gTasks[taskId].tTimer)
    {
        gTasks[taskId].tTimer--;
    }
    else
    {
        LoadMessageBoxGfx(0, 0x200, BG_PLTT_ID(15));
        DrawDialogFrameWithCustomTile(0, FALSE, 0x200);
        StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("Choose your presentation."));
        AddTextPrinterForMessage(TRUE);
        CopyWindowToVram(0, COPYWIN_FULL);
        gTasks[taskId].func = Task_PlayerGen_WaitToShowGenderMenu;
    }
}

static void Task_PlayerGen_WaitToShowGenderMenu(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        PlayerGen_ShowGenderMenu(gTasks[taskId].tPlayerGender);
        gTasks[taskId].func = Task_PlayerGen_ChooseGender;
    }
}

static void Task_PlayerGen_ChooseGender(u8 taskId)
{
    enum PlayerGender gender = PlayerGen_ProcessGenderMenuInput();
    enum PlayerGender gender2;

    switch (gender)
    {
    case GENDER_MASCULINE:
    case GENDER_FEMININE:
    case GENDER_ANDROGYNOUS:
        PlaySE(SE_SELECT);
        gSaveBlock2Ptr->playerGender = gender;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_PlayerGen_WaitFadeAndExitGracefully;
        break;
    default: //repeat task if nothing is selected
        break;
    }
    gender2 = Menu_GetCursorPos();
    if (gender2 != gTasks[taskId].tPlayerGender)
    {
        gTasks[taskId].tPlayerGender = gender2;
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        PlayerGen_StartFadeOutTarget1InTarget2(taskId, 0);
        gTasks[taskId].func = Task_PlayerGen_SlideOutOldGenderSprite;
    }
}

static void Task_PlayerGen_SlideOutOldGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;
    if (gTasks[taskId].tIsDoneFadingSprites == 0)
    {
        gSprites[spriteId].x += 4;
    }
    else
    {
        gSprites[spriteId].invisible = TRUE;
        switch(gTasks[taskId].tPlayerGender)
        {
            case GENDER_MASCULINE:
                spriteId = gTasks[taskId].tBrendanSpriteId;
                break;
            default:
            case GENDER_FEMININE:
                spriteId = gTasks[taskId].tMaySpriteId;
                break;
            case GENDER_ANDROGYNOUS:
                spriteId = gTasks[taskId].tKrisSpriteId;
                break;
        }

        gSprites[spriteId].x = DISPLAY_WIDTH;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        PlayerGen_StartFadeInTarget1OutTarget2(taskId, 0);
        gTasks[taskId].func = Task_PlayerGen_SlideInNewGenderSprite;
    }
}

static void Task_PlayerGen_SlideInNewGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].x > 180)
    {
        gSprites[spriteId].x -= 4;
    }
    else
    {
        gSprites[spriteId].x = 180;
        if (gTasks[taskId].tIsDoneFadingSprites)
        {
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
            gTasks[taskId].func = Task_PlayerGen_ChooseGender;
        }
    }
}

static void Task_PlayerGen_WaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sPlayerGenState->savedCallback);
        PlayerGen_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_PlayerGen_WaitFadeAndExitGracefully(u8 taskId)
{
    if (gPaletteFade.active) return;

    PlayerGen_FreeResources();
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = Task_PlayerGen_Cleanup;
}

#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 PlayerGen_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sPlayerGenBgTemplates, NELEMS(sPlayerGenBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void PlayerGen_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_PlayerGen_WaitFadeAndBail, 0);
    SetVBlankCallback(PlayerGen_VBlankCB);
    SetMainCallback2(PlayerGen_MainCB);
}

static bool8 PlayerGen_LoadGraphics(void)
{
    switch (sPlayerGenState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sPlayerGenTiles, 0, 0, 0);
        sPlayerGenState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(sPlayerGenTilemap, sBg1TilemapBuffer);
            sPlayerGenState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sPlayerGenPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sPlayerGenState->loadState++;
    default:
        sPlayerGenState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void PlayerGen_InitWindows(void)
{
    InitWindows(sPlayerGenTextWindows);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    for (u32 i = 0; i < ARRAY_COUNT(sPlayerGenTextWindows) - 1; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        PutWindowTilemap(i);
        CopyWindowToVram(i, 3);
    }
}

static void PlayerGen_FreeResources(void)
{
    if (sPlayerGenState != NULL)
    {
        Free(sPlayerGenState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}

void PlayerGen_SetDefaultPlayerName(u8 nameId)
{
    const u8 *name = 0;
    u8 i;

    switch(gSaveBlock2Ptr->playerGender)
    {
        case GENDER_MASCULINE:
            name = sMascPresetNames[nameId];
            break;
        case GENDER_FEMININE:
            name = sFemmePresetNames[nameId];
            break;
        case GENDER_ANDROGYNOUS:
            name = sAndroPresetNames[nameId];
            break;
    }

    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        gSaveBlock2Ptr->playerName[i] = name[i];

    gSaveBlock2Ptr->playerName[PLAYER_NAME_LENGTH] = EOS;
}

static void Task_StartRenamingScreen(u8 taskId)
{
    if (gPaletteFade.active) return;

    CleanupOverworldWindowsAndTilemaps();
    PlayerGen_SetDefaultPlayerName(Random() % NUM_PRESET_NAMES);
    DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToFieldContinueScript);
    DestroyTask(taskId);
}

void PlayerGen_StartNamingScreen(void)
{
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_StartRenamingScreen, 1);
}

static void PlayerGen_ShowGenderMenu(u32 pos)
{
    LoadUserWindowBorderGfx(1, 0xF3, 2);
    DrawStdFrameWithCustomTileAndPalette(1, FALSE, 0xF3, 2);
    PrintMenuTable(1, ARRAY_COUNT(sMenuActions_Gender), sMenuActions_Gender);
    InitMenuInUpperLeftCornerNormal(1, ARRAY_COUNT(sMenuActions_Gender), pos);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static s8 PlayerGen_ProcessGenderMenuInput(void)
{
    return Menu_ProcessInputNoWrap();
}

#undef tPlayerSpriteId
#undef tTimer
#undef tPlayerGender
#undef tBrendanSpriteId
#undef tMaySpriteId
#undef tKrisSpriteId

#define tMainTask data[0]
#define tAlphaCoeff1 data[1]
#define tAlphaCoeff2 data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void PlayerGen_StartFadeInTarget1OutTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_PlayerGen_FadeInTarget1OutTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 0;
    gTasks[taskId2].tAlphaCoeff2 = 16;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_PlayerGen_FadeInTarget1OutTarget2(u8 taskId)
{
    if (gTasks[taskId].tAlphaCoeff1 == 16)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1++;
        gTasks[taskId].tAlphaCoeff2--;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND((u8)gTasks[taskId].tAlphaCoeff1, (u8)gTasks[taskId].tAlphaCoeff2));
    }
}

static void PlayerGen_StartFadeOutTarget1InTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_PlayerGen_FadeOutTarget1InTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 16;
    gTasks[taskId2].tAlphaCoeff2 = 0;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_PlayerGen_FadeOutTarget1InTarget2(u8 taskId)
{
    if (gTasks[taskId].tAlphaCoeff1 == 0)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1--;
        gTasks[taskId].tAlphaCoeff2++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND((u8)gTasks[taskId].tAlphaCoeff1, (u8)gTasks[taskId].tAlphaCoeff2));
    }
}

#undef tMainTask
#undef tAlphaCoeff1
#undef tAlphaCoeff2
#undef tDelay
#undef tDelayTimer

#undef tIsDoneFadingSprites

static void Task_PlayerGen_Cleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        ResetAllPicSprites();
        SetMainCallback2(CB2_NewGame);
        DestroyTask(taskId);
    }
}
