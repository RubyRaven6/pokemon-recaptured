
.set LOCALID_ELSIE, 1
.set LOCALID_BALL, 2

FlottTown_AbandonedGym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_AbandonedGym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_AbandonedGym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FLOTT_TOWN_STATE, 2, FlottTown_AbandonedGym_BeforeEvent
	map_script_2 VAR_FLOTT_TOWN_STATE, 3, FlottTown_AbandonedGym_OnFrame
	.2byte 0


FlottTown_AbandonedGym_BeforeEvent::
	setflag FLAG_ELSIE_ENTERS_GYM
	setflag FLAG_VISITED_GYM
	msgbox FlottTown_AbandonedGym_BeforeEvent_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	warp MAP_FLOTT_TOWN, 9, 25
	waitstate
	return


FlottTown_AbandonedGym_OnFrame::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_AbandonedGym_WalkingIn
	waitmovement 0
	clearflag FLAG_ELSIE_ENTERS_GYM
	addobject LOCALID_ELSIE
	applymovement LOCALID_ELSIE, Common_Movement_FaceUp
	lock
	waitmovement LOCALID_ELSIE
	msgbox FlottTown_AbandonedGym_OnFrame_Text_0, MSGBOX_DEFAULT
	msgbox FlottTown_AbandonedGym_OnFrame_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setfollower LOCALID_ELSIE, FOLLOWER_ALL, FlottTown_AbandonedGym_ElsieFollowerScript, 0
	setvar VAR_FLOTT_TOWN_STATE, 4
	end


FlottTown_AbandonedGym_LadderStopper::
	msgbox FlottTown_AbandonedGym_Text_LetsStayUp, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkAway
	return


FlottTown_AbandonedGym_EventScript_FreePokeball::
	msgbox FlottTown_AbandonedGym_EventScript_FreePokeball_Text_0, MSGBOX_AUTOCLOSE
	removeobject LOCALID_BALL, MAP_FLOTT_TOWN_ABANDONED_GYM
	giveitem ITEM_POKE_BALL, 1
	setvar VAR_FLOTT_TOWN_STATE, 5
	closemessage
	msgbox FlottTown_AbandonedGym_Text_BeforeCollapse, MSGBOX_NPC
	waitmessage
	closemessage
	end


FlottTown_AbandonedGym_EventScript_GymCollapses::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FacePlayer
	setmetatile 12, 17, METATILE_Cave_CrackedFloor, FALSE
	setmetatile 13, 17, METATILE_Cave_CrackedFloor, FALSE
	setmetatile 14, 17, METATILE_Cave_CrackedFloor, FALSE
	setmetatile 12, 18, METATILE_Cave_CrackedFloor, FALSE
	setmetatile 13, 18, METATILE_Cave_CrackedFloor, FALSE
	setmetatile 14, 18, METATILE_Cave_CrackedFloor, FALSE
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_FOLLOW_ME, Common_Movement_FacePlayer
	msgbox FlottTown_AbandonedGym_EventScript_GymCollapses_Text_0
	setmetatile 12, 17, METATILE_Cave_CrackedFloor_Hole, FALSE
	setmetatile 13, 17, METATILE_Cave_CrackedFloor_Hole, FALSE
	setmetatile 14, 17, METATILE_Cave_CrackedFloor_Hole, FALSE
	setmetatile 12, 18, METATILE_Cave_CrackedFloor_Hole, FALSE
	setmetatile 13, 18, METATILE_Cave_CrackedFloor_Hole, FALSE
	setmetatile 14, 18, METATILE_Cave_CrackedFloor_Hole, FALSE
	warphole MAP_FLOTT_TOWN_FLOTT_CAVE
	special DrawWholeMapView
	setvar VAR_FLOTT_TOWN_STATE, 6
	return


FlottTown_AbandonedGym_ElsieFollowerScript::
	facefollower
	compare VAR_FLOTT_TOWN_STATE, 4
	goto_if_eq FlottTown_AbandonedGym_ElsieFollowerScript_1
	msgbox FlottTown_AbandonedGym_ElsieFollowerScript_Text_1
	closemessage
	return

FlottTown_AbandonedGym_ElsieFollowerScript_1:
	msgbox FlottTown_AbandonedGym_ElsieFollowerScript_Text_0
	closemessage
	return


FlottTown_AbandonedGym_WalkingIn:
	walk_left
	face_up
	step_end

WalkAway:
	walk_left
	step_end

FlottTown_AbandonedGym_BeforeEvent_Text_0:
	.string "This place seems pretty rundown. You\n"
	.string "should probably leave for now.$"

FlottTown_AbandonedGym_OnFrame_Text_0:
	.string "ELSIE: Huh, this gym is pretty run down.\n"
	.string "I wonder what's inside?$"

FlottTown_AbandonedGym_OnFrame_Text_1:
	.string "Elsie decided to follow you!$"

FlottTown_AbandonedGym_EventScript_FreePokeball_Text_0:
	.string "It's a Pokéball! It seems there's no\n"
	.string "Pokémon inside it, though.$"

FlottTown_AbandonedGym_EventScript_GymCollapses_Text_0:
	.string "ELSIE: {PLAYER}! Watch out!$"

FlottTown_AbandonedGym_ElsieFollowerScript_Text_0:
	.string "ELSIE: I wonder what's inside? There\n"
	.string "must be something interesting deeper\l"
	.string "in.$"

FlottTown_AbandonedGym_ElsieFollowerScript_Text_1:
	.string "ELSIE: What'cha waiting for? Let's get\n"
	.string "outta here!\p"
	.string "Once we get home, I can cook you up a\n"
	.string "hamburg steak.$"

FlottTown_AbandonedGym_Text_LetsStayUp:
	.string "ELSIE: A ladder? Hmm...let's not go down\n"
	.string "there.$"

FlottTown_AbandonedGym_Text_BeforeCollapse:
	.string "ELSIE: Huh, it's just a Pokéball. Will you\n"
	.string "ever use it, though?\p"
	.string "There doesn't seem to be anything else\n"
	.string "in here though. We'd best get home.$"