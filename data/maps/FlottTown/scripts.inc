FlottTown_MapScripts::
# 2 "data/maps/FlottTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_OnTransition
	.byte 0


FlottTown_OnTransition::
# 18 "data/maps/FlottTown/scripts.pory"
	setflag FLAG_BARNEY_IN_HOUSE
	return


FlottTown_EventScript_ElsieBringsUsHome1::
# 22 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 23 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 24 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 25 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie1
# 26 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 27 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome2::
# 31 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 32 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 33 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 34 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie2
# 35 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 36 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome3::
# 40 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 41 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 42 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 43 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie3
# 44 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 45 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome4::
# 49 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 50 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 51 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 52 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 53 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_TookYourTime, MSGBOX_DEFAULT
# 54 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 55 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 56 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 57 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 58 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 59 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LetsTakeALook, MSGBOX_DEFAULT
# 60 "data/maps/FlottTown/scripts.pory"
	closemessage
# 61 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksUp
# 62 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 63 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksToHouse
# 64 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToHouse
# 65 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 66 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 67 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceUp
# 68 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 69 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OurNewHome, MSGBOX_DEFAULT
# 70 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 71 "data/maps/FlottTown/scripts.pory"
	closemessage
# 72 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 73 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 74 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 75 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 76 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_DoYouLikeIt, MSGBOX_YESNO
# 77 "data/maps/FlottTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_EventScript_ElsieBringsUsHome4_2
# 82 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImSorryChamp, MSGBOX_DEFAULT
# 83 "data/maps/FlottTown/scripts.pory"
	waitmessage
FlottTown_EventScript_ElsieBringsUsHome4_1:
# 85 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_IllPrepareInside, MSGBOX_DEFAULT
# 86 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 87 "data/maps/FlottTown/scripts.pory"
	closemessage
# 88 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside1
# 89 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 90 "data/maps/FlottTown/scripts.pory"
	delay 16
# 91 "data/maps/FlottTown/scripts.pory"
	opendoor 10, 6
# 92 "data/maps/FlottTown/scripts.pory"
	waitdooranim
# 93 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside2
# 94 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 95 "data/maps/FlottTown/scripts.pory"
	closedoor 10, 6
# 96 "data/maps/FlottTown/scripts.pory"
	waitdooranim
# 97 "data/maps/FlottTown/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 3
	end

FlottTown_EventScript_ElsieBringsUsHome4_2:
# 78 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImGladYouLikeIt, MSGBOX_DEFAULT
# 79 "data/maps/FlottTown/scripts.pory"
	waitmessage
	goto FlottTown_EventScript_ElsieBringsUsHome4_1


FlottTown_PlayerHouseSign::
# 102 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_PlayerHouseSign, MSGBOX_SIGN
	return


FlottTown_BarneyHouseSign::
# 106 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_BarneyHouseSign, MSGBOX_SIGN
	return


FlottTown_OldGymSign::
# 110 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OldGymSign, MSGBOX_SIGN
	return


# 113 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie1:
# 114 "data/maps/FlottTown/scripts.pory"
	walk_up
# 114 "data/maps/FlottTown/scripts.pory"
	walk_up
# 115 "data/maps/FlottTown/scripts.pory"
	walk_right
# 116 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 119 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie2:
# 120 "data/maps/FlottTown/scripts.pory"
	walk_up
# 120 "data/maps/FlottTown/scripts.pory"
	walk_up
# 120 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 123 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie3:
# 124 "data/maps/FlottTown/scripts.pory"
	walk_up
# 124 "data/maps/FlottTown/scripts.pory"
	walk_up
# 125 "data/maps/FlottTown/scripts.pory"
	walk_left
# 126 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 129 "data/maps/FlottTown/scripts.pory"
ElsieWalksUp:
# 130 "data/maps/FlottTown/scripts.pory"
	walk_up
# 131 "data/maps/FlottTown/scripts.pory"
	walk_right
	step_end

# 134 "data/maps/FlottTown/scripts.pory"
ElsieWalksToHouse:
# 135 "data/maps/FlottTown/scripts.pory"
	walk_right
# 136 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 137 "data/maps/FlottTown/scripts.pory"
	walk_up
# 138 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
# 139 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 142 "data/maps/FlottTown/scripts.pory"
PlayerWalksToHouse:
# 143 "data/maps/FlottTown/scripts.pory"
	walk_up
# 144 "data/maps/FlottTown/scripts.pory"
	walk_right
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_up
# 146 "data/maps/FlottTown/scripts.pory"
	walk_up
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
# 147 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 150 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside1:
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 152 "data/maps/FlottTown/scripts.pory"
	walk_right
# 153 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 156 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside2:
# 157 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	set_invisible
# 159 "data/maps/FlottTown/scripts.pory"
	step_end

FlottTown_Text_TookYourTime::
# 162 "data/maps/FlottTown/scripts.pory"
	.string "Hey! You really took your time, huh?$"

FlottTown_Text_LetsTakeALook::
# 166 "data/maps/FlottTown/scripts.pory"
	.string "Well, that's enough sight-seeing. Let's\n"
	.string "go check our our new house!$"

FlottTown_Text_OurNewHome::
# 170 "data/maps/FlottTown/scripts.pory"
	.string "This is it! This is where we'll be living\n"
	.string "from now on.$"

FlottTown_Text_DoYouLikeIt::
# 174 "data/maps/FlottTown/scripts.pory"
	.string "So Champ, do you like the new place?$"

FlottTown_Text_ImGladYouLikeIt::
# 178 "data/maps/FlottTown/scripts.pory"
	.string "Good to hear! Of course, anyone's gonna\n"
	.string "be glad we got out of that old hole. We\l"
	.string "don't have to suffer under his roof\l"
	.string "anymore. Plus, we got a killer view.$"

FlottTown_Text_ImSorryChamp::
# 182 "data/maps/FlottTown/scripts.pory"
	.string "...\p"
	.string "I'm sorry, Champ. I know you miss all\n"
	.string "your friends back...well I don't even\l"
	.string "wanna call it home anymore. But, hey, at\l"
	.string "least we aren't suffering under his\l"
	.string "roof anymore, right? I promise, you'll\l"
	.string "see all of them again soon.$"

FlottTown_Text_IllPrepareInside::
# 186 "data/maps/FlottTown/scripts.pory"
	.string "I'll get some stuff ready inside. Why\n"
	.string "not take a look around town?$"

FlottTown_Text_PlayerHouseSign::
# 190 "data/maps/FlottTown/scripts.pory"
	.string "ASTER RESIDENCE$"

FlottTown_Text_BarneyHouseSign::
# 194 "data/maps/FlottTown/scripts.pory"
	.string "HEINRICH RESIDNECE$"

FlottTown_Text_OldGymSign::
# 198 "data/maps/FlottTown/scripts.pory"
	.string "The text is faded, but you can just\n"
	.string "barely make out the text written on it.\p"
	.string "FLOTT TOWN GYM\p"
	.string "LEADER: BARNEY HEINRICH\p"
	.string "The pursuant excavator!$"
