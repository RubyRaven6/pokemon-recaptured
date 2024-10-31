SSTidal_Harbor_EventScript_SailorWarpScript::
# 2 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_0, MSGBOX_DEFAULT
# 3 "data/scripts/sailor.pory"
	checkitem ITEM_JOURNAL
# 4 "data/scripts/sailor.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_2
SSTidal_Harbor_EventScript_SailorWarpScript_1:
# 9 "data/scripts/sailor.pory"
	dynmultistack 16, 0, FALSE, 10, TRUE, 0, DYN_MULTICHOICE_CB_NONE
# 10 "data/scripts/sailor.pory"
	switch VAR_RESULT
# 11 "data/scripts/sailor.pory"
	case 0, SSTidal_Harbor_EventScript_SailorWarpScript_5
# 19 "data/scripts/sailor.pory"
	case 1, SSTidal_Harbor_EventScript_SailorWarpScript_6
# 27 "data/scripts/sailor.pory"
	case 2, SSTidal_Harbor_EventScript_SailorWarpScript_7
	return

SSTidal_Harbor_EventScript_SailorWarpScript_2:
# 5 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_1, 0
# 6 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_2, 1
# 7 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_3, 2
	goto SSTidal_Harbor_EventScript_SailorWarpScript_1

SSTidal_Harbor_EventScript_SailorWarpScript_5:
# 12 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 0
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_8
# 17 "data/scripts/sailor.pory"
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 11
	return

SSTidal_Harbor_EventScript_SailorWarpScript_6:
# 20 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 1
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_11
# 25 "data/scripts/sailor.pory"
	warp MAP_DOCKSIDE_CITY_PORT, 8, 11
	return

SSTidal_Harbor_EventScript_SailorWarpScript_7:
# 28 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_5, MSGBOX_DEFAULT
# 29 "data/scripts/sailor.pory"
	closemessage
	return

SSTidal_Harbor_EventScript_SailorWarpScript_8:
# 13 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 14 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return

SSTidal_Harbor_EventScript_SailorWarpScript_11:
# 21 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 22 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return


PlayerSelectsSameTown:
# 34 "data/scripts/sailor.pory"
	msgbox PlayerSelectsSameTown_Text_0, MSGBOX_DEFAULT
# 35 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_1, 0
# 36 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_2, 1
# 37 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_3, 2
# 38 "data/scripts/sailor.pory"
	dynmultistack 16, 0, FALSE, 10, TRUE, 0, DYN_MULTICHOICE_CB_NONE
# 39 "data/scripts/sailor.pory"
	switch VAR_RESULT
# 40 "data/scripts/sailor.pory"
	case 0, PlayerSelectsSameTown_2
# 48 "data/scripts/sailor.pory"
	case 1, PlayerSelectsSameTown_3
# 56 "data/scripts/sailor.pory"
	case 2, PlayerSelectsSameTown_4
	return

PlayerSelectsSameTown_2:
# 41 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 0
	goto_if_eq PlayerSelectsSameTown_5
# 46 "data/scripts/sailor.pory"
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 4
	return

PlayerSelectsSameTown_3:
# 49 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 1
	goto_if_eq PlayerSelectsSameTown_8
# 54 "data/scripts/sailor.pory"
	warp MAP_DOCKSIDE_CITY_PORT, 8, 11
	return

PlayerSelectsSameTown_4:
# 57 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_5, MSGBOX_DEFAULT
# 58 "data/scripts/sailor.pory"
	closemessage
	return

PlayerSelectsSameTown_5:
# 42 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 43 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return

PlayerSelectsSameTown_8:
# 50 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 51 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return


SSTidal_Harbor_EventScript_SailorWarpScript_Text_0:
# 2 "data/scripts/sailor.pory"
	.string "Ahoy! Where do you want to go to today?$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_1:
# 5 "data/scripts/sailor.pory"
	.string "Flott Town$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_2:
# 6 "data/scripts/sailor.pory"
	.string "Dockside City$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_3:
# 7 "data/scripts/sailor.pory"
	.string "Mountport$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_4:
# 13 "data/scripts/sailor.pory"
	.string "But…we're already here?$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_5:
# 28 "data/scripts/sailor.pory"
	.string "Test$"

PlayerSelectsSameTown_Text_0:
# 34 "data/scripts/sailor.pory"
	.string "Where do you want to go to today?$"
