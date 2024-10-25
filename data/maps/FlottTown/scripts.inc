FlottTown_MapScripts::
# 4 "data/maps/FlottTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_OnTransition
	.byte 0


FlottTown_OnTransition::
# 22 "data/maps/FlottTown/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_OnTransition_1
	return

FlottTown_OnTransition_1:
# 23 "data/maps/FlottTown/scripts.pory"
	setflag FLAG_BARNEY_IN_HOUSE
# 24 "data/maps/FlottTown/scripts.pory"
	setflag FLAG_ELSIE_IN_BARNEYS_HOUSE
	return


FlottTown_EventScript_ElsieBringsUsHome1::
# 29 "data/maps/FlottTown/scripts.pory"
	lock
# 30 "data/maps/FlottTown/scripts.pory"
	goto_if_unset FLAG_ELSIE_GOES_INSIDE, FlottTown_EventScript_ElsieBringsUsHome1_2
FlottTown_EventScript_ElsieBringsUsHome1_1:
# 39 "data/maps/FlottTown/scripts.pory"
	release
	end

FlottTown_EventScript_ElsieBringsUsHome1_2:
# 31 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 32 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 33 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 34 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie1
# 35 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 36 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	goto FlottTown_EventScript_ElsieBringsUsHome1_1


FlottTown_EventScript_ElsieBringsUsHome2::
# 44 "data/maps/FlottTown/scripts.pory"
	goto_if_unset FLAG_ELSIE_GOES_INSIDE, FlottTown_EventScript_ElsieBringsUsHome2_2
FlottTown_EventScript_ElsieBringsUsHome2_1:
# 53 "data/maps/FlottTown/scripts.pory"
	releaseall
	end

FlottTown_EventScript_ElsieBringsUsHome2_2:
# 45 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 46 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 47 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 48 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie2
# 49 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 50 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	goto FlottTown_EventScript_ElsieBringsUsHome2_1


FlottTown_EventScript_ElsieBringsUsHome3::
# 58 "data/maps/FlottTown/scripts.pory"
	goto_if_unset FLAG_ELSIE_GOES_INSIDE, FlottTown_EventScript_ElsieBringsUsHome3_2
FlottTown_EventScript_ElsieBringsUsHome3_1:
# 67 "data/maps/FlottTown/scripts.pory"
	releaseall
	end

FlottTown_EventScript_ElsieBringsUsHome3_2:
# 59 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 60 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 61 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 62 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie3
# 63 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 64 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	goto FlottTown_EventScript_ElsieBringsUsHome3_1


FlottTown_EventScript_ElsieBringsUsHome4::
# 72 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 73 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 74 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 75 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 76 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_TookYourTime, MSGBOX_DEFAULT
# 77 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 78 "data/maps/FlottTown/scripts.pory"
	closemessage
# 79 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceUp
# 80 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 81 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 82 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 83 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ThisIsIt, MSGBOX_DEFAULT
# 84 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 85 "data/maps/FlottTown/scripts.pory"
	closemessage
# 86 "data/maps/FlottTown/scripts.pory"
	delay 180
# 87 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 88 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 89 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LetsTakeALook, MSGBOX_DEFAULT
# 90 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 91 "data/maps/FlottTown/scripts.pory"
	closemessage
# 92 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksUp
# 93 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 94 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksToHouse
# 95 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToHouse
# 96 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 97 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 98 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceUp
# 99 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 100 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OurNewHome, MSGBOX_DEFAULT
# 101 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 102 "data/maps/FlottTown/scripts.pory"
	closemessage
# 103 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 104 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 105 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 106 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 107 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_DoYouLikeIt, MSGBOX_YESNO
# 108 "data/maps/FlottTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_EventScript_ElsieBringsUsHome4_2
# 113 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImSorryChamp, MSGBOX_DEFAULT
# 114 "data/maps/FlottTown/scripts.pory"
	waitmessage
FlottTown_EventScript_ElsieBringsUsHome4_1:
# 116 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_IllPrepareInside, MSGBOX_DEFAULT
# 117 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 118 "data/maps/FlottTown/scripts.pory"
	closemessage
# 119 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside1
# 120 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 121 "data/maps/FlottTown/scripts.pory"
	delay 16
# 122 "data/maps/FlottTown/scripts.pory"
	opendoor 10, 6
# 123 "data/maps/FlottTown/scripts.pory"
	waitdooranim
# 124 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside2
# 125 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 126 "data/maps/FlottTown/scripts.pory"
	closedoor 10, 6
# 127 "data/maps/FlottTown/scripts.pory"
	waitdooranim
# 128 "data/maps/FlottTown/scripts.pory"
	setflag FLAG_ELSIE_GOES_INSIDE
# 129 "data/maps/FlottTown/scripts.pory"
	special DrawWholeMapView
	end

FlottTown_EventScript_ElsieBringsUsHome4_2:
# 109 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImGladYouLikeIt, MSGBOX_DEFAULT
# 110 "data/maps/FlottTown/scripts.pory"
	waitmessage
	goto FlottTown_EventScript_ElsieBringsUsHome4_1


