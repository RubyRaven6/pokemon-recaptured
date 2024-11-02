FlottTown_PlayerHouse_1F_MapScripts::
# 4 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FlottTown_PlayerHouse_1F_OnLoad
	.byte 0


FlottTown_PlayerHouse_1F_OnLoad::
# 8 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	goto_if_set FLAG_UNPACKED_ROOM, FlottTown_PlayerHouse_1F_OnLoad_2
# 12 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setdynamicwarp MAP_FLOTT_TOWN_PLAYER_HOUSE_2F_UNPACKED, 5, 1
FlottTown_PlayerHouse_1F_OnLoad_1:
# 14 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	goto_if_unset FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_OnLoad_5
	return

FlottTown_PlayerHouse_1F_OnLoad_2:
# 9 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setdynamicwarp MAP_FLOTT_TOWN_PLAYER_HOUSE_2F, 5, 1
	goto FlottTown_PlayerHouse_1F_OnLoad_1

FlottTown_PlayerHouse_1F_OnLoad_5:
# 15 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 8, 1, METATILE_PlayersHouse_WallBottom, TRUE
# 16 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 8, 2, METATILE_PlayersHouse_FloorWithWallShadow, FALSE
# 17 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 10, 1, METATILE_PlayersHouse_WallMovingBox_Top, TRUE
# 18 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 10, 2, METATILE_PlayersHouse_WallMovingBox_Bottom, FALSE
# 19 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 0, 3, METATILE_PlayersHouse_MovingBox_Closed, TRUE
# 20 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 0, 4, METATILE_PlayersHouse_MovingBox_Stacked, TRUE
# 21 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 0, 5, METATILE_PlayersHouse_MovingBoxPair_Top, TRUE
# 22 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 0, 6, METATILE_PlayersHouse_MovingBoxPair_Bottom, TRUE
# 23 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 1, 4, METATILE_PlayersHouse_MovingBox_StackNoShadow, TRUE
# 24 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 1, 5, METATILE_PlayersHouse_MovingBox_Stacked, TRUE
# 25 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 1, 6, METATILE_PlayersHouse_MovingBox_Open, TRUE
# 26 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_PlayersHouse_BlueRugCenter, FALSE
# 27 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 5, 5, METATILE_PlayersHouse_BlueRugCenter, FALSE
# 28 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 8, 4, METATILE_PlayersHouse_BlueRugCenter, FALSE
# 29 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 8, 5, METATILE_PlayersHouse_BlueRugCenter, FALSE
	return


FlottTown_PlayerHouse_1F_Elsie::
# 34 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	faceplayer
# 35 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	goto_if_unset FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_Elsie_1
# 38 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	goto_if_set FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_Elsie_6
FlottTown_PlayerHouse_1F_Elsie_5:
# 46 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 10
	goto_if_eq FlottTown_PlayerHouse_1F_Elsie_3
# 50 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	call FlottTown_PlayerHouse_1F_NPCElsie
	return

FlottTown_PlayerHouse_1F_Elsie_1:
# 36 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_CheckOurRoom, MSGBOX_NPC
	return

FlottTown_PlayerHouse_1F_Elsie_2:
# 39 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	clearflag FLAG_ELSIE_ENTERS_GYM
# 40 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 3
# 41 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_AnAbandonedGym, MSGBOX_DEFAULT
# 42 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 43 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 44 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	warp MAP_FLOTT_TOWN_ABANDONED_GYM, 13, 18
	return

FlottTown_PlayerHouse_1F_Elsie_3:
# 47 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	call FlottTown_PlayerHouse_1F_StartYourAdventure
	return

FlottTown_PlayerHouse_1F_Elsie_6:
# 38 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_PlayerHouse_1F_Elsie_2
	goto FlottTown_PlayerHouse_1F_Elsie_5


FlottTown_PlayerHouse_1F_StartYourAdventure::
# 55 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	lockall
# 56 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	faceplayer
# 57 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_ImSorryForWalkingOut, MSGBOX_DEFAULT
# 58 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 59 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_FaceAwayPlayer
# 60 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 61 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	delay 120
# 62 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_FacePlayer
# 63 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 64 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_CallingYouChamp, MSGBOX_DEFAULT
# 65 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	giveitem ITEM_TOWN_MAP
# 66 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 67 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 68 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 69 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_StartYourAdventure_Text_0
# 70 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitfanfare
# 71 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_ILoveYou, MSGBOX_DEFAULT
# 72 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 11
# 73 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	releaseall
	return


