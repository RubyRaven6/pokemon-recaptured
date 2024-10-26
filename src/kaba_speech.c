#include "global.h"
#include "main.h"
#include "bg.h"
#include "gpu_regs.h"
#include "sprite.h"
#include "window.h"
#include "decompress.h"
#include "text.h"
#include "characters.h"
#include "string_util.h"
#include "palette.h"
#include "palette_util.h"
#include "malloc.h"
#include "task.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "trainer_pokemon_sprites.h"
#include "pokeball.h"
#include "naming_screen.h"
#include "kaba_speech.h"
#include "constants/rgb.h"
#include "constants/songs.h"

/*! @brief
 * This file controls Elder Kaba's speech sequence, made
 * seperately from src/main_menu.c to avoid too big of
 * conflicts and just makes the sequence much cleaner to
 * read.
 *
 * Below is the order of functions that'll run the intro.
 * - DoKabaSpeech
 *   - Move the game state into Elder Kaba's Speech.
 *
 * - Task_KabaSpeech_Begin
 *   - Start the process of loading the intro resources.
 */

// Define, enum, struct definitions

// If you want to edit these sprite pos defines, dont touch the `+ 32`!
// positions for joltik + pokeball
// If you want to edit these, dont touch the `+ 32`!
#define MON_POS_X 55 + 32
#define MON_POS_Y 66 + 32
// positions for platform (they're split into two sprites!)
#define PLAT_POS_X 56 + 32
#define PLAT_POS_Y 83 + 16
// this is pos difference for the second platform sprite
#define PLAT_POS_X2 64

// bg pos
#define AKA_PIC_CENTER_POS 30
#define AO_PIC_CENTER_POS  29

#define PLAT_SPRITE_ID_COUNT 2

// tSpriteType, for fade in/out
enum SpriteTypes
{
    SPRITE_TYPE_PLATFORM = 0,
    SPRITE_TYPE_POKE_BALL,
    // these arent technically sprites but close nuff :)
    SPRITE_TYPE_PIC_1,
    SPRITE_TYPE_PIC_2,
    SPRITE_TYPE_NONE,
};

enum SpriteTags
{
    TAG_PLATFORM = 0x9000,
};

enum Bgs
{
    // self explanatory
    BG_TEXT = 0,
    // generic names as their usage is both for
    // kaba and player/rival sprites
    BG_PIC_1,
    BG_PIC_2,
    // BG_BG feels stupid but this isn't any better either,
    // suggestions welcome (for context this is for the red bg)
    BG_INTRO,
    BG_COUNT,
};

enum WindowIds
{
    WIN_TEXT = 0,
    WIN_COUNT,
};

enum SpeechLoadStates
{
    STATE_RESET = 0,
    STATE_ALLOC,
    STATE_REGS,
    STATE_BGS,
    STATE_BG_GFX,
    STATE_WINDOWS,
    STATE_FINISH,
    STATE_COUNT,
};

enum PicIds
{
    PIC_AKA = 0,
    PIC_AO,
    PIC_KABA,
    PIC_COUNT
};

struct KabaSpeech
{
    u16 introTilemapBuffer[0x800];
    u16 pic1TilemapBuffer[0x800];
    u16 pic2TilemapBuffer[0x800];
    u8 monSpriteId;
    u8 ballSpriteId;
    u8 platformSpriteIds[PLAT_SPRITE_ID_COUNT]; // the platform is made out of 2 64x32sprites
    s16 alphaCoeff;
    s16 alphaCoeff2;
    s16 timer;
    s16 fadeTimer;
    s16 counter;
    bool32 fadeFinished:1;
    bool32 playerHasName:1;
    u8 chosenPic:2;
};

// EWRAM data
static EWRAM_DATA struct KabaSpeech *sKabaSpeech = NULL;

// Function declarations
static void Task_KabaSpeech_Begin(u8);
static void Task_KabaSpeech_FadeInEverything(u8);
static void Task_KabaSpeech_GreetingsTraveler(u8);
static void Task_KabaSpeech_AndThis(u8);
static void Task_KabaSpeech_ReleaseJoltikFromPokeball(u8);
static void Task_KabaSpeech_JoltikAPokemon(u8);
static void Task_KabaSpeech_MainTalk(u8);
static void Task_KabaSpeech_ReturnJoltik(u8);
static void Task_KabaSpeech_FadeOutPokeball(u8);
static void Task_KabaSpeech_FadeOutEverything(u8);
static void Task_KabaSpeech_FadeOutPlayerChoice(u8);
static void Task_KabaSpeech_SpawnPlayerChoice(u8);
static void Task_KabaSpeech_WaitForChoice(u8);
static void Task_KabaSpeech_MoveChosenPic(u8);
static void Task_KabaSpeech_SpawnYesNoMenu(u8);
static void Task_KabaSpeech_HandleConfirmChosenPicInput(u8);
static void Task_KabaSpeech_MovePicsBack(u8);
static void Task_KabaSpeech_AskForName(u8);
static void Task_KabaSpeech_WaitBeforeNamingScreen(u8);
static void Task_KabaSpeech_DoNamingScreen(u8);
static void Task_KabaSpeech_ConfirmChosenName(u8);
static void Task_KabaSpeech_HandleConfirmNameInput(u8);

