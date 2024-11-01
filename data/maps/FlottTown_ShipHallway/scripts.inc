FlottTown_ShipHallway_MapScripts::
# 2 "data/maps/FlottTown_ShipHallway/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_ShipHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_ShipHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/FlottTown_ShipHallway/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 1, FlottTown_ShipHallway_EventScript_ElsieLeaves
	.2byte 0


FlottTown_ShipHallway_EventScript_ElsieLeaves::
# 8 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtElsie
# 9 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement 2, ElsieLooks
# 10 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmovement 0
# 11 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_LetsGoChild, MSGBOX_DEFAULT
# 12 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmessage
# 13 "data/maps/FlottTown_ShipHallway/scripts.pory"
	closemessage
# 14 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement 2, ElsieExits
# 15 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmovement 0
# 16 "data/maps/FlottTown_ShipHallway/scripts.pory"
	removeobject 2
# 17 "data/maps/FlottTown_ShipHallway/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, FLOTT_TOWN_EXITED_CABIN
	return


FlottTown_ShipHallway_EventScript_LowerStairway::
# 21 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_LowerStairway, MSGBOX_DEFAULT
# 22 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmessage
# 23 "data/maps/FlottTown_ShipHallway/scripts.pory"
	closemessage
# 24 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LowerStairway
# 25 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmovement 0
	return


FlottTown_ShipHallway_EventScript_Sailor::
# 29 "data/maps/FlottTown_ShipHallway/scripts.pory"
	lock
# 30 "data/maps/FlottTown_ShipHallway/scripts.pory"
	faceplayer
# 31 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_Sailor, MSGBOX_DEFAULT
# 32 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmessage
# 33 "data/maps/FlottTown_ShipHallway/scripts.pory"
	closemessage
# 34 "data/maps/FlottTown_ShipHallway/scripts.pory"
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 5
	return


FlottTown_ShipHallway_GottaGo::
# 38 "data/maps/FlottTown_ShipHallway/scripts.pory"
	lockall
# 39 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_GottaGo, MSGBOX_DEFAULT
# 40 "data/maps/FlottTown_ShipHallway/scripts.pory"
	releaseall
	return


FlottTown_ShipHallway_LockedDoor::
# 44 "data/maps/FlottTown_ShipHallway/scripts.pory"
	lockall
# 45 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_LockedDoor, MSGBOX_DEFAULT
# 46 "data/maps/FlottTown_ShipHallway/scripts.pory"
	releaseall
	return


# 49 "data/maps/FlottTown_ShipHallway/scripts.pory"
LookAtElsie:
# 50 "data/maps/FlottTown_ShipHallway/scripts.pory"
	face_left
	step_end

# 53 "data/maps/FlottTown_ShipHallway/scripts.pory"
LowerStairway:
# 54 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
	step_end

# 57 "data/maps/FlottTown_ShipHallway/scripts.pory"
ElsieLooks:
# 58 "data/maps/FlottTown_ShipHallway/scripts.pory"
	face_right
	step_end

# 61 "data/maps/FlottTown_ShipHallway/scripts.pory"
ElsieExits:
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
	step_end

FlottTown_ShipHallway_Text_LetsGoChild::
# 65 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "ELSIE: Oh, {PLAYER}! You're finally up.\n"
	.string "Just in time, too. We're finally at Flott\l"
	.string "Town! Let's get off before the boat\l"
	.string "departs.$"

FlottTown_ShipHallway_Text_GottaGo::
# 69 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "No need to go back. We need to get off\n"
	.string "the ship!$"

FlottTown_ShipHallway_Text_LowerStairway::
# 73 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "I don't think I can pass through there.$"

FlottTown_ShipHallway_Text_LockedDoor::
# 77 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "The door's locked.$"

FlottTown_ShipHallway_Text_Sailor::
# 81 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "We've arrived at Flott Town! Thank you\n"
	.string "for sailing with the S.S. Tidal.$"
