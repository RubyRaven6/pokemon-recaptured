FlottTown_BarneysHouse_MapScripts::
# 9 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 13 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 10 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 9, FlottTown_BarneysHouse_FacePlayerUp
	.2byte 0

FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 9, FlottTown_BarneysHouse_EventScript_BarneysLecture
	.2byte 0


FlottTown_BarneysHouse_FacePlayerUp::
# 19 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	return


FlottTown_BarneysHouse_EventScript_BarneysLecture::
# 23 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	lockall
# 24 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 25 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_BarneysLecture, MSGBOX_DEFAULT
# 26 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 3, Common_Movement_FaceRight
# 27 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 28 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_0, MSGBOX_DEFAULT
# 29 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceDown
# 30 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 3, Common_Movement_FaceUp
# 31 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 32 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_GoodBattler, MSGBOX_DEFAULT
# 33 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_1, MSGBOX_DEFAULT
# 34 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	closemessage
# 35 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 36 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement 3, FlottTown_BarneysHouse_Movement_ElsieWalksOut
# 37 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	waitmovement 3
# 38 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	removeobject 3
# 39 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	playse SE_DOOR
# 40 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	waitse
# 41 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 42 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_ImTerriblySorry, MSGBOX_DEFAULT
# 43 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 10
# 44 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	releaseall
	end


FlottTown_BarneysHouse_Barney::
# 49 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	switch VAR_FLOTT_TOWN_STATE
# 50 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	case 10, FlottTown_BarneysHouse_Barney_2
# 52 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	case 11, FlottTown_BarneysHouse_Barney_3
	return

FlottTown_BarneysHouse_Barney_2:
# 51 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_GoToYourSister, MSGBOX_NPC
	return

FlottTown_BarneysHouse_Barney_3:
# 53 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_GymLeaderChallenge, MSGBOX_NPC
	return


FlottTown_BarneysHouse_Adelaide::
# 59 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_BarneysHouse_Adelaide_1
# 63 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_GladYoureOkay, MSGBOX_NPC
	return

FlottTown_BarneysHouse_Adelaide_1:
# 60 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	msgbox FlottTown_BarneysHouse_Text_BarneysOut, MSGBOX_NPC
	return


# 67 "data/maps/FlottTown_BarneysHouse/scripts.pory"
FlottTown_BarneysHouse_Movement_ElsieWalksOut:
# 68 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
# 68 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
# 69 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_left
# 69 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_left
# 70 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
# 70 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	walk_down
	step_end

FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_0:
# 28 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "ELSIE: What's Mr. Barney talking about,\n"
	.string "{PLAYER}? Who else was in the cave?$"

FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_1:
# 33 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "ELSIE: ...$"

FlottTown_BarneysHouse_Text_BarneysLecture::
# 73 "data/maps/FlottTown_BarneysHouse/scripts.pory"
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
# 82 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "BARNEY: Oh my, I didn't expect her to be\n"
	.string "upset. I'm terribly sorry. That being\l"
	.string "said, if you'd like to know more about\l"
	.string "training, you can come back to me.$"

FlottTown_BarneysHouse_Text_BarneysOut::
# 86 "data/maps/FlottTown_BarneysHouse/scripts.pory"
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

FlottTown_BarneysHouse_Text_GoodBattler::
# 96 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "BARNEY: Hm? That's a Pokéball on your\n"
	.string "side, right? I assumed you used a\l"
	.string "Pokémon. I even heard the faint sounds\l"
	.string "of battling. I'm sure you've got a good\l"
	.string "head on your shoulders to be a trainer!$"

FlottTown_BarneysHouse_Text_GladYoureOkay::
# 100 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "My goodness, your first day and already\n"
	.string "making quite a ruckus!\p"
	.string "But nonetheless, I'm happy that you and\n"
	.string "your sister are safe.$"

FlottTown_BarneysHouse_Text_GoToYourSister::
# 106 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "I appreciate your enthusiasm, but I\n"
	.string "believe it's apt that you check-in on\l"
	.string "your sister first.$"

FlottTown_BarneysHouse_Text_GymLeaderChallenge::
# 111 "data/maps/FlottTown_BarneysHouse/scripts.pory"
	.string "Oh, you've returned! I imagine you're\n"
	.string "interested in growing as a trainer, no?$"