static void KabaSpeech_DrawCharacterPic(u8);
static inline void KabaSpeech_PrintMessageBox(const u8 *);
static void KabaSpeech_CreateMonSprite(void);
static void KabaSpeech_CreatePlatformSprites(bool32 hide);
static void KabaSpeech_DestroyPlatformSprites(void);
static void KabaSpeech_BeginFade(u8, u8, u8);
static void KabaSpeech_SetDefaultName(void);
static void CB2_KabaSpeech_ReturnFromNamingScreen(void);

// Const data
static const u8 sKabaSpeech_Aka[] = _("Aka");
static const u8 sKabaSpeech_Ao[]  = _("Ao");

static const u8 sKabaSpeech_Greetings[] = _(
    "Greetings, young traveler.\p"
    "And welcome to the world of Pokémon.\p"
    "I am Kaba, one of the four elders of\n"
    "the Toku Region.\p"
    "However, you can call me Elder Kaba\n"
    "instead.\p"
);
static const u8 sKabaSpeech_AndThis[] = _(
    "And this…"
);
static const u8 sKabaSpeech_JoltikAPokemon[] = _(
    "…is Joltik, a Pokémon creature.{PAUSE 30}\p"
);
static const u8 sKabaSpeech_MainTalk[] = _(
    "Joltik, with other Pokémon creatures,\n"
    "initially lives seperately from us,\l"
    "humans.\p"
    "However, thanks to a latest discovery,\n"
    "we're now able capture and befriend\l"
    "these creatures with this special\l"
    "device we call Pokéball.\p"
    "More here blah blah i ran out of ideas\p"
);
static const u8 sKabaSpeech_GenderChoice[] = _(
    "boy or girl ?"
);
static const u8 sKabaSpeech_ConfirmChosenGender[] = _(
    "So you're this mofo?"
);
static const u8 sKabaSpeech_AskPlayerName[] = _(
    "ok, you're name ?"
);
static const u8 sKabaSpeech_CancelChosenGender[] = _(
    "bruh"
);
static const u8 sKabaSpeech_SoYourePlayer[] = _(
    "so {PLAYER} is you ?"
);

static const u16 sKabaSpeech_BgGfx[] = INCBIN_U16("graphics/kaba_speech/bg.4bpp");
static const u16 sKabaSpeech_BgPal[] = INCBIN_U16("graphics/kaba_speech/bg.gbapal");
static const u32 sKabaSpeech_BgMap[] = INCBIN_U32("graphics/kaba_speech/bg.bin.lz");

static const u8 sKabaSpeech_KabaPicGfx[] = INCBIN_U8("graphics/kaba_speech/pics/kaba.4bpp");
static const u16 sKabaSpeech_KabaPicPal[] = INCBIN_U16("graphics/kaba_speech/pics/kaba.gbapal");
static const u32 sKabaSpeech_KabaPicMap[] = INCBIN_U32("graphics/kaba_speech/pics/kaba.bin.lz");

static const struct BgTemplate sKabaSpeech_BgTemplates[BG_COUNT] =
{
    [BG_TEXT] = {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0,
        // other unspecified attributes defaults to 0
    },
    [BG_PIC_1] = {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .priority = 1,
    },
    [BG_PIC_2] = {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .priority = 2,
    },
    [BG_INTRO] = {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .priority = 3,
    },
};

