FlottTown_FlottCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	destroyfollower
	setflag FLAG_BARNEY_IN_CAVE
	setflag FLAG_ELSIE_IN_CAVE
	setflag FLAG_HIDE_MON0
	setflag FLAG_HIDE_MON1
	setflag FLAG_HIDE_MON2
	setflag FLAG_HIDE_MON3
	setflag FLAG_HIDE_MON4
	call StarterSelection_GFXSetting
	call FlottTown_FlottCave_CaveLightLevel
	return

FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FLOTT_TOWN_STATE, 6, FlottTown_FlottCave_OnFrame
	.2byte 0


FlottTown_FlottCave_OnFrame::
	speakername FlottTown_FlottCave_OnFrame_Text_0
	msgbox FlottTown_FlottCave_Text_ElsieWorried, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_FALLEN_INTO_CAVE
	setvar VAR_FLOTT_TOWN_STATE, 7
	end


FlottTown_FlottCave_CaveLightLevel::
	setflashlevel 6
	end


FlottTown_FlottCave_EventScript_ZubatAttacks::
	lockall
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	waitmoncry
	call FlottTown_FlottCave_ZubatSpawn
	applymovement 10, Common_Movement_FacePlayer
	fadescreen FADE_TO_BLACK
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_1
	call FlottTown_FlottCave_StarterChoice
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


FlottTown_FlottCave_ZubatSpawn::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	getobjectfacingdirection OBJ_EVENT_ID_PLAYER, VAR_TEMP_4
	copyvar VAR_TEMP_2, VAR_TEMP_0
	copyvar VAR_TEMP_3, VAR_TEMP_1
	copyvar VAR_TEMP_5, VAR_TEMP_0
	copyvar VAR_TEMP_6, VAR_TEMP_1
	switch VAR_TEMP_4
	case 2, FlottTown_FlottCave_ZubatSpawn_3
	case 1, FlottTown_FlottCave_ZubatSpawn_4
	case 3, FlottTown_FlottCave_ZubatSpawn_5
	case 4, FlottTown_FlottCave_ZubatSpawn_6
FlottTown_FlottCave_ZubatSpawn_1:
	addobject 10
	setobjectxy 10, VAR_TEMP_2, VAR_TEMP_3
	return

FlottTown_FlottCave_ZubatSpawn_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	addvar VAR_TEMP_3, 2
	addvar VAR_TEMP_6, 1
	goto FlottTown_FlottCave_ZubatSpawn_1

FlottTown_FlottCave_ZubatSpawn_4:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	subvar VAR_TEMP_3, 2
	subvar VAR_TEMP_6, 1
	goto FlottTown_FlottCave_ZubatSpawn_1

FlottTown_FlottCave_ZubatSpawn_5:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	addvar VAR_TEMP_2, 2
	addvar VAR_TEMP_5, 1
	goto FlottTown_FlottCave_ZubatSpawn_1

FlottTown_FlottCave_ZubatSpawn_6:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	subvar VAR_TEMP_2, 2
	subvar VAR_TEMP_5, 1
	goto FlottTown_FlottCave_ZubatSpawn_1


FlottTown_FlottCave_EventScript_RockSmash::
	fadescreen FADE_FROM_BLACK
	speakername FlottTown_FlottCave_EventScript_RockSmash_Text_0
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_1, MSGBOX_DEFAULT
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
	msgbox FlottTown_FlottCave_EventScript_RockSmash_Text_2, MSGBOX_DEFAULT
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
	speakername FlottTown_FlottCave_EventScript_ElsieRescue_Text_0
	msgbox FlottTown_FlottCave_Text_Rescue, MSGBOX_DEFAULT
	closemessage
	applymovement 8, FlottTown_FlottCave_Movement_BarneyWalksUp
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_FlottCave_Movement_PlayerWalksUp
	applymovement 7, FlottTown_FlottCave_Movement_ElsieWalksUp
	waitmovement 8
	waitmovement 7
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 7, Common_Movement_FaceRight
	speakername FlottTown_FlottCave_OnFrame_Text_0
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceRight
	speakername FlottTown_FlottCave_OnFrame_Text_0
	msgbox FlottTown_FlottCave_EventScript_ElsieRescue_Text_2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 7, Common_Movement_FaceRight
	applymovement 8, Common_Movement_WalkInPlaceDown
	speakername FlottTown_FlottCave_EventScript_ElsieRescue_Text_0
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


FlottTown_FlottCave_StarterChoice::
	lockall
	msgbox FlottTown_FlottCave_StarterChoice_Text_0, MSGBOX_DEFAULT
	checkplayerpersonality
	switch VAR_RESULT
	case 0, FlottTown_FlottCave_StarterChoice_3
	case 1, FlottTown_FlottCave_StarterChoice_4
	case 2, FlottTown_FlottCave_StarterChoice_5
