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
	return

FlottTown_FlottCave_CaveLightLevel_2:
# 40 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflashlevel 6
	return


FlottTown_FlottCave_EventScript_ZubatAttacks::
# 46 "data/maps/FlottTown_FlottCave/scripts.pory"
	lockall
# 47 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0, MSGBOX_DEFAULT
# 48 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 49 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 50 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
# 51 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 52 "data/maps/FlottTown_FlottCave/scripts.pory"
	special CheckZubatSpawning
# 53 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_ZUBAT
# 54 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_ZUBAT, VAR_TEMP_0, VAR_TEMP_1
# 55 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ZUBAT, Common_Movement_FacePlayer
# 56 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_FacePlayerDirection
# 57 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1
# 59 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterChoice
# 60 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 61 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_WildZubatBattle
# 62 "data/maps/FlottTown_FlottCave/scripts.pory"
	delay 60
# 63 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
# 64 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_FALLEN_INTO_CAVE
# 65 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 8
# 66 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 67 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_0x8004, 13
# 68 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_0x8005, 12
# 69 "data/maps/FlottTown_FlottCave/scripts.pory"
	special TeleportCamera
# 70 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 13, 12
# 71 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 72 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_2
# 73 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 74 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_RockSmash
	end


FlottTown_FlottCave_EventScript_RockSmash::
# 79 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 80 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_0, MSGBOX_DEFAULT
# 81 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_GOLURK, CRY_MODE_NORMAL
# 82 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 83 "data/maps/FlottTown_FlottCave/scripts.pory"
	playse SE_M_ROCK_THROW
# 84 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitse
# 85 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_ELSIE_IN_CAVE
# 86 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_BARNEY_IN_CAVE
# 87 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_TEMP_11
# 88 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject 6
# 89 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitse
# 90 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_1, MSGBOX_DEFAULT
# 91 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
	end


FlottTown_FlottCave_RightTrigger::
# 96 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 97 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_BottomTrigger::
# 100 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_PlayerFacesBarneyFromBottomTrigger
# 101 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_EventScript_ElsieRescue::
# 105 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 106 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_Rescue, MSGBOX_DEFAULT
# 107 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 108 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_BARNEY, FlottTown_FlottCave_Movement_BarneyWalksUp
# 109 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_Movement_PlayerWalksUp
# 110 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, FlottTown_FlottCave_Movement_ElsieWalksUp
# 111 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement LOCALID_BARNEY
# 112 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement LOCALID_ELSIE
# 113 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 114 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
# 115 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_0, MSGBOX_DEFAULT
# 116 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 117 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 118 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_WalkInPlaceRight
# 119 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_1, MSGBOX_DEFAULT
# 120 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 121 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 122 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
# 123 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_BARNEY, Common_Movement_WalkInPlaceDown
# 124 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_LetsGoHome, MSGBOX_DEFAULT
# 125 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 126 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 127 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_ELSIE_IN_CAVE
# 128 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_BARNEY_IN_CAVE
# 129 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_BARNEY_IN_HOUSE
# 130 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_ELSIE_IN_BARNEYS_HOUSE
# 131 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 9
# 132 "data/maps/FlottTown_FlottCave/scripts.pory"
	warpsilent MAP_FLOTT_TOWN_BARNEYS_HOUSE, 7, 4
	end


FlottTown_FlottCave_FacePlayerDirection::
# 137 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_ZUBAT_DIR
# 139 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_FacePlayerDirection_2
# 143 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_FacePlayerDirection_3
# 147 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 3, FlottTown_FlottCave_FacePlayerDirection_4
# 151 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 4, FlottTown_FlottCave_FacePlayerDirection_5
	return

FlottTown_FlottCave_FacePlayerDirection_2:
# 140 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	return

FlottTown_FlottCave_FacePlayerDirection_3:
# 144 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	return

FlottTown_FlottCave_FacePlayerDirection_4:
# 148 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	return

FlottTown_FlottCave_FacePlayerDirection_5:
# 152 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	return


FlottTown_FlottCave_StarterChoice::
# 158 "data/maps/FlottTown_FlottCave/scripts.pory"
	lockall
