DocksideCity_MapScripts::
	.byte 0


DocksideCity_OnTransition::
	return


DocksideCity_EventScript_SailorMachoke::
	faceplayer
	speakername DocksideCity_EventScript_SailorMachoke_Text_0
	msgbox DocksideCity_Text_SailorMachoke, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement 2, Common_Movement_FaceRight
	end


DocksideCity_EventScript_SailorPoliwrath::
	faceplayer
	speakername DocksideCity_EventScript_SailorMachoke_Text_0
	msgbox DocksideCity_Text_SailorPoliwrath, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement 1, Common_Movement_FaceRight
	end


DocksideCity_EventScript_SailorSpectator::
	faceplayer
	speakername DocksideCity_EventScript_SailorSpectator_Text_0
	msgbox DocksideCity_Text_SailorSpectator, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement 3, Common_Movement_FaceDown
	end


DocksideCity_EventScript_MomEatingOut::
	applymovement 20, DocksideCity_EventScript_MomEatingOut_Movement_0
	speakername DocksideCity_EventScript_MomEatingOut_Text_0
	msgbox DocksideCity_EventScript_MomEatingOut_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_SonEatingOut::
	speakername DocksideCity_EventScript_SonEatingOut_Text_0
	msgbox DocksideCity_EventScript_SonEatingOut_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_DaughterEatingOut::
	speakername DocksideCity_EventScript_DaughterEatingOut_Text_0
	msgbox DocksideCity_EventScript_DaughterEatingOut_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Lesbian1EatingOut::
	applymovement 19, DocksideCity_EventScript_MomEatingOut_Movement_0
	speakername DocksideCity_EventScript_Lesbian1EatingOut_Text_0
	msgbox DocksideCity_EventScript_Lesbian1EatingOut_Text_1, MSGBOX_DEFAULT
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_0
	speakername DocksideCity_EventScript_Lesbian1EatingOut_Text_2
	msgbox DocksideCity_EventScript_Lesbian1EatingOut_Text_3, MSGBOX_DEFAULT
	applymovement 19, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Lesbian2EatingOut::
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_0
	speakername DocksideCity_EventScript_Lesbian1EatingOut_Text_2
	msgbox DocksideCity_EventScript_Lesbian2EatingOut_Text_0, MSGBOX_DEFAULT
	applymovement 19, DocksideCity_EventScript_MomEatingOut_Movement_0
	speakername DocksideCity_EventScript_Lesbian1EatingOut_Text_0
	msgbox DocksideCity_EventScript_Lesbian2EatingOut_Text_1, MSGBOX_DEFAULT
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_0
	speakername DocksideCity_EventScript_Lesbian2EatingOut_Text_2
	msgbox DocksideCity_EventScript_Lesbian2EatingOut_Text_3, MSGBOX_DEFAULT
	applymovement 19, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Date1EatingOut::
	applymovement 24, DocksideCity_EventScript_Date1EatingOut_Movement_0
	speakername DocksideCity_EventScript_Date1EatingOut_Text_0
	msgbox DocksideCity_EventScript_Date1EatingOut_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 23, DocksideCity_EventScript_Date1EatingOut_Movement_1
	speakername DocksideCity_EventScript_Date1EatingOut_Text_2
	msgbox DocksideCity_EventScript_Date1EatingOut_Text_3, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Date2EatingOut::
	applymovement 24, DocksideCity_EventScript_Date1EatingOut_Movement_1
	msgbox DocksideCity_EventScript_Date2EatingOut_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Custodian::
	speakername DocksideCity_EventScript_Custodian_Text_0
	msgbox DocksideCity_EventScript_Custodian_Text_1, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_GirlTuber::
	speakername DocksideCity_EventScript_GirlTuber_Text_0
	msgbox DocksideCity_EventScript_GirlTuber_Text_1, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_BoyTuber::
	speakername DocksideCity_EventScript_BoyTuber_Text_0
	msgbox DocksideCity_EventScript_BoyTuber_Text_1, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_TuberDad::
	speakername DocksideCity_EventScript_TuberDad_Text_0
	msgbox DocksideCity_EventScript_TuberDad_Text_1, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_BuriedGuy::
	lock
	speakername DocksideCity_EventScript_BuriedGuy_Text_0
	msgbox DocksideCity_Text_BuriedGuy, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end


DocksideCity_EventScript_LighthouseFan::
	speakername DocksideCity_EventScript_LighthouseFan_Text_0
	msgbox DocksideCity_EventScript_LighthouseFan_Text_1, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_GardenLady::
	msgbox DocksideCity_EventScript_GardenLady_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_ResearchHouse_Sign::
	msgbox DocksideCity_EventScript_ResearchHouse_Sign_Text_0, MSGBOX_SIGN
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Shipyard_Sign::
	msgbox DocksideCity_EventScript_Shipyard_Sign_Text_0, MSGBOX_SIGN
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Harbor_Sign::
	msgbox DocksideCity_EventScript_Harbor_Sign_Text_0, MSGBOX_SIGN
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Sign::
	msgbox DocksideCity_EventScript_Sign_Text_0, MSGBOX_SIGN
	waitmessage
	closemessage
	end


DocksideCity_EventScript_MomEatingOut_Movement_0:
	walk_in_place_right
	step_end

DocksideCity_EventScript_Lesbian1EatingOut_Movement_0:
	walk_in_place_left
	step_end

DocksideCity_EventScript_Lesbian1EatingOut_Movement_1:
	emote_heart
	step_end

