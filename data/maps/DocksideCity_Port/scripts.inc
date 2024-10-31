DocksideCity_Port_MapScripts::
# 2 "data/maps/DocksideCity_Port/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DocksideCity_Port_OnLoad
	.byte 0


DocksideCity_Port_OnLoad:
# 6 "data/maps/DocksideCity_Port/scripts.pory"
	setvar VAR_DOCKED_CITY, 1
	return

