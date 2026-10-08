#include "sample_ui.h"
#include "reload_save.h"

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

struct GameOverState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 mode;
};

enum WindowIds
{
    WINDOW_0
};

static EWRAM_DATA struct GameOverState *sGameOverState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const struct BgTemplate sGameOverBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    }
};

static const struct WindowTemplate sGameOverWindowTemplates[] =
{
    [WINDOW_0] =
    {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 17,
        .width = 16,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

static const u32 sGameOverTiles[] = INCGFX_U32("graphics/game_over/tiles.png", ".4bpp.smol");

static const u32 sGameOverTilemap[] = INCBIN_U32("graphics/game_over/tiles.bin.smol");

static const u16 sGameOverPalette[] = INCBIN_U16("graphics/game_over/tiles.gbapal");

enum FontColor
{
    FONT_WHITE,
    FONT_RED
};
static const u8 sGameOverWindowFontColors[][3] =
{
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
};

// Callbacks for the Game Over
static void GameOver_SetupCB(void);
static void GameOver_MainCB(void);
static void GameOver_VBlankCB(void);

// Game Over tasks
static void Task_GameOverWaitFadeIn(u8 taskId);
static void Task_GameOverMainInput(u8 taskId);
static void Task_GameOverWaitFadeAndBail(u8 taskId);
static void Task_GameOverWaitFadeAndExitGracefully(u8 taskId);

// Game Over helper functions
static void GameOver_Init(MainCallback callback);
static void GameOver_ResetGpuRegsAndBgs(void);
static bool8 GameOver_InitBgs(void);
static void GameOver_FadeAndBail(void);
static bool8 GameOver_LoadGraphics(void);
static void GameOver_InitWindows(void);
static void GameOver_PrintUiSampleWindowText(void);
static void GameOver_FreeResources(void);

void CB2_GameOverScreen(void)
{
    GameOver_Init(CB2_WhiteOut);
}

// Declared in sample_ui.h
void Task_OpenGameOver(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        GameOver_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void GameOver_Init(MainCallback callback)
{
    sGameOverState = AllocZeroed(sizeof(struct GameOverState));
    if (sGameOverState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sGameOverState->loadState = 0;
    sGameOverState->savedCallback = callback;

    SetMainCallback2(GameOver_SetupCB);
}

// Credit: Jaizu, pret
static void GameOver_ResetGpuRegsAndBgs(void)
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
    // SetGpuReg(REG_OFFSET_DISPCNT, 0);
    // SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON);
    // SetGpuReg(REG_OFFSET_BG3CNT, 0);
    // SetGpuReg(REG_OFFSET_BG2CNT, 0);
    // SetGpuReg(REG_OFFSET_BG1CNT, 0);
    // SetGpuReg(REG_OFFSET_BG0CNT, 0);
    // ChangeBgX(0, 0, BG_COORD_SET);
    // ChangeBgY(0, 0, BG_COORD_SET);
    // ChangeBgX(1, 0, BG_COORD_SET);
    // ChangeBgY(1, 0, BG_COORD_SET);
    // ChangeBgX(2, 0, BG_COORD_SET);
    // ChangeBgY(2, 0, BG_COORD_SET);
    // ChangeBgX(3, 0, BG_COORD_SET);
    // ChangeBgY(3, 0, BG_COORD_SET);
    // SetGpuReg(REG_OFFSET_BLDCNT, 0);
    // SetGpuReg(REG_OFFSET_BLDY, 0);
    // SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    // SetGpuReg(REG_OFFSET_WIN0H, 0);
    // SetGpuReg(REG_OFFSET_WIN0V, 0);
    // SetGpuReg(REG_OFFSET_WIN1H, 0);
    // SetGpuReg(REG_OFFSET_WIN1V, 0);
    // SetGpuReg(REG_OFFSET_WININ, 0);
    // SetGpuReg(REG_OFFSET_WINOUT, 0);
    // CpuFill16(0, (void *)VRAM, VRAM_SIZE);
    // CpuFill32(0, (void *)OAM, OAM_SIZE);
}

static void GameOver_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        GameOver_ResetGpuRegsAndBgs();
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
        if (GameOver_InitBgs())
        {
            sGameOverState->loadState = 0;
            gMain.state++;
        }
        else
        {
            GameOver_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (GameOver_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        GameOver_InitWindows();
        PlayBGM(MUS_SEALED_CHAMBER);
        gMain.state++;
        break;
    case 5:
        GameOver_PrintUiSampleWindowText();
        CreateTask(Task_GameOverWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(GameOver_VBlankCB);
        SetMainCallback2(GameOver_MainCB);
        break;
    }
}

static void GameOver_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void GameOver_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_GameOverWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_GameOverMainInput;
    }
}

static void Task_GameOverMainInput(u8 taskId)
{
    // if (JOY_NEW(B_BUTTON))
    // {
    //     PlaySE(SE_PC_OFF);
    //     BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    //     gTasks[taskId].func = Task_GameOverWaitFadeAndExitGracefully;
    // }
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_GameOverWaitFadeAndExitGracefully;
    }
}

static void Task_GameOverWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sGameOverState->savedCallback);
        GameOver_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_GameOverWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        GameOver_FreeResources();
        DestroyTask(taskId);
        ReloadSave();
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 GameOver_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sGameOverBgTemplates, NELEMS(sGameOverBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void GameOver_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_GameOverWaitFadeAndBail, 0);
    SetVBlankCallback(GameOver_VBlankCB);
    SetMainCallback2(GameOver_MainCB);
}

static bool8 GameOver_LoadGraphics(void)
{
    switch (sGameOverState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sGameOverTiles, 0, 0, 0);
        sGameOverState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(sGameOverTilemap, sBg1TilemapBuffer);
            sGameOverState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sGameOverPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sGameOverState->loadState++;
    default:
        sGameOverState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void GameOver_InitWindows(void)
{
    InitWindows(sGameOverWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_0);
    CopyWindowToVram(WINDOW_0, 3);
}

static const u8 sText_Text1[] = _("{A_BUTTON} Retry for the heart");
static void GameOver_PrintUiSampleWindowText(void)
{
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    AddTextPrinterParameterized4(WINDOW_0, FONT_NORMAL, 0, 0, 0, 0,
        sGameOverWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_Text1);

    CopyWindowToVram(WINDOW_0, COPYWIN_GFX);
}

static void GameOver_FreeResources(void)
{
    if (sGameOverState != NULL)
    {
        Free(sGameOverState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}
