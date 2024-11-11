DocksideCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DocksideCity_OnTransition
	.byte 0


DocksideCity_OnTransition::
	setvar VAR_DOCKED_CITY, 1
	gettime
	compare VAR_0x8000, 12
	goto_if_lt DocksideCity_OnTransition_2
	compare VAR_0x8000, 14
	goto_if_gt DocksideCity_OnTransition_2
DocksideCity_OnTransition_1:
	gettime
	compare VAR_0x8000, 10
	goto_if_lt DocksideCity_OnTransition_7
	compare VAR_0x8000, 12
	goto_if_gt DocksideCity_OnTransition_7
DocksideCity_OnTransition_6:
	gettime
	compare VAR_0x8000, 14
	goto_if_lt DocksideCity_OnTransition_12
	compare VAR_0x8000, 15
	goto_if_gt DocksideCity_OnTransition_12
DocksideCity_OnTransition_11:
	gettime
	compare VAR_0x8000, 16
	goto_if_lt DocksideCity_OnTransition_17
	compare VAR_0x8000, 17
	goto_if_gt DocksideCity_OnTransition_17
DocksideCity_OnTransition_16:
	gettime
	compare VAR_0x8000, 17
	goto_if_lt DocksideCity_OnTransition_22
	compare VAR_0x8000, 20
	goto_if_gt DocksideCity_OnTransition_22
DocksideCity_OnTransition_21:
	end

DocksideCity_OnTransition_2:
	setflag FLAG_TEMP_1
	goto DocksideCity_OnTransition_1

DocksideCity_OnTransition_7:
	setflag FLAG_TEMP_2
	goto DocksideCity_OnTransition_6

DocksideCity_OnTransition_12:
	setflag FLAG_TEMP_3
	goto DocksideCity_OnTransition_11

DocksideCity_OnTransition_17:
	setflag FLAG_TEMP_4
	goto DocksideCity_OnTransition_16

DocksideCity_OnTransition_22:
	setflag FLAG_TEMP_5
	goto DocksideCity_OnTransition_21


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


DocksideCity_EventScript_MomEatingOut_Movement_0:
	walk_in_place_right
	step_end

DocksideCity_EventScript_Lesbian1EatingOut_Movement_0:
	walk_in_place_left
	step_end

DocksideCity_EventScript_Lesbian1EatingOut_Movement_1:
	emote_heart
	step_end

DocksideCity_EventScript_MomEatingOut_Text_0:
	.string "Jana! I told you to stop playing with\n"
	.string "your food!$"

DocksideCity_EventScript_SonEatingOut_Text_0:
	.string "Huh, this pasta is staler than usual…$"

DocksideCity_EventScript_DaughterEatingOut_Text_0:
	.string "PAsta!$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_0:
	.string "Hey… thanks for saying yes. I was really\n"
	.string "looking forward to spending the day\l"
	.string "with you.$"

DocksideCity_EventScript_Lesbian1EatingOut_Text_1:
	.string "Of course! I always love spending time\n"
	.string "with you. You know that, right?$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_0:
	.string "Huh… this pasta tastes better than\n"
	.string "when I went here last time.$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_1:
	.string "Really? I don't think they changed the\n"
	.string "recipe…$"

DocksideCity_EventScript_Lesbian2EatingOut_Text_2:
	.string "Well… maybe there's just something\n"
	.string "better about today?$"

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
