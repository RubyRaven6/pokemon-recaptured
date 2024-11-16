#ifndef GUARD_COMPLEX_QUESTS_H
#define GUARD_COMPLEX_QUESTS_H

#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"
#include "pokemon_icon.h"

/////////////////////////////////////////////
/////////////BEGIN STRING EXTERNS/////////////

//Descriptions
//Hearts and Diamonds
extern const u8 gText_HeartsQuestDesc_1[];
extern const u8 gText_HeartsQuestDesc_2[];
extern const u8 gText_HeartsQuestDesc_3[];

extern const u8 *const gTable_HeartQuestDescs[];

//Aurelious League
extern const u8 gText_LeagueQuestDesc_1[];
extern const u8 gText_LeagueQuestDesc_2[];
extern const u8 gText_LeagueQuestDesc_3[];

extern const u8 *const gTable_LeagueQuestDescs[];

//Maps
//Heart Quest
extern const u8 gText_HeartsQuestMap_1[];
extern const u8 gText_HeartsQuestMap_2[];
extern const u8 gText_HeartsQuestMap_3[];

extern const u8 *const gTable_HeartQuestMaps[];

//league quest
extern const u8 gText_LeagueQuestMap_1[];
extern const u8 gText_LeagueQuestMap_2[];
extern const u8 gText_LeagueQuestMap_3[];

extern const u8 *const gTable_LeagueQuestMaps[];


/////////////END STRING EXTERNS/////////////
////////////////////////////////////////////

/////////////////////////////////////////
///////////BEGIN QUEST STRINGS///////////

/////BEGIN DESCRIPTIONS/////

//Hearts and Diamonds Descriptions
const u8 gText_HeartsQuestDesc_1[] = _("Find a way to meet Diancie again!");
const u8 gText_HeartsQuestDesc_2[] = _("Content 2");
const u8 gText_HeartsQuestDesc_3[] = _("Content 3");

//Aurelious League Descriptions
const u8 gText_LeagueQuestDesc_1[] = _("Find Professor Narra at Dockside\nCity!");
const u8 gText_LeagueQuestDesc_2[] = _("Catch a Pokémon for Professor Narra!");
const u8 gText_LeagueQuestDesc_3[] = _("Content 3");

//////END DESCRIPTIONS//////

//////////BEGIN MAPS////////

//Heart Quest Maps
const u8 gText_HeartsQuestMap_1[] = _("?????");
const u8 gText_HeartsQuestMap_2[] = _("Route 1");
const u8 gText_HeartsQuestMap_3[] = _("Oasis Town");

//League Quest Maps
const u8 gText_LeagueQuestMap_1[] = _("Dockside City");
const u8 gText_LeagueQuestMap_2[] = _("Route 1");
const u8 gText_LeagueQuestMap_3[] = _("Town 3");

/////////END MAPS///////////

////////////////////////////////////////
///////////BEGIN QUEST ARRAYS///////////

//Hearts Quest Arrays
const u8 *const gTable_HeartQuestDescs[3] = {
    gText_HeartsQuestDesc_1,
    gText_HeartsQuestDesc_2,
    gText_HeartsQuestDesc_3,
};

const u8 *const gTable_HeartQuestMaps[3] = {
    gText_HeartsQuestMap_1,
    gText_HeartsQuestMap_2,
    gText_HeartsQuestMap_3,
};

static const u16 HeartQuestSprites[3]={
	SPECIES_DIANCIE,
	OBJ_EVENT_GFX_WALLY,
	OBJ_EVENT_GFX_WALLY,
};

static const u8 HeartQuestSpriteTypes[3]={
	PKMN,
	OBJECT,
	OBJECT,
};


//League Quest Descriptions
const u8 *const gTable_LeagueQuestDescs[3] = {
    gText_LeagueQuestDesc_1,
    gText_LeagueQuestDesc_2,
    gText_LeagueQuestDesc_3,
};

//League Quest Maps
const u8 *const gTable_LeagueQuestMaps[3] = {
    gText_LeagueQuestMap_1,
    gText_LeagueQuestMap_2,
    gText_LeagueQuestMap_3,
};

//League Quest Sprites
static const u16 LeagueQuestSprites[3]={
	OBJ_EVENT_GFX_PROF_BIRCH,
	SPECIES_DRILBUR,
	OBJ_EVENT_GFX_WALLY,
};

static const u8 LeagueQuestSpriteTypes[3]={
	OBJECT,
	PKMN,
	OBJECT,
};

/////////END QUEST ARRAYS/////////
//////////////////////////////////

#endif