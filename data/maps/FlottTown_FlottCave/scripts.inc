# 1 "data/maps/FlottTown_FlottCave/scripts.pory"

# 2 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_ZUBAT, 1
# 3 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_MANKEY, 2
# 4 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_TINKATINK, 3
# 5 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_TEDDIURSA, 4
# 6 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_ELSIE, 7
# 7 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_BARNEY, 8

FlottTown_FlottCave_MapScripts::
# 11 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_FlottCave_OnTransition
# 12 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 6, FlottTown_FlottCave_OnFrame
# 14 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 9, FlottTown_FlottCave_TurnOn
	.2byte 0


FlottTown_FlottCave_OnTransition::
# 19 "data/maps/FlottTown_FlottCave/scripts.pory"
	destroyfollower
# 20 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_BARNEY_IN_CAVE
# 21 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_ELSIE_IN_CAVE
# 22 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_CaveLightLevel
	return


FlottTown_FlottCave_OnFrame::
# 26 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_ElsieWorried, MSGBOX_DEFAULT
# 27 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 28 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_FALLEN_INTO_CAVE
# 29 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 7
	end


FlottTown_FlottCave_TurnOn::
# 34 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflashlevel 0
	return


FlottTown_FlottCave_CaveLightLevel::
# 38 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_FLOTT_TOWN_STATE
# 39 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 6, FlottTown_FlottCave_CaveLightLevel_2
# 42 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 8, FlottTown_FlottCave_CaveLightLevel_3
	return

FlottTown_FlottCave_CaveLightLevel_2:
# 40 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflashlevel 6
	return

FlottTown_FlottCave_CaveLightLevel_3:
# 43 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflashlevel 0
	return


FlottTown_FlottCave_EventScript_ZubatAttacks::
# 49 "data/maps/FlottTown_FlottCave/scripts.pory"
	lockall
# 50 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0, MSGBOX_DEFAULT
# 51 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 52 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 53 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
# 54 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 55 "data/maps/FlottTown_FlottCave/scripts.pory"
	special CheckZubatSpawning
# 56 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_ZUBAT
# 57 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_ZUBAT, VAR_TEMP_0, VAR_TEMP_1
# 58 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ZUBAT, Common_Movement_FacePlayer
# 59 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_FacePlayerDirection
# 60 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 61 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1
# 62 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterChoice
# 63 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 64 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_WildZubatBattle
# 65 "data/maps/FlottTown_FlottCave/scripts.pory"
	delay 60
# 66 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
# 67 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_FALLEN_INTO_CAVE
# 68 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 8
# 69 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_RockSmash
	end


FlottTown_FlottCave_EventScript_RockSmash::
# 74 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_0, MSGBOX_DEFAULT
# 75 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_GOLURK, CRY_MODE_NORMAL
# 76 "data/maps/FlottTown_FlottCave/scripts.pory"
	playse SE_M_ROCK_THROW
# 77 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_ELSIE_IN_CAVE
# 78 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_BARNEY_IN_CAVE
# 79 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_TEMP_11
# 80 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject 6
# 81 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_1, MSGBOX_DEFAULT
# 82 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
	end


FlottTown_FlottCave_RightTrigger::
# 87 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 88 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_BottomTrigger::
# 91 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 92 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_EventScript_ElsieRescue::
# 96 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 97 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_Rescue, MSGBOX_DEFAULT
# 98 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 99 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_BARNEY, FlottTown_FlottCave_Movement_BarneyWalksToPlayer
# 100 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement LOCALID_BARNEY
# 101 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, FlottTown_FlottCave_Movement_ElsieWalksUp
# 102 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_Movement_PlayerWalksUp
# 103 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement LOCALID_BARNEY
# 104 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement LOCALID_ELSIE
# 105 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 106 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
# 107 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_0, MSGBOX_DEFAULT
# 108 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_WalkInPlaceRight
# 109 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_1, MSGBOX_DEFAULT
# 110 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
# 111 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_BARNEY, Common_Movement_WalkInPlaceDown
# 112 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_LetsGoHome, MSGBOX_DEFAULT
# 113 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_ELSIE_IN_CAVE
# 114 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_BARNEY_IN_CAVE
# 115 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 9
# 116 "data/maps/FlottTown_FlottCave/scripts.pory"
	warp MAP_FLOTT_TOWN_BARNEYS_HOUSE, 7, 4
	end


Holder::
	return


FlottTown_FlottCave_FacePlayerDirection::
# 125 "data/maps/FlottTown_FlottCave/scripts.pory"
	specialvar VAR_ZUBAT_DIR, GetPlayerFacingDirection
