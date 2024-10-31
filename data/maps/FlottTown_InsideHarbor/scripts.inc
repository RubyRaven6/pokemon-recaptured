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
	return

FlottTown_InsideHarbor_OnLoad_2:
# 8 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setflag FLAG_FLOTT_HARBOR_SAILOR
	goto FlottTown_InsideHarbor_OnLoad_1


FlottTown_InsideHarbor_EventScript_BoatLeaves::
# 16 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	lockall
# 17 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtBoat
# 18 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	waitmovement 0
# 19 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	applymovement 1, BoatDeparts
# 20 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	waitmovement 0
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	hideobjectat 1, MAP_FLOTT_TOWN_INSIDE_HARBOR
# 22 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setflag FLAG_BOAT_DEPARTS
# 23 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 2
# 24 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	release
	return


# 29 "data/maps/FlottTown_InsideHarbor/scripts.pory"
LookAtBoat:
# 30 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	face_down
	step_end

# 33 "data/maps/FlottTown_InsideHarbor/scripts.pory"
BoatDeparts:
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 34 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 35 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 35 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 35 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 35 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
	step_end
