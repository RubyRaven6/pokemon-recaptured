FlottTown_ShipHallway_MapScripts::
# 2 "data/maps/FlottTown_ShipHallway/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_ShipHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_ShipHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/FlottTown_ShipHallway/scripts.pory"
	map_script_2 VAR_BOAT_DEPARTED, 0, FlottTown_ShipHallway_EventScript_MomLeaves
	.2byte 0


FlottTown_ShipHallway_EventScript_MomLeaves::
# 8 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtMom
# 9 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement 2, MomLooks
# 10 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmovement 0
# 11 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_LetsGoChild, MSGBOX_DEFAULT
# 12 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmessage
# 13 "data/maps/FlottTown_ShipHallway/scripts.pory"
	closemessage
# 14 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement 2, MomExits
# 15 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmovement 0
# 16 "data/maps/FlottTown_ShipHallway/scripts.pory"
	removeobject 2
# 17 "data/maps/FlottTown_ShipHallway/scripts.pory"
	special DrawWholeMapView
# 18 "data/maps/FlottTown_ShipHallway/scripts.pory"
	setvar VAR_BOAT_DEPARTED, 1
	return


FlottTown_ShipHallway_EventScript_LowerStairway::
# 22 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_LowerStairway, MSGBOX_DEFAULT
# 23 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmessage
# 24 "data/maps/FlottTown_ShipHallway/scripts.pory"
	closemessage
# 25 "data/maps/FlottTown_ShipHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LowerStairway
# 26 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmovement 0
	return


FlottTown_ShipHallway_EventScript_Sailor::
# 30 "data/maps/FlottTown_ShipHallway/scripts.pory"
	lock
# 31 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_Sailor, MSGBOX_DEFAULT
# 32 "data/maps/FlottTown_ShipHallway/scripts.pory"
	waitmessage
# 33 "data/maps/FlottTown_ShipHallway/scripts.pory"
	closemessage
# 34 "data/maps/FlottTown_ShipHallway/scripts.pory"
	setvar VAR_BOAT_DEPARTED, 1
# 35 "data/maps/FlottTown_ShipHallway/scripts.pory"
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 5
	return


FlottTown_ShipHallway_GottaGo::
# 39 "data/maps/FlottTown_ShipHallway/scripts.pory"
	lockall
# 40 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_GottaGo, MSGBOX_DEFAULT
# 41 "data/maps/FlottTown_ShipHallway/scripts.pory"
	releaseall
	return


FlottTown_ShipHallway_LockedDoor::
# 45 "data/maps/FlottTown_ShipHallway/scripts.pory"
	lockall
# 46 "data/maps/FlottTown_ShipHallway/scripts.pory"
	msgbox FlottTown_ShipHallway_Text_LockedDoor, MSGBOX_DEFAULT
# 47 "data/maps/FlottTown_ShipHallway/scripts.pory"
	releaseall
	return


# 50 "data/maps/FlottTown_ShipHallway/scripts.pory"
LookAtMom:
# 51 "data/maps/FlottTown_ShipHallway/scripts.pory"
	face_left
	step_end

# 54 "data/maps/FlottTown_ShipHallway/scripts.pory"
LowerStairway:
# 55 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 55 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
	step_end

# 58 "data/maps/FlottTown_ShipHallway/scripts.pory"
MomLooks:
# 59 "data/maps/FlottTown_ShipHallway/scripts.pory"
	face_right
	step_end

# 62 "data/maps/FlottTown_ShipHallway/scripts.pory"
MomExits:
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
# 63 "data/maps/FlottTown_ShipHallway/scripts.pory"
	walk_left
	step_end

FlottTown_ShipHallway_Text_LetsGoChild::
# 66 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "Oh, {PLAYER}! You're finally up. Just\n"
	.string "in time, too. We're finally at Flott Town!\l"
	.string "Let's get off before the boat departs.$"

FlottTown_ShipHallway_Text_GottaGo::
# 70 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "No need to go back. We need to get off\n"
	.string "the ship!$"

FlottTown_ShipHallway_Text_LowerStairway::
# 74 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "I don't think I can pass through there.$"

FlottTown_ShipHallway_Text_LockedDoor::
# 78 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "The door's locked.$"

FlottTown_ShipHallway_Text_Sailor::
# 82 "data/maps/FlottTown_ShipHallway/scripts.pory"
	.string "We've arrived at Flott Town! Thank you\n"
	.string "for sailing with the S.S. Tidal.$"
