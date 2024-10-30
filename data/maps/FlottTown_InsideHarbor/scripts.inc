FlottTown_InsideHarbor_MapScripts::
	.byte 0


FlottTown_InsideHarbor_EventScript_BoatLeaves::
# 5 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	lockall
# 6 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LookAtBoat
# 7 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	waitmovement 0
# 8 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	applymovement 1, BoatDeparts
# 9 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	waitmovement 0
# 10 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	hideobjectat 1, MAP_FLOTT_TOWN_INSIDE_HARBOR
# 11 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setflag FLAG_BOAT_DEPARTS
# 12 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 2
# 13 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	release
	return


FlottTown_InsideHarbor_TempTeleporter::
# 17 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	warp MAP_DOCKSIDE_CITY, 38, 18
	return


# 20 "data/maps/FlottTown_InsideHarbor/scripts.pory"
LookAtBoat:
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	face_down
	step_end

# 24 "data/maps/FlottTown_InsideHarbor/scripts.pory"
BoatDeparts:
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 25 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 26 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 26 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 26 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 26 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
	step_end
