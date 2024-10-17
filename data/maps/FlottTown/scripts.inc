FlottTown_MapScripts::
	.byte 0


FlottTown_EventScript_ElsieBringsUsHome1::
# 14 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 15 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 16 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 17 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie1
# 18 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 19 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome2::
# 23 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 24 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 25 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 26 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie2
# 27 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 28 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome3::
# 32 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtDown
# 33 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 34 "data/maps/FlottTown/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 35 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveNextToElsie3
# 36 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 37 "data/maps/FlottTown/scripts.pory"
	goto FlottTown_EventScript_ElsieBringsUsHome4
	return


FlottTown_EventScript_ElsieBringsUsHome4::
# 41 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 42 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 43 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 44 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 45 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_TookYourTime, MSGBOX_DEFAULT
# 46 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 47 "data/maps/FlottTown/scripts.pory"
	applymovement 1, LookAtTown
# 48 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtTown
# 49 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 50 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 51 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LookAtTown, MSGBOX_DEFAULT
# 52 "data/maps/FlottTown/scripts.pory"
	closemessage
# 53 "data/maps/FlottTown/scripts.pory"
	delay 180
# 54 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 55 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 56 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 57 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 58 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_LetsTakeALook, MSGBOX_DEFAULT
# 59 "data/maps/FlottTown/scripts.pory"
	closemessage
# 60 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksUp
# 61 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 62 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieWalksToHouse
# 63 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToHouse
# 64 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 65 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 66 "data/maps/FlottTown/scripts.pory"
	applymovement 1, LookAtTown
# 67 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtTown
# 68 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OurNewHome, MSGBOX_DEFAULT
# 69 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 70 "data/maps/FlottTown/scripts.pory"
	closemessage
# 71 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieLooksAtPlayer
# 72 "data/maps/FlottTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerLooksAtElsie
# 73 "data/maps/FlottTown/scripts.pory"
	waitmovement 1
# 74 "data/maps/FlottTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 75 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_DoYouLikeIt, MSGBOX_YESNO
# 76 "data/maps/FlottTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_EventScript_ElsieBringsUsHome4_2
# 81 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImSorryChamp, MSGBOX_DEFAULT
# 82 "data/maps/FlottTown/scripts.pory"
	waitmessage
FlottTown_EventScript_ElsieBringsUsHome4_1:
# 84 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_IllPrepareInside, MSGBOX_DEFAULT
# 85 "data/maps/FlottTown/scripts.pory"
	waitmessage
# 86 "data/maps/FlottTown/scripts.pory"
	closemessage
# 87 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside1
# 88 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 89 "data/maps/FlottTown/scripts.pory"
	delay 16
# 90 "data/maps/FlottTown/scripts.pory"
	opendoor 10, 6
# 91 "data/maps/FlottTown/scripts.pory"
	waitdooranim
# 92 "data/maps/FlottTown/scripts.pory"
	applymovement 1, ElsieGoesInside2
# 93 "data/maps/FlottTown/scripts.pory"
	waitmovement 0
# 94 "data/maps/FlottTown/scripts.pory"
	closedoor 10, 6
# 95 "data/maps/FlottTown/scripts.pory"
	waitdooranim
# 96 "data/maps/FlottTown/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 3
	end

FlottTown_EventScript_ElsieBringsUsHome4_2:
# 77 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_ImGladYouLikeIt, MSGBOX_DEFAULT
# 78 "data/maps/FlottTown/scripts.pory"
	waitmessage
	goto FlottTown_EventScript_ElsieBringsUsHome4_1


FlottTown_PlayerHouseSign::
# 101 "data/maps/FlottTown/scripts.pory"
	lockall
# 102 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_PlayerHouseSign, MSGBOX_DEFAULT
# 103 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


FlottTown_BarneyHouseSign::
# 107 "data/maps/FlottTown/scripts.pory"
	lockall
# 108 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_BarneyHouseSign, MSGBOX_DEFAULT
# 109 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


FlottTown_OldGymSign::
# 113 "data/maps/FlottTown/scripts.pory"
	lockall
# 114 "data/maps/FlottTown/scripts.pory"
	msgbox FlottTown_Text_OldGymSign, MSGBOX_DEFAULT
# 115 "data/maps/FlottTown/scripts.pory"
	releaseall
	return


# 118 "data/maps/FlottTown/scripts.pory"
LookAtTown:
# 119 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 122 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie1:
# 123 "data/maps/FlottTown/scripts.pory"
	walk_up
# 123 "data/maps/FlottTown/scripts.pory"
	walk_up
# 124 "data/maps/FlottTown/scripts.pory"
	walk_right
# 125 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 128 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie2:
# 129 "data/maps/FlottTown/scripts.pory"
	walk_up
# 129 "data/maps/FlottTown/scripts.pory"
	walk_up
# 129 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 132 "data/maps/FlottTown/scripts.pory"
MoveNextToElsie3:
# 133 "data/maps/FlottTown/scripts.pory"
	walk_up