static const struct WindowTemplate sKabaSpeech_WindowTemplates[] =
{
    [WIN_TEXT] =
    {
        .bg = BG_TEXT,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sKabaSpeech_YesNoWindow =
{
    .bg = BG_TEXT,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = (26*4)+1,
};

static const struct SpriteSheet sKabaSpeech_PlatformSpriteSheet = 
{
    .data = sKabaSpeech_PlatformGfx,
    .size = 2048, // 64x128/2
    .tag = TAG_PLATFORM,
};

static const struct SpritePalette sKabaSpeech_PlatformSpritePalette =
{
    .data = sKabaSpeech_PlatformPal,
    .tag = TAG_PLATFORM,
};

static const struct OamData sKabaSpeech_PlatformOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sKabaSpeech_PlatformLeft[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sKabaSpeech_PlatformRight[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sKabaSpeech_PlatformAnims[] =
{
    sKabaSpeech_PlatformLeft,
    sKabaSpeech_PlatformRight
};

static const struct SpriteTemplate sKabaSpeech_PlatformTemplate =
{
    .tileTag = TAG_PLATFORM,
    .paletteTag = TAG_PLATFORM,
    .oam = &sKabaSpeech_PlatformOamData,
    .anims = sKabaSpeech_PlatformAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// Code
void CB2_KabaSpeech(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void VBlankCB_KabaSpeech(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void DoKabaSpeech(void)
{
    CreateTask(Task_KabaSpeech_Begin, 0);
    SetMainCallback2(CB2_KabaSpeech);
}

static void Task_KabaSpeech_Begin(u8 taskId)
{
    switch(gMain.state)
    {
        case STATE_RESET:
            SetVBlankCallback(NULL);
            SetHBlankCallback(NULL);
            DmaFill16(3, 0, VRAM, VRAM_SIZE);
            ResetPaletteFade();
            ScanlineEffect_Stop();
            ResetSpriteData();
            FreeAllSpritePalettes();
            ResetTempTileDataBuffers();
            break;
        case STATE_ALLOC:
            sKabaSpeech = AllocZeroed(sizeof(*sKabaSpeech));
            break;
        case STATE_REGS:
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WIN1H, 0);
            SetGpuReg(REG_OFFSET_WIN1V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            break;
        case STATE_BGS:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sKabaSpeech_BgTemplates, ARRAY_COUNT(sKabaSpeech_BgTemplates));
            SetBgTilemapBuffer(BG_INTRO, sKabaSpeech->introTilemapBuffer);
            SetBgTilemapBuffer(BG_PIC_1, sKabaSpeech->pic1TilemapBuffer);
            SetBgTilemapBuffer(BG_PIC_2, sKabaSpeech->pic2TilemapBuffer);
            ResetBgPositions();
            break;
        case STATE_BG_GFX:
            KabaSpeech_CreateMonSprite();
            KabaSpeech_CreatePlatformSprites(TRUE);
            LoadPalette(sKabaSpeech_BgPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_INTRO, sKabaSpeech_BgGfx, 0x180, 0);
            CopyToBgTilemapBuffer(BG_INTRO, sKabaSpeech_BgMap, 0, 0);
            CopyBgTilemapBufferToVram(BG_INTRO);
            FillBgTilemapBufferRect_Palette0(BG_PIC_2, 0, 0, 0, 32, 32);
            CopyBgTilemapBufferToVram(BG_PIC_2);
            FillBgTilemapBufferRect_Palette0(BG_TEXT, 0, 0, 0, 32, 32);
            CopyBgTilemapBufferToVram(BG_TEXT);
            KabaSpeech_DrawCharacterPic(PIC_KABA);
            break;
        case STATE_WINDOWS:
            InitWindows(sKabaSpeech_WindowTemplates);
            InitTextBoxGfxAndPrinters();
            Menu_LoadStdPalAt(BG_PLTT_ID(13));
            DrawDialogueFrame(WIN_TEXT, TRUE);
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            break;
        case STATE_FINISH:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
            SetGpuReg(REG_OFFSET_BLDY, 0);
            ShowBg(BG_INTRO);
            ShowBg(BG_PIC_1);
            ShowBg(BG_TEXT);
            SetVBlankCallback(VBlankCB_KabaSpeech);
            PlayBGM(MUS_ROUTE122);
            gTasks[taskId].func = Task_KabaSpeech_FadeInEverything;
            gMain.state = 0;
            return;
    }
    DebugPrintf("state: %d", gMain.state);
    gMain.state++;
}

static void Task_KabaSpeech_FadeInEverything(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sKabaSpeech->timer = 30;
        KabaSpeech_BeginFade(FALSE, 0xd8, SPRITE_TYPE_NONE);
        gTasks[taskId].func = Task_KabaSpeech_GreetingsTraveler;
    }
}

static void Task_KabaSpeech_GreetingsTraveler(u8 taskId)
{
    if (sKabaSpeech->fadeFinished)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
            return;
        }

        KabaSpeech_PrintMessageBox(sKabaSpeech_Greetings);
        gTasks[taskId].func = Task_KabaSpeech_AndThis;
    }
}

static void Task_KabaSpeech_AndThis(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        KabaSpeech_PrintMessageBox(sKabaSpeech_AndThis);
        sKabaSpeech->timer = 30;
        gTasks[taskId].func = Task_KabaSpeech_ReleaseJoltikFromPokeball;
    }
}

static void Task_KabaSpeech_ReleaseJoltikFromPokeball(u8 taskId)
{
    u32 spriteId;
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
            return;
        }

        spriteId = sKabaSpeech->monSpriteId;
        gSprites[spriteId].invisible = FALSE;
        CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, MON_POS_X, MON_POS_Y, 0, 0, 32, 0x00007FFF, SPECIES_JOLTIK);
        gTasks[taskId].func = Task_KabaSpeech_JoltikAPokemon;
        sKabaSpeech->timer = 0;
    }
}

