DiancieCave_MapScripts::
	.byte 0


DiancieCave_EventScript_MeetingDiancie::
# 8 "data/maps/DiancieCave/scripts.pory"
	faceplayer
# 9 "data/maps/DiancieCave/scripts.pory"
	msgbox DiancieCave_Text_WowYoureHere, MSGBOX_DEFAULT
# 10 "data/maps/DiancieCave/scripts.pory"
	waitmessage
# 11 "data/maps/DiancieCave/scripts.pory"
	closemessage
# 12 "data/maps/DiancieCave/scripts.pory"
	applymovement 7, DiancieCave_Movement_DianceLooksAround
# 13 "data/maps/DiancieCave/scripts.pory"
	waitmovement 7
# 14 "data/maps/DiancieCave/scripts.pory"
	msgbox DiancieCave_Text_IWishYouCouldStay, MSGBOX_DEFAULT
# 15 "data/maps/DiancieCave/scripts.pory"
	warpwhitefade MAP_FLOTT_TOWN_SHIP_CABIN, 6, 4
	return


# 18 "data/maps/DiancieCave/scripts.pory"
DiancieCave_Movement_DianceLooksAround:
# 19 "data/maps/DiancieCave/scripts.pory"
	face_up
# 20 "data/maps/DiancieCave/scripts.pory"
	face_left
# 21 "data/maps/DiancieCave/scripts.pory"
	face_down
# 22 "data/maps/DiancieCave/scripts.pory"
	face_right
# 23 "data/maps/DiancieCave/scripts.pory"
	face_player
# 24 "data/maps/DiancieCave/scripts.pory"
	jump_in_place_down
	step_end

DiancieCave_Text_WowYoureHere:
# 27 "data/maps/DiancieCave/scripts.pory"
	.string "Oh my stars! You're actually here! It's\n"
	.string "so nice to meet you, {PLAYER}!\p"
	.string "We can't speak for long, but, know that\n"
	.string "I'm happy we got to meet.\p"
	.string "Welcome to my domain!$"

DiancieCave_Text_IWishYouCouldStay:
# 35 "data/maps/DiancieCave/scripts.pory"
	.string "I wish you could stay, I really do... But\n"
	.string "this is the most that we can talk for\l"
	.string "now.\p"
	.string "I hope to meet you soon!$"
