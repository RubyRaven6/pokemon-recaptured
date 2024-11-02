FlottTown_ShipCabin_MapScripts::
# 2 "data/maps/FlottTown_ShipCabin/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_ShipCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_ShipCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/FlottTown_ShipCabin/scripts.pory"
	map_script_2 VAR_FLOTT_TOWN_STATE, 0, FlottTown_ShipCabin_OnFrame
	.2byte 0


FlottTown_ShipCabin_OnFrame:
# 9 "data/maps/FlottTown_ShipCabin/scripts.pory"
	delay 120
# 10 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_WokeUpLikeThis, MSGBOX_DEFAULT
# 11 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 12 "data/maps/FlottTown_ShipCabin/scripts.pory"
	call FlottTown_ShipCabin_EventScript_SetClock
# 13 "data/maps/FlottTown_ShipCabin/scripts.pory"
	playse SE_DING_DONG
# 14 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_ThanksForSailing, MSGBOX_DEFAULT
# 15 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 16 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
# 17 "data/maps/FlottTown_ShipCabin/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 1
	return


FlottTown_ShipCabin_ElsieBed::
# 21 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_ElsieBed, MSGBOX_SIGN
# 22 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 23 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
	return


FlottTown_ShipCabin_Bed::
# 27 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_Bed, MSGBOX_SIGN
# 28 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 29 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
	return


FlottTown_ShipCabin_Trash::
# 33 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_Trash, MSGBOX_SIGN
# 34 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitmessage
# 35 "data/maps/FlottTown_ShipCabin/scripts.pory"
	closemessage
	return


FlottTown_ShipCabin_EventScript_SetClock::
# 39 "data/maps/FlottTown_ShipCabin/scripts.pory"
	fadescreen FADE_TO_BLACK
# 40 "data/maps/FlottTown_ShipCabin/scripts.pory"
	special StartWallClock
# 41 "data/maps/FlottTown_ShipCabin/scripts.pory"
	waitstate
	return


FlottTown_ShipCabin_Text_Bed:
# 44 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "It's your bed!$"

FlottTown_ShipCabin_Text_ElsieBed:
# 48 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "It's your sister's bed.$"

FlottTown_ShipCabin_Text_Trash:
# 52 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "Just some trash.$"

FlottTown_ShipCabin_Text_ThanksForSailing:
# 56 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "P.A.: Attention, passengers. We've now\n"
	.string "arrived at Flott Town.\l"
	.string "Kindly disembark from the vessel in an\l"
	.string "orderly manner.\l"
	.string "Thank you for sailing with the S.S.\l"
	.string "Tidal.$"

FlottTown_ShipCabin_Text_WokeUpLikeThis:
# 61 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "Yawn…\p"
	.string "That was a nice trip… and an even\n"
	.string "better dream.\p"
	.string "What time is it anyway?$"