static void Task_KabaSpeech_JoltikAPokemon(u8 taskId)
{
    sKabaSpeech->timer++;
    if (IsCryFinished())
    {
        if (sKabaSpeech->timer >= 192)
        {
            KabaSpeech_PrintMessageBox(sKabaSpeech_JoltikAPokemon);
            gTasks[taskId].func = Task_KabaSpeech_MainTalk;
        }
    }
}

static void Task_KabaSpeech_MainTalk(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        KabaSpeech_PrintMessageBox(sKabaSpeech_MainTalk);
        gTasks[taskId].func = Task_KabaSpeech_ReturnJoltik;
    }
}

static void Task_KabaSpeech_ReturnJoltik(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        u32 spriteId = sKabaSpeech->monSpriteId;
        sKabaSpeech->ballSpriteId = CreateTradePokeballSprite(spriteId, gSprites[spriteId].oam.paletteNum, MON_POS_X, MON_POS_Y, 0, 0, 32, 0x00007FFF);
        gTasks[taskId].func = Task_KabaSpeech_FadeOutPokeball;
    }
}

static void Task_KabaSpeech_FadeOutPokeball(u8 taskId)
{
    // the ball callback ends its functionality with SpriteCallbackDummy
    if (gSprites[sKabaSpeech->ballSpriteId].callback == SpriteCallbackDummy)
    {
        KabaSpeech_BeginFade(TRUE, 0, SPRITE_TYPE_POKE_BALL);
        gTasks[taskId].func = Task_KabaSpeech_FadeOutEverything;
    }
}

static void Task_KabaSpeech_FadeOutEverything(u8 taskId)
{
    if (sKabaSpeech->fadeFinished)
    {
        DestroySprite(&gSprites[sKabaSpeech->monSpriteId]);
        DestroySprite(&gSprites[sKabaSpeech->ballSpriteId]);
        ClearDialogWindowAndFrameToTransparent(WIN_TEXT, TRUE);
        FillBgTilemapBufferRect_Palette0(BG_PIC_1, 0, 0, 0, 32, 32);
        CopyBgTilemapBufferToVram(BG_PIC_1);
        KabaSpeech_DrawCharacterPic(PIC_AO);
        KabaSpeech_DrawCharacterPic(PIC_AKA);
        gTasks[taskId].func = Task_KabaSpeech_FadeOutPlayerChoice;
    }
}

static void Task_KabaSpeech_FadeOutPlayerChoice(u8 taskId)
{
    sKabaSpeech->timer = 60;
    KabaSpeech_BeginFade(FALSE, 60, SPRITE_TYPE_PLATFORM);
    gTasks[taskId].func = Task_KabaSpeech_SpawnPlayerChoice;

}

static void Task_KabaSpeech_SpawnPlayerChoice(u8 taskId)
{
    if (sKabaSpeech->fadeFinished)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
            return;
        }

        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        KabaSpeech_PrintMessageBox(sKabaSpeech_GenderChoice);
        sKabaSpeech->chosenPic = PIC_AO;
        sKabaSpeech->timer = 30;
        gTasks[taskId].func = Task_KabaSpeech_WaitForChoice;
    }
}

