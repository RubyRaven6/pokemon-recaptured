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
	.2byte 0


FlottTown_FlottCave_OnTransition:
# 19 "data/maps/FlottTown_FlottCave/scripts.pory"
	destroyfollower
# 20 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_BARNEY_IN_CAVE
# 21 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_ELSIE_IN_CAVE
# 22 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_CaveLightLevel
	return


FlottTown_FlottCave_OnFrame:
# 26 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_ElsieWorried, MSGBOX_DEFAULT
# 27 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 28 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_FALLEN_INTO_CAVE
# 29 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 7
	end


FlottTown_FlottCave_CaveLightLevel:
# 34 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflashlevel 6
	end


FlottTown_FlottCave_EventScript_ZubatAttacks::
# 43 "data/maps/FlottTown_FlottCave/scripts.pory"
	lockall
# 44 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0, MSGBOX_DEFAULT
# 45 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 46 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 47 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
# 48 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 49 "data/maps/FlottTown_FlottCave/scripts.pory"
	special CheckZubatSpawning
# 50 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_ZUBAT
# 51 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_ZUBAT, VAR_TEMP_0, VAR_TEMP_1
# 52 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ZUBAT, Common_Movement_FacePlayer
# 53 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_FacePlayerDirection
# 54 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 55 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1
# 56 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterChoice
# 57 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 58 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_WildZubatBattle
# 59 "data/maps/FlottTown_FlottCave/scripts.pory"
	delay 60
# 60 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
# 61 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_FALLEN_INTO_CAVE
# 62 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 8
# 63 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 64 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_0x8004, 13
# 65 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_0x8005, 12
# 66 "data/maps/FlottTown_FlottCave/scripts.pory"
	special TeleportCamera
# 67 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 13, 12
# 68 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 69 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_2
# 70 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 71 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_RockSmash
	end


FlottTown_FlottCave_EventScript_RockSmash::
# 76 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 77 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_0, MSGBOX_DEFAULT
# 78 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_GOLURK, CRY_MODE_NORMAL
# 79 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 80 "data/maps/FlottTown_FlottCave/scripts.pory"
	playse SE_M_ROCK_THROW
# 81 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitse
# 82 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 83 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_ELSIE_IN_CAVE
# 84 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_BARNEY_IN_CAVE
# 85 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_TEMP_11
# 86 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject 6
# 87 "data/maps/FlottTown_FlottCave/scripts.pory"
	callnative RemoveFollowingPokemon
# 88 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitse
# 89 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_1, MSGBOX_DEFAULT
# 90 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
	end


FlottTown_FlottCave_RightTrigger::
# 95 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 96 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_BottomTrigger::
# 99 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_PlayerFacesBarneyFromBottomTrigger
# 100 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_EventScript_ElsieRescue::
# 104 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 105 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_Rescue, MSGBOX_DEFAULT
# 106 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 107 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_BARNEY, FlottTown_FlottCave_Movement_BarneyWalksUp
# 108 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_Movement_PlayerWalksUp
# 109 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, FlottTown_FlottCave_Movement_ElsieWalksUp
# 110 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement LOCALID_BARNEY
# 111 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement LOCALID_ELSIE
# 112 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 113 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
# 114 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_0, MSGBOX_DEFAULT
# 115 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 116 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 117 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_WalkInPlaceRight
# 118 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_1, MSGBOX_DEFAULT
# 119 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 120 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 121 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
# 122 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_BARNEY, Common_Movement_WalkInPlaceDown
# 123 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_LetsGoHome, MSGBOX_DEFAULT
# 124 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 125 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 126 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_ELSIE_IN_CAVE
# 127 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_BARNEY_IN_CAVE
# 128 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_BARNEY_IN_HOUSE
# 129 "data/maps/FlottTown_FlottCave/scripts.pory"
	clearflag FLAG_ELSIE_IN_BARNEYS_HOUSE
# 130 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 9
# 131 "data/maps/FlottTown_FlottCave/scripts.pory"
	warpsilent MAP_FLOTT_TOWN_BARNEYS_HOUSE, 7, 4
	end


FlottTown_FlottCave_FacePlayerDirection:
# 136 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_ZUBAT_DIR
# 138 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_FacePlayerDirection_2
# 142 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_FacePlayerDirection_3
# 146 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 3, FlottTown_FlottCave_FacePlayerDirection_4
# 150 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 4, FlottTown_FlottCave_FacePlayerDirection_5
	return

FlottTown_FlottCave_FacePlayerDirection_2:
# 139 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	return

FlottTown_FlottCave_FacePlayerDirection_3:
# 143 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	return

FlottTown_FlottCave_FacePlayerDirection_4:
# 147 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	return

FlottTown_FlottCave_FacePlayerDirection_5:
# 151 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	return