# 126 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_ZUBAT_DIR
# 127 "data/maps/FlottTown_FlottCave/scripts.pory"
	case DIR_NORTH, FlottTown_FlottCave_FacePlayerDirection_3
# 130 "data/maps/FlottTown_FlottCave/scripts.pory"
	case DIR_SOUTH, FlottTown_FlottCave_FacePlayerDirection_4
# 133 "data/maps/FlottTown_FlottCave/scripts.pory"
	case DIR_EAST, FlottTown_FlottCave_FacePlayerDirection_5
# 136 "data/maps/FlottTown_FlottCave/scripts.pory"
	case DIR_WEST, FlottTown_FlottCave_FacePlayerDirection_6
	return

FlottTown_FlottCave_FacePlayerDirection_3:
# 128 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	return

FlottTown_FlottCave_FacePlayerDirection_4:
# 131 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	return

FlottTown_FlottCave_FacePlayerDirection_5:
# 134 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	return

FlottTown_FlottCave_FacePlayerDirection_6:
# 137 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	return


FlottTown_FlottCave_StarterChoice::
# 144 "data/maps/FlottTown_FlottCave/scripts.pory"
	lockall
# 145 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_0
# 146 "data/maps/FlottTown_FlottCave/scripts.pory"
	multichoice 10, 4, 115, 1
# 147 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FlottTown_FlottCave_StarterChoice_2
# 161 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FlottTown_FlottCave_StarterChoice_5
# 175 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FlottTown_FlottCave_StarterChoice_7
	return

FlottTown_FlottCave_StarterChoice_2:
# 148 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_MANKEY
# 149 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_MANKEY, Common_Movement_FaceAwayPlayer
# 150 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_MANKEY, VAR_TEMP_2, VAR_TEMP_3
# 151 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 152 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_1, MSGBOX_DEFAULT
# 153 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
# 154 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 155 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_MANKEY, 10, ITEM_NONE
# 156 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 157 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
# 158 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_5:
# 162 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_TINKATINK
# 163 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TINKATINK, Common_Movement_FaceAwayPlayer
# 164 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_TINKATINK, VAR_TEMP_2, VAR_TEMP_3
# 165 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 166 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_2, MSGBOX_DEFAULT
# 167 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_TINKATINK, CRY_MODE_NORMAL
# 168 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 169 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_TINKATINK, 10, ITEM_NONE
# 170 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 171 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 172 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_7:
# 176 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_TEDDIURSA
# 177 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TEDDIURSA, Common_Movement_FaceAwayPlayer
# 178 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_TEDDIURSA, VAR_TEMP_2, VAR_TEMP_3
# 179 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 180 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_3, MSGBOX_DEFAULT
# 181 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_TEDDIURSA, CRY_MODE_NORMAL
# 182 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 183 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_TEDDIURSA, 10, ITEM_NONE
# 184 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 185 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 186 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
	return


FlottTown_FlottCave_WildZubatBattle::
# 192 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeitem ITEM_POKE_BALL, 1
# 193 "data/maps/FlottTown_FlottCave/scripts.pory"
	setwildbattle SPECIES_ZUBAT, 10
# 194 "data/maps/FlottTown_FlottCave/scripts.pory"
	dowildbattle
# 195 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 196 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_ZUBAT
# 197 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 198 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_WildZubatBattle_Text_0, MSGBOX_DEFAULT
# 199 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
	return


FlottTown_FlottCave_StarterWantsToJoin::
# 204 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_STARTER_MON
# 205 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 0, FlottTown_FlottCave_StarterWantsToJoin_3
# 216 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_StarterWantsToJoin_4
# 227 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_StarterWantsToJoin_5
FlottTown_FlottCave_StarterWantsToJoin_1:
	return

FlottTown_FlottCave_StarterWantsToJoin_3:
# 206 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_MANKEY, Common_Movement_FacePlayer
# 207 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_0, MSGBOX_DEFAULT
# 208 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
# 209 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_6
# 213 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_2, MSGBOX_DEFAULT
# 214 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_4:
# 217 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TINKATINK, Common_Movement_FacePlayer
# 218 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_3, MSGBOX_DEFAULT
# 219 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_4, MSGBOX_YESNO
# 220 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_9
# 224 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_5, MSGBOX_DEFAULT
# 225 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_5:
# 228 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TEDDIURSA, Common_Movement_FacePlayer
# 229 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_6, MSGBOX_DEFAULT
# 230 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
# 231 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_12
# 235 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_7, MSGBOX_DEFAULT
# 236 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_6:
# 210 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_9:
# 221 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_12:
# 232 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1


