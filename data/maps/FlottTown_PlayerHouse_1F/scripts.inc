FlottTown_PlayerHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FlottTown_PlayerHouse_1F_OnLoad
	.byte 0


FlottTown_PlayerHouse_1F_OnLoad::
	goto_if_set FLAG_UNPACKED_ROOM, FlottTown_PlayerHouse_1F_OnLoad_2
	setdynamicwarp MAP_FLOTT_TOWN_PLAYER_HOUSE_2F_UNPACKED, 5, 1
FlottTown_PlayerHouse_1F_OnLoad_1:
	goto_if_unset FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_OnLoad_5
	return

FlottTown_PlayerHouse_1F_OnLoad_2:
	setdynamicwarp MAP_FLOTT_TOWN_PLAYER_HOUSE_2F, 5, 1
	goto FlottTown_PlayerHouse_1F_OnLoad_1

FlottTown_PlayerHouse_1F_OnLoad_5:
	setmetatile 8, 1, METATILE_PlayersHouse_WallBottom, TRUE
	setmetatile 8, 2, METATILE_PlayersHouse_FloorWithWallShadow, FALSE
	setmetatile 10, 1, METATILE_PlayersHouse_WallMovingBox_Top, TRUE
	setmetatile 10, 2, METATILE_PlayersHouse_WallMovingBox_Bottom, FALSE
	setmetatile 0, 3, METATILE_PlayersHouse_MovingBox_Closed, TRUE
	setmetatile 0, 4, METATILE_PlayersHouse_MovingBox_Stacked, TRUE
	setmetatile 0, 5, METATILE_PlayersHouse_MovingBoxPair_Top, TRUE
	setmetatile 0, 6, METATILE_PlayersHouse_MovingBoxPair_Bottom, TRUE
	setmetatile 1, 4, METATILE_PlayersHouse_MovingBox_StackNoShadow, TRUE
	setmetatile 1, 5, METATILE_PlayersHouse_MovingBox_Stacked, TRUE
	setmetatile 1, 6, METATILE_PlayersHouse_MovingBox_Open, TRUE
	setmetatile 5, 4, METATILE_PlayersHouse_BlueRugCenter, FALSE
	setmetatile 5, 5, METATILE_PlayersHouse_BlueRugCenter, FALSE
	setmetatile 8, 4, METATILE_PlayersHouse_BlueRugCenter, FALSE
	setmetatile 8, 5, METATILE_PlayersHouse_BlueRugCenter, FALSE
	return


FlottTown_PlayerHouse_1F_Elsie::
	faceplayer
	goto_if_unset FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_Elsie_1
	goto_if_set FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_Elsie_6
FlottTown_PlayerHouse_1F_Elsie_5:
	compare VAR_FLOTT_TOWN_STATE, 10
	goto_if_eq FlottTown_PlayerHouse_1F_Elsie_3
	call FlottTown_PlayerHouse_1F_NPCElsie
	return

FlottTown_PlayerHouse_1F_Elsie_1:
	msgbox FlottTown_PlayerHouse_1F_Text_CheckOurRoom, MSGBOX_NPC
	return

FlottTown_PlayerHouse_1F_Elsie_2:
	clearflag FLAG_ELSIE_ENTERS_GYM
	setvar VAR_FLOTT_TOWN_STATE, 3
	msgbox FlottTown_PlayerHouse_1F_Text_AnAbandonedGym, MSGBOX_DEFAULT
	waitmessage
	closemessage
	warp MAP_FLOTT_TOWN_ABANDONED_GYM, 13, 18
	return

FlottTown_PlayerHouse_1F_Elsie_3:
	call FlottTown_PlayerHouse_1F_StartYourAdventure
	return

FlottTown_PlayerHouse_1F_Elsie_6:
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_PlayerHouse_1F_Elsie_2
	goto FlottTown_PlayerHouse_1F_Elsie_5


FlottTown_PlayerHouse_1F_StartYourAdventure::
	lockall
	faceplayer
	msgbox FlottTown_PlayerHouse_1F_Text_ImSorryForWalkingOut, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceAwayPlayer
	waitmovement 0
	delay 120
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FlottTown_PlayerHouse_1F_Text_CallingYouChamp, MSGBOX_DEFAULT
	giveitem ITEM_TOWN_MAP
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	playfanfare MUS_OBTAIN_ITEM
	msgbox FlottTown_PlayerHouse_1F_StartYourAdventure_Text_0
	waitfanfare
	msgbox FlottTown_PlayerHouse_1F_Text_ILoveYou, MSGBOX_DEFAULT
	setvar VAR_FLOTT_TOWN_STATE, 11
	releaseall
	return


FlottTown_PlayerHouse_2F_Gamecube::
	msgbox FlottTown_PlayerHouse_2F_Gamecube_Text_0, MSGBOX_SIGN
	waitmessage
	closemessage
	return