FlottTown_FlottCave_StarterChoice:
# 157 "data/maps/FlottTown_FlottCave/scripts.pory"
	lockall
# 158 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_0
# 159 "data/maps/FlottTown_FlottCave/scripts.pory"
	multichoice 10, 4, 115, 1
# 160 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FlottTown_FlottCave_StarterChoice_2
# 174 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FlottTown_FlottCave_StarterChoice_5
# 188 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FlottTown_FlottCave_StarterChoice_7
	return

FlottTown_FlottCave_StarterChoice_2:
# 161 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_MANKEY
# 162 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_MANKEY, Common_Movement_FaceAwayPlayer
# 163 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_MANKEY, VAR_TEMP_2, VAR_TEMP_3
# 164 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 165 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_1, MSGBOX_DEFAULT
# 166 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
# 167 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 168 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_MANKEY, 10, ITEM_NONE
# 169 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 170 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
# 171 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_5:
# 175 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_TINKATINK
# 176 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TINKATINK, Common_Movement_FaceAwayPlayer
# 177 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_TINKATINK, VAR_TEMP_2, VAR_TEMP_3
# 178 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 179 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_2, MSGBOX_DEFAULT
# 180 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_TINKATINK, CRY_MODE_NORMAL
# 181 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 182 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_TINKATINK, 10, ITEM_NONE
# 183 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 184 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 185 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_7:
# 189 "data/maps/FlottTown_FlottCave/scripts.pory"
	addobject LOCALID_TEDDIURSA
# 190 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TEDDIURSA, Common_Movement_FaceAwayPlayer
# 191 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_TEDDIURSA, VAR_TEMP_2, VAR_TEMP_3
# 192 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 193 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterChoice_Text_3, MSGBOX_DEFAULT
# 194 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_TEDDIURSA, CRY_MODE_NORMAL
# 195 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 196 "data/maps/FlottTown_FlottCave/scripts.pory"
	givemon SPECIES_TEDDIURSA, 10, ITEM_NONE
# 197 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 198 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 199 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
	return


FlottTown_FlottCave_WildZubatBattle:
# 205 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeitem ITEM_POKE_BALL, 1
# 206 "data/maps/FlottTown_FlottCave/scripts.pory"
	setwildbattle SPECIES_ZUBAT, 10
# 207 "data/maps/FlottTown_FlottCave/scripts.pory"
	dowildbattle
# 208 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 209 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_ZUBAT
# 210 "data/maps/FlottTown_FlottCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 211 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_WildZubatBattle_Text_0, MSGBOX_DEFAULT
# 212 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
	return


FlottTown_FlottCave_StarterWantsToJoin:
# 217 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_STARTER_MON
# 218 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 0, FlottTown_FlottCave_StarterWantsToJoin_3
# 229 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_StarterWantsToJoin_4
# 240 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_StarterWantsToJoin_5
FlottTown_FlottCave_StarterWantsToJoin_1:
	return

FlottTown_FlottCave_StarterWantsToJoin_3:
# 219 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_MANKEY, Common_Movement_FacePlayer
# 220 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_0, MSGBOX_DEFAULT
# 221 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
# 222 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_6
# 226 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_2, MSGBOX_DEFAULT
# 227 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_4:
# 230 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TINKATINK, Common_Movement_FacePlayer
# 231 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_3, MSGBOX_DEFAULT
# 232 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_4, MSGBOX_YESNO
# 233 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_9
# 237 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_5, MSGBOX_DEFAULT
# 238 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_5:
# 241 "data/maps/FlottTown_FlottCave/scripts.pory"
	applymovement LOCALID_TEDDIURSA, Common_Movement_FacePlayer
# 242 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_6, MSGBOX_DEFAULT
# 243 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
# 244 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_12
# 248 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_7, MSGBOX_DEFAULT
# 249 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_6:
# 223 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_9:
# 234 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_12:
# 245 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1


FlottTown_FlottCave_StarterYesNo:
# 256 "data/maps/FlottTown_FlottCave/scripts.pory"
	switch VAR_STARTER_MON
# 257 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 0, FlottTown_FlottCave_StarterYesNo_2
# 265 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 1, FlottTown_FlottCave_StarterYesNo_3
# 273 "data/maps/FlottTown_FlottCave/scripts.pory"
	case 2, FlottTown_FlottCave_StarterYesNo_4
	return

FlottTown_FlottCave_StarterYesNo_2:
# 258 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 259 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_0, MSGBOX_DEFAULT
# 260 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 261 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 262 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_MANKEY
# 263 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_3:
# 266 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 267 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_1, MSGBOX_DEFAULT
# 268 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 269 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 270 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TINKATINK
# 271 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_4:
# 274 "data/maps/FlottTown_FlottCave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 275 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_StarterYesNo_Text_2, MSGBOX_DEFAULT
# 276 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitfanfare
# 277 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 278 "data/maps/FlottTown_FlottCave/scripts.pory"
	removeobject LOCALID_TEDDIURSA
