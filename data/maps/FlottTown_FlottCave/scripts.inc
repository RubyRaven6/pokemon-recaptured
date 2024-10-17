FlottTown_FlottCave_MapScripts::
# 2 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FlottTown_FlottCave_OnTransition
# 3 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_FlottCave_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/FlottTown_FlottCave/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 6, FlottTown_FlottCave_OnFrame
	.2byte 0


FlottTown_FlottCave_OnTransition::
# 9 "data/maps/FlottTown_FlottCave/scripts.pory"
	destroyfollower
# 10 "data/maps/FlottTown_FlottCave/scripts.pory"
	setflag FLAG_TEMP_5
	return


FlottTown_FlottCave_OnFrame::
# 14 "data/maps/FlottTown_FlottCave/scripts.pory"
	msgbox FlottTown_FlottCave_Text_ElsieWorried, MSGBOX_DEFAULT
# 15 "data/maps/FlottTown_FlottCave/scripts.pory"
	closemessage
# 16 "data/maps/FlottTown_FlottCave/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 7
	return


FlottTown_FlottCave_Text_ElsieWorried::
# 19 "data/maps/FlottTown_FlottCave/scripts.pory"
	.string "ELSIE: Oh my god! {PLAYER}! Are you\n"
	.string "okay?! Sit tight in there, okay? I'll go\l"
	.string "get help!\p"
	.string "You here the footsteps of your sister\n"
	.string "exiting the gym.$"
