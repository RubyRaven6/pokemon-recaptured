DocksideCity_MapScripts::
	.byte 0


DocksideCity_OnTransition::
	return


DocksideCity_EventScript_SailorMachoke::
	faceplayer
	msgbox DocksideCity_Text_SailorMachoke, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement 2, Common_Movement_FaceRight
	end


DocksideCity_EventScript_SailorPoliwrath::
	faceplayer
	msgbox DocksideCity_Text_SailorPoliwrath, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement 1, Common_Movement_FaceRight
	end


DocksideCity_EventScript_SailorSpectator::
	faceplayer
	msgbox DocksideCity_Text_SailorSpectator, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement 3, Common_Movement_FaceDown
	end


DocksideCity_EventScript_MomEatingOut::
	applymovement 20, DocksideCity_EventScript_MomEatingOut_Movement_0
	msgbox DocksideCity_EventScript_MomEatingOut_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_SonEatingOut::
	msgbox DocksideCity_EventScript_SonEatingOut_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_DaughterEatingOut::
	msgbox DocksideCity_EventScript_DaughterEatingOut_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Lesbian1EatingOut::
	applymovement 19, DocksideCity_EventScript_MomEatingOut_Movement_0
	msgbox DocksideCity_EventScript_Lesbian1EatingOut_Text_0, MSGBOX_DEFAULT
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_0
	msgbox DocksideCity_EventScript_Lesbian1EatingOut_Text_1, MSGBOX_DEFAULT
	applymovement 19, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Lesbian2EatingOut::
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_0
	msgbox DocksideCity_EventScript_Lesbian2EatingOut_Text_0, MSGBOX_DEFAULT
	applymovement 19, DocksideCity_EventScript_MomEatingOut_Movement_0
	msgbox DocksideCity_EventScript_Lesbian2EatingOut_Text_1, MSGBOX_DEFAULT
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_0
	msgbox DocksideCity_EventScript_Lesbian2EatingOut_Text_2, MSGBOX_DEFAULT
	applymovement 19, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	applymovement 18, DocksideCity_EventScript_Lesbian1EatingOut_Movement_1
	waitmessage
	closemessage
	end


DocksideCity_EventScript_Date1EatingOut::
	applymovement 23, DocksideCity_EventScript_Date1EatingOut_Movement_0
	msgbox DocksideCity_EventScript_Date1EatingOut_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 24, DocksideCity_EventScript_Date1EatingOut_Movement_1
	msgbox DocksideCity_EventScript_Date1EatingOut_Text_1, MSGBOX_DEFAULT
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
	msgbox DocksideCity_EventScript_Custodian_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_GirlTuber::
	msgbox DocksideCity_EventScript_GirlTuber_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_BoyTuber::
	msgbox DocksideCity_EventScript_BoyTuber_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_TuberDad::
	msgbox DocksideCity_EventScript_TuberDad_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_BuriedGuy::
	lock
	msgbox DocksideCity_Text_BuriedGuy, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end


DocksideCity_EventScript_LighthouseFan::
	faceplayer
	msgbox DocksideCity_EventScript_LighthouseFan_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	end


DocksideCity_EventScript_GardenLady::
	faceplayer
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

DocksideCity_EventScript_MomEatingOut_Text_0:
	.string "MOM: Jaiden! I told you to stop playing\n"
	.string "with your food!$"

DocksideCity_EventScript_SonEatingOut_Text_0:
	.string "SON: Huh, this pasta is staler than usual…$"

DocksideCity_EventScript_DaughterEatingOut_Text_0:
	.string "JAIDEN: PAsta!$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_0:
	.string "LASS: Hey… thanks for saying yes. I was\n"
	.string "really looking forward to spending the\l"
	.string "day with you.$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_1:
	.string "LADY: Of course! I always love spending\n"
	.string "time with you. You know that, right?$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_0:
	.string "LADY: Huh… this pasta tastes better\n"
	.string "than when I went here last time.$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_1:
	.string "LASS: Really? I don't think they\n"
	.string "changed the recipe…$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_2:
	.string "LADY: Well… maybe there's just\n"
	.string "something better about today?$"

DocksideCity_EventScript_Date1EatingOut_Text_0:
	.string "LASS: Hm… I'm getting kind of bored\n"
	.string "going here each week…$"

DocksideCity_EventScript_Date1EatingOut_Text_1:
	.string "LAD: What? But this is the best pasta\n"
	.string "place in the city!$"

DocksideCity_EventScript_Date2EatingOut_Text_0:
	.string "LAD: The lad seems to just eating his\n"
	.string "food in peace.$"

DocksideCity_EventScript_Custodian_Text_0:
	.string "CUSTODIAN: I'll tell ya, it's astounding\n"
	.string "how much mess people can leave around\l"
	.string "after they eat.$"

DocksideCity_EventScript_GirlTuber_Text_0:
	.string "TUBER: I love the beach! It's so nice to\n"
	.string "swim in the water.$"

DocksideCity_EventScript_BoyTuber_Text_0:
	.string "TUBER: We can't go too far into the\n"
	.string "water. It's fine though.$"

DocksideCity_EventScript_TuberDad_Text_0:
	.string "SAILOR: My kids love coming to the\n"
	.string "beach, so I always come with them when\l"
	.string "I have time.$"

DocksideCity_EventScript_LighthouseFan_Text_0:
	.string "SAILOR: Whenever I dock here, I love\n"
	.string "looking at the wide vision of the sea.\l"
	.string "It's such a majestic view.$"

DocksideCity_EventScript_GardenLady_Text_0:
	.string "LADY: This is a community garden for\n"
	.string "the city. I like to take care of it with\l"
	.string "my Pokémon when I have the time.$"

DocksideCity_EventScript_ResearchHouse_Sign_Text_0:
	.string "Prof. Narra's Research House$"

DocksideCity_EventScript_Shipyard_Sign_Text_0:
	.string "Dockside Shipyard$"

DocksideCity_EventScript_Harbor_Sign_Text_0:
	.string "Dockside Harbor$"

DocksideCity_EventScript_Sign_Text_0:
	.string "Dockside City\p"
	.string "Where dreams meet the sea.$"

DocksideCity_Text_SailorMachoke:
	.string "We're currently on our break. We decided\n"
	.string "to have a battle while we're at it! He\l"
	.string "doesn't know that I made sure to give\l"
	.string "my buddy Machoke some moves to match\l"
	.string "up against Poliwrath!$"

DocksideCity_Text_SailorPoliwrath:
	.string "It's our union-mandated break at the\n"
	.string "moment. So, we decided to spar and give\l"
	.string "our Pokémon a workout. Joke's on him\l"
	.string "though. My Poliwrath is gonna wipe the\l"
	.string "floor with his Machoke!$"

DocksideCity_Text_SailorSpectator:
	.string "I'm just here to watch. These two\n"
	.string "always spar and somehow always end up\l"
	.string "in a dead-tie.$"

DocksideCity_Text_BuriedGuy:
	.string "BURIED GUY: So, I asked my friends to\n"
	.string "bury me in the sand. As a bit, y'know? I\l"
	.string "asked them to do it days ago. I think\l"
	.string "they forgot me here. It's not all too\l"
	.string "bad though. I still get food whenever\l"
	.string "the kids want some company.$"