FlottTown_FlottCave_StarterChoice_1:
	fadescreen FADE_FROM_BLACK
	msgbox FlottTown_FlottCave_StarterChoice_Text_1, MSGBOX_DEFAULT
	playmoncry VAR_TEMP_7, CRY_MODE_NORMAL
	waitmoncry
	givemon VAR_TEMP_7, 10, ITEM_NONE
	return

FlottTown_FlottCave_StarterChoice_3:
	call StarterSelection_FuryPersonality
	goto FlottTown_FlottCave_StarterChoice_1

FlottTown_FlottCave_StarterChoice_4:
	call StarterSelection_MischiefPersonality
	goto FlottTown_FlottCave_StarterChoice_1

FlottTown_FlottCave_StarterChoice_5:
	call StarterSelection_FriendshipPersonality
	goto FlottTown_FlottCave_StarterChoice_1


FlottTown_FlottCave_WildZubatBattle::
	removeitem ITEM_POKE_BALL, 1
	setwildbattle SPECIES_ZUBAT, 10
	dowildbattle
	fadescreen FADE_TO_BLACK
	removeobject 10
	fadescreen FADE_FROM_BLACK
	msgbox FlottTown_FlottCave_WildZubatBattle_Text_0, MSGBOX_DEFAULT
	closemessage
	return


FlottTown_FlottCave_StarterWantsToJoin::
	applymovement VAR_TEMP_8, Common_Movement_FacePlayer
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_1
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_3, MSGBOX_DEFAULT
	call FlottTown_FlottCave_StarterWantsToJoin
	return

FlottTown_FlottCave_StarterWantsToJoin_1:
	playfanfare MUS_OBTAIN_ITEM
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_1, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	removeobject VAR_TEMP_8
	msgbox FlottTown_FlottCave_StarterWantsToJoin_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_FlottCave_StarterWantsToJoin_5
	closemessage
FlottTown_FlottCave_StarterWantsToJoin_4:
	return

FlottTown_FlottCave_StarterWantsToJoin_5:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FlottTown_FlottCave_StarterWantsToJoin_4


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

FlottTown_FlottCave_OnFrame_Text_0:
	.string "Elsie$"

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
	.string "???$"

FlottTown_FlottCave_EventScript_RockSmash_Text_1:
	.string "Golurk! Use Rock Smash!$"

FlottTown_FlottCave_EventScript_RockSmash_Text_2:
	.string "That sounded like it came from the\n"
	.string "smashable rocks!$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_0:
	.string "Barney$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_1:
	.string "{PLAYER}! Thank goodness you're\n"
	.string "alright. I don't know what I'd do if you\l"
	.string "got hurt.$"

FlottTown_FlottCave_EventScript_ElsieRescue_Text_2:
	.string "This is Mr. Heinrich. This was his old\n"
	.string "gym.$"

FlottTown_FlottCave_StarterChoice_Text_0:
	.string "But…before it could hurt you, something\n"
	.string "intervenes.\l"
	.string "What is it?$"

FlottTown_FlottCave_StarterChoice_Text_1:
	.string "{STR_VAR_1} jumped in to save you!$"

FlottTown_FlottCave_WildZubatBattle_Text_0:
	.string "The wild Zubat ran away!$"

FlottTown_FlottCave_StarterWantsToJoin_Text_0:
	.string "It looks like the {STR_VAR_1} wants\nto join you. Let it?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_1:
	.string "{STR_VAR_1} joined you!$"

FlottTown_FlottCave_StarterWantsToJoin_Text_2:
	.string "Give a nickname?$"

FlottTown_FlottCave_StarterWantsToJoin_Text_3:
	.string "The Pokémon looks sad.$"

FlottTown_FlottCave_Text_ElsieWorried::
	.string "Oh my god! {PLAYER}! Are you okay?!\n"
	.string "Sit tight in there, okay? I'll go get\l"
	.string "help!\p"
	.string "You here the footsteps of your sister\n"
	.string "exiting the gym.$"

FlottTown_FlottCave_Text_Rescue::
	.string "Ah! There you are! Come, let's get you\n"
	.string "out here.\p"
	.string "{PLAYER}! Oh gods, I'm so glad you're\n"
	.string "okay!$"

FlottTown_FlottCave_Text_LetsGoHome::
	.string "Indeed it were. Now, how about we get\n"
	.string "you kids out of this dreadful place?\l"
	.string "You both look tired. Seeing as it's my\l"
	.string "gym, anything that happens here is on\l"
	.string "my head. My home is nearby; let's take a\l"
	.string "rest there.$"
