FlottTown_MapScripts::
	.byte 0


FlottTown_EventScript_ElsieBringsUsHome1::
# 11 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 12 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 13 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 14 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie1
# 15 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 16 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome2::
# 20 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 21 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 22 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 23 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie2
# 24 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 25 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome3::
# 29 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 30 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 31 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 32 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie3
# 33 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 34 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome4::
# 38 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 39 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 40 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 41 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 42 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_TookYourTime, MSGBOX_DEFAULT
# 43 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 44 "data/maps/FlottTown/scripts.pory"
	applymovement 1, LookAtTown
# 45 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtTown
# 46 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 47 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 48 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LookAtTown, MSGBOX_DEFAULT
# 49 "data/maps/FlottTown/scripts.pory"
	closemessage
# 50 "data/maps/FlottTown/scripts.pory"
	delay 60
# 51 "data/maps/FlottTown/scripts.pory"
	delay 60
# 52 "data/maps/FlottTown/scripts.pory"
	delay 60
# 53 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 54 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 55 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 56 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 57 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LetsTakeALook, MSGBOX_DEFAULT
# 58 "data/maps/FlottTown/scripts.pory"
	closemessage
# 59 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksUp
# 60 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 61 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksToHouse
# 62 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToHouse
# 63 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 64 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 65 "data/maps/FlottTown/scripts.pory"
	applymovement 1, LookAtTown
# 66 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtTown
# 67 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OurNewHome, MSGBOX_DEFAULT
# 68 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 69 "data/maps/FlottTown/scripts.pory"
	closemessage
# 70 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 71 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 72 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 73 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 74 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_DoYouLikeIt, MSGBOX_YESNO
# 75 "data/maps/FlottTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_EventScript_ElsieBringsUsHome4_2
# 80 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImSorryChamp, MSGBOX_DEFAULT
# 81 "data/maps/FlottTown/scripts.pory"
	waitmessage
FlottTown_EventScript_ElsieBringsUsHome4_1:
# 83 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_IllPrepareInside, MSGBOX_DEFAULT
# 84 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 85 "data/maps/FlottTown/scripts.pory"
	closemessage
# 86 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside
# 87 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/FlottTown/scripts.pory"
	delay 16
# 89 "data/maps/FlottTown/scripts.pory"
	hideobjectat 1, MAP_FLOTT_TOWN
	end

FlottTown_EventScript_ElsieBringsUsHome4_2:
# 76 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImGladYouLikeIt, MSGBOX_DEFAULT
# 77 "data/maps/FlottTown/scripts.pory"
	waitmessage
	goto FlottTown_EventScript_ElsieBringsUsHome4_1


FlottTown_PlayerHouseSign::
# 94 "data/maps/FlottTown/scripts.pory"
	lockall
# 95 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_PlayerHouseSign, MSGBOX_DEFAULT
# 96 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


FlottTown_BarneyHouseSign::
# 100 "data/maps/FlottTown/scripts.pory"
	lockall
# 101 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_BarneyHouseSign, MSGBOX_DEFAULT
# 102 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


FlottTown_OldGymSign::
# 106 "data/maps/FlottTown/scripts.pory"
	lockall
# 107 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OldGymSign, MSGBOX_DEFAULT
# 108 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


# 111 "data/maps/FlottTown/scripts.pory"
LookAtTown:
# 112 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 115 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie1:
# 116 "data/maps/FlottTown/scripts.pory"
	walk_up
# 116 "data/maps/FlottTown/scripts.pory"
	walk_up
# 117 "data/maps/FlottTown/scripts.pory"
	walk_right
# 118 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 121 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie2:
# 122 "data/maps/FlottTown/scripts.pory"
	walk_up
# 122 "data/maps/FlottTown/scripts.pory"
	walk_up
# 122 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 125 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie3:
# 126 "data/maps/FlottTown/scripts.pory"
	walk_up
