# 1 "data/maps/FlottTown_FlottCave/scripts.pory"

# 2 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_ZUBAT, 1
# 3 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_MANKEY, 2
# 4 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_TINKATINK, 3
# 5 "data/maps/FlottTown_FlottCave/scripts.pory"
.set LOCALID_TEDDIURSA, 4

FlottTown_FlottCave_MapScripts::
# 9 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_FlottCave_OnTransition
# 10 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 6, FlottTown_FlottCave_OnFrame
	.2byte 0


FlottTown_FlottCave_OnTransition::
# 16 "data/maps/FlottTown_FlottCave/scripts.pory"
	destroyfollower
# 17 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_TEMP_5
	return


FlottTown_FlottCave_OnFrame::
# 21 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_ElsieWorried, MSGBOX_DEFAULT
# 22 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 23 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_FALLEN_INTO_CAVE
# 24 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 7
	end


FlottTown_FlottCave_EventScript_ZubatAttacks::
# 29 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0
# 30 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmessage
# 31 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 32 "data/maps/FlottTown_FlottCave/scripts.pory"
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
# 33 "data/maps/FlottTown_FlottCave/scripts.pory"
	waitmoncry
# 34 "data/maps/FlottTown_FlottCave/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 35 "data/maps/FlottTown_FlottCave/scripts.pory"
	subvar VAR_TEMP_0, 2
# 36 "data/maps/FlottTown_FlottCave/scripts.pory"
	subvar VAR_TEMP_1, 2
# 37 "data/maps/FlottTown_FlottCave/scripts.pory"
	setobjectxy LOCALID_ZUBAT, VAR_TEMP_0, VAR_TEMP_1
	return


FlottTown_FlottCave_EventScript_SavedByStarter::
# 42 "data/maps/FlottTown_FlottCave/scripts.pory"
	compare VAR_TEMP_2, 30
	goto_if_eq FlottTown_FlottCave_EventScript_SavedByStarter_1
	return

FlottTown_FlottCave_EventScript_SavedByStarter_1:
	return


FlottTown_FlottCave_EventScript_ZubatAttacks_Text_0:
# 29 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "As you walk inside the dark cave, you\n"
	.string "hear a noise coming from the darkness!$"

FlottTown_FlottCave_Text_ElsieWorried::
# 48 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: Oh my god! {PLAYER}! Are you\n"
	.string "okay?! Sit tight in there, okay? I'll go\l"
	.string "get help!\p"
	.string "You here the footsteps of your sister\n"
	.string "exiting the gym.$"
