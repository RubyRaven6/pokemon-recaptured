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
	map_script_2 VAR_FLOTT_TOWN_STATE, 3, FlottTown_AbandonedGym_Setup
	.2byte 0


FlottTown_AbandonedGym_Setup::
# 13 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_AbandonedGym_WalkingUp1
# 14 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmovement 0
# 15 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	clearflag FLAG_ELSIE_ENTERS
# 16 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	addobject LOCALID_ELSIE
# 17 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FlottTown_AbandonedGym_WalkingUp2
# 18 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement LOCALID_ELSIE, FlottTown_AbandonedGym_WalkingUp3
# 19 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmovement LOCALID_ELSIE
# 20 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 21 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 4
	end


FlottTown_AbandonedGym_FreePokeball::
# 26 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_Text_FreePokeball, MSGBOX_AUTOCLOSE
# 27 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	removeobject LOCALID_BALL, MAP_FLOTT_TOWN_ABANDONED_GYM
# 28 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	giveitem ITEM_POKE_BALL, 1
# 29 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 5
# 30 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
	end


FlottTown_AbandonedGym_Elsie::
# 35 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	faceplayer
# 36 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_Text_ThisPlaceIsCool, MSGBOX_DEFAULT
# 37 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
	return


FlottTown_AbandonedGym_AfterBallPickup::
# 41 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement LOCALID_ELSIE, FlottTown_AbandonedGym_GoToPlayer
# 42 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitmessage
# 43 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	msgbox FlottTown_AbandonedGym_Text_BeforeCollapse, MSGBOX_DEFAULT
# 44 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	waitbuttonpress
# 45 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	closemessage
# 46 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	goto FlottTown_AbandonedGym_GymCollapses
	return


FlottTown_AbandonedGym_GymCollapses::
# 50 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	applymovement LOCALID_ELSIE, FlottTown_AbandonedGym_WalkingOut
# 51 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 6
# 52 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	setmetatile 13, 18, METATILE_MirageTower_MirageTower_CrackedFloorHole, FALSE
	return


# 55 "data/maps/FlottTown_AbandonedGym/scripts.pory"
FlottTown_AbandonedGym_WalkingUp1:
# 56 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
	step_end

# 59 "data/maps/FlottTown_AbandonedGym/scripts.pory"
FlottTown_AbandonedGym_WalkingUp2:
# 60 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 60 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 60 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 60 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 60 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 61 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 61 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 61 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 61 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 62 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 62 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
	step_end

# 65 "data/maps/FlottTown_AbandonedGym/scripts.pory"
FlottTown_AbandonedGym_WalkingUp3:
# 66 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 66 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 66 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 66 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 66 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 66 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 67 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 67 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 67 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 68 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 69 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 69 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
	step_end

# 72 "data/maps/FlottTown_AbandonedGym/scripts.pory"
FlottTown_AbandonedGym_GoToPlayer:
# 73 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_left
# 74 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 74 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 74 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
# 74 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_up
	step_end

# 77 "data/maps/FlottTown_AbandonedGym/scripts.pory"
FlottTown_AbandonedGym_WalkingOut:
# 78 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	walk_down
	step_end

FlottTown_AbandonedGym_Text_FreePokeball::
# 81 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "It's a Pokéball! It seems there's no\n"
	.string "Pokémon inside it, though.$"

FlottTown_AbandonedGym_Text_ThisPlaceIsCool::
# 85 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "This place seems pretty cool! Sad it\n"
	.string "seems abandoned, though.$"

FlottTown_AbandonedGym_Text_BeforeCollapse::
# 89 "data/maps/FlottTown_AbandonedGym/scripts.pory"
	.string "Oh hey, a Pokéball! Maybe you can catch\n"
	.string "your own Pokémon with that someday?\p"
	.string "There doesn't seem to be anything else\n"
	.string "in here though. We'd best get home.$"
