FlottTown_MapScripts::
	.byte 0


FlottTown_EventScript_ElsieBringsUsHome1::
# 15 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 16 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 17 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 18 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie1
# 19 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 20 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome2::
# 24 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 25 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 26 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 27 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie2
# 28 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 29 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome3::
# 33 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 34 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 35 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 36 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie3
# 37 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 38 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome4::
# 42 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 43 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 44 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 45 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 46 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_TookYourTime, MSGBOX_DEFAULT
# 47 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 48 "data/maps/FlottTown/scripts.pory"
	applymovement 1, LookAtTown
# 49 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtTown
# 50 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 51 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 52 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LookAtTown, MSGBOX_DEFAULT
# 53 "data/maps/FlottTown/scripts.pory"
	closemessage
# 54 "data/maps/FlottTown/scripts.pory"
	delay 180
# 55 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 56 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
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
	applymovement 1, LookAtTown
# 68 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtTown
# 69 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OurNewHome, MSGBOX_DEFAULT
# 70 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 71 "data/maps/FlottTown/scripts.pory"
	closemessage
# 72 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 73 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
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
LookAtTown:
# 114 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 117 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie1:
# 118 "data/maps/FlottTown/scripts.pory"
	walk_up
# 118 "data/maps/FlottTown/scripts.pory"
	walk_up
# 119 "data/maps/FlottTown/scripts.pory"
	walk_right
# 120 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 123 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie2:
# 124 "data/maps/FlottTown/scripts.pory"
	walk_up
# 124 "data/maps/FlottTown/scripts.pory"
	walk_up
# 124 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 127 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie3:
# 128 "data/maps/FlottTown/scripts.pory"
	walk_up
# 128 "data/maps/FlottTown/scripts.pory"
	walk_up
# 129 "data/maps/FlottTown/scripts.pory"
	walk_left
# 130 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 133 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtDown:
# 134 "data/maps/FlottTown/scripts.pory"
	face_down
	step_end

# 137 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtPlayer:
# 138 "data/maps/FlottTown/scripts.pory"
	face_right
	step_end

# 141 "data/maps/FlottTown/scripts.pory"
PlayerLooksAtElsie:
# 142 "data/maps/FlottTown/scripts.pory"
	face_left
	step_end

# 145 "data/maps/FlottTown/scripts.pory"
ElsieWalksUp:
# 146 "data/maps/FlottTown/scripts.pory"
	walk_up
# 147 "data/maps/FlottTown/scripts.pory"
	walk_right
	step_end

# 150 "data/maps/FlottTown/scripts.pory"
ElsieWalksToHouse:
# 151 "data/maps/FlottTown/scripts.pory"
	walk_right
# 152 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 153 "data/maps/FlottTown/scripts.pory"
	walk_up
# 154 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
# 155 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 158 "data/maps/FlottTown/scripts.pory"
PlayerWalksToHouse:
# 159 "data/maps/FlottTown/scripts.pory"
	walk_up
# 160 "data/maps/FlottTown/scripts.pory"
	walk_right
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 161 "data/maps/FlottTown/scripts.pory"
	walk_up
# 162 "data/maps/FlottTown/scripts.pory"
	walk_up
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
# 163 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 166 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside1:
# 167 "data/maps/FlottTown/scripts.pory"
	walk_up
# 167 "data/maps/FlottTown/scripts.pory"
	walk_up
# 167 "data/maps/FlottTown/scripts.pory"
	walk_up
# 168 "data/maps/FlottTown/scripts.pory"
	walk_right
# 169 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 172 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside2:
# 173 "data/maps/FlottTown/scripts.pory"
	walk_up
# 174 "data/maps/FlottTown/scripts.pory"
	set_invisible
# 175 "data/maps/FlottTown/scripts.pory"
	step_end

FlottTown_Text_TookYourTime::
# 178 "data/maps/FlottTown/scripts.pory"
	.string "Hey! You really took your time, huh?$"

FlottTown_Text_LookAtTown::
# 182 "data/maps/FlottTown/scripts.pory"
	.string "So, this is our new home. Beautiful, isn't\n"
	.string "it?$"

FlottTown_Text_LetsTakeALook::
# 186 "data/maps/FlottTown/scripts.pory"
	.string "Well, that's enough sight-seeing. Let's\n"
	.string "go check our our new house!$"

FlottTown_Text_OurNewHome::
# 190 "data/maps/FlottTown/scripts.pory"
	.string "This is it! This is where we'll be living\n"
	.string "from now on.$"

FlottTown_Text_DoYouLikeIt::
# 194 "data/maps/FlottTown/scripts.pory"
	.string "So Champ, do you like the new place?$"

FlottTown_Text_ImGladYouLikeIt::
# 198 "data/maps/FlottTown/scripts.pory"
	.string "Good to hear! Of course, anyone's gonna\n"
	.string "be glad we got out of that old hole. We\l"
	.string "don't have to suffer under his roof\l"
	.string "anymore. Plus, we got a killer view.$"

FlottTown_Text_ImSorryChamp::
# 202 "data/maps/FlottTown/scripts.pory"
	.string "...\p"
	.string "I'm sorry, Champ. I know you miss all\n"
	.string "your friends back...well I don't even\l"
	.string "wanna call it home anymore. But, hey, at\l"
	.string "least we aren't suffering under his\l"
	.string "roof anymore, right? I promise, you'll\l"
	.string "see all of them again soon.$"

FlottTown_Text_IllPrepareInside::
# 206 "data/maps/FlottTown/scripts.pory"
	.string "I'll get some stuff ready inside. Why\n"
	.string "not take a look around town?$"

FlottTown_Text_PlayerHouseSign::
# 210 "data/maps/FlottTown/scripts.pory"
	.string "ASTER RESIDENCE$"

FlottTown_Text_BarneyHouseSign::
# 214 "data/maps/FlottTown/scripts.pory"
	.string "HEINRICH RESIDNECE$"

FlottTown_Text_OldGymSign::
# 218 "data/maps/FlottTown/scripts.pory"
	.string "The text is faded, but you can just\n"
	.string "barely make out the text written on it.\p"
	.string "FLOTT TOWN GYM\p"
	.string "LEADER: BARNEY HEINRICH\p"
	.string "The pursuant excavator!$"
