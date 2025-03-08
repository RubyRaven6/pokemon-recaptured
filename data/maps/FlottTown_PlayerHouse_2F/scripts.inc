FlottTown_PlayerHouse_2F_MapScripts::
	.byte 0


FlottTown_PlayerHouse_2F_PlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end


FlottTown_PlayerHouse_2F_EventScript_Map::
	return


FlottTown_PlayerHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end


FlottTown_PlayerHouse_2F_ElsieDresser::
	msgbox FlottTown_PlayerHouse_2F_ElsieDresser_Text_0, MSGBOX_SIGN
	return


FlottTown_PlayerHouse_2F_PlayerDresser::
	msgbox FlottTown_PlayerHouse_2F_PlayerDresser_Text_0, MSGBOX_SIGN
	return


FlottTown_PlayerHouse_2F_FinancialBooks::
	msgbox FlottTown_PlayerHouse_2F_FinancialBooks_Text_0, MSGBOX_SIGN
	return


FlottTown_PlayerHouse_2F_Diary::
	msgbox FlottTown_PlayerHouse_2F_Diary_Text_0, MSGBOX_SIGN
	closemessage
	return


FlottTown_PlayerHouse_2F_SistersPC::
	msgbox FlottTown_PlayerHouse_2F_Text_SistersPC, MSGBOX_SIGN
	closemessage
	return


FlottTown_PlayerHouse_2F_ElsieDresser_Text_0:
	.string "It's your sister's dresser.$"

FlottTown_PlayerHouse_2F_PlayerDresser_Text_0:
	.string "It's your dresser.$"

FlottTown_PlayerHouse_2F_FinancialBooks_Text_0:
	.string "It's a book of financial statements.$"

FlottTown_PlayerHouse_2F_Diary_Text_0:
	.string "It's your journal.$"

FlottTown_PlayerHouse_2F_Text_SistersPC::
	.string "It's your Sister's PC. It has a lot of\n"
	.string "documents about her classes and\l"
	.string "students.\l"
	.string "It's way too much information for you\l"
	.string "to really parse.\p"
	.string "$"
