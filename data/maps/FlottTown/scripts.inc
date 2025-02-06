FlottTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_OnTransition
	.byte 0


FlottTown_OnTransition::
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_OnTransition_1
	return

FlottTown_OnTransition_1:
	setflag FLAG_BARNEY_IN_HOUSE
	setflag FLAG_ELSIE_IN_BARNEYS_HOUSE
	return


FlottTown_EventScript_ElsieBringsUsHome1::
	lock
	goto_if_unset FLAG_ELSIE_GOES_INSIDE, FlottTown_EventScript_ElsieBringsUsHome1_2
FlottTown_EventScript_ElsieBringsUsHome1_1:
	release
	end

FlottTown_EventScript_ElsieBringsUsHome1_2:
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie1
	waitmovement 0
	goto FlottTown_EventScript_ElsieBringsUsHome4
	goto FlottTown_EventScript_ElsieBringsUsHome1_1


FlottTown_EventScript_ElsieBringsUsHome2::
	goto_if_unset FLAG_ELSIE_GOES_INSIDE, FlottTown_EventScript_ElsieBringsUsHome2_2
FlottTown_EventScript_ElsieBringsUsHome2_1:
	releaseall
	end

FlottTown_EventScript_ElsieBringsUsHome2_2:
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie2
	waitmovement 0
	goto FlottTown_EventScript_ElsieBringsUsHome4
	goto FlottTown_EventScript_ElsieBringsUsHome2_1


FlottTown_EventScript_ElsieBringsUsHome3::
	goto_if_unset FLAG_ELSIE_GOES_INSIDE, FlottTown_EventScript_ElsieBringsUsHome3_2
FlottTown_EventScript_ElsieBringsUsHome3_1:
	releaseall
	end

FlottTown_EventScript_ElsieBringsUsHome3_2:
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie3
	waitmovement 0
	goto FlottTown_EventScript_ElsieBringsUsHome4
	goto FlottTown_EventScript_ElsieBringsUsHome3_1


FlottTown_EventScript_ElsieBringsUsHome4::
	applymovement 1, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 1
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_TookYourTime, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 1, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 1
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_ThisIsIt, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 180
	applymovement 1, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_LetsTakeALook, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 1, ElsieWalksUp
	waitmovement 0
	applymovement 1, ElsieWalksToHouse
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToHouse
	waitmovement 1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 1, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_OurNewHome, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 1, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 1
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_DoYouLikeIt, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_EventScript_ElsieBringsUsHome4_2
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_ImSorryChamp, MSGBOX_DEFAULT
	waitmessage
FlottTown_EventScript_ElsieBringsUsHome4_1:
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_IllPrepareInside, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 1, ElsieGoesInside1
	waitmovement 0
	delay 16
	opendoor 10, 6
	waitdooranim
	applymovement 1, ElsieGoesInside2
	waitmovement 0
	closedoor 10, 6
	waitdooranim
	setflag FLAG_ELSIE_GOES_INSIDE
	special DrawWholeMapView
	end

FlottTown_EventScript_ElsieBringsUsHome4_2:
	speakername FlottTown_EventScript_ElsieBringsUsHome4_Text_0
	msgbox FlottTown_Text_ImGladYouLikeIt, MSGBOX_DEFAULT
	waitmessage
	goto FlottTown_EventScript_ElsieBringsUsHome4_1


FlottTown_LittleGirl::
	msgbox FlottTown_LittleGirl_Text_0, MSGBOX_NPC
	return


FlottTown_TempTeleporter:
	warp MAP_DOCKSIDE_CITY, 36, 15
	return


FlottTown_TechGirl::
	msgbox FlottTown_Text_TechnologyIsAmazing, MSGBOX_NPC
	return


FlottTown_PlayerHouseSign::
	msgbox FlottTown_Text_PlayerHouseSign, MSGBOX_SIGN
	return


FlottTown_BarneyHouseSign::
	msgbox FlottTown_Text_BarneyHouseSign, MSGBOX_SIGN
	return


FlottTown_OldGymSign::
	msgbox FlottTown_Text_OldGymSign, MSGBOX_SIGN
	return


MoveNextToElsie1:
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

MoveNextToElsie2:
	walk_up
	walk_up
	walk_up
	step_end

MoveNextToElsie3:
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

ElsieWalksUp:
	walk_up
	walk_right
	step_end

ElsieWalksToHouse:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PlayerWalksToHouse:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

ElsieGoesInside1:
	walk_up
	walk_up
	walk_up
	walk_right
	face_up
	step_end

ElsieGoesInside2:
	walk_up
	set_invisible
	step_end

FlottTown_EventScript_ElsieBringsUsHome4_Text_0:
	.string "Elsie$"

FlottTown_LittleGirl_Text_0:
	.string "My mommy says I shouldn't go too far to\n"
	.string "the edge.\p"
	.string "But I like seeing all the cool\n"
	.string "Water-type Pokémon!$"

FlottTown_Text_TookYourTime::
	.string "Hey! You really took your time, huh?$"

FlottTown_Text_ThisIsIt::
	.string "This is it! Our new home.$"

FlottTown_Text_LetsTakeALook::
	.string "Well, that's enough sight-seeing. Let's\n"
	.string "go check our our new house!$"

FlottTown_Text_OurNewHome::
	.string "Say hello to the new place! This is\n"
	.string "where we'll be living from now on.$"

FlottTown_Text_DoYouLikeIt::
	.string "So Champ, do you like the new place?$"

FlottTown_Text_ImGladYouLikeIt::
	.string "Good to hear! Of course, anyone's gonna\n"
	.string "be glad we got out of that old hole. We\l"
	.string "don't have to suffer under his roof\l"
	.string "anymore. Plus, we got a killer view.$"

FlottTown_Text_ImSorryChamp::
	.string "...\p"
	.string "I'm sorry, Champ. I know you miss all\n"
	.string "your friends back...well I don't even\l"
	.string "wanna call it home anymore. But, hey, at\l"
	.string "least we aren't suffering under his\l"
	.string "roof anymore, right? I promise, you'll\l"
	.string "see all of them again soon.$"

FlottTown_Text_IllPrepareInside::
	.string "I'll get some stuff ready inside. Why\n"
	.string "not take a look around town?$"

FlottTown_Text_TechnologyIsAmazing::
	.string "So many scientific breakthroughs have\n"
	.string "happened recently, it's staggering!\p"
	.string "First, it's unbelievably easy to create\n"
	.string "your own ROM Hack these days!\l"
	.string "Decompilations have come so far!\p"
	.string "You can change the game however you\n"
	.string "like to a practically atomic level!\p"
	.string "Speaking of change, I heard they've had\n"
	.string "incredible advancements in changing\l"
	.string "Pokémon down to an atomic level, like\l"
	.string "changing what gender they are.\p"
	.string "I wonder if they can do that for humans\n"
	.string "too...$"

FlottTown_Text_PlayerHouseSign::
	.string "ASTER RESIDENCE$"

FlottTown_Text_BarneyHouseSign::
	.string "HEINRICH RESIDNECE$"

FlottTown_Text_OldGymSign::
	.string "The text is faded, but you can just\n"
	.string "barely make out the text written on it.\p"
	.string "FLOTT TOWN GYM\p"
	.string "LEADER: BARNEY HEINRICH\p"
	.string "The pursuant excavator!$"
