FlottTown_ShipHallway_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_ShipHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_ShipHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FLOTT_TOWN_STATE, 1, FlottTown_ShipHallway_EventScript_ElsieLeaves
	.2byte 0


FlottTown_ShipHallway_EventScript_ElsieLeaves::
	applymovement OBJ_EVENT_ID_PLAYER, LookAtElsie
	applymovement 2, ElsieLooks
	waitmovement 0
	msgbox FlottTown_ShipHallway_Text_LetsGoChild, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 2, ElsieExits
	waitmovement 0
	removeobject 2
	setvar VAR_FLOTT_TOWN_STATE, FLOTT_TOWN_EXITED_CABIN
	return


FlottTown_ShipHallway_EventScript_LowerStairway::
	msgbox FlottTown_ShipHallway_Text_LowerStairway, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LowerStairway
	waitmovement 0
	return


FlottTown_ShipHallway_EventScript_Sailor::
	lock
	faceplayer
	msgbox FlottTown_ShipHallway_Text_Sailor, MSGBOX_DEFAULT
	waitmessage
	closemessage
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 5
	return


FlottTown_ShipHallway_GottaGo::
	lockall
	msgbox FlottTown_ShipHallway_Text_GottaGo, MSGBOX_DEFAULT
	releaseall
	return


FlottTown_ShipHallway_LockedDoor::
	lockall
	msgbox FlottTown_ShipHallway_Text_LockedDoor, MSGBOX_DEFAULT
	releaseall
	return


LookAtElsie:
	face_left
	step_end

LowerStairway:
	walk_left
	step_end

ElsieLooks:
	face_right
	step_end

ElsieExits:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FlottTown_ShipHallway_Text_LetsGoChild::
	.string "ELSIE: Oh, {PLAYER}! You're finally up.\n"
	.string "Just in time, too. We're finally at Flott\l"
	.string "Town! Let's get off before the boat\l"
	.string "departs.$"

FlottTown_ShipHallway_Text_GottaGo::
	.string "No need to go back. We need to get off\n"
	.string "the ship!$"

FlottTown_ShipHallway_Text_LowerStairway::
	.string "I don't think I can pass through there.$"

FlottTown_ShipHallway_Text_LockedDoor::
	.string "The door's locked.$"

FlottTown_ShipHallway_Text_Sailor::
	.string "We've arrived at Flott Town! Thank you\n"
	.string "for sailing with the S.S. Tidal.$"