# 159 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_0
# 160 "data/maps/FlottTown_FlottCave/scripts.pory"
	multichoice 10, 4, 115, 1
# 161 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FlottTown_FlottCave_StarterChoice_2
# 175 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FlottTown_FlottCave_StarterChoice_5
# 189 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FlottTown_FlottCave_StarterChoice_7
	return

FlottTown_FlottCave_StarterChoice_2:
# 162 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_MANKEY
# 163 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_MANKEY, Common_Movement_FaceAwayPlayer
# 164 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_MANKEY, VAR_TEMP_2, VAR_TEMP_3
# 165 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 166 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_1, MSGBOX_DEFAULT
# 167 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
# 168 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 169 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_MANKEY, 10, ITEM_NONE
# 170 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 171 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
# 172 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_5:
# 176 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_TINKATINK
# 177 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TINKATINK, Common_Movement_FaceAwayPlayer
# 178 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_TINKATINK, VAR_TEMP_2, VAR_TEMP_3
# 179 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 180 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_2, MSGBOX_DEFAULT
# 181 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_TINKATINK, CRY_MODE_NORMAL
# 182 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 183 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_TINKATINK, 10, ITEM_NONE
# 184 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 185 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 186 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_7:
# 190 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_TEDDIURSA
# 191 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TEDDIURSA, Common_Movement_FaceAwayPlayer
# 192 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_TEDDIURSA, VAR_TEMP_2, VAR_TEMP_3
# 193 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 194 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_3, MSGBOX_DEFAULT
# 195 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_TEDDIURSA, CRY_MODE_NORMAL
# 196 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 197 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_TEDDIURSA, 10, ITEM_NONE
# 198 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 199 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 200 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
	return


FlottTown_FlottCave_WildZubatBattle::
# 206 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeitem ITEM_POKE_BALL, 1
# 207 "data/maps/FlottTown_FlottCave/scripts.pory"
	setwildbattle SPECIES_ZUBAT, 10
# 208 "data/maps/FlottTown_FlottCave/scripts.pory"
	dowildbattle
# 209 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 210 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_ZUBAT
# 211 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 212 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_WildZubatBattle_Text_0, MSGBOX_DEFAULT
# 213 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
	return


FlottTown_FlottCave_StarterWantsToJoin::
# 218 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_STARTER_MON
# 219 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 0, FlottTown_FlottCave_StarterWantsToJoin_3
# 230 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_StarterWantsToJoin_4
# 241 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_StarterWantsToJoin_5
FlottTown_FlottCave_StarterWantsToJoin_1:
	return

FlottTown_FlottCave_StarterWantsToJoin_3:
# 220 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_MANKEY, Common_Movement_FacePlayer
# 221 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_0, MSGBOX_DEFAULT
# 222 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
# 223 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_6
# 227 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_2, MSGBOX_DEFAULT
# 228 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_4:
# 231 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TINKATINK, Common_Movement_FacePlayer
# 232 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_3, MSGBOX_DEFAULT
# 233 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_4, MSGBOX_YESNO
# 234 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_9
# 238 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_5, MSGBOX_DEFAULT
# 239 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_5:
# 242 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TEDDIURSA, Common_Movement_FacePlayer
# 243 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_6, MSGBOX_DEFAULT
# 244 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
# 245 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_12
# 249 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_7, MSGBOX_DEFAULT
# 250 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_6:
# 224 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_9:
# 235 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_12:
# 246 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1


FlottTown_FlottCave_StarterYesNo::
# 257 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_STARTER_MON
# 258 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 0, FlottTown_FlottCave_StarterYesNo_2
# 266 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_StarterYesNo_3
# 274 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_StarterYesNo_4
	return

FlottTown_FlottCave_StarterYesNo_2:
# 259 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 260 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_0, MSGBOX_DEFAULT
# 261 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 262 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 263 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 264 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_3:
# 267 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 268 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_1, MSGBOX_DEFAULT
# 269 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 270 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 271 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
# 272 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_4:
# 275 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 276 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_2, MSGBOX_DEFAULT
# 277 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 278 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 279 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
# 280 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return


