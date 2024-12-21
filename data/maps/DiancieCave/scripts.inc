DiancieCave_MapScripts::
	.byte 0


DiancieCave_EventScript_MeetingDiancie::
	faceplayer
	msgbox DiancieCave_Text_WowYoureHere, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 7, DiancieCave_Movement_DianceLooksAround
	waitmovement 7
	msgbox DiancieCave_Text_IWishYouCouldStay, MSGBOX_DEFAULT
	warpwhitefade MAP_FLOTT_TOWN_SHIP_CABIN, 6, 4
	waitstate
	end


DiancieCave_Movement_DianceLooksAround:
	jump_in_place_down
	delay_4
	jump_in_place_down
	delay_4
	jump_in_place_down
	delay_4
	step_end

DiancieCave_Text_WowYoureHere:
	.string "DIANCIE: Oh my stars! You're actually\n"
	.string "here! It's so nice to meet you, {PLAYER}!\l"
	.string "We can't speak for long, but, know that\l"
	.string "I'm happy we got to meet.\p"
	.string "Welcome to my domain!$"

DiancieCave_Text_IWishYouCouldStay:
	.string "You know, after I assumed my duties as\n"
	.string "Princess, I couldn't explore again. And\l"
	.string "I missed it so! I used my connection\l"
	.string "with the earth to find a soul that I\l"
	.string "might befriend. While I was searching, I\l"
	.string "found you. And I felt that you were…\l"
	.string "hurting… I wanted to reach out and help\l"
	.string "you.\p"
	.string "I wish you could stay, I really do… But\n"
	.string "this is the most that we can talk for\l"
	.string "now.\p"
	.string "I hope to meet you again soon!$"
