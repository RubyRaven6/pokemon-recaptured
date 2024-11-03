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
	jump_in_place_down
# 22 "data/maps/DiancieCave/scripts.pory"
	delay_4
# 23 "data/maps/DiancieCave/scripts.pory"
	jump_in_place_down
# 24 "data/maps/DiancieCave/scripts.pory"
	delay_4
# 25 "data/maps/DiancieCave/scripts.pory"
	jump_in_place_down
# 26 "data/maps/DiancieCave/scripts.pory"
	delay_4
# 27 "data/maps/DiancieCave/scripts.pory"
	step_end

DiancieCave_Text_WowYoureHere:
# 30 "data/maps/DiancieCave/scripts.pory"
	.string "DIANCIE: Oh my stars! You're actually\n"
	.string "here! It's so nice to meet you, {PLAYER}!\l"
	.string "We can't speak for long, but, know that\l"
	.string "I'm happy we got to meet.\p"
	.string "Welcome to my domain!$"

DiancieCave_Text_IWishYouCouldStay:
# 37 "data/maps/DiancieCave/scripts.pory"
	.string "You know, after I assumed my duties as\n"
	.string "Princess, I couldn't explore again. And\l"
	.string "I missed it so! I used my connection\l"
	.string "with the earth to find a soul that I\l"
	.string "might befriend. When I found yours, my\l"
	.string "interest was so piqued, I had to know\l"
	.string "more! I wish you could stay, I really\l"
	.string "do... But this is the most that we can\l"
	.string "talk for now.\p"
	.string "I hope to meet you soon!$"