static void Task_KabaSpeech_WaitForChoice(u8 taskId)
{
    if (sKabaSpeech->timer)
    {
        sKabaSpeech->timer--;
        return;
    }

    switch (sKabaSpeech->chosenPic)
    {
    default:
    case PIC_AO: // female
        SetGpuReg(REG_OFFSET_BLDCNT,
            BLDCNT_TGT1_BG2 |
            BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 |
            BLDCNT_EFFECT_BLEND);
        break;
    case PIC_AKA: // male
        SetGpuReg(REG_OFFSET_BLDCNT,
            BLDCNT_TGT1_BG1 |
            BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 |
            BLDCNT_EFFECT_BLEND);
        break;
    }
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));

    if (JOY_NEW(DPAD_LEFT))
    {
        if (sKabaSpeech->chosenPic > 0)
            sKabaSpeech->chosenPic--;
        else
            sKabaSpeech->chosenPic++;
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (sKabaSpeech->chosenPic < 1)
            sKabaSpeech->chosenPic++;
        else
            sKabaSpeech->chosenPic--;
    }

    if (JOY_NEW(A_BUTTON))
    {
        u32 blend1 = (sKabaSpeech->chosenPic == PIC_AO) ? BLDCNT_TGT1_BG2 : BLDCNT_TGT1_BG1;

        SetGpuReg(REG_OFFSET_BLDCNT,
            blend1 |
            BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 |
            BLDCNT_EFFECT_BLEND);
        DebugPrintf("%d is chosen", sKabaSpeech->chosenPic);
        sKabaSpeech->counter = 0;
        KabaSpeech_BeginFade(TRUE, 0, (sKabaSpeech->chosenPic == PIC_AO) ? SPRITE_TYPE_PIC_2 : SPRITE_TYPE_PIC_1);
        gTasks[taskId].func = Task_KabaSpeech_MoveChosenPic;
    }
}

static void Task_KabaSpeech_MoveChosenPic(u8 taskId)
{
    u32 limit = (sKabaSpeech->chosenPic == PIC_AO) ? AO_PIC_CENTER_POS : AKA_PIC_CENTER_POS;
    if (sKabaSpeech->counter == limit)
    {
        KabaSpeech_PrintMessageBox(sKabaSpeech_ConfirmChosenGender);
        sKabaSpeech->timer = 15;
        gTasks[taskId].func = Task_KabaSpeech_SpawnYesNoMenu;
    }
    else
    {
        s32 counter = (sKabaSpeech->chosenPic == PIC_AO) ? -sKabaSpeech->counter : sKabaSpeech->counter;
        sKabaSpeech->counter++;
        SetGpuReg(REG_OFFSET_BG1HOFS, counter);
        SetGpuReg(REG_OFFSET_BG2HOFS, counter);
    }
}

static void Task_KabaSpeech_SpawnYesNoMenu(u8 taskId)
{
    if (sKabaSpeech->timer)
    {
        sKabaSpeech->timer--;
    }
    else
    {
        CreateYesNoMenu(&sKabaSpeech_YesNoWindow, 0x214, 14, 0);
        gTasks[taskId].func = Task_KabaSpeech_HandleConfirmChosenPicInput;
    }
}

static void Task_KabaSpeech_HandleConfirmChosenPicInput(u8 taskId)
{
    s32 input = Menu_ProcessInputNoWrapClearOnChoose();

    switch(input)
    {
    case 0: // YES
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_KabaSpeech_AskForName;
        break;
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        KabaSpeech_PrintMessageBox(sKabaSpeech_CancelChosenGender);
        KabaSpeech_BeginFade(FALSE, 0, (sKabaSpeech->chosenPic == PIC_AO) ? SPRITE_TYPE_PIC_2 : SPRITE_TYPE_PIC_1);
        gTasks[taskId].func = Task_KabaSpeech_MovePicsBack;
        break;
    }
}

static void Task_KabaSpeech_MovePicsBack(u8 taskId)
{
    u32 limit = 0;
    if (sKabaSpeech->counter == limit)
    {
        sKabaSpeech->timer = 60;
        gTasks[taskId].func = Task_KabaSpeech_SpawnPlayerChoice;
    }
    else
    {
        s32 counter = (sKabaSpeech->chosenPic == PIC_AO) ? -sKabaSpeech->counter : sKabaSpeech->counter;
        sKabaSpeech->counter--;
        SetGpuReg(REG_OFFSET_BG1HOFS, counter);
        SetGpuReg(REG_OFFSET_BG2HOFS, counter);
    }
}

static void Task_KabaSpeech_AskForName(u8 taskId)
{
    sKabaSpeech->timer = 60;
    KabaSpeech_PrintMessageBox(sKabaSpeech_AskPlayerName);
    gTasks[taskId].func = Task_KabaSpeech_WaitBeforeNamingScreen;
}

static void Task_KabaSpeech_WaitBeforeNamingScreen(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
        }
        else
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sKabaSpeech->playerHasName = FALSE;
            gTasks[taskId].func = Task_KabaSpeech_DoNamingScreen;
        }
    }
}