FlottTown_PlayerHouse_2F_Sink::
	msgbox FlottTown_PlayerHouse_2F_Sink_Text_0, MSGBOX_SIGN
	waitmessage
	closemessage
	return


FlottTown_PlayerHouse_2F_Cabinet::
	compare VAR_FLOTT_TOWN_STATE, 4
	goto_if_lt FlottTown_PlayerHouse_2F_Cabinet_2
	msgbox FlottTown_PlayerHouse_2F_Cabinet_Text_1, MSGBOX_SIGN
FlottTown_PlayerHouse_2F_Cabinet_1:
	waitmessage
	closemessage
	return

FlottTown_PlayerHouse_2F_Cabinet_2:
	msgbox FlottTown_PlayerHouse_2F_Cabinet_Text_0, MSGBOX_SIGN
	goto FlottTown_PlayerHouse_2F_Cabinet_1


FlottTown_PlayerHouse_2F_Fridge::
	msgbox FlottTown_PlayerHouse_2F_Fridge_Text_0, MSGBOX_SIGN
	waitmessage
	closemessage
	return


FlottTown_PlayerHouse_1F_NPCElsie::
	lockall
	msgbox FlottTown_PlayerHouse_1F_NPCElsie_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox FlottTown_PlayerHouse_1F_NPCElsie_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end


FlottTown_PlayerHouse_1F_StartYourAdventure_Text_0:
	.string "Elsie gave the Running Shoes!$"

FlottTown_PlayerHouse_2F_Gamecube_Text_0:
	.string "It's your sister's old Gamecube.\p"
	.string "You recall fond memories playing on it\n"
	.string "with her.$"

FlottTown_PlayerHouse_2F_Sink_Text_0:
	.string "It's a sink with a garbage disposal.\p"
	.string "You resist the urge to stick your hand\n"
	.string "in.$"

FlottTown_PlayerHouse_2F_Cabinet_Text_0:
	.string "It's an empty dish cabinet.$"

FlottTown_PlayerHouse_2F_Cabinet_Text_1:
	.string "It's a cabinet full of dishes.$"

FlottTown_PlayerHouse_2F_Fridge_Text_0:
	.string "It's a brand new fridge!\p"
	.string "It's so brand new, there's nothing in it\n"
	.string "yet.$"

FlottTown_PlayerHouse_1F_NPCElsie_Text_0:
	.string "Is my Champ tired? Come rest for a while.$"

FlottTown_PlayerHouse_1F_NPCElsie_Text_1:
	.string "There. Go get 'em, tiger.$"

FlottTown_PlayerHouse_1F_Text_AnAbandonedGym::
	.string "Hey! I just got finished unpacking the\n"
	.string "boxes.\l"
	.string "How was the town?\p"
	.string "…\p"
	.string "An abanonded gym, huh? Are you sure you\n"
	.string "want to go in?\p"
	.string "…\p"
	.string "Well, it's better than you sneaking in\n"
	.string "yourself. Sure, I'll come with you.$"

FlottTown_PlayerHouse_1F_Text_CheckOurRoom::
	.string "Pretty nice place, huh? Why not check\n"
	.string "our room out? I'll tidy some stuff up\l"
	.string "here.$"

FlottTown_PlayerHouse_1F_Text_ImSorryForWalkingOut::
	.string "ELSIE: Oh, hey, {PLAYER}.\p"
	.string "…\p"
	.string "I'm… sorry for walking out. I hope Mr.\n"
	.string "Heinrich didn't think it was too rude.\p"
	.string "…\p"
	.string "I'm not mad at you for having a Pokémon.\n"
	.string "Really, I'm not. But… I saw that twinkle\l"
	.string "in your eye when Mr. Heinrich talked\l"
	.string "about training it. I'm sure he means\l"
	.string "taking on the gym challenge. You know\l"
	.string "what's waiting at the end of that,\l"
	.string "right?\p"
	.string "Sooner or later, you'll have to\n"
	.string "challenge the Pokémon League… and go\l"
	.string "toe to toe with…\p"
	.string "With Dad.\p"
	.string "I've spent so long trying to get us away\n"
	.string "from him, and now you might go on a path\l"
	.string "that leads you straight to him.$"

FlottTown_PlayerHouse_1F_Text_CallingYouChamp::
	.string "ELSIE: Hmph. Who am I kidding? I've been\n"
	.string "the one calling you Champ all of these\l"
	.string "years. It's on me for not seeing this\l"
	.string "coming someday. Go get 'im, Champ. I'll\l"
	.string "always be here for you.\p"
	.string "In fact, here's a little something for\n"
	.string "the road.$"

FlottTown_PlayerHouse_1F_Text_ILoveYou::
	.string "Heh… just moved in and here you are\n"
	.string "flying out of the coop.\p"
	.string "I love you, {PLAYER}. Remember to\n"
	.string "stop by sometime, okay?$"
