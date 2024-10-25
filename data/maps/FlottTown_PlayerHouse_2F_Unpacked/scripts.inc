FlottTown_PlayerHouse_2F_Unpacked_MapScripts::
	.byte 0


FlottTown_PlayerHouse_2F_Unpacked_Boxes::
# 5 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	lockall
# 6 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_0, MSGBOX_DEFAULT
# 7 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	waitmessage
# 8 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	closemessage
# 9 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_1, MSGBOX_YESNO
# 10 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FlottTown_PlayerHouse_2F_Unpacked_Boxes_1
	return

FlottTown_PlayerHouse_2F_Unpacked_Boxes_1:
# 11 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	setflag FLAG_UNPACKED_ROOM
# 12 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	fadescreen FADE_TO_BLACK
# 13 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_2, MSGBOX_DEFAULT
# 14 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	waitmessage
# 15 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	closemessage
# 16 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	warpsilent MAP_FLOTT_TOWN_PLAYER_HOUSE_2F, 5, 2
# 17 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	waitmessage
# 18 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	closemessage
	end


FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_0:
# 6 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	.string "It's a pile of boxes full of stuff your\n"
	.string "sister bought for the new house.$"

FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_1:
# 9 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	.string "Do you wanna unbox all of it?$"

FlottTown_PlayerHouse_2F_Unpacked_Boxes_Text_2:
# 13 "data/maps/FlottTown_PlayerHouse_2F_Unpacked/scripts.pory"
	.string "You take about an hour or so to unpack\n"
	.string "all the stuff inside.$"