# 133 "data/maps/FlottTown/scripts.pory"
	walk_up
# 134 "data/maps/FlottTown/scripts.pory"
	walk_left
# 135 "data/maps/FlottTown/scripts.pory"
	walk_up
	step_end

# 138 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtDown:
# 139 "data/maps/FlottTown/scripts.pory"
	face_down
	step_end

# 142 "data/maps/FlottTown/scripts.pory"
ElsieLooksAtPlayer:
# 143 "data/maps/FlottTown/scripts.pory"
	face_right
	step_end

# 146 "data/maps/FlottTown/scripts.pory"
PlayerLooksAtElsie:
# 147 "data/maps/FlottTown/scripts.pory"
	face_left
	step_end

# 150 "data/maps/FlottTown/scripts.pory"
ElsieWalksUp:
# 151 "data/maps/FlottTown/scripts.pory"
	walk_up
# 152 "data/maps/FlottTown/scripts.pory"
	walk_right
	step_end

# 155 "data/maps/FlottTown/scripts.pory"
ElsieWalksToHouse:
# 156 "data/maps/FlottTown/scripts.pory"
	walk_right
# 157 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 158 "data/maps/FlottTown/scripts.pory"
	walk_up
# 159 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
# 160 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 163 "data/maps/FlottTown/scripts.pory"
PlayerWalksToHouse:
# 164 "data/maps/FlottTown/scripts.pory"
	walk_up
# 165 "data/maps/FlottTown/scripts.pory"
	walk_right
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 166 "data/maps/FlottTown/scripts.pory"
	walk_up
# 167 "data/maps/FlottTown/scripts.pory"
	walk_up
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
# 168 "data/maps/FlottTown/scripts.pory"
	walk_left
	step_end

# 171 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside1:
# 172 "data/maps/FlottTown/scripts.pory"
	walk_up
# 172 "data/maps/FlottTown/scripts.pory"
	walk_up
# 172 "data/maps/FlottTown/scripts.pory"
	walk_up
# 173 "data/maps/FlottTown/scripts.pory"
	walk_right
# 174 "data/maps/FlottTown/scripts.pory"
	face_up
	step_end

# 177 "data/maps/FlottTown/scripts.pory"
ElsieGoesInside2:
# 178 "data/maps/FlottTown/scripts.pory"
	walk_up
# 179 "data/maps/FlottTown/scripts.pory"
	set_invisible
# 180 "data/maps/FlottTown/scripts.pory"
	step_end

FlottTown_Text_TookYourTime::
# 183 "data/maps/FlottTown/scripts.pory"
	.string "Hey! You really took your time, huh?$"

FlottTown_Text_LookAtTown::
# 187 "data/maps/FlottTown/scripts.pory"
	.string "So, this is our new home. Beautiful, isn't\n"
	.string "it?$"

FlottTown_Text_LetsTakeALook::
# 191 "data/maps/FlottTown/scripts.pory"
	.string "Well, that's enough sight-seeing. Let's\n"
	.string "go check our our new house!$"

FlottTown_Text_OurNewHome::
# 195 "data/maps/FlottTown/scripts.pory"
	.string "This is it! This is where we'll be living\n"
	.string "from now on.$"

FlottTown_Text_DoYouLikeIt::
# 199 "data/maps/FlottTown/scripts.pory"
	.string "So Champ, do you like the new place?$"

FlottTown_Text_ImGladYouLikeIt::
# 203 "data/maps/FlottTown/scripts.pory"
	.string "Good to hear! Of course, anyone's gonna\n"
	.string "be glad we got out of that old hole. We\l"
	.string "don't have to suffer under his roof\l"
	.string "anymore. Plus, we got a killer view.$"

FlottTown_Text_ImSorryChamp::
# 207 "data/maps/FlottTown/scripts.pory"
	.string "...\p"
	.string "I'm sorry, Champ. I know you miss all\n"
	.string "your friends back...well I don't even\l"
	.string "wanna call it home anymore. But, hey, at\l"
	.string "least we aren't suffering under his\l"
	.string "roof anymore, right? I promise, you'll\l"
	.string "see all of them again soon.$"

FlottTown_Text_IllPrepareInside::
# 211 "data/maps/FlottTown/scripts.pory"
	.string "I'll get some stuff ready inside. Why\n"
	.string "not take a look around town?$"

FlottTown_Text_PlayerHouseSign::
# 215 "data/maps/FlottTown/scripts.pory"
	.string "ASTER RESIDENCE$"

FlottTown_Text_BarneyHouseSign::
# 219 "data/maps/FlottTown/scripts.pory"
	.string "HEINRICH RESIDNECE$"

FlottTown_Text_OldGymSign::
# 223 "data/maps/FlottTown/scripts.pory"
	.string "The text is faded, but you can just\n"
	.string "barely make out the text written on it.\p"
	.string "FLOTT TOWN GYM\p"
	.string "LEADER: BARNEY HEINRICH\p"
	.string "The pursuant excavator!$"
