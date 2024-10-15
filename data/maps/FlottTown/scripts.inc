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
	delay 180
# 51 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 52 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 53 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 54 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 55 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LetsTakeALook, MSGBOX_DEFAULT
# 56 "data/maps/FlottTown/scripts.pory"
	closemessage
# 57 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksUp
# 58 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 59 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksToHouse
# 60 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToHouse
# 61 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 62 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 63 "data/maps/FlottTown/scripts.pory"
	applymovement 1, LookAtTown
# 64 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtTown
# 65 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OurNewHome, MSGBOX_DEFAULT
# 66 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 67 "data/maps/FlottTown/scripts.pory"
	closemessage
# 68 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 69 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 70 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 71 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 72 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_DoYouLikeIt, MSGBOX_YESNO
# 73 "data/maps/FlottTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_EventScript_ElsieBringsUsHome4_2
# 78 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImSorryChamp, MSGBOX_DEFAULT
# 79 "data/maps/FlottTown/scripts.pory"
	waitmessage
FlottTown_EventScript_ElsieBringsUsHome4_1:
# 81 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_IllPrepareInside, MSGBOX_DEFAULT
# 82 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 83 "data/maps/FlottTown/scripts.pory"
	closemessage
# 84 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside1
# 85 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 86 "data/maps/FlottTown/scripts.pory"
	delay 16
# 87 "data/maps/FlottTown/scripts.pory"
	opendoor 10, 6
# 88 "data/maps/FlottTown/scripts.pory"
	waitdooranim
# 89 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside2
# 90 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 91 "data/maps/FlottTown/scripts.pory"
	closedoor 10, 6
# 92 "data/maps/FlottTown/scripts.pory"
	waitdooranim
	end

FlottTown_EventScript_ElsieBringsUsHome4_2:
# 74 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImGladYouLikeIt, MSGBOX_DEFAULT
# 75 "data/maps/FlottTown/scripts.pory"
	waitmessage
	goto FlottTown_EventScript_ElsieBringsUsHome4_1


FlottTown_PlayerHouseSign::
# 97 "data/maps/FlottTown/scripts.pory"
	lockall
# 98 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_PlayerHouseSign, MSGBOX_DEFAULT
# 99 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


FlottTown_BarneyHouseSign::
# 103 "data/maps/FlottTown/scripts.pory"
	lockall
# 104 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_BarneyHouseSign, MSGBOX_DEFAULT
# 105 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


FlottTown_OldGymSign::
# 109 "data/maps/FlottTown/scripts.pory"
	lockall
# 110 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OldGymSign, MSGBOX_DEFAULT
# 111 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


# 114 "data/maps/FlottTown/scripts.pory"
LookAtTown:
# 115 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 118 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie1:
# 119 "data/maps/FlottTown/scripts.pory"
	walk_up
# 119 "data/maps/FlottTown/scripts.pory"
	walk_up
# 120 "data/maps/FlottTown/scripts.pory"
	walk_right
# 121 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 124 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie2:
# 125 "data/maps/FlottTown/scripts.pory"
	walk_up
# 125 "data/maps/FlottTown/scripts.pory"
	walk_up
# 125 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 128 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie3:
# 129 "data/maps/FlottTown/scripts.pory"
	walk_up
# 129 "data/maps/FlottTown/scripts.pory"
	walk_up
# 130 "data/maps/FlottTown/scripts.pory"
	walk_left
# 131 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 134 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtDown:
# 135 "data/maps/FlottTown/scripts.pory"
	face_down
	step_end

# 138 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtPlayer:
# 139 "data/maps/FlottTown/scripts.pory"
	face_right
	step_end

# 142 "data/maps/FlottTown/scripts.pory"
PlayerLooksAtElsie:
# 143 "data/maps/FlottTown/scripts.pory"
	face_left
	step_end

# 146 "data/maps/FlottTown/scripts.pory"
ElsieWalksUp:
# 147 "data/maps/FlottTown/scripts.pory"
	walk_up
# 148 "data/maps/FlottTown/scripts.pory"
	walk_right
	step_end

# 151 "data/maps/FlottTown/scripts.pory"
ElsieWalksToHouse:
# 152 "data/maps/FlottTown/scripts.pory"
	walk_right
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_up
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
# 156 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 159 "data/maps/FlottTown/scripts.pory"
PlayerWalksToHouse:
# 160 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_right
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 163 "data/maps/FlottTown/scripts.pory"
	walk_up
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
# 164 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 167 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside1:
# 168 "data/maps/FlottTown/scripts.pory"
	walk_up
# 168 "data/maps/FlottTown/scripts.pory"
	walk_up
# 168 "data/maps/FlottTown/scripts.pory"
	walk_up
# 169 "data/maps/FlottTown/scripts.pory"
	walk_right
# 170 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 173 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside2:
# 174 "data/maps/FlottTown/scripts.pory"
	walk_up
# 175 "data/maps/FlottTown/scripts.pory"
	set_invisible
# 176 "data/maps/FlottTown/scripts.pory"
	step_end

FlottTown_Text_TookYourTime::
# 179 "data/maps/FlottTown/scripts.pory"
	.string "Hey! You really took your time, huh?$"

FlottTown_Text_LookAtTown::
# 183 "data/maps/FlottTown/scripts.pory"
	.string "So, this is our new home. Beautiful, isn't\n"
	.string "it?$"

FlottTown_Text_LetsTakeALook::
# 187 "data/maps/FlottTown/scripts.pory"
	.string "Well, that's enough sight-seeing. Let's\n"
	.string "go check our our new house!$"

FlottTown_Text_OurNewHome::
# 191 "data/maps/FlottTown/scripts.pory"
	.string "This is it! This is where we'll be living\n"
	.string "from now on.$"

FlottTown_Text_DoYouLikeIt::
# 195 "data/maps/FlottTown/scripts.pory"
	.string "So Champ, do you like the new place?$"

FlottTown_Text_ImGladYouLikeIt::
# 199 "data/maps/FlottTown/scripts.pory"
	.string "Good to hear! Of course, anyone's gonna\n"
	.string "be glad we got out of that old hole. We\l"
	.string "don't have to suffer under his roof\l"
	.string "anymore. Plus, we got a killer view.$"

FlottTown_Text_ImSorryChamp::
# 203 "data/maps/FlottTown/scripts.pory"
	.string "...\p"
	.string "I'm sorry, Champ. I know you miss all\n"
	.string "your friends back...well I don't even\l"
	.string "wanna call it home anymore. But, hey, at\l"
	.string "least we aren't suffering under his\l"
	.string "roof anymore, right? I promise, you'll\l"
	.string "see all of them again soon.$"

FlottTown_Text_IllPrepareInside::
# 207 "data/maps/FlottTown/scripts.pory"
	.string "I'll get some stuff ready inside. Why\n"
	.string "not take a look around town?$"

FlottTown_Text_PlayerHouseSign::
# 211 "data/maps/FlottTown/scripts.pory"
	.string "ASTER RESIDENCE$"

FlottTown_Text_BarneyHouseSign::
# 215 "data/maps/FlottTown/scripts.pory"
	.string "HEINRICH RESIDNECE$"

FlottTown_Text_OldGymSign::
# 219 "data/maps/FlottTown/scripts.pory"
	.string "The text is faded, but you can just\n"
	.string "barely make out the text written on it.\p"
	.string "FLOTT TOWN GYM\p"
	.string "LEADER: BARNEY HEINRICH\p"
	.string "The pursuant excavator!$"
