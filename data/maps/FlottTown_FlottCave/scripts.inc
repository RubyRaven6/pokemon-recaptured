
.set LOCALID_ZUBAT, 1
.set LOCALID_MANKEY, 2
.set LOCALID_TINKATINK, 3
.set LOCALID_TEDDIURSA, 4
.set LOCALID_ELSIE, 7
.set LOCALID_BARNEY, 8

FlottTown_FlottCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_FlottCave_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FLOTT_TOWN_STATE, 6, FlottTown_FlottCave_OnFrame
	.2byte 0


FlottTown_FlottCave_OnTransition:
	destroyfollower
	setflag FLAG_BARNEY_IN_CAVE
	setflag FLAG_ELSIE_IN_CAVE
	call FlottTown_FlottCave_CaveLightLevel
	return


FlottTown_FlottCave_OnFrame:
	msgbox FlottTown_FlottCave_Text_ElsieWorried, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_FALLEN_INTO_CAVE
	setvar VAR_FLOTT_TOWN_STATE, 7
	end


FlottTown_FlottCave_CaveLightLevel:
	setflashlevel 6
	end


FlottTown_FlottCave_EventScript_ZubatAttacks::
	lockall
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	waitmoncry
	special CheckZubatSpawning
	addobject LOCALID_ZUBAT
	setobjectxy LOCALID_ZUBAT, VAR_TEMP_0, VAR_TEMP_1
	applymovement LOCALID_ZUBAT, Common_Movement_FacePlayer
	call FlottTown_FlottCave_FacePlayerDirection
	fadescreen FADE_TO_BLACK
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1
	call FlottTown_FlottCave_StarterChoice
	fadescreen FADE_FROM_BLACK
	call FlottTown_FlottCave_WildZubatBattle
	delay 60
	call FlottTown_FlottCave_StarterWantsToJoin
	clearflag FLAG_FALLEN_INTO_CAVE
	setvar VAR_FLOTT_TOWN_STATE, 8
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 12
	special TeleportCamera
	setobjectxy OBJ_EVENT_ID_PLAYER, 13, 12
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_2
	waitmessage
	call FlottTown_FlottCave_EventScript_RockSmash
	end


FlottTown_FlottCave_EventScript_RockSmash::
	fadescreen FADE_FROM_BLACK
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_0, MSGBOX_DEFAULT
	playmoncry SPECIES_GOLURK, CRY_MODE_NORMAL
	waitmoncry
	playse SE_M_ROCK_THROW
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	clearflag FLAG_ELSIE_IN_CAVE
	clearflag FLAG_BARNEY_IN_CAVE
	setflag FLAG_TEMP_11
	removeobject 6
	callnative RemoveFollowingPokemon
	waitse
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_1, MSGBOX_DEFAULT
	closemessage
	end


FlottTown_FlottCave_RightTrigger::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_BottomTrigger::
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_PlayerFacesBarneyFromBottomTrigger
	call FlottTown_FlottCave_EventScript_ElsieRescue
	return


FlottTown_FlottCave_EventScript_ElsieRescue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	msgbox FlottTown_FlottCave_Text_Rescue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BARNEY, FlottTown_FlottCave_Movement_BarneyWalksUp
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_Movement_PlayerWalksUp
	applymovement LOCALID_ELSIE, FlottTown_FlottCave_Movement_ElsieWalksUp
	waitmovement LOCALID_BARNEY
	waitmovement LOCALID_ELSIE
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_ELSIE, Common_Movement_WalkInPlaceRight
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_ELSIE, Common_Movement_FaceRight
	applymovement LOCALID_BARNEY, Common_Movement_WalkInPlaceDown
	msgbox FlottTown_FlottCave_Text_LetsGoHome, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setflag FLAG_ELSIE_IN_CAVE
	setflag FLAG_BARNEY_IN_CAVE
	clearflag FLAG_BARNEY_IN_HOUSE
	clearflag FLAG_ELSIE_IN_BARNEYS_HOUSE
	setvar VAR_FLOTT_TOWN_STATE, 9
	warpsilent MAP_FLOTT_TOWN_BARNEYS_HOUSE, 7, 4
	end


FlottTown_FlottCave_FacePlayerDirection:
	switch VAR_ZUBAT_DIR
	case 1, FlottTown_FlottCave_FacePlayerDirection_2
	case 2, FlottTown_FlottCave_FacePlayerDirection_3
	case 3, FlottTown_FlottCave_FacePlayerDirection_4
	case 4, FlottTown_FlottCave_FacePlayerDirection_5
	return

FlottTown_FlottCave_FacePlayerDirection_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	return

FlottTown_FlottCave_FacePlayerDirection_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	return

FlottTown_FlottCave_FacePlayerDirection_4:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	return