# 126 "data/maps/FlottTown/scripts.pory"
	walk_up
# 127 "data/maps/FlottTown/scripts.pory"
	walk_left
# 128 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 131 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtDown:
# 132 "data/maps/FlottTown/scripts.pory"
	face_down
	step_end

# 135 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtPlayer:
# 136 "data/maps/FlottTown/scripts.pory"
	face_right
	step_end

# 139 "data/maps/FlottTown/scripts.pory"
PlayerLooksAtElsie:
# 140 "data/maps/FlottTown/scripts.pory"
	face_left
	step_end

# 143 "data/maps/FlottTown/scripts.pory"
ElsieWalksUp:
# 144 "data/maps/FlottTown/scripts.pory"
	walk_up
# 145 "data/maps/FlottTown/scripts.pory"
	walk_right
	step_end

# 148 "data/maps/FlottTown/scripts.pory"
ElsieWalksToHouse:
# 149 "data/maps/FlottTown/scripts.pory"
	walk_right
# 150 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 152 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
# 153 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 156 "data/maps/FlottTown/scripts.pory"
PlayerWalksToHouse:
# 157 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_right
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 160 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
# 161 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 164 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside:
# 165 "data/maps/FlottTown/scripts.pory"
	walk_up
# 165 "data/maps/FlottTown/scripts.pory"
	walk_up
# 165 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_right
# 167 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

FlottTown_Text_TookYourTime::
# 170 "data/maps/FlottTown/scripts.pory"
	.string "Hey! You really took your time, huh?$"

FlottTown_Text_LookAtTown::
# 174 "data/maps/FlottTown/scripts.pory"
	.string "So, this is our new home. Beautiful, isn't\n"
	.string "it?$"

FlottTown_Text_LetsTakeALook::
# 178 "data/maps/FlottTown/scripts.pory"
	.string "Well, that's enough sight-seeing. Let's\n"
	.string "go check our our new house!$"

FlottTown_Text_OurNewHome::
# 182 "data/maps/FlottTown/scripts.pory"
	.string "This is it! This is where we'll be living\n"
	.string "from now on.$"

FlottTown_Text_DoYouLikeIt::
# 186 "data/maps/FlottTown/scripts.pory"
	.string "So champ; do you like the new place?$"

FlottTown_Text_ImGladYouLikeIt::
# 190 "data/maps/FlottTown/scripts.pory"
	.string "Good to hear! Of course, anyone's gonna\n"
	.string "be glad we got out of that old hole. We\l"
	.string "don't have to suffer under his roof\l"
	.string "anymore. Plus, we got a killer view.$"

FlottTown_Text_ImSorryChamp::
# 194 "data/maps/FlottTown/scripts.pory"
	.string "...\p"
	.string "I'm sorry, champ. I know you miss all\n"
	.string "your friends back...well I don't even\l"
	.string "wanna call it home anymore. But, hey, at\l"
	.string "least we aren't suffering under him\l"
	.string "anymore, right? I promise, you'll see all\l"
	.string "of them again soon.$"

FlottTown_Text_IllPrepareInside::
# 198 "data/maps/FlottTown/scripts.pory"
	.string "I'll get some stuff ready inside. Why\n"
	.string "not take a look around town?$"

FlottTown_Text_PlayerHouseSign::
# 202 "data/maps/FlottTown/scripts.pory"
	.string "ASTER RESIDENCE$"

FlottTown_Text_BarneyHouseSign::
# 206 "data/maps/FlottTown/scripts.pory"
	.string "HEINRICH RESIDNECE$"

FlottTown_Text_OldGymSign::
# 210 "data/maps/FlottTown/scripts.pory"
	.string "The text is faded, but you can just\n"
	.string "barely make out the text written on it.\p"
	.string "FLOTT TOWN GYM\p"
	.string "LEADER: BARNEY HEINRICH\p"
	.string "The pursuant excavator!$"
