FlottTown_BarneysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_FLOTT_TOWN_STATE, 9, FlottTown_BarneysHouse_FacePlayerUp
	.2byte 0

FlottTown_BarneysHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FLOTT_TOWN_STATE, 9, FlottTown_BarneysHouse_EventScript_BarneysLecture
	.2byte 0


FlottTown_BarneysHouse_FacePlayerUp:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	return


FlottTown_BarneysHouse_EventScript_BarneysLecture::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox FlottTown_BarneysHouse_Text_BarneysLecture, MSGBOX_DEFAULT
	applymovement 3, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	msgbox FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_0, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_WalkInPlaceDown
	applymovement 3, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox FlottTown_BarneysHouse_Text_GoodBattler, MSGBOX_DEFAULT
	msgbox FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 3, FlottTown_BarneysHouse_Movement_ElsieWalksOut
	waitmovement 3
	removeobject 3
	playse SE_DOOR
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox FlottTown_BarneysHouse_Text_ImTerriblySorry, MSGBOX_DEFAULT
	setvar VAR_FLOTT_TOWN_STATE, 10
	releaseall
	end


FlottTown_BarneysHouse_Barney::
	switch VAR_FLOTT_TOWN_STATE
	case 10, FlottTown_BarneysHouse_Barney_2
	case 11, FlottTown_BarneysHouse_Barney_3
	return

FlottTown_BarneysHouse_Barney_2:
	faceplayer
	msgbox FlottTown_BarneysHouse_Text_GoToYourSister, MSGBOX_NPC
	return

FlottTown_BarneysHouse_Barney_3:
	checkitem ITEM_SS_TICKET
	compare VAR_RESULT, FALSE
	goto_if_eq FlottTown_BarneysHouse_Barney_4
	msgbox FlottTown_BarneysHouse_Barney_Text_0, MSGBOX_NPC
	waitmessage
	closemessage
	return

FlottTown_BarneysHouse_Barney_4:
	faceplayer
	msgbox FlottTown_BarneysHouse_Text_GymLeaderChallenge, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setflag FLAG_SYS_QUEST_MENU_GET
	giveitem ITEM_JOURNAL, 1
	closemessage
	msgbox FlottTown_BarneysHouse_Text_BrandNewAdventure, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET, 1
	closemessage
	msgbox FlottTown_BarneysHouse_Text_GoToDockside, MSGBOX_DEFAULT
	waitmessage
	closemessage
	questmenu QUEST_MENU_SET_ACTIVE, 0
	questmenu QUEST_MENU_SET_ACTIVE, 1
	startquest QUEST_AURELIOUS_LEAGUE
	openquestmenu
	clearflag FLAG_BOAT_DEPARTS
	clearflag FLAG_FLOTT_HARBOR_SAILOR
	clearflag FLAG_BOAT_DEPARTS
	end


FlottTown_BarneysHouse_Adelaide::
	compare VAR_FLOTT_TOWN_STATE, 9
	goto_if_lt FlottTown_BarneysHouse_Adelaide_1
	msgbox FlottTown_BarneysHouse_Text_GladYoureOkay, MSGBOX_NPC
	return

FlottTown_BarneysHouse_Adelaide_1:
	msgbox FlottTown_BarneysHouse_Text_BarneysOut, MSGBOX_NPC
	return


FlottTown_BarneysHouse_Movement_ElsieWalksOut:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_0:
	.string "ELSIE: What's Mr. Barney talking about,\n"
	.string "{PLAYER}? Who else was in the cave?$"

FlottTown_BarneysHouse_EventScript_BarneysLecture_Text_1:
	.string "ELSIE: …$"

FlottTown_BarneysHouse_Barney_Text_0:
	.string "Get a move on now! Adventure awaits!$"

FlottTown_BarneysHouse_Text_BarneysLecture:
	.string "Now, I wouldn't be a responsible adult if\n"
	.string "I don't reprimand you for what you did\l"
	.string "in the first place.\p"
	.string "See here: what you did was incredibly\n"
	.string "reckless. The gym is closed for a\l"
	.string "reason. As much as it breaks my heart\l"
	.string "for it to be unmaintained, such is its\l"
	.string "state.\p"
	.string "Normally, this is also the part where I\n"
	.string "emphasize how dangerous it was.\p"
	.string "But, it seems that you had no reason to\n"
	.string "be scared; after all, you weren't alone,\l"
	.string "were you?$"

