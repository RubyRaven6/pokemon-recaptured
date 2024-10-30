# 1 "data/maps/FlottTown_AbandonedGym/scripts.pory"

# 2 "data/maps/FlottTown_AbandonedGym/scripts.pory"
.set LOCALID_ELSIE, 1
# 3 "data/maps/FlottTown_AbandonedGym/scripts.pory"
.set LOCALID_BALL, 2

FlottTown_AbandonedGym_MapScripts::
# 7 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_AbandonedGym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_AbandonedGym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 2, FlottTown_AbandonedGym_BeforeEvent
# 9 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 3, FlottTown_AbandonedGym_OnFrame
	.2byte 0


FlottTown_AbandonedGym_BeforeEvent::
# 14 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setflag FLAG_ELSIE_ENTERS_GYM
# 15 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setflag FLAG_VISITED_GYM
# 16 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_BeforeEvent_Text_0, MSGBOX_DEFAULT
# 17 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmessage
# 18 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
# 19 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 20 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	warp MAP_FLOTT_TOWN, 9, 25
# 21 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitstate
	return


FlottTown_AbandonedGym_OnFrame::
# 25 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	lock
# 26 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_AbandonedGym_WalkingIn
# 27 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmovement 0
# 28 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	clearflag FLAG_ELSIE_ENTERS_GYM
# 29 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	addobject LOCALID_ELSIE
# 30 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement LOCALID_ELSIE, Common_Movement_FaceUp
# 31 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	lock
# 32 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmovement LOCALID_ELSIE
# 33 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_OnFrame_Text_0, MSGBOX_DEFAULT
# 34 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_OnFrame_Text_1, MSGBOX_DEFAULT
# 35 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmessage
# 36 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
# 37 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setfollower LOCALID_ELSIE, FOLLOWER_ALL, FlottTown_AbandonedGym_ElsieFollowerScript, 0
# 38 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 4
	end


FlottTown_AbandonedGym_LadderStopper::
# 43 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_Text_LetsStayUp, MSGBOX_DEFAULT
# 44 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmessage
# 45 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
# 46 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, WalkAway
	return


FlottTown_AbandonedGym_EventScript_FreePokeball::
# 50 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_EventScript_FreePokeball_Text_0, MSGBOX_AUTOCLOSE
# 51 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	removeobject LOCALID_BALL, MAP_FLOTT_TOWN_ABANDONED_GYM
# 52 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	giveitem ITEM_POKE_BALL, 1
# 53 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 5
# 54 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
# 55 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_Text_BeforeCollapse, MSGBOX_NPC
# 56 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmessage
# 57 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
	end


FlottTown_AbandonedGym_EventScript_GymCollapses::
# 62 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FacePlayer
# 63 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 12, 17, METATILE_Cave_CrackedFloor, FALSE
# 64 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 13, 17, METATILE_Cave_CrackedFloor, FALSE
# 65 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 14, 17, METATILE_Cave_CrackedFloor, FALSE
# 66 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 12, 18, METATILE_Cave_CrackedFloor, FALSE
# 67 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 13, 18, METATILE_Cave_CrackedFloor, FALSE
# 68 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 14, 18, METATILE_Cave_CrackedFloor, FALSE
# 69 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	special DrawWholeMapView
# 70 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOW_ME, Common_Movement_FacePlayer
# 71 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_EventScript_GymCollapses_Text_0
# 72 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 12, 17, METATILE_Cave_CrackedFloor_Hole, FALSE
# 73 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 13, 17, METATILE_Cave_CrackedFloor_Hole, FALSE
# 74 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 14, 17, METATILE_Cave_CrackedFloor_Hole, FALSE
# 75 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 12, 18, METATILE_Cave_CrackedFloor_Hole, FALSE
# 76 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 13, 18, METATILE_Cave_CrackedFloor_Hole, FALSE
# 77 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 14, 18, METATILE_Cave_CrackedFloor_Hole, FALSE
# 78 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	warphole MAP_FLOTT_TOWN_FLOTT_CAVE
# 79 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	special DrawWholeMapView
# 80 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 6
	return


FlottTown_AbandonedGym_ElsieFollowerScript::
# 84 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	facefollower
# 85 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 4
	goto_if_eq FlottTown_AbandonedGym_ElsieFollowerScript_1
# 90 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_ElsieFollowerScript_Text_1
# 91 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
	return

FlottTown_AbandonedGym_ElsieFollowerScript_1:
# 86 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_ElsieFollowerScript_Text_0
# 87 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
	return


# 95 "data/maps/FlottTown_AbandonedGym/scripts.pory"
FlottTown_AbandonedGym_WalkingIn:
# 96 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 97 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	face_up
# 98 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	step_end

# 101 "data/maps/FlottTown_AbandonedGym/scripts.pory"
WalkAway:
# 102 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 103 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	step_end

FlottTown_AbandonedGym_BeforeEvent_Text_0:
# 16 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "This place seems pretty rundown. You\n"
	.string "should probably leave for now.$"

FlottTown_AbandonedGym_OnFrame_Text_0:
# 33 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "ELSIE: Huh, this gym is pretty run down.\n"
	.string "I wonder what's inside?$"

FlottTown_AbandonedGym_OnFrame_Text_1:
# 34 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "Elsie decided to follow you!$"

FlottTown_AbandonedGym_EventScript_FreePokeball_Text_0:
# 50 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "It's a Pokéball! It seems there's no\n"
	.string "Pokémon inside it, though.$"

FlottTown_AbandonedGym_EventScript_GymCollapses_Text_0:
# 71 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "ELSIE: {PLAYER}! Watch out!$"

FlottTown_AbandonedGym_ElsieFollowerScript_Text_0:
# 86 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "ELSIE: I wonder what's inside? There\n"
	.string "must be something interesting deeper\l"
	.string "in.$"

FlottTown_AbandonedGym_ElsieFollowerScript_Text_1:
# 90 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "ELSIE: What'cha waiting for? Let's get\n"
	.string "outta here!\p"
	.string "Once we get home, I can cook you up a\n"
	.string "hamburg steak.$"

FlottTown_AbandonedGym_Text_LetsStayUp:
# 106 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "ELSIE: A ladder? Hmm...let's not go down\n"
	.string "there.$"

FlottTown_AbandonedGym_Text_BeforeCollapse:
# 110 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "ELSIE: Huh, it's just a Pokéball. Will you\n"
	.string "ever use it, though?\p"
	.string "There doesn't seem to be anything else\n"
	.string "in here though. We'd best get home.$"