FlottTown_FlottCave_FacePlayerDirection_5:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	return


FlottTown_FlottCave_StarterChoice:
	lockall
	msgbox FlottTown_FlottCave_StarterChoice_Text_0
	switch VAR_STARTER_MON
	case 0, FlottTown_FlottCave_StarterChoice_2
	case 1, FlottTown_FlottCave_StarterChoice_3
	case 2, FlottTown_FlottCave_StarterChoice_4
	return

FlottTown_FlottCave_StarterChoice_2:
	addobject LOCALID_MANKEY
	applymovement LOCALID_MANKEY, Common_Movement_FaceAwayPlayer
	setobjectxy LOCALID_MANKEY, VAR_TEMP_2, VAR_TEMP_3
	fadescreen FADE_FROM_BLACK
	msgbox FlottTown_FlottCave_StarterChoice_Text_1, MSGBOX_DEFAULT
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
	waitmoncry
	givemon SPECIES_MANKEY, 10, ITEM_NONE
	removeobject LOCALID_TINKATINK
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_3:
	addobject LOCALID_TINKATINK
	applymovement LOCALID_TINKATINK, Common_Movement_FaceAwayPlayer
	setobjectxy LOCALID_TINKATINK, VAR_TEMP_2, VAR_TEMP_3
	fadescreen FADE_FROM_BLACK
	msgbox FlottTown_FlottCave_StarterChoice_Text_2, MSGBOX_DEFAULT
	playmoncry SPECIES_TINKATINK, CRY_MODE_NORMAL
	waitmoncry
	givemon SPECIES_TINKATINK, 10, ITEM_NONE
	removeobject LOCALID_MANKEY
	removeobject LOCALID_TEDDIURSA
	return

FlottTown_FlottCave_StarterChoice_4:
	addobject LOCALID_TEDDIURSA
	applymovement LOCALID_TEDDIURSA, Common_Movement_FaceAwayPlayer
	setobjectxy LOCALID_TEDDIURSA, VAR_TEMP_2, VAR_TEMP_3
	fadescreen FADE_FROM_BLACK
	msgbox FlottTown_FlottCave_StarterChoice_Text_3, MSGBOX_DEFAULT
	playmoncry SPECIES_TEDDIURSA, CRY_MODE_NORMAL
	waitmoncry
	givemon SPECIES_TEDDIURSA, 10, ITEM_NONE
	removeobject LOCALID_MANKEY
	removeobject LOCALID_TINKATINK
	return


FlottTown_FlottCave_WildZubatBattle:
	removeitem ITEM_POKE_BALL, 1
	setwildbattle SPECIES_ZUBAT, 10
	dowildbattle
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZUBAT
	fadescreen FADE_FROM_BLACK
	msgbox FlottTown_FlottCave_WildZubatBattle_Text_0, MSGBOX_DEFAULT
	closemessage
	return


FlottTown_FlottCave_StarterWantsToJoin:
	switch VAR_STARTER_MON
	case 0, FlottTown_FlottCave_StarterWantsToJoin_3
	case 1, FlottTown_FlottCave_StarterWantsToJoin_4
	case 2, FlottTown_FlottCave_StarterWantsToJoin_5
FlottTown_FlottCave_StarterWantsToJoin_1:
	return

FlottTown_FlottCave_StarterWantsToJoin_3:
	applymovement LOCALID_MANKEY, Common_Movement_FacePlayer
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_0, MSGBOX_DEFAULT
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_6
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_2, MSGBOX_DEFAULT
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_4:
	applymovement LOCALID_TINKATINK, Common_Movement_FacePlayer
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_3, MSGBOX_DEFAULT
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_9
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_5, MSGBOX_DEFAULT
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_5:
	applymovement LOCALID_TEDDIURSA, Common_Movement_FacePlayer
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_6, MSGBOX_DEFAULT
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_12
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_7, MSGBOX_DEFAULT
	call FlottTown_FlottCave_StarterWantsToJoin
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_6:
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_9:
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1

FlottTown_FlottCave_StarterWantsToJoin_12:
	call FlottTown_FlottCave_StarterYesNo
	goto FlottTown_FlottCave_StarterWantsToJoin_1


FlottTown_FlottCave_StarterYesNo:
	switch VAR_STARTER_MON
	case 0, FlottTown_FlottCave_StarterYesNo_2
	case 1, FlottTown_FlottCave_StarterYesNo_3
	case 2, FlottTown_FlottCave_StarterYesNo_4
	return

FlottTown_FlottCave_StarterYesNo_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox FlottTown_FlottCave_StarterYesNo_Text_0, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	removeobject LOCALID_MANKEY
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_3:
	playfanfare MUS_OBTAIN_ITEM
	msgbox FlottTown_FlottCave_StarterYesNo_Text_1, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	removeobject LOCALID_TINKATINK
	call FlottTown_FlottCave_NicknamePartyMon
	return

