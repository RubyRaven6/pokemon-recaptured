FlottTown_ShipCabin_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_ShipCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_ShipCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FLOTT_TOWN_STATE, 0, FlottTown_ShipCabin_OnFrame
	.2byte 0


FlottTown_ShipCabin_OnFrame:
	delay 120
	msgbox FlottTown_ShipCabin_Text_WokeUpLikeThis, MSGBOX_DEFAULT
	waitmessage
	playse SE_DING_DONG
	speakername FlottTown_ShipCabin_OnFrame_Text_0
	msgbox FlottTown_ShipCabin_Text_ThanksForSailing, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_FLOTT_TOWN_STATE, 1
	return


FlottTown_ShipCabin_ElsieBed::
	msgbox FlottTown_ShipCabin_Text_ElsieBed, MSGBOX_SIGN
	waitmessage
	closemessage
	return


FlottTown_ShipCabin_Bed::
	msgbox FlottTown_ShipCabin_Text_Bed, MSGBOX_SIGN
	waitmessage
	closemessage
	return


FlottTown_ShipCabin_Trash::
	msgbox FlottTown_ShipCabin_Text_Trash, MSGBOX_SIGN
	waitmessage
	closemessage
	return


FlottTown_ShipCabin_EventScript_SetClock::
	fadescreen FADE_TO_BLACK
	waitstate
	return


FlottTown_ShipCabin_OnFrame_Text_0:
	.string "P.A.$"

FlottTown_ShipCabin_Text_Bed:
	.string "It's your bed!$"

FlottTown_ShipCabin_Text_ElsieBed:
	.string "It's your sister's bed.$"

FlottTown_ShipCabin_Text_Trash:
	.string "Just some trash.$"

FlottTown_ShipCabin_Text_WokeUpLikeThis:
	.string "Yawn…\p"
	.string "That was a nice trip… and an even\n"
	.string "better dream.$"

FlottTown_ShipCabin_Text_ThanksForSailing:
	.string "Attention, passengers. We've now\n"
	.string "arrived at Flott Town.\l"
	.string "Kindly disembark from the vessel in an\l"
	.string "orderly manner.\p"
	.string "Thank you for sailing with the S.S.\n"
	.string "Tidal.$"
