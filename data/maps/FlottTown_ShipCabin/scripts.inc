FlottTown_ShipCabin_MapScripts::
	.byte 0


FlottTown_ShipCabin_MomsBed::
# 5 "data/maps/FlottTown_ShipCabin/scripts.pory"
	lockall
# 6 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_MomsBed, MSGBOX_DEFAULT
# 7 "data/maps/FlottTown_ShipCabin/scripts.pory"
	releaseall
	return


FlottTown_ShipCabin_Bed::
# 11 "data/maps/FlottTown_ShipCabin/scripts.pory"
	lockall
# 12 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_Bed, MSGBOX_DEFAULT
# 13 "data/maps/FlottTown_ShipCabin/scripts.pory"
	releaseall
	return


FlottTown_ShipCabin_Trash::
# 17 "data/maps/FlottTown_ShipCabin/scripts.pory"
	lockall
# 18 "data/maps/FlottTown_ShipCabin/scripts.pory"
	msgbox FlottTown_ShipCabin_Text_Trash, MSGBOX_DEFAULT
# 19 "data/maps/FlottTown_ShipCabin/scripts.pory"
	releaseall
	return


FlottTown_ShipCabin_Text_MomsBed::
# 22 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "It's your bed!$"

FlottTown_ShipCabin_Text_Bed::
# 26 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "It's your mom's bed.$"

FlottTown_ShipCabin_Text_Trash::
# 30 "data/maps/FlottTown_ShipCabin/scripts.pory"
	.string "Just some trash.$"
