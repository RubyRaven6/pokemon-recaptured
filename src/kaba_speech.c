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

// positions for joltik + pokeball
// If you want to edit these, dont touch the `+ 32`!
#define MON_POS_X 55 + 32
#define MON_POS_Y 66 + 32

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
    WIN_YESNO,
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
    u8 platformSpriteIds[2]; // the platform is made out of 2 32x64sprites
    u16 alphaCoeff;
    u16 timer;
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
static void Task_KabaSpeech_SpawnPlatform(u8);

static void KabaSpeech_DrawCharacterPic(u8);
static inline void KabaSpeech_PrintMessageBox(const u8 *);
static void KabaSpeech_CreateMonSprite(void);

// Const data
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
    [WIN_YESNO] = 
    {
        .bg = BG_TEXT,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = (26*4)+1,
    },
    DUMMY_WIN_TEMPLATE,
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
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG_ALL | BLDCNT_EFFECT_BLEND);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
            SetGpuReg(REG_OFFSET_BLDY, 0);
            ShowBg(BG_INTRO);
            ShowBg(BG_PIC_1);
            ShowBg(BG_TEXT);
            SetVBlankCallback(VBlankCB_KabaSpeech);
            PlayBGM(MUS_ROUTE122);
            sKabaSpeech->alphaCoeff = 0;
            sKabaSpeech->timer = 0xD8;
            gTasks[taskId].func = Task_KabaSpeech_FadeInEverything;
            gMain.state = 0;
            return;
    }
    DebugPrintf("state: %d", gMain.state);
    gMain.state++;
}

static void Task_KabaSpeech_FadeInEverything(u8 taskId)
{
    if (sKabaSpeech->timer)
    {
        sKabaSpeech->timer--;
    }
    else if (sKabaSpeech->alphaCoeff >= 16)
    {
        sKabaSpeech->alphaCoeff = 16;
        sKabaSpeech->timer = 80;
        gTasks[taskId].func = Task_KabaSpeech_GreetingsTraveler;
        return;
    }
    else
    {
        sKabaSpeech->alphaCoeff++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sKabaSpeech->alphaCoeff, 16 - sKabaSpeech->alphaCoeff));
    }
}

static void Task_KabaSpeech_GreetingsTraveler(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
        }
        else
        {
            KabaSpeech_PrintMessageBox(sKabaSpeech_Greetings);
            gTasks[taskId].func = Task_KabaSpeech_AndThis;
        }
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
        }
        else
        {
            spriteId = sKabaSpeech->monSpriteId;
            gSprites[spriteId].invisible = FALSE;
            CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, MON_POS_X, MON_POS_Y, 0, 0, 32, 0x00007FFF, SPECIES_JOLTIK);
            gTasks[taskId].func = Task_KabaSpeech_JoltikAPokemon;
            sKabaSpeech->timer = 0;
        }
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
        gSprites[sKabaSpeech->monSpriteId].invisible = TRUE;
        gSprites[sKabaSpeech->ballSpriteId].invisible = TRUE;
        DestroySprite(&gSprites[sKabaSpeech->monSpriteId]);
        DestroySprite(&gSprites[sKabaSpeech->ballSpriteId]);
        sKabaSpeech->alphaCoeff = 16;
        gTasks[taskId].func = Task_KabaSpeech_FadeOutEverything;
    }
}

static void Task_KabaSpeech_FadeOutEverything(u8 taskId)
{
    if (sKabaSpeech->alphaCoeff <= 0)
    {
        sKabaSpeech->alphaCoeff = 0;
        sKabaSpeech->timer = 80;
        gTasks[taskId].func = Task_KabaSpeech_SpawnPlatform;
    }
    else
    {
        sKabaSpeech->alphaCoeff--;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sKabaSpeech->alphaCoeff, 16 - sKabaSpeech->alphaCoeff));
    }
}

static void Task_KabaSpeech_SpawnPlatform(u8 taskId)
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

static void KabaSpeech_CreatePlatformSprites(void)
{

}