FlottTown_PlayerHouse_2F_Gamecube::
# 77 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Gamecube_Text_0, MSGBOX_SIGN
# 78 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 79 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
	return


FlottTown_PlayerHouse_2F_Sink::
# 83 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Sink_Text_0, MSGBOX_SIGN
# 84 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 85 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
	return


FlottTown_PlayerHouse_2F_Cabinet::
# 89 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 4
	goto_if_lt FlottTown_PlayerHouse_2F_Cabinet_2
# 93 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Cabinet_Text_1, MSGBOX_SIGN
FlottTown_PlayerHouse_2F_Cabinet_1:
# 95 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 96 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
	return

FlottTown_PlayerHouse_2F_Cabinet_2:
# 90 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Cabinet_Text_0, MSGBOX_SIGN
	goto FlottTown_PlayerHouse_2F_Cabinet_1


FlottTown_PlayerHouse_2F_Fridge::
# 100 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_2F_Fridge_Text_0, MSGBOX_SIGN
# 101 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 102 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
	return


FlottTown_PlayerHouse_1F_NPCElsie::
# 106 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	lockall
# 107 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_NPCElsie_Text_0, MSGBOX_DEFAULT
# 108 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 109 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 110 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	playfanfare MUS_HEAL
# 111 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitfanfare
# 112 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	special HealPlayerParty
# 113 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_NPCElsie_Text_1, MSGBOX_DEFAULT
# 114 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 115 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 116 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	releaseall
	end


FlottTown_PlayerHouse_1F_StartYourAdventure_Text_0:
# 69 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Elsie gave the Running Shoes!$"

FlottTown_PlayerHouse_2F_Gamecube_Text_0:
# 77 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "It's your sister's old Gamecube.\p"
	.string "You recall fond memories playing on it\n"
	.string "with her.$"

FlottTown_PlayerHouse_2F_Sink_Text_0:
# 83 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "It's a sink with a garbage disposal.\p"
	.string "You resist the urge to stick your hand\n"
	.string "in.$"

FlottTown_PlayerHouse_2F_Cabinet_Text_0:
# 90 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "It's an empty dish cabinet.$"

FlottTown_PlayerHouse_2F_Cabinet_Text_1:
# 93 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "It's a cabinet full of dishes.$"

FlottTown_PlayerHouse_2F_Fridge_Text_0:
# 100 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "It's a brand new fridge!\p"
	.string "It's so brand new, there's nothing in it\n"
	.string "yet.$"

FlottTown_PlayerHouse_1F_NPCElsie_Text_0:
# 107 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Is my Champ tired? Come rest for a while.$"

FlottTown_PlayerHouse_1F_NPCElsie_Text_1:
# 113 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "There. Go get 'em, tiger.$"

FlottTown_PlayerHouse_1F_Text_AnAbandonedGym::
# 120 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Hey! I just got finished unpacking the\n"
	.string "boxes.\l"
	.string "How was the town?\p"
	.string "…\p"
	.string "An abanonded gym, huh? Are you sure you\n"
	.string "want to go in?\p"
	.string "…\p"
	.string "Well, it's better than you sneaking in\n"
	.string "yourself. Sure, I'll come with you.\p"
	.string "$"

FlottTown_PlayerHouse_1F_Text_CheckOurRoom::
# 131 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Pretty nice place, huh? Why not check\n"
	.string "our room out? I'll tidy some stuff up\l"
	.string "here.$"

FlottTown_PlayerHouse_1F_Text_ImSorryForWalkingOut::
# 135 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
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
# 149 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "ELSIE: Hmph. Who am I kidding? I've been\n"
	.string "the one calling you Champ all of these\l"
	.string "years. It's on me for not seeing this\l"
	.string "coming someday. Go get 'im, Champ. I'll\l"
	.string "always be here for you.\p"
	.string "In fact, here's a little something for\n"
	.string "the road.$"

FlottTown_PlayerHouse_1F_Text_ILoveYou::
# 156 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Heh… just moved in and here you are\n"
	.string "flying out of the coop.\p"
	.string "I love you, {PLAYER}. Remember to\n"
	.string "stop by sometime, okay?$"
