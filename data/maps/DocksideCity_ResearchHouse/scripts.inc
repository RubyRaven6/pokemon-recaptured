DocksideCity_ResearchHouse_MapScripts::
	.byte 0


DocksideCity_ResearchHouse_ProfNarra::
	msgbox DocksideCity_ResearchHouse_Text_WhoAreYou, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadescreen FADE_TO_BLACK
	msgbox DocksideCity_ResearchHouse_ProfNarra_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox DocksideCity_ResearchHouse_Text_Pokedex, MSGBOX_DEFAULT
	return


DocksideCity_ResearchHouse_ProfNarra_Text_0:
	.string "Prof. Narra takes a few minutes to\n"
	.string "explain what a Pokédex is to you.$"

DocksideCity_ResearchHouse_Text_WhoAreYou:
	.string "PROF. NARRA: Oh, hello there. I'm\n"
	.string "Professor Narra. Can I help you with\l"
	.string "something?\p"
	.string "…A Pokédex? Why would- Oh, you say\n"
	.string "Barney sent you here? Well, that\l"
	.string "certainly makes a lot of sense.\p"
	.string "To tell the truth, I haven't given out\n"
	.string "any Pokédexes yet, because frankly,\l"
	.string "it's much too expensive to handily give\l"
	.string "out. That being said, I do need some\l"
	.string "additional help for research; if you can\l"
	.string "convince me that I can trust you with a\l"
	.string "Pokédex, I can grant you one.\p"
	.string "…\p"
	.string "PROF. NARRA: What do you mean you don't\n"
	.string "know what a Pokédex is? Did Barney not-\l"
	.string "gah, fine.$"

DocksideCity_ResearchHouse_Text_Pokedex:
	.string "There, I hope that explanation was\n"
	.string "succinct enough. Now, with all of that\l"
	.string "in mind, I have an assignment for you to\l"
	.string "do.$"
