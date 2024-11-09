FlottTown_InsideHarbor_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FlottTown_InsideHarbor_OnLoad
	.byte 0


FlottTown_InsideHarbor_OnLoad:
	setflag FLAG_VISITED_FLOTT_TOWN
	setvar VAR_DOCKED_CITY, 0
	checkitem ITEM_JOURNAL
	compare VAR_RESULT, FALSE
	goto_if_eq FlottTown_InsideHarbor_OnLoad_2
	removeobject 1
FlottTown_InsideHarbor_OnLoad_1:
	compare VAR_FLOTT_TOWN_STATE, 2
	goto_if_eq FlottTown_InsideHarbor_OnLoad_5
	return

FlottTown_InsideHarbor_OnLoad_2:
	setflag FLAG_FLOTT_HARBOR_SAILOR
	addobject 1
	addobject 2
	goto FlottTown_InsideHarbor_OnLoad_1

FlottTown_InsideHarbor_OnLoad_5:
	setvar VAR_FLOTT_TOWN_STATE, 1
	return


FlottTown_InsideHarbor_EventScript_BoatLeaves::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LookAtBoat
	waitmovement 0
	applymovement 1, BoatDeparts
	waitmovement 0
	hideobjectat 1, MAP_FLOTT_TOWN_INSIDE_HARBOR
	setflag FLAG_BOAT_DEPARTS
	setvar VAR_FLOTT_TOWN_STATE, 2
	release
	return


LookAtBoat:
	face_down
	step_end

BoatDeparts:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