DocksideCity_EventScript_Date1EatingOut_Movement_0:
	walk_in_place_right
	step_end

DocksideCity_EventScript_Date1EatingOut_Movement_1:
	walk_in_place_left
	step_end

DocksideCity_EventScript_SailorMachoke_Text_0:
	.string "Betting sailor$"

DocksideCity_EventScript_SailorSpectator_Text_0:
	.string "High-rolling sailor$"

DocksideCity_EventScript_MomEatingOut_Text_0:
	.string "Tired mom$"

DocksideCity_EventScript_MomEatingOut_Text_1:
	.string "Jaiden! I told you to stop playing with\n"
	.string "your food!$"

DocksideCity_EventScript_SonEatingOut_Text_0:
	.string "“Foodie”$"

DocksideCity_EventScript_SonEatingOut_Text_1:
	.string "Huh, this pasta is staler than usual…$"

DocksideCity_EventScript_DaughterEatingOut_Text_0:
	.string "Messy kid$"

DocksideCity_EventScript_DaughterEatingOut_Text_1:
	.string "PAsta!$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_0:
	.string "Smitten lady$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_1:
	.string "Hey… thanks for saying yes. I was really\n"
	.string "looking forward to spending the day\l"
	.string "with you.$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_2:
	.string "Girl in love$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_3:
	.string "Of course! I always love spending time\n"
	.string "with you. You know that, right?$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_0:
	.string "Huh… this pasta tastes better than\n"
	.string "when I went here last time.$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_1:
	.string "Really? I don't think they changed the\n"
	.string "recipe…$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_2:
	.string "Lovestruck woman$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_3:
	.string "Well… maybe there's just something\n"
	.string "better about today?$"

DocksideCity_EventScript_Date1EatingOut_Text_0:
	.string "Picky girl$"

DocksideCity_EventScript_Date1EatingOut_Text_1:
	.string "Hm… I'm getting kind of bored going here\n"
	.string "each week…$"

DocksideCity_EventScript_Date1EatingOut_Text_2:
	.string "Stubborn guy$"

DocksideCity_EventScript_Date1EatingOut_Text_3:
	.string "What? But this is the best pasta place\n"
	.string "in the city!$"

DocksideCity_EventScript_Date2EatingOut_Text_0:
	.string "The lad seems to just eating his food in\n"
	.string "peace.$"

DocksideCity_EventScript_Custodian_Text_0:
	.string "Custodian$"

DocksideCity_EventScript_Custodian_Text_1:
	.string "I'll tell ya, it's astounding how much\n"
	.string "mess people can leave around after\l"
	.string "they eat.$"

DocksideCity_EventScript_GirlTuber_Text_0:
	.string "Tuber girl$"

DocksideCity_EventScript_GirlTuber_Text_1:
	.string "I love the beach! It's so nice to swim in\n"
	.string "the water.$"

DocksideCity_EventScript_BoyTuber_Text_0:
	.string "Tuber boy$"

DocksideCity_EventScript_BoyTuber_Text_1:
	.string "We can't go too far into the water. It's\n"
	.string "fine though.$"

DocksideCity_EventScript_TuberDad_Text_0:
	.string "Doting dad$"

DocksideCity_EventScript_TuberDad_Text_1:
	.string "My kids love coming to the beach, so I\n"
	.string "always come with them when I have time.$"

DocksideCity_EventScript_BuriedGuy_Text_0:
	.string "Buried guy$"

DocksideCity_EventScript_LighthouseFan_Text_0:
	.string "Wistful sailor$"

DocksideCity_EventScript_LighthouseFan_Text_1:
	.string "Whenever I dock here, I love looking at\n"
	.string "the wide vision of the sea. It's such a\l"
	.string "majestic view.$"

DocksideCity_EventScript_GardenLady_Text_0:
	.string "This is a community garden for the city.\n"
	.string "I like to take care of it with my\l"
	.string "Pokémon when I have the time.$"

DocksideCity_EventScript_ResearchHouse_Sign_Text_0:
	.string "Prof. Narra's Research House$"

DocksideCity_EventScript_Shipyard_Sign_Text_0:
	.string "Dockside Shipyard$"

DocksideCity_EventScript_Harbor_Sign_Text_0:
	.string "Dockside Harbor$"

DocksideCity_EventScript_Sign_Text_0:
	.string "Dockside City\p"
	.string "Where dreams meet the sea.$"

DocksideCity_Text_SailorMachoke::
	.string "We're currently on our break. We decided\n"
	.string "to have a battle while we're at it! He\l"
	.string "doesn't know that I made sure to give\l"
	.string "my buddy Machoke some moves to match\l"
	.string "up against Poliwrath!$"

DocksideCity_Text_SailorPoliwrath::
	.string "It's our union-mandated break at the\n"
	.string "moment. So, we decided to spar and give\l"
	.string "our Pokémon a workout. Joke's on him\l"
	.string "though. My Poliwrath is gonna wipe the\l"
	.string "floor with his Machoke!$"

DocksideCity_Text_SailorSpectator::
	.string "I'm just here to watch. These two\n"
	.string "always spar and somehow always end up\l"
	.string "in a dead-tie.$"

DocksideCity_Text_BuriedGuy::
	.string "So, I asked my friends to bury me in the\n"
	.string "sand. As a bit, y'know? I asked them to\l"
	.string "do it days ago. I think they forgot me\l"
	.string "here. It's not all too bad though. I still\l"
	.string "get food whenever the kids want some\l"
	.string "company.$"
