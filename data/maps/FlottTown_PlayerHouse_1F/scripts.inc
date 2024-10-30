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
	goto_if_set FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_OnLoad_5
	return

FlottTown_PlayerHouse_1F_OnLoad_2:
# 9 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setdynamicwarp MAP_FLOTT_TOWN_PLAYER_HOUSE_2F, 5, 1
	goto FlottTown_PlayerHouse_1F_OnLoad_1

FlottTown_PlayerHouse_1F_OnLoad_5:
# 15 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 3, 1, METATILE_PlayersHouse_WallBottom, FALSE
# 16 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 3, 2, METATILE_PlayersHouse_WallCornerShadow, FALSE
# 17 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 0, 3, METATILE_PlayersHouse_FloorWithWallShadow, FALSE
# 18 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 0, 4, METATILE_PlayersHouse_NormalFloor, FALSE
# 19 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 1, 4, METATILE_PlayersHouse_NormalFloor, FALSE
# 20 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_PlayersHouse_UpperLeftChair, FALSE
# 21 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 5, 5, METATILE_PlayersHouse_LowerLeftChair, FALSE
# 22 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 8, 4, METATILE_PlayersHouse_UpperRightChair, FALSE
# 23 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 8, 5, METATILE_PlayersHouse_LowerRightChair, FALSE
# 24 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 7, 0, METATILE_PlayersHouse_TV_Top, TRUE
# 25 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 7, 1, METATILE_Building_TV_Off, TRUE
# 26 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setmetatile 7, 2, METATILE_PlayersHouse_TV_Bottom, FALSE
	return


FlottTown_PlayerHouse_1F_Elsie::
# 31 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	faceplayer
# 32 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	goto_if_unset FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_Elsie_1
# 35 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	goto_if_set FLAG_VISITED_GYM, FlottTown_PlayerHouse_1F_Elsie_6
FlottTown_PlayerHouse_1F_Elsie_5:
# 41 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 10
	goto_if_eq FlottTown_PlayerHouse_1F_Elsie_3
# 45 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	call FlottTown_PlayerHouse_1F_NPCElsie
	return

FlottTown_PlayerHouse_1F_Elsie_1:
# 33 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_CheckOurRoom, MSGBOX_NPC
	return

FlottTown_PlayerHouse_1F_Elsie_2:
# 36 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	clearflag FLAG_ELSIE_ENTERS_GYM
# 37 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 3
# 38 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_AnAbandonedGym, MSGBOX_DEFAULT
# 39 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	warp MAP_FLOTT_TOWN_ABANDONED_GYM, 13, 18
	return

FlottTown_PlayerHouse_1F_Elsie_3:
# 42 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	call FlottTown_PlayerHouse_1F_StartYourAdventure
	return

FlottTown_PlayerHouse_1F_Elsie_6:
# 35 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_PlayerHouse_1F_Elsie_2
	goto FlottTown_PlayerHouse_1F_Elsie_5


FlottTown_PlayerHouse_1F_StartYourAdventure::
# 50 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	lockall
# 51 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	faceplayer
# 52 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_ImSorryForWalkingOut, MSGBOX_DEFAULT
# 53 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 54 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_FaceAwayPlayer
# 55 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	delay 120
# 57 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_FacePlayer
# 58 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 59 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_CallingYouChamp, MSGBOX_DEFAULT
# 60 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	giveitem ITEM_TOWN_MAP
# 61 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 62 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 63 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 64 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_StartYourAdventure_Text_0
# 65 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitfanfare
# 66 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_Text_ILoveYou, MSGBOX_DEFAULT
# 67 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	setvar VAR_FLOTT_TOWN_STATE, 11
# 68 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	releaseall
	return


FlottTown_PlayerHouse_1F_NPCElsie::
# 72 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	lockall
# 73 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_NPCElsie_Text_0, MSGBOX_DEFAULT
# 74 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 75 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 76 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	playfanfare MUS_HEAL
# 77 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitfanfare
# 78 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	special HealPlayerParty
# 79 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	msgbox FlottTown_PlayerHouse_1F_NPCElsie_Text_1, MSGBOX_DEFAULT
# 80 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	waitmessage
# 81 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 82 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	releaseall
	end


FlottTown_PlayerHouse_1F_StartYourAdventure_Text_0:
# 64 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Elsie gave the Running Shoes!$"

FlottTown_PlayerHouse_1F_NPCElsie_Text_0:
# 73 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Is my Champ tired? Come rest for a while.$"

FlottTown_PlayerHouse_1F_NPCElsie_Text_1:
# 79 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "There. Go get 'em, tiger.$"

FlottTown_PlayerHouse_1F_Text_AnAbandonedGym::
# 86 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
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
# 97 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "Pretty nice place, huh? Why not check\n"
	.string "our room out? I'll tidy some stuff up\l"
	.string "here.$"

FlottTown_PlayerHouse_1F_Text_ImSorryForWalkingOut::
# 101 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
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
# 115 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "ELSIE: Hmph. Who am I kidding? I've been\n"
	.string "the one calling you Champ all of these\l"
	.string "years. It's on me for not seeing this\l"
	.string "coming someday. Go get 'im, Champ. I'll\l"
	.string "always be here for you.\p"
	.string "In fact, here's a little something for\n"
	.string "the road.$"

FlottTown_PlayerHouse_1F_Text_ILoveYou::
# 122 "data/maps/FlottTown_PlayerHouse_1F/scripts.pory"
	.string "I love you, {PLAYER}. Remember to\n"
	.string "stop by sometime, okay?$"
