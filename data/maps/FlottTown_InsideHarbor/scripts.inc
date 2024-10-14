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


# 16 "data/maps/FlottTown_InsideHarbor/scripts.pory"
LookAtBoat:
# 17 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	face_down
	step_end

# 20 "data/maps/FlottTown_InsideHarbor/scripts.pory"
BoatDeparts:
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 21 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 22 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 22 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 22 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
# 22 "data/maps/FlottTown_InsideHarbor/scripts.pory"
	walk_left
	step_end
