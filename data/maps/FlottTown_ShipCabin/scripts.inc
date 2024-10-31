FlottTown_ShipCabin_MapScripts::
# 2 "data/maps/FlottTown_ShipCabin/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FlottTown_ShipCabin_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

FlottTown_ShipCabin_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/FlottTown_ShipCabin/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 0, FlottTown_ShipCabin_OnLoad
	.2byte 0


FlottTown_ShipCabin_OnLoad:
# 9 "data/maps/FlottTown_ShipCabin/scripts.pory"
	call FlottTown_ShipCabin_Clock
	return


FlottTown_ShipCabin_ElsieBed::
# 13 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_ElsieBed, MSGBOX_SIGN
# 14 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 15 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
	return


FlottTown_ShipCabin_Bed::
# 19 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_Bed, MSGBOX_SIGN
# 20 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 21 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
	return


FlottTown_ShipCabin_Trash::
# 25 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_Trash, MSGBOX_SIGN
# 26 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 27 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
	return


FlottTown_ShipCabin_Clock:
# 31 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Clock_Text_0, MSGBOX_DEFAULT
# 32 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 33 "data/maps/FlottTown_ShipCabin/scripts.pory"
	call FlottTown_ShipCabin_EventScript_SetClock
# 34 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Clock_Text_1, MSGBOX_DEFAULT
# 35 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 36 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
	return


FlottTown_ShipCabin_EventScript_SetClock::
# 40 "data/maps/FlottTown_ShipCabin/scripts.pory"
	fadescreen FADE_TO_BLACK
# 41 "data/maps/FlottTown_ShipCabin/scripts.pory"
	special StartWallClock
# 42 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitstate
	return


FlottTown_ShipCabin_Clock_Text_0:
# 31 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "That was quite the trip… What time is it\n"
	.string "anyway?$"

FlottTown_ShipCabin_Clock_Text_1:
# 34 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "P.A.: Attention, passengers. We've now\n"
	.string "arrived at Flott Town. Kindly disembark\l"
	.string "from the vessel in an orderly manner.\l"
	.string "Thank you for sailing with the S.S.\l"
	.string "Tidal.$"

FlottTown_ShipCabin_Text_Bed:
# 45 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "It's your bed!$"

FlottTown_ShipCabin_Text_ElsieBed:
# 49 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "It's your sister's bed.$"

FlottTown_ShipCabin_Text_Trash:
# 53 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "Just some trash.$"