FlottTown_FlottCave_StarterYesNo::
# 243 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_STARTER_MON
# 244 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 0, FlottTown_FlottCave_StarterYesNo_2
# 252 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_StarterYesNo_3
# 260 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_StarterYesNo_4
	return

FlottTown_FlottCave_StarterYesNo_2:
# 245 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 246 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_0, MSGBOX_DEFAULT
# 247 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 248 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 249 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 250 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_3:
# 253 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 254 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_1, MSGBOX_DEFAULT
# 255 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 256 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 257 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
# 258 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_4:
# 261 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 262 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_2, MSGBOX_DEFAULT
# 263 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 264 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 265 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
# 266 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return


FlottTown_FlottCave_NicknamePartyMon::
# 272 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_NicknamePartyMon_Text_0, MSGBOX_YESNO
# 273 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_NicknamePartyMon_2
# 277 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
FlottTown_FlottCave_NicknamePartyMon_1:
	return

FlottTown_FlottCave_NicknamePartyMon_2:
# 274 "data/maps/FlottTown_FlottCave/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 275 "data/maps/FlottTown_FlottCave/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto FlottTown_FlottCave_NicknamePartyMon_1


# 281 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_BarneyWalksToPlayer:
# 282 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 282 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 282 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 282 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 283 "data/maps/FlottTown_FlottCave/scripts.pory"
	face_down
# 284 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 287 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_ElsieWalksUp:
# 288 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 288 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 288 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 289 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 292 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_PlayerWalksUp:
# 293 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_left
# 294 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 294 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 294 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 295 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0:
# 50 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "As you walk inside the dark cave, you\n"
	.string "hear a noise coming from the darkness!$"

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1:
# 61 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "As the Pokémon is about to attack, you\n"
	.string "feel a presence approach.$"

FlottTown_FlottCave_EventScript_RockSmash_Text_0:
# 74 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "???: Golurk! Use Rock Smash!$"

FlottTown_FlottCave_EventScript_RockSmash_Text_1:
# 81 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "That sounded like it came from the\n"
	.string "smashable rocks!$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_0:
# 107 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: {PLAYER}! Thank goodness\n"
	.string "you're alright. I don't know what I'd do\l"
	.string "if you got hurt.$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_1:
# 109 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: This is Mr. Heinrich. This was his\n"
	.string "old gym.$"

FlottTown_FlottCave_StarterChoice_Text_0:
# 145 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "What presence do you feel intervenes?$"

FlottTown_FlottCave_StarterChoice_Text_1:
# 152 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_2:
# 166 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_3:
# 180 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa jumped in to save you!$"

FlottTown_FlottCave_WildZubatBattle_Text_0:
# 198 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "The wild Zubat ran away!$"

FlottTown_FlottCave_StarterWantsToJoin_Text_0:
# 207 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey is looking at you curiously. It\n"
	.string "seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_1:
# 208 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Do you accept?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_2:
# 213 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey looks like it's about to hit you\n"
	.string "next.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_3:
# 218 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink is too busy playing with its\n"
	.string "hammer to notice you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_4:
# 219 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Do you want to convince it to join you?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_5:
# 224 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Are you sure? It looks really cute.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_6:
# 229 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa is looking at you curiously.\n"
	.string "It seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_7:
# 235 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa looks at you with Baby-Doll\n"
	.string "eyes.$"

FlottTown_FlottCave_StarterYesNo_Text_0:
# 246 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_1:
# 254 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_2:
# 262 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa joined you!$"

FlottTown_FlottCave_NicknamePartyMon_Text_0:
# 272 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Give a nickname?$"

FlottTown_FlottCave_Text_ElsieWorried::
# 298 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: Oh my god! {PLAYER}! Are you\n"
	.string "okay?! Sit tight in there, okay? I'll go\l"
	.string "get help!\p"
	.string "You here the footsteps of your sister\n"
	.string "exiting the gym.$"

FlottTown_FlottCave_Text_Rescue::
# 302 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "???: Ah! There you are! Come, let's get\n"
	.string "you out here.\p"
	.string "ELSIE: {PLAYER}! Oh gods, I'm so glad\n"
	.string "you're okay!$"

FlottTown_FlottCave_Text_LetsGoHome::
# 307 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "BARNEY: Indeed it were. Now, how about\n"
	.string "we get you kids out of this dreadful\l"
	.string "place? You both look tired. Seeing as\l"
	.string "it's my gym, anything that happens here\l"
	.string "is on my head. My home is nearby; let's\l"
	.string "take a rest there.$"