FlottTown_BarneysHouse_Text_GoodBattler:
	.string "BARNEY: Hm? That's a Pokéball on your\n"
	.string "side, right? I assumed you used a\l"
	.string "Pokémon. I even heard the faint sounds\l"
	.string "of battling. I'm sure you've got a good\l"
	.string "head on your shoulders to be a trainer!$"

FlottTown_BarneysHouse_Text_ImTerriblySorry:
	.string "BARNEY: Oh my, I didn't expect her to be\n"
	.string "upset. I'm terribly sorry. That being\l"
	.string "said, if you'd like to know more about\l"
	.string "training, you can come back to me.$"

FlottTown_BarneysHouse_Text_BarneysOut:
	.string "ADELDAIDE: Oh my, a visitor! Are you the\n"
	.string "girls that just moved in?\p"
	.string "My name is Adelaide. It's a pleaesure to\n"
	.string "meet you. Unfortunately, my husband is\l"
	.string "out at the moment.\p"
	.string "He's currently in the mainland\n"
	.string "attending to Gym Leader business. I'll\l"
	.string "say, you can take the man out of the\l"
	.string "gym, but not the gym out of the man!\p"
	.string "Sigh… but that conviction of him is\n"
	.string "definitely one of his best traits.\p"
	.string "Oh, look at me! Going off to someone\n"
	.string "likely tired from their journey. I'm sure\l"
	.string "we'll see each other soon.$"

FlottTown_BarneysHouse_Text_GladYoureOkay:
	.string "ADELDAIDE: My goodness, your first day\n"
	.string "and already making quite a ruckus!\p"
	.string "But nonetheless, I'm happy that you and\n"
	.string "your sister are safe.$"

FlottTown_BarneysHouse_Text_GoToYourSister:
	.string "BARNEY: I appreciate your enthusiasm,\n"
	.string "but I believe it's apt that you check-in\l"
	.string "on your sister first.$"

FlottTown_BarneysHouse_Text_GymLeaderChallenge:
	.string "BARNEY: Oh, you've returned! I hope all\n"
	.string "is well with your sister.\p"
	.string "I imagine you're interested in growing\n"
	.string "as a trainer, no? Well dear, the way to\l"
	.string "get there is through the Gym Challenge.\l"
	.string "You'll be challenging all the gyms in\l"
	.string "Aurelious and…\p"
	.string "…\p"
	.string "Well, you have a glint in your eye that\n"
	.string "says you already know what to expect.\p"
	.string "As a new trainer, you'll definitely be\n"
	.string "needing one of these, though…$"

FlottTown_BarneysHouse_Text_BrandNewAdventure:
	.string "BARNEY: I had one of these myself in my\n"
	.string "youth. It's a simple journal to mark\l"
	.string "down requests people have for you. As\l"
	.string "you do your adventure, you're bound to\l"
	.string "come across countless people to help.\p"
	.string "People will always be grateful for the\n"
	.string "help. If you return to them after\l"
	.string "completing their request, more often\l"
	.string "than not, they'll give you a gift.\p"
	.string "Now, normally this is the point in a\n"
	.string "young adventurer's life they receive a\l"
	.string "Pokédex. Unfortuantely, as I'm not a\l"
	.string "professor, I don't have one to offer.\l"
	.string "But I can point you in the right\l"
	.string "direction.\p"
	.string "Here, this is my second gift to you\n"
	.string "starting your new adventure.$"

FlottTown_BarneysHouse_Text_GoToDockside:
	.string "This is a ticket of mine for the S.S.\n"
	.string "Anne. Unlike most, though, you can use\l"
	.string "this to go back an forth from here to\l"
	.string "Dockside and back! It's mighty\l"
	.string "convenient. Once you get to Dockside\l"
	.string "City, look for Professor Narra.$"
