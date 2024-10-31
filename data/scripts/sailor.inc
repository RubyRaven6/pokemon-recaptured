SSTidal_Harbor_EventScript_SailorWarpScript::
# 4 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_0, MSGBOX_DEFAULT
# 5 "data/scripts/sailor.pory"
	checkitem ITEM_JOURNAL
# 6 "data/scripts/sailor.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_2
SSTidal_Harbor_EventScript_SailorWarpScript_1:
# 11 "data/scripts/sailor.pory"
	dynmultistack 16, 0, FALSE, 10, TRUE, 0, DYN_MULTICHOICE_CB_NONE
# 12 "data/scripts/sailor.pory"
	switch VAR_RESULT
# 13 "data/scripts/sailor.pory"
	case 0, SSTidal_Harbor_EventScript_SailorWarpScript_5
# 21 "data/scripts/sailor.pory"
	case 1, SSTidal_Harbor_EventScript_SailorWarpScript_6
# 29 "data/scripts/sailor.pory"
	case 4, SSTidal_Harbor_EventScript_SailorWarpScript_7
	return

SSTidal_Harbor_EventScript_SailorWarpScript_2:
# 7 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_1, 0
# 8 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_2, 1
# 9 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_3, 2
	goto SSTidal_Harbor_EventScript_SailorWarpScript_1

SSTidal_Harbor_EventScript_SailorWarpScript_5:
# 14 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 0
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_8
# 19 "data/scripts/sailor.pory"
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 11
	return

SSTidal_Harbor_EventScript_SailorWarpScript_6:
# 22 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 1
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_11
# 27 "data/scripts/sailor.pory"
	warp MAP_DOCKSIDE_CITY_PORT, 8, 11
	return

SSTidal_Harbor_EventScript_SailorWarpScript_7:
# 30 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 4
	goto_if_eq SSTidal_Harbor_EventScript_SailorWarpScript_14
# 35 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_5, MSGBOX_DEFAULT
# 36 "data/scripts/sailor.pory"
	closemessage
	return

SSTidal_Harbor_EventScript_SailorWarpScript_8:
# 15 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 16 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return

SSTidal_Harbor_EventScript_SailorWarpScript_11:
# 23 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 24 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return

SSTidal_Harbor_EventScript_SailorWarpScript_14:
# 31 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 32 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return


PlayerSelectsSameTown:
# 42 "data/scripts/sailor.pory"
	msgbox PlayerSelectsSameTown_Text_0, MSGBOX_DEFAULT
# 43 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_1, 0
# 44 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_2, 1
# 45 "data/scripts/sailor.pory"
	dynmultipush SSTidal_Harbor_EventScript_SailorWarpScript_Text_3, 2
# 46 "data/scripts/sailor.pory"
	dynmultistack 16, 0, FALSE, 10, TRUE, 0, DYN_MULTICHOICE_CB_NONE
# 47 "data/scripts/sailor.pory"
	switch VAR_RESULT
# 48 "data/scripts/sailor.pory"
	case 0, PlayerSelectsSameTown_2
# 56 "data/scripts/sailor.pory"
	case 1, PlayerSelectsSameTown_3
# 64 "data/scripts/sailor.pory"
	case 4, PlayerSelectsSameTown_4
	return

PlayerSelectsSameTown_2:
# 49 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 0
	goto_if_eq PlayerSelectsSameTown_5
# 54 "data/scripts/sailor.pory"
	warp MAP_FLOTT_TOWN_INSIDE_HARBOR, 8, 4
	return

PlayerSelectsSameTown_3:
# 57 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 1
	goto_if_eq PlayerSelectsSameTown_8
# 62 "data/scripts/sailor.pory"
	warp MAP_DOCKSIDE_CITY_PORT, 8, 11
	return

PlayerSelectsSameTown_4:
# 65 "data/scripts/sailor.pory"
	compare VAR_DOCKED_CITY, 4
	goto_if_eq PlayerSelectsSameTown_11
# 70 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_5, MSGBOX_DEFAULT
# 71 "data/scripts/sailor.pory"
	closemessage
	return

PlayerSelectsSameTown_5:
# 50 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 51 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return

PlayerSelectsSameTown_8:
# 58 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 59 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return

PlayerSelectsSameTown_11:
# 66 "data/scripts/sailor.pory"
	msgbox SSTidal_Harbor_EventScript_SailorWarpScript_Text_4, MSGBOX_DEFAULT
# 67 "data/scripts/sailor.pory"
	call PlayerSelectsSameTown
	return


SSTidal_Harbor_EventScript_SailorWarpScript_Text_0:
# 4 "data/scripts/sailor.pory"
	.string "Ahoy! Where do you want to go to today?$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_1:
# 7 "data/scripts/sailor.pory"
	.string "Flott Town$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_2:
# 8 "data/scripts/sailor.pory"
	.string "Dockside City$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_3:
# 9 "data/scripts/sailor.pory"
	.string "Mountport$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_4:
# 15 "data/scripts/sailor.pory"
	.string "But…we're already here?$"

SSTidal_Harbor_EventScript_SailorWarpScript_Text_5:
# 35 "data/scripts/sailor.pory"
	.string "Test$"

PlayerSelectsSameTown_Text_0:
# 42 "data/scripts/sailor.pory"
	.string "Where do you want to go to today?$"