static void Task_KabaSpeech_DoNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        KabaSpeech_SetDefaultName();
        if (sKabaSpeech->playerHasName)
        {
            // sKabaSpeech->chosenPic ^ 1 is opposite
            DoNamingScreen(NAMING_SCREEN_RIVAL, gSaveBlock2Ptr->rivalName, (sKabaSpeech->chosenPic ^ 1), 0, 0, CB2_KabaSpeech_ReturnFromNamingScreen);
        }
        else
        {
            DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, sKabaSpeech->chosenPic, 0, 0, CB2_KabaSpeech_ReturnFromNamingScreen);
        }
        KabaSpeech_DestroyPlatformSprites();
        FreeAllWindowBuffers();
        DestroyTask(taskId);
    }
}

// .. actual naming screen menu here ..

static void Task_KabaSpeech_ConfirmChosenName(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
        }
        else
        {
            KabaSpeech_PrintMessageBox(sKabaSpeech_SoYourePlayer);
            CreateYesNoMenu(&sKabaSpeech_YesNoWindow, 0x214, 14, 0);
            gTasks[taskId].func = Task_KabaSpeech_HandleConfirmNameInput;
        }
    }
}

static void Task_KabaSpeech_HandleConfirmNameInput(u8 taskId)
{
    s32 input = Menu_ProcessInputNoWrapClearOnChoose();

    switch(input)
    {
    case 0: // YES
        PlaySE(SE_SELECT);
        sKabaSpeech->playerHasName = TRUE;
        break;
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_KabaSpeech_AskForName;
        break;
    }
}

static void Task_KabaSpeech_BeginRivalNaming(u8 taskId)
{

}

// misc. helper functions

static void KabaSpeech_DrawCharacterPic(u8 id)
{
    switch(id)
    {
        case PIC_AKA: // male
            return;
        case PIC_AO: // female
            return;
        case PIC_KABA:
            LoadPalette(sKabaSpeech_KabaPicPal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_PIC_1, sKabaSpeech_KabaPicGfx, 0x1800, 0);
            CopyToBgTilemapBuffer(BG_PIC_1, sKabaSpeech_KabaPicMap, 0, 0);
            CopyBgTilemapBufferToVram(BG_PIC_1);
            return;
        default:
            return;
    }
}