FlottTown_PlayerHouseSign::
# 134 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_PlayerHouseSign, MSGBOX_SIGN
	return


FlottTown_BarneyHouseSign::
# 138 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_BarneyHouseSign, MSGBOX_SIGN
	return


FlottTown_OldGymSign::
# 142 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OldGymSign, MSGBOX_SIGN
	return


# 145 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie1:
# 146 "data/maps/FlottTown/scripts.pory"
	walk_up
# 146 "data/maps/FlottTown/scripts.pory"
	walk_up
# 147 "data/maps/FlottTown/scripts.pory"
	walk_right
# 148 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 151 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie2:
# 152 "data/maps/FlottTown/scripts.pory"
	walk_up
# 152 "data/maps/FlottTown/scripts.pory"
	walk_up
# 152 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 155 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie3:
# 156 "data/maps/FlottTown/scripts.pory"
	walk_up
# 156 "data/maps/FlottTown/scripts.pory"
	walk_up
# 157 "data/maps/FlottTown/scripts.pory"
	walk_left
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 161 "data/maps/FlottTown/scripts.pory"
ElsieWalksUp:
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 163 "data/maps/FlottTown/scripts.pory"
	walk_right
	step_end

# 166 "data/maps/FlottTown/scripts.pory"
ElsieWalksToHouse:
# 167 "data/maps/FlottTown/scripts.pory"
	walk_right
# 168 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_up
# 170 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
# 171 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 174 "data/maps/FlottTown/scripts.pory"
PlayerWalksToHouse:
# 175 "data/maps/FlottTown/scripts.pory"
	walk_up
# 176 "data/maps/FlottTown/scripts.pory"
	walk_right
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 177 "data/maps/FlottTown/scripts.pory"
	walk_up
# 178 "data/maps/FlottTown/scripts.pory"
	walk_up
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
# 179 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 182 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside1:
# 183 "data/maps/FlottTown/scripts.pory"
	walk_up
# 183 "data/maps/FlottTown/scripts.pory"
	walk_up
# 183 "data/maps/FlottTown/scripts.pory"
	walk_up
# 184 "data/maps/FlottTown/scripts.pory"
	walk_right
# 185 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 188 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside2:
# 189 "data/maps/FlottTown/scripts.pory"
	walk_up
# 190 "data/maps/FlottTown/scripts.pory"
	set_invisible
# 191 "data/maps/FlottTown/scripts.pory"
	step_end

FlottTown_Text_TookYourTime::
# 194 "data/maps/FlottTown/scripts.pory"
	.string "Hey! You really took your time, huh?$"

FlottTown_Text_ThisIsIt::
# 198 "data/maps/FlottTown/scripts.pory"
	.string "This is it! Our new home.$"

FlottTown_Text_LetsTakeALook::
# 202 "data/maps/FlottTown/scripts.pory"
	.string "Well, that's enough sight-seeing. Let's\n"
	.string "go check our our new house!$"

FlottTown_Text_OurNewHome::
# 206 "data/maps/FlottTown/scripts.pory"
	.string "Say hello to the new place! This is\n"
	.string "where we'll be living from now on.$"

FlottTown_Text_DoYouLikeIt::
# 210 "data/maps/FlottTown/scripts.pory"
	.string "So Champ, do you like the new place?$"

FlottTown_Text_ImGladYouLikeIt::
# 214 "data/maps/FlottTown/scripts.pory"
	.string "Good to hear! Of course, anyone's gonna\n"
	.string "be glad we got out of that old hole. We\l"
	.string "don't have to suffer under his roof\l"
	.string "anymore. Plus, we got a killer view.$"

FlottTown_Text_ImSorryChamp::
# 218 "data/maps/FlottTown/scripts.pory"
	.string "...\p"
	.string "I'm sorry, Champ. I know you miss all\n"
	.string "your friends back...well I don't even\l"
	.string "wanna call it home anymore. But, hey, at\l"
	.string "least we aren't suffering under his\l"
	.string "roof anymore, right? I promise, you'll\l"
	.string "see all of them again soon.$"

FlottTown_Text_IllPrepareInside::
# 222 "data/maps/FlottTown/scripts.pory"
	.string "I'll get some stuff ready inside. Why\n"
	.string "not take a look around town?$"

FlottTown_Text_PlayerHouseSign::
# 226 "data/maps/FlottTown/scripts.pory"
	.string "ASTER RESIDENCE$"

FlottTown_Text_BarneyHouseSign::
# 230 "data/maps/FlottTown/scripts.pory"
	.string "HEINRICH RESIDNECE$"

FlottTown_Text_OldGymSign::
# 234 "data/maps/FlottTown/scripts.pory"
	.string "The text is faded, but you can just\n"
	.string "barely make out the text written on it.\p"
	.string "FLOTT TOWN GYM\p"
	.string "LEADER: BARNEY HEINRICH\p"
	.string "The pursuant excavator!$"