FlottTown_FlottCave_StarterYesNo_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox FlottTown_FlottCave_StarterYesNo_Text_2, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	removeobject LOCALID_TEDDIURSA
	call FlottTown_FlottCave_NicknamePartyMon
	return


FlottTown_FlottCave_NicknamePartyMon:
	msgbox FlottTown_FlottCave_NicknamePartyMon_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_NicknamePartyMon_2
	closemessage
FlottTown_FlottCave_NicknamePartyMon_1:
	return

FlottTown_FlottCave_NicknamePartyMon_2:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FlottTown_FlottCave_NicknamePartyMon_1


FlottTown_FlottCave_PlayerFacesBarneyFromBottomTrigger:
	walk_up
	face_left
	step_end

FlottTown_FlottCave_Movement_BarneyWalksUp:
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

FlottTown_FlottCave_Movement_ElsieWalksUp:
	walk_up
	walk_up
	walk_up
	step_end

FlottTown_FlottCave_Movement_PlayerWalksUp:
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0:
	.string "As you walk inside the dark cave, you\n"
	.string "hear a noise coming from the darkness!$"

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1:
	.string "As the Pokémon is about to attack, you\n"
	.string "feel a presence approach.$"

FlottTown_FlottCave_EventScript_ZubatAttacks_Text_2:
	.string "You decide to wait with your new\n"
	.string "partner for your sister to return.$"

FlottTown_FlottCave_EventScript_RockSmash_Text_0:
	.string "???: Golurk! Use Rock Smash!$"

FlottTown_FlottCave_EventScript_RockSmash_Text_1:
	.string "That sounded like it came from the\n"
	.string "smashable rocks!$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_0:
	.string "ELSIE: {PLAYER}! Thank goodness\n"
	.string "you're alright. I don't know what I'd do\l"
	.string "if you got hurt.$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_1:
	.string "ELSIE: This is Mr. Heinrich. This was his\n"
	.string "old gym.$"

FlottTown_FlottCave_StarterChoice_Text_0:
	.string "But…before it could hurt you, something\n"
	.string "intervenes.$"

FlottTown_FlottCave_StarterChoice_Text_1:
	.string "Mankey jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_2:
	.string "Tinkatink jumped in to save you!$"

FlottTown_FlottCave_StarterChoice_Text_3:
	.string "Teddiursa jumped in to save you!$"

FlottTown_FlottCave_WildZubatBattle_Text_0:
	.string "The wild Zubat ran away!$"

FlottTown_FlottCave_StarterWantsToJoin_Text_0:
	.string "Mankey is looking at you curiously. It\n"
	.string "seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_1:
	.string "Do you accept?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_2:
	.string "Mankey looks like it's about to hit you\n"
	.string "next.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_3:
	.string "Tinkatink is too busy playing with its\n"
	.string "hammer to notice you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_4:
	.string "Do you want to convince it to join you?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_5:
	.string "Are you sure? It looks really cute.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_6:
	.string "Teddiursa is looking at you curiously.\n"
	.string "It seems to want to join you.$"

FlottTown_FlottCave_StarterWantsToJoin_Text_7:
	.string "Teddiursa looks at you with Baby-Doll\n"
	.string "eyes.$"

FlottTown_FlottCave_StarterYesNo_Text_0:
	.string "Mankey joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_1:
	.string "Tinkatink joined you!$"

FlottTown_FlottCave_StarterYesNo_Text_2:
	.string "Teddiursa joined you!$"

FlottTown_FlottCave_NicknamePartyMon_Text_0:
	.string "Give a nickname?$"

FlottTown_FlottCave_Text_ElsieWorried:
	.string "ELSIE: Oh my god! {PLAYER}! Are you\n"
	.string "okay?! Sit tight in there, okay? I'll go\l"
	.string "get help!\p"
	.string "You here the footsteps of your sister\n"
	.string "exiting the gym.$"

FlottTown_FlottCave_Text_Rescue:
	.string "???: Ah! There you are! Come, let's get\n"
	.string "you out here.\p"
	.string "ELSIE: {PLAYER}! Oh gods, I'm so glad\n"
	.string "you're okay!$"

FlottTown_FlottCave_Text_LetsGoHome:
	.string "BARNEY: Indeed it were. Now, how about\n"
	.string "we get you kids out of this dreadful\l"
	.string "place? You both look tired. Seeing as\l"
	.string "it's my gym, anything that happens here\l"
	.string "is on my head. My home is nearby; let's\l"
	.string "take a rest there.$"
