FlottTown_BarneysHouse_MapScripts::
# 9 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 9, FlottTown_BarneysHouse_EventScript_BarneysLecture
	.2byte 0


FlottTown_BarneysHouse_EventScript_BarneysLecture::
# 15 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	lockall
# 16 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 17 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_BarneysLecture, MSGBOX_DEFAULT
# 18 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 3, Common_Movement_FaceRight
# 19 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 20 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_0, MSGBOX_DEFAULT
# 21 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceDown
# 22 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 3, Common_Movement_FaceUp
# 23 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 24 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_1, MSGBOX_DEFAULT
# 25 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_2, MSGBOX_DEFAULT
# 26 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	closemessage
# 27 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 28 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 3, FlottTown_BarneysHouse_Movement_ElsieWalksOut
# 29 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	waitmovement 3
# 30 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	removeobject 3
# 31 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	playse SE_DOOR
# 32 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	waitse
# 33 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 34 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_ImTerriblySorry, MSGBOX_DEFAULT
# 35 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 10
# 36 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	releaseall
	end


FlottTown_BarneysHouse_Barney::
# 41 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	switch VAR_FLOTT_TOWN_STATE
# 42 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	case 10, FlottTown_BarneysHouse_Barney_2
# 44 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	case 11, FlottTown_BarneysHouse_Barney_3
	return

FlottTown_BarneysHouse_Barney_2:
# 43 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_GoToYourSister, MSGBOX_NPC
	return

FlottTown_BarneysHouse_Barney_3:
# 45 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_GymLeaderChallenge, MSGBOX_NPC
	return


FlottTown_BarneysHouse_Adelaide::
# 51 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_BarneysHouse_Adelaide_1
# 55 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_GladYoureOkay, MSGBOX_NPC
	return

FlottTown_BarneysHouse_Adelaide_1:
# 52 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_BarneysOut, MSGBOX_NPC
	return


# 59 "data/maps/FlottTown_BarneysHouse/scripts.pory"
FlottTown_BarneysHouse_Movement_ElsieWalksOut:
# 60 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
# 60 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
# 61 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_left
# 61 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
# 62 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
	step_end

FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_0:
# 20 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "ELSIE: What's Mr. Barney talking about,\n"
	.string "{PLAYER}? Who else was in the cave?$"

FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_1:
# 24 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "BARNEY: Hm? That's a Pokéball on your\n"
	.string "side, right? I assumed you used a\l"
	.string "Pokémon.$"

FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_2:
# 25 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "ELSIE: ...$"

FlottTown_BarneysHouse_Text_BarneysLecture::
# 65 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "Now, I wouldn't be a responsible adult if\n"
	.string "I don't reprimand you for what you did\l"
	.string "in the first place.\p"
	.string "See here: what you did was incredibly\n"
	.string "reckless. The gym is closed for a\l"
	.string "reason. As much as it breaks my heart\l"
	.string "for it to be unmaintained, such is its\l"
	.string "state.\p"
	.string "Normally, this is also the part where I\n"
	.string "emphasize how dangerous it was.\p"
	.string "But, it seems that you had no reason to\n"
	.string "be scared; after all, you weren't alone,\l"
	.string "were you?$"

FlottTown_BarneysHouse_Text_ImTerriblySorry::
# 74 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "BARNEY: Oh my, I didn't expect her to be\n"
	.string "upset. I'm terribly sorry. That being\l"
	.string "said, if you'd like to know more about\l"
	.string "training, you can come back to me.$"

FlottTown_BarneysHouse_Text_BarneysOut::
# 78 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "Oh my, a visitor! Are you the girls that\n"
	.string "just moved in?\p"
	.string "My name is Adelaide. It's a pleaesure to\n"
	.string "meet you. Unfortunately, my husband is\l"
	.string "out at the moment.\p"
	.string "He's currently in the mainland\n"
	.string "attending to Gym Leader business. I'll\l"
	.string "say, you can take the man out of the\l"
	.string "gym, but not the gym out of the man!\p"
	.string "Sigh... but that conviction of him is\n"
	.string "definitely one of his best traits.\p"
	.string "Oh, look at me! Going off to someone\n"
	.string "likely tired from their journey. I'm sure\l"
	.string "we'll see each other soon.$"

FlottTown_BarneysHouse_Text_GladYoureOkay::
# 88 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "My goodness, your first day and already\n"
	.string "making quite a ruckus!\p"
	.string "But nonetheless, I'm happy that you and\n"
	.string "your sister are safe.$"

FlottTown_BarneysHouse_Text_GoToYourSister::
# 94 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "I appreciate your enthusiasm, but I\n"
	.string "believe it's apt that you check-in on\l"
	.string "your sister first.$"

FlottTown_BarneysHouse_Text_GymLeaderChallenge::
# 99 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "Oh, you've returned! I imagine you're\n"
	.string "interested in growing as a trainer, no?$"
