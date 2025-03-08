DocksideCity_Port_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DocksideCity_Port_OnLoad
	.byte 0


DocksideCity_Port_OnLoad:
	setvar VAR_DOCKED_CITY, 1
	return

