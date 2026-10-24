#include "global.h"
#include "config/general.h"
#include "constants/global.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "graphics.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "config/quickstart.h"
#include "quickstart.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"


#define TAG_SKIP_INTRO 2000

static const u32 gQuickstartHudGfx[] = INCGFX_U32("graphics/quickstart/quickstart_hud.png", ".4bpp.smol");
#if FIRERED
static const u16 gQuickstartHudPal[] = INCGFX_U16("graphics/quickstart/firered.pal", ".gbapal");
#elif LEAFGREEN
static const u16 gQuickstartHudPal[] = INCGFX_U16("graphics/quickstart/leafgreen.pal", ".gbapal");
#else
static const u16 gQuickstartHudPal[] = INCGFX_U16("graphics/quickstart/emerald.pal", ".gbapal");
#endif

static const struct OamData sQuickstartHudOam = {
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .priority = 0,
    .paletteNum = 0,
};

static const struct SpriteTemplate sQuickstartHudTemplate = {
    .tileTag = TAG_SKIP_INTRO,
    .paletteTag = TAG_SKIP_INTRO,
    .oam = &sQuickstartHudOam,
    .anims = gDummySpriteAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_QuickstartHud = {
    .data = gQuickstartHudGfx,
    .size = 0x200,
    .tag = TAG_SKIP_INTRO
};
static const struct SpritePalette sSpritePalette_QuickstartHud = {
    .data = gQuickstartHudPal,
    .tag = TAG_SKIP_INTRO
};

static inline enum PlayerGender SetQuickstartPlayerGender()
{
    const enum PlayerGender genders[] = {GENDER_MASCULINE, GENDER_FEMININE, GENDER_ANDROGYNOUS};
    switch (QUICKSTART_GENDER)
    {
    case GENDER_MASC:
        return GENDER_MASCULINE;
    case GENDER_FEMME:
        return GENDER_FEMININE;
    case GENDER_ANDRO:
        return GENDER_ANDROGYNOUS;
    case GENDER_RANDOM:
    default:
        return RandomElement(RNG_NONE, genders);
    }
}

static void CB2_SkipToNewGame(void)
{
#if IS_FRLG
    static const u8 sText_PlayerMale[] = _("RED");
    static const u8 sText_PlayerFemale[] = _("LEAF");
    static const u8 sText_Rival[] = _("BLUE");
#else
    static const u8 sText_PlayerMale[] = _("Brendan");
    static const u8 sText_PlayerFemale[] = _("May");
    static const u8 sText_PlayerAndro[] = _("Kris");
#endif  // IS_FRLG

    if (!UpdatePaletteFade())
    {
        gSaveBlock2Ptr->playerGender = SetQuickstartPlayerGender();
        const u8* textPtr = 0;
        switch(gSaveBlock2Ptr->playerGender)
        {
            case GENDER_MASCULINE:
                textPtr = sText_PlayerMale;
                break;
            case GENDER_FEMININE:
                textPtr = sText_PlayerFemale;
                break;
            case GENDER_ANDROGYNOUS:
                textPtr = sText_PlayerAndro;
                break;
        }
        StringCopy_PlayerName(gSaveBlock2Ptr->playerName, textPtr);

#if IS_FRLG
        StringCopy_PlayerName(gSaveBlock1Ptr->rivalName, sText_Rival);
#endif  // IS_FRLG

        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        SetMainCallback2(CB2_NewGame);
    }
}

static void LoadQuickstartSpritsheetAndPal(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_QuickstartHud);
    LoadSpritePalette(&sSpritePalette_QuickstartHud);
}

void CreateQuickstartHud(void)
{
    s16 x = QUICKSTART_HUD_X;
    s16 y = QUICKSTART_HUD_Y;

    LoadQuickstartSpritsheetAndPal();
    CreateSprite(&sQuickstartHudTemplate, x, y, 0);
}

void Quickstart(void)
{
    if (!gPaletteFade.active)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_SkipToNewGame);
    }
}

