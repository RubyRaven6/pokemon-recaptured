DocksideCity_ResearchHouse_MapScripts::
	.byte 0


DocksideCity_ResearchHouse_EventScript_ProfNarra::
	switch VAR_DOCKSIDE_CITY_STATE
	case 0, DocksideCity_ResearchHouse_EventScript_ProfNarra_2
	case 1, DocksideCity_ResearchHouse_EventScript_ProfNarra_3
	return

DocksideCity_ResearchHouse_EventScript_ProfNarra_2:
	faceplayer
	msgbox DocksideCity_ResearchHouse_Text_WhoAreYou, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadescreen FADE_TO_BLACK
	msgbox DocksideCity_ResearchHouse_EventScript_ProfNarra_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox DocksideCity_ResearchHouse_Text_Pokedex, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_DOCKSIDE_CITY_STATE, 1
	playse SE_PIN
	msgbox DocksideCity_ResearchHouse_EventScript_ProfNarra_Text_1, MSGBOX_DEFAULT
	setvar VAR_LEAGUE_QUEST, 1
	waitmessage
	closemessage
	end

DocksideCity_ResearchHouse_EventScript_ProfNarra_3:
	msgbox DocksideCity_ResearchHouse_EventScript_ProfNarra_Text_2, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_ResearchHouse_EventScript_Aide1::
	msgbox DocksideCity_ResearchHouse_Text_WhoIsNarra, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_ResearchHouse_EventScript_Aide2::
	msgbox DocksideCity_ResearchHouse_EventScript_Aide2_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_ResearchHouse_EventScript_ProfNarra_Text_0:
	.string "Prof. Narra takes a few minutes to\n"
	.string "explain what a Pokédex is to you.$"

DocksideCity_ResearchHouse_EventScript_ProfNarra_Text_1:
	.string "Your quest, The Aurelious League, has\n"
	.string "been updated!$"

DocksideCity_ResearchHouse_EventScript_ProfNarra_Text_2:
	.string "Have you caught a Pokémon yet? I can't\n"
	.string "trust you with a Pokédex if not.$"

DocksideCity_ResearchHouse_EventScript_Aide2_Text_0:
	.string "The aide seems to be drowned in work.\n"
	.string "Best not to disturb him.$"

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
	.string "do.\p"
	.string "If you can prove that you can catch\n"
	.string "yourself a Pokémon on your own, I'll\l"
	.string "consider you one of my research aides.\p"
	.string "Not just any Pokémon though: I'd like\n"
	.string "for you to return a Drilbur, which is one\l"
	.string "of rare Pokémon in the nearby Route 1.\p"
	.string "Once you prove your determination to\n"
	.string "me, I'll grant you a Pokédex.$"

DocksideCity_ResearchHouse_Text_WhoIsNarra:
	.string "Prof. Narra is one of the leading expert\n"
	.string "in Pokémon medicine. His father was one\l"
	.string "of the first inventors of potions.\p"
	.string "Because he likes working in the lab\n"
	.string "more, we're actually the ones that get\l"
	.string "sent out do more fieldwork…$"
