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
# 16 "data/maps/DiancieCave/scripts.pory"
	waitstate
	end


# 20 "data/maps/DiancieCave/scripts.pory"
DiancieCave_Movement_DianceLooksAround:
# 21 "data/maps/DiancieCave/scripts.pory"
	face_down
# 22 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 23 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 24 "data/maps/DiancieCave/scripts.pory"
	face_left
# 25 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 26 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 27 "data/maps/DiancieCave/scripts.pory"
	face_up
# 28 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 29 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 30 "data/maps/DiancieCave/scripts.pory"
	face_right
# 31 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 32 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 33 "data/maps/DiancieCave/scripts.pory"
	face_player
# 34 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 35 "data/maps/DiancieCave/scripts.pory"
	delay_16
# 36 "data/maps/DiancieCave/scripts.pory"
	jump_in_place_down
	step_end

# 39 "data/maps/DiancieCave/scripts.pory"

# 40 "data/maps/DiancieCave/scripts.pory"
DiancieCave_Text_WowYoureHere:
# 41 "data/maps/DiancieCave/scripts.pory"
# 37 "data/maps/DiancieCave/scripts.pory"
# 42 "data/maps/DiancieCave/scripts.pory"
	.string "DIANCIE: Oh my stars! You're actually\n"
# 43 "data/maps/DiancieCave/scripts.pory"
	.string "here! It's so nice to meet you, {PLAYER}!\l"
# 44 "data/maps/DiancieCave/scripts.pory"
	.string "We can't speak for long, but, know that\l"
# 45 "data/maps/DiancieCave/scripts.pory"
	.string "I'm happy we got to meet.\p"
# 46 "data/maps/DiancieCave/scripts.pory"
	.string "Welcome to my domain!$"

DiancieCave_Text_IWishYouCouldStay:
# 49 "data/maps/DiancieCave/scripts.pory"
	.string "I wish you could stay, I really do... But\n"
	.string "this is the most that we can talk for\l"
	.string "now.\p"
	.string "I hope to meet you soon!$"