# 279 "data/maps/FlottTown_FlottCave/scripts.pory"
	call FlottTown_FlottCave_NicknamePartyMon
	return


FlottTown_FlottCave_NicknamePartyMon:
# 285 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_NicknamePartyMon_Text_0, MSGBOX_YESNO
# 286 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_NicknamePartyMon_2
# 290 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
FlottTown_FlottCave_NicknamePartyMon_1:
	return

FlottTown_FlottCave_NicknamePartyMon_2:
# 287 "data/maps/FlottTown_FlottCave/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 288 "data/maps/FlottTown_FlottCave/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto FlottTown_FlottCave_NicknamePartyMon_1


# 294 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_PlayerFacesBarneyFromBottomTrigger:
# 295 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 296 "data/maps/FlottTown_FlottCave/scripts.pory"
	face_left
# 297 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 301 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_BarneyWalksUp:
# 302 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 302 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 302 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 302 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 303 "data/maps/FlottTown_FlottCave/scripts.pory"
	face_down
# 304 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 307 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_ElsieWalksUp:
# 308 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 308 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 308 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 309 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

# 312 "data/maps/FlottTown_FlottCave/scripts.pory"
FlottTown_FlottCave_Movement_PlayerWalksUp:
# 313 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_left
# 314 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 314 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 314 "data/maps/FlottTown_FlottCave/scripts.pory"
	walk_up
# 315 "data/maps/FlottTown_FlottCave/scripts.pory"
	step_end

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0:
# 44 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "As you walk inside the dark cave, you\n"
	.string "hear a noise coming from the darkness!$"

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1:
# 55 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "As the Pokémon is about to attack, you\n"
	.string "feel a presence approach.$"

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_2:
# 69 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "You decide to wait with your new\n"
	.string "partner for your sister to return.$"

FlottTown_FlottCave_EventScript_RockSmash_Text_0:
# 77 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "???: Golurk! Use Rock Smash!$"

FlottTown_FlottCave_EventScript_RockSmash_Text_1:
# 89 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "That sounded like it came from the\n"
	.string "smashable rocks!$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_0:
# 114 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: {PLAYER}! Thank goodness\n"
	.string "you're alright. I don't know what I'd do\l"
	.string "if you got hurt.$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_1:
# 118 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: This is Mr. Heinrich. This was his\n"
	.string "old gym.$"

FlottTown_FlottCave_StarterChoice_Text_0:
# 158 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "What presence do you feel intervenes?$"

FlottTown_FlottCave_StarterChoice_Text_1:
# 165 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_2:
# 179 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_3:
# 193 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa jumped in to save you!$"

FlottTown_FlottCave_WildZubatBattle_Text_0:
# 211 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "The wild Zubat ran away!$"

FlottTown_FlottCave_StarterWantsToJoin_Text_0:
# 220 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey is looking at you curiously. It\n"
	.string "seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_1:
# 221 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Do you accept?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_2:
# 226 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey looks like it's about to hit you\n"
	.string "next.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_3:
# 231 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink is too busy playing with its\n"
	.string "hammer to notice you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_4:
# 232 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Do you want to convince it to join you?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_5:
# 237 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Are you sure? It looks really cute.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_6:
# 242 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa is looking at you curiously.\n"
	.string "It seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_7:
# 248 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa looks at you with Baby-Doll\n"
	.string "eyes.$"

FlottTown_FlottCave_StarterYesNo_Text_0:
# 259 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Mankey joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_1:
# 267 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Tinkatink joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_2:
# 275 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Teddiursa joined you!$"

FlottTown_FlottCave_NicknamePartyMon_Text_0:
# 285 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "Give a nickname?$"

FlottTown_FlottCave_Text_ElsieWorried:
# 318 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: Oh my god! {PLAYER}! Are you\n"
	.string "okay?! Sit tight in there, okay? I'll go\l"
	.string "get help!\p"
	.string "You here the footsteps of your sister\n"
	.string "exiting the gym.$"

FlottTown_FlottCave_Text_Rescue:
# 322 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "???: Ah! There you are! Come, let's get\n"
	.string "you out here.\p"
	.string "ELSIE: {PLAYER}! Oh gods, I'm so glad\n"
	.string "you're okay!$"

FlottTown_FlottCave_Text_LetsGoHome:
# 327 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "BARNEY: Indeed it were. Now, how about\n"
	.string "we get you kids out of this dreadful\l"
	.string "place? You both look tired. Seeing as\l"
	.string "it's my gym, anything that happens here\l"
	.string "is on my head. My home is nearby; let's\l"
	.string "take a rest there.$"
