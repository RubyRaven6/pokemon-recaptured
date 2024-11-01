FlottTown_InsideHarbor_MapScripts::
# 2 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FlottTown_InsideHarbor_OnLoad
	.byte 0


FlottTown_InsideHarbor_OnLoad:
# 6 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	checkitem ITEM_JOURNAL
# 7 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FlottTown_InsideHarbor_OnLoad_2
FlottTown_InsideHarbor_OnLoad_1:
# 9 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setflag FLAG_VISITED_FLOTT_TOWN
# 10 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setvar VAR_DOCKED_CITY, 0
# 11 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	addobject 1
# 12 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	addobject 2
# 13 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 2
	goto_if_eq FlottTown_InsideHarbor_OnLoad_4
	return

FlottTown_InsideHarbor_OnLoad_2:
# 8 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setflag FLAG_FLOTT_HARBOR_SAILOR
	goto FlottTown_InsideHarbor_OnLoad_1

FlottTown_InsideHarbor_OnLoad_4:
# 14 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 1
	return


FlottTown_InsideHarbor_EventScript_BoatLeaves::
# 19 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	lockall
# 20 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtBoat
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	waitmovement 0
# 22 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	applymovement 1, BoatDeparts
# 23 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	waitmovement 0
# 24 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	hideobjectat 1, MAP_FLOTT_TOWN_INSIDE_HARBOR
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setflag FLAG_BOAT_DEPARTS
# 26 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 2
# 27 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	release
	return


# 32 "data/maps/FlottTown_InsideHarbor/scripts.pory"
LookAtBoat:
# 33 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	face_down
	step_end

# 36 "data/maps/FlottTown_InsideHarbor/scripts.pory"
BoatDeparts:
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 37 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 38 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 38 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 38 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 38 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
	step_end
