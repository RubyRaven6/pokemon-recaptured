FlottTown_House1_MapScripts::
	.byte 0


FlottTown_House1_Dad::
	msgbox FlottTown_House1_Text_FlottTownsQuiet, MSGBOX_NPC
	waitmessage
	closemessage
	end


FlottTown_House1_Mom::
	msgbox FlottTown_House1_Text_ItsPeacefulOutHere, MSGBOX_NPC
	waitmessage
	closemessage
	end


FlottTown_House1_Doll::
	msgbox FlottTown_House1_Text_CrushYou, MSGBOX_NPC
	waitmessage
	closemessage
	end


FlottTown_House1_Text_CrushYou::
	.string "It's an enormous Snorlax doll. You fear\n"
	.string "that it may somehow crush you with it's\l"
	.string "immense size.$"

FlottTown_House1_Text_FlottTownsQuiet::
	.string "Oh, you must be one of the new girls\n"
	.string "that just moved in! I hope you like it\l"
	.string "here. It's really quiet and peaceful.$"

FlottTown_House1_Text_ItsPeacefulOutHere::
	.string "Hello! It's nice to meet you! You're one\n"
	.string "of the new girls that just moved in,\l"
	.string "right? You're going to have a wonderful\l"
	.string "time here in Flott Town. Our family\l"
	.string "moved from the big city, and it's been a\l"
	.string "wonderful change of pace.$"
