SSTidal_Harbor_EventScript_SailorWarpScript::
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_0, MSGBOX_DEFAULT
	checkitem ITEM_JOURNAL
	compare VAR_RESULT, TRUE
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_2
SSTidal_Harbor_EventScript_SailorWarpScript_1:
	dynmultistack 16, 0, FALSE, 10, TRUE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, SSTidal_Harbor_EventScript_SailorWarpScript_5
	case 1, SSTidal_Harbor_EventScript_SailorWarpScript_6
	case 4, SSTidal_Harbor_EventScript_SailorWarpScript_7
	return

SSTidal_Harbor_EventScript_SailorWarpScript_2:
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_1, 0
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_2, 1
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_3, 2
	goto SSTidal_Harbor_EventScript_SailorWarpScript_1

SSTidal_Harbor_EventScript_SailorWarpScript_5:
	compare VAR_DOCKED_CITY, 0
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_8
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 11
	return

SSTidal_Harbor_EventScript_SailorWarpScript_6:
	compare VAR_DOCKED_CITY, 1
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_11
	warp MAP_DOCKSIDE_CITY_PORT, 8, 11
	return

SSTidal_Harbor_EventScript_SailorWarpScript_7:
	compare VAR_DOCKED_CITY, 4
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_14
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_5, MSGBOX_DEFAULT
	closemessage
	return

SSTidal_Harbor_EventScript_SailorWarpScript_8:
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
	call PlayerSelectsSameTown
	return

SSTidal_Harbor_EventScript_SailorWarpScript_11:
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
	call PlayerSelectsSameTown
	return

SSTidal_Harbor_EventScript_SailorWarpScript_14:
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
	call PlayerSelectsSameTown
	return


PlayerSelectsSameTown:
	msgbox PlayerSelectsSameTown_Text_0, MSGBOX_DEFAULT
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_1, 0
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_2, 1
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_3, 2
	dynmultistack 16, 0, FALSE, 10, TRUE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, PlayerSelectsSameTown_2
	case 1, PlayerSelectsSameTown_3
	case 4, PlayerSelectsSameTown_4
	return

PlayerSelectsSameTown_2:
	compare VAR_DOCKED_CITY, 0
	goto_if_eq PlayerSelectsSameTown_5
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 4
	return

PlayerSelectsSameTown_3:
	compare VAR_DOCKED_CITY, 1
	goto_if_eq PlayerSelectsSameTown_8
	warp MAP_DOCKSIDE_CITY_PORT, 8, 11
	return

PlayerSelectsSameTown_4:
	compare VAR_DOCKED_CITY, 4
	goto_if_eq PlayerSelectsSameTown_11
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_5, MSGBOX_DEFAULT
	closemessage
	return

PlayerSelectsSameTown_5:
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
	call PlayerSelectsSameTown
	return

PlayerSelectsSameTown_8:
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
	call PlayerSelectsSameTown
	return

PlayerSelectsSameTown_11:
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
	call PlayerSelectsSameTown
	return


SSTidal_Harbor_EventScript_SailorWarpScript_Text_0:
	.string "Ahoy! Where do you want to go to today?$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_1:
	.string "Flott Town$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_2:
	.string "Dockside City$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_3:
	.string "Mountport$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_4:
	.string "But…we're already here?$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_5:
	.string "Test$"

PlayerSelectsSameTown_Text_0:
	.string "Where do you want to go to today?$"