FlottTown_FlottCave_NicknamePartyMon::
# 286 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_NicknamePartyMon_Text_0, MSGBOX_YESNO
# 287 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_NicknamePartyMon_2
# 291 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
FlottTown_FlottCave_NicknamePartyMon_1:
	return

FlottTown_FlottCave_NicknamePartyMon_2:
# 288 "data/maps/FlottTown_FlottCave/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 289 "data/maps/FlottTown_FlottCave/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto FlottTown_FlottCave_NicknamePartyMon_1


# 295 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_PlayerFacesBarneyFromBottomTrigger:
# 296 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 297 "data/maps/FlottTown_FlottCave/scripts.pory"
	face_left
# 298 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 302 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_BarneyWalksUp:
# 303 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 303 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 303 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 303 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 304 "data/maps/FlottTown_FlottCave/scripts.pory"
	face_down
# 305 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 308 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_ElsieWalksUp:
# 309 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 309 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 309 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 310 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 313 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_PlayerWalksUp:
# 314 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_left
# 315 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 315 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 315 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 316 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0:
# 47 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "As you walk inside the dark cave, you\n"
	.string "hear a noise coming from the darkness!$"

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1:
# 58 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "As the Pokémon is about to attack, you\n"
	.string "feel a presence approach.$"

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_2:
# 72 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "You decide to wait with your new\n"
	.string "partner for your sister to return.$"

FlottTown_FlottCave_EventScript_RockSmash_Text_0:
# 80 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "???: Golurk! Use Rock Smash!$"

FlottTown_FlottCave_EventScript_RockSmash_Text_1:
# 90 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "That sounded like it came from the\n"
	.string "smashable rocks!$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_0:
# 115 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: {PLAYER}! Thank goodness\n"
	.string "you're alright. I don't know what I'd do\l"
	.string "if you got hurt.$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_1:
# 119 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: This is Mr. Heinrich. This was his\n"
	.string "old gym.$"

FlottTown_FlottCave_StarterChoice_Text_0:
# 159 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "What presence do you feel intervenes?$"

FlottTown_FlottCave_StarterChoice_Text_1:
# 166 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_2:
# 180 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_3:
# 194 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa jumped in to save you!$"

FlottTown_FlottCave_WildZubatBattle_Text_0:
# 212 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "The wild Zubat ran away!$"

FlottTown_FlottCave_StarterWantsToJoin_Text_0:
# 221 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey is looking at you curiously. It\n"
	.string "seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_1:
# 222 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Do you accept?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_2:
# 227 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey looks like it's about to hit you\n"
	.string "next.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_3:
# 232 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink is too busy playing with its\n"
	.string "hammer to notice you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_4:
# 233 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Do you want to convince it to join you?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_5:
# 238 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Are you sure? It looks really cute.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_6:
# 243 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa is looking at you curiously.\n"
	.string "It seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_7:
# 249 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa looks at you with Baby-Doll\n"
	.string "eyes.$"

FlottTown_FlottCave_StarterYesNo_Text_0:
# 260 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_1:
# 268 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_2:
# 276 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa joined you!$"

FlottTown_FlottCave_NicknamePartyMon_Text_0:
# 286 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Give a nickname?$"

FlottTown_FlottCave_Text_ElsieWorried::
# 319 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: Oh my god! {PLAYER}! Are you\n"
	.string "okay?! Sit tight in there, okay? I'll go\l"
	.string "get help!\p"
	.string "You here the footsteps of your sister\n"
	.string "exiting the gym.$"

FlottTown_FlottCave_Text_Rescue::
# 323 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "???: Ah! There you are! Come, let's get\n"
	.string "you out here.\p"
	.string "ELSIE: {PLAYER}! Oh gods, I'm so glad\n"
	.string "you're okay!$"

FlottTown_FlottCave_Text_LetsGoHome::
# 328 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "BARNEY: Indeed it were. Now, how about\n"
	.string "we get you kids out of this dreadful\l"
	.string "place? You both look tired. Seeing as\l"
	.string "it's my gym, anything that happens here\l"
	.string "is on my head. My home is nearby; let's\l"
	.string "take a rest there.$"
