FlottTown_PlayerHouse_2F_MapScripts::
	.byte 0


FlottTown_PlayerHouse_2F_PlayerPC::
# 6 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
# 7 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 8 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	playse SE_PC_ON
# 9 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 10 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	special BedroomPC
# 11 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	waitstate
# 12 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	releaseall
	end


FlottTown_PlayerHouse_2F_EventScript_Map::
	return


FlottTown_PlayerHouse_2F_EventScript_TurnOffPlayerPC::
# 21 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
# 22 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 23 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 24 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	releaseall
	end


FlottTown_PlayerHouse_2F_ElsieDresser::
# 29 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_ElsieDresser_Text_0, MSGBOX_SIGN
	return


FlottTown_PlayerHouse_2F_PlayerDresser::
# 33 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_PlayerDresser_Text_0, MSGBOX_SIGN
	return


FlottTown_PlayerHouse_2F_FinancialBooks::
# 37 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_FinancialBooks_Text_0, MSGBOX_SIGN
	return


FlottTown_PlayerHouse_2F_Diary::
# 41 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Diary_Text_0, MSGBOX_SIGN
# 42 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	closemessage
	return


FlottTown_PlayerHouse_2F_SistersPC::
# 46 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Text_SistersPC, MSGBOX_SIGN
# 47 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	closemessage
	return


FlottTown_PlayerHouse_2F_ElsieDresser_Text_0:
# 29 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	.string "It's your sister's dresser.$"

FlottTown_PlayerHouse_2F_PlayerDresser_Text_0:
# 33 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	.string "It's your dresser.$"

FlottTown_PlayerHouse_2F_FinancialBooks_Text_0:
# 37 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	.string "It's a book of financial statements.$"

FlottTown_PlayerHouse_2F_Diary_Text_0:
# 41 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	.string "It's your journal.$"

FlottTown_PlayerHouse_2F_Text_SistersPC::
# 50 "data/maps/FlottTown_PlayerHouse_2F/scripts.pory"
	.string "It's your Sister's PC. It has a lot of\n"
	.string "documents about her classes and\l"
	.string "students.\l"
	.string "It's way too much information for you\l"
	.string "to really parse.\p"
	.string "$"
