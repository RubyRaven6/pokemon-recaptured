FlottTown_PlayerHouse_2F_Unpacked_MapScripts::
	.byte 0


FlottTown_PlayerHouse_2F_Unpacked_Boxes::
	lockall
	msgbox FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	msgbox FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_PlayerHouse_2F_Unpacked_Boxes_1
	closemessage
	return

FlottTown_PlayerHouse_2F_Unpacked_Boxes_1:
	setflag FLAG_UNPACKED_ROOM
	fadescreen FADE_TO_BLACK
	msgbox FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	warpsilent MAP_FLOTT_TOWN_PLAYER_HOUSE_2F, 5, 2
	waitmessage
	closemessage
	addhour 2
	addminute 42
	end


FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_0:
	.string "It's a pile of boxes full of stuff your\n"
	.string "sister bought for the new house.$"

FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_1:
	.string "Do you wanna unbox all of it?$"

FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_2:
	.string "You take a while to unpack all the stuff\n"
	.string "inside.$"