static inline void KabaSpeech_PrintMessageBox(const u8 *str)
{
    DrawDialogueFrame(WIN_TEXT, FALSE);
    if (str != gStringVar4)
    {
        StringExpandPlaceholders(gStringVar4, str);
        AddTextPrinterParameterized2(WIN_TEXT, FONT_NORMAL, gStringVar4, GetPlayerTextSpeed(), NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    }
    else
    {
        AddTextPrinterParameterized2(WIN_TEXT, FONT_NORMAL, str, GetPlayerTextSpeed(), NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    }
    CopyWindowToVram(WIN_TEXT, COPYWIN_FULL);
}

static void KabaSpeech_CreateMonSprite(void)
{
    sKabaSpeech->monSpriteId = CreateMonPicSprite_Affine(SPECIES_JOLTIK, FALSE, 0, MON_PIC_AFFINE_FRONT, MON_POS_X, MON_POS_Y, 14, TAG_NONE);
    gSprites[sKabaSpeech->monSpriteId].callback = SpriteCallbackDummy;
    gSprites[sKabaSpeech->monSpriteId].oam.priority = 0;
    gSprites[sKabaSpeech->monSpriteId].invisible = TRUE;
}

static void KabaSpeech_CreatePlatformSprites(bool32 hide)
{
    u32 leftSpriteId, rightSpriteId;
    LoadSpriteSheet(&sKabaSpeech_PlatformSpriteSheet);
    LoadSpritePalette(&sKabaSpeech_PlatformSpritePalette);
    leftSpriteId = CreateSprite(&sKabaSpeech_PlatformTemplate, PLAT_POS_X, PLAT_POS_Y, 0);
    rightSpriteId = CreateSprite(&sKabaSpeech_PlatformTemplate, PLAT_POS_X, PLAT_POS_Y, 0);
    gSprites[rightSpriteId].x2 = PLAT_POS_X2;
    StartSpriteAnim(&gSprites[leftSpriteId], 0);
    StartSpriteAnim(&gSprites[rightSpriteId], 1);
    gSprites[leftSpriteId].invisible = hide;
    gSprites[rightSpriteId].invisible = hide;
    sKabaSpeech->platformSpriteIds[0] = leftSpriteId;
    sKabaSpeech->platformSpriteIds[1] = rightSpriteId;
}

static void KabaSpeech_DestroyPlatformSprites(void)
{
    DestroySprite(&gSprites[sKabaSpeech->platformSpriteIds[1]]);
    DestroySpriteAndFreeResources(&gSprites[sKabaSpeech->platformSpriteIds[0]]);
    sKabaSpeech->platformSpriteIds[0] = SPRITE_NONE;
    sKabaSpeech->platformSpriteIds[1] = SPRITE_NONE;
}

#define tSpriteType data[0]

static void Task_KabaSpeech_FadeOut(u8 taskId)
{
    u32 i = 0;
    if (sKabaSpeech->alphaCoeff == 0)
    {
        sKabaSpeech->fadeFinished = TRUE;
        switch (gTasks[taskId].tSpriteType)
        {
            case SPRITE_TYPE_PLATFORM:
            {
                for (i = 0; i < PLAT_SPRITE_ID_COUNT; i++)
                    gSprites[sKabaSpeech->platformSpriteIds[i]].invisible = TRUE;
            }
                break;
            case SPRITE_TYPE_POKE_BALL:
                gSprites[sKabaSpeech->ballSpriteId].invisible = TRUE;
                break;
            default:
            case SPRITE_TYPE_NONE:
                break;
        }
        DestroyTask(taskId);
    }
    else
    {
        if (sKabaSpeech->fadeTimer != 0)
        {
            sKabaSpeech->fadeTimer--;
        }
        else
        {
            sKabaSpeech->fadeTimer = 0;
            sKabaSpeech->alphaCoeff--;
            sKabaSpeech->alphaCoeff2++;
            if (sKabaSpeech->alphaCoeff == 8)
            {
                switch (gTasks[taskId].tSpriteType)
                {
                    case SPRITE_TYPE_PLATFORM:
                    {
                        for (i = 0; i < PLAT_SPRITE_ID_COUNT; i++)
                            gSprites[sKabaSpeech->platformSpriteIds[i]].invisible ^= TRUE;
                    }
                        break;
                    case SPRITE_TYPE_POKE_BALL:
                        gSprites[sKabaSpeech->ballSpriteId].invisible ^= TRUE;
                        break;
                    default:
                    case SPRITE_TYPE_NONE:
                        break;
                }
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (sKabaSpeech->alphaCoeff2 * 256) + sKabaSpeech->alphaCoeff);
        }
    }
}

static void Task_KabaSpeech_FadeIn(u8 taskId)
{
    u32 i = 0;

    if (sKabaSpeech->alphaCoeff == 16)
    {
        if (!gPaletteFade.active)
        {
            sKabaSpeech->fadeFinished = TRUE;
            DestroyTask(taskId);
        }
    }
    else
    {
        if (sKabaSpeech->fadeTimer != 0)
        {
            sKabaSpeech->fadeTimer--;
        }
        else
        {
            sKabaSpeech->fadeTimer = 0;
            sKabaSpeech->alphaCoeff++;
            sKabaSpeech->alphaCoeff2--;
            if (sKabaSpeech->alphaCoeff == 8)
            {
                switch (gTasks[taskId].tSpriteType)
                {
                    case SPRITE_TYPE_PLATFORM:
                    {
                        for (i = 0; i < PLAT_SPRITE_ID_COUNT; i++)
                            gSprites[sKabaSpeech->platformSpriteIds[i]].invisible ^= TRUE;
                    }
                        break;
                    case SPRITE_TYPE_POKE_BALL:
                        gSprites[sKabaSpeech->ballSpriteId].invisible ^= TRUE;
                        break;
                    default:
                    case SPRITE_TYPE_NONE:
                        break;
                }
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (sKabaSpeech->alphaCoeff2 * 256) + sKabaSpeech->alphaCoeff);
        }
    }
}

static void KabaSpeech_BeginFade(u8 fadeOut, u8 delay, u8 spriteType)
{
    u32 taskId;
    u32 bldTarget1, bldTarget2;

    sKabaSpeech->fadeFinished = FALSE;
    if (spriteType == SPRITE_TYPE_PIC_1 || spriteType == SPRITE_TYPE_PIC_2)
    {
        bldTarget1 = fadeOut ? 8 : 0;
        bldTarget2 = fadeOut ? 8 : 16;
    }
    else
    {
        bldTarget1 = fadeOut ? 16 : 0;
        bldTarget2 = fadeOut ? 0 : 16;
    }
    sKabaSpeech->alphaCoeff = bldTarget1;
    sKabaSpeech->alphaCoeff2 = bldTarget2;
    sKabaSpeech->fadeTimer = delay;

    switch(spriteType)
    {
    case SPRITE_TYPE_PLATFORM:
    case SPRITE_TYPE_POKE_BALL:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    case SPRITE_TYPE_PIC_1:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    case SPRITE_TYPE_PIC_2:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    case SPRITE_TYPE_NONE:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    default:
        break;
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(bldTarget1, bldTarget2));
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DebugPrintf("fadeOut: %d", fadeOut);
    taskId = CreateTask(fadeOut ? Task_KabaSpeech_FadeOut : Task_KabaSpeech_FadeIn, 0);
    gTasks[taskId].tSpriteType = spriteType;
}

static void KabaSpeech_SetDefaultName(void)
{
    u32 i;
    const u8 *src = NULL;
    u8 *dst = NULL;

    if (sKabaSpeech->playerHasName) // rival
    {
        src = (sKabaSpeech->chosenPic == PIC_AO) ? sKabaSpeech_Aka : sKabaSpeech_Ao;
        dst = gSaveBlock2Ptr->rivalName;
    }
    else // player
    {
        src = (sKabaSpeech->chosenPic == PIC_AO) ? sKabaSpeech_Ao : sKabaSpeech_Aka;
        dst = gSaveBlock2Ptr->playerName;
    }

    for (i = 0; i < PLAYER_NAME_LENGTH && src[i] != EOS; i++)
    {
        dst[i] = src[i];
    }
    for (; i < PLAYER_NAME_LENGTH + 1; i++)
    {
        dst[i] = EOS;
    }
}

static void CB2_KabaSpeech_ReturnFromNamingScreen(void)
{
    switch(gMain.state)
    {
        case STATE_RESET:
            SetVBlankCallback(NULL);
            SetHBlankCallback(NULL);
            DmaFill16(3, 0, VRAM, VRAM_SIZE);
            ResetPaletteFade();
            ScanlineEffect_Stop();
            ResetSpriteData();
            ResetTasks();
            FreeAllSpritePalettes();
            ResetTempTileDataBuffers();
            break;
        case STATE_ALLOC: // unused here
            break;
        case STATE_REGS:
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WIN1H, 0);
            SetGpuReg(REG_OFFSET_WIN1V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, 0);
            break;
        case STATE_BGS:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sKabaSpeech_BgTemplates, ARRAY_COUNT(sKabaSpeech_BgTemplates));
            SetBgTilemapBuffer(BG_INTRO, sKabaSpeech->introTilemapBuffer);
            SetBgTilemapBuffer(BG_PIC_1, sKabaSpeech->pic1TilemapBuffer);
            SetBgTilemapBuffer(BG_PIC_2, sKabaSpeech->pic2TilemapBuffer);
            ResetBgPositions();
            break;
        case STATE_BG_GFX:
            KabaSpeech_CreatePlatformSprites(FALSE);
            LoadPalette(sKabaSpeech_BgPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_INTRO, sKabaSpeech_BgGfx, sizeof(sKabaSpeech_BgGfx), 0);
            CopyToBgTilemapBuffer(BG_INTRO, sKabaSpeech_BgMap, 0, 0);
            CopyBgTilemapBufferToVram(BG_INTRO);
            // we're still loading both even though
            // only one of them will be shown at this point
            KabaSpeech_DrawCharacterPic(PIC_AO);
            KabaSpeech_DrawCharacterPic(PIC_AKA);
            break;
        case STATE_WINDOWS:
            InitWindows(sKabaSpeech_WindowTemplates);
            InitTextBoxGfxAndPrinters();
            Menu_LoadStdPalAt(BG_PLTT_ID(13));
            DrawDialogueFrame(WIN_TEXT, TRUE);
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            break;
        case STATE_FINISH:
        {
            u32 hideBg, showBg, bldBg;

            if (sKabaSpeech->chosenPic == PIC_AO)
            {
                hideBg = BG_PIC_2;
                showBg = BG_PIC_1;
                bldBg  = BLDCNT_TGT1_BG2;
            }
            else
            {
                hideBg = BG_PIC_1;
                showBg = BG_PIC_2;
                bldBg  = BLDCNT_TGT1_BG1;
            }

            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BLDCNT,
                bldBg |
                BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BG1HOFS, -AO_PIC_CENTER_POS);
            SetGpuReg(REG_OFFSET_BG2HOFS, AKA_PIC_CENTER_POS);
            ShowBg(BG_INTRO);
            ShowBg(showBg);
            HideBg(hideBg);
            ShowBg(BG_TEXT);
            SetVBlankCallback(VBlankCB_KabaSpeech);
            SetMainCallback2(CB2_KabaSpeech);
            sKabaSpeech->timer = 30;
            CreateTask(Task_KabaSpeech_ConfirmChosenName, 0);
            gMain.state = 0;
            return;
        }
    }
    DebugPrintf("state: %d", gMain.state);
    gMain.state++;
}
