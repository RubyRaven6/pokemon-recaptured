StarterSelection_GFXSetting::
	checkplayerpersonality
	switch VAR_RESULT
	case 0, StarterSelection_GFXSetting_3
	case 1, StarterSelection_GFXSetting_4
	case 2, StarterSelection_GFXSetting_5
StarterSelection_GFXSetting_1:
	return

StarterSelection_GFXSetting_3:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( MANKEY )
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( BUDEW )
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( TRAPINCH )
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPECIES ( LITWICK )
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_SPECIES ( HATENNA )
	goto StarterSelection_GFXSetting_1

StarterSelection_GFXSetting_4:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( TINKATINK )
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( BLIPBUG )
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( FLABEBE )
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPECIES ( ZUBAT )
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_SPECIES ( GOTHITA )
	goto StarterSelection_GFXSetting_1

StarterSelection_GFXSetting_5:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( TEDDIURSA )
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( DUSKULL )
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( AZURILL )
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPECIES ( ARON )
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_SPECIES ( NACLI )
	goto StarterSelection_GFXSetting_1


StarterSelection_FuryPersonality::
	debugprint StarterSelection_FuryPersonality_Text_0
	dynmultichoice 9, 2, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, StarterSelection_FuryPersonality_Text_1, StarterSelection_FuryPersonality_Text_2, StarterSelection_FuryPersonality_Text_3, StarterSelection_FuryPersonality_Text_4, StarterSelection_FuryPersonality_Text_5
	switch VAR_RESULT
	case 0, StarterSelection_FuryPersonality_2
	case 1, StarterSelection_FuryPersonality_3
	case 2, StarterSelection_FuryPersonality_4
	case 3, StarterSelection_FuryPersonality_5
	case 4, StarterSelection_FuryPersonality_6
	return

StarterSelection_FuryPersonality_2:
	setvar VAR_TEMP_8, 3
	addobject 3
	applymovement 3, Common_Movement_FaceAwayPlayer
	setobjectxy 3, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_MANKEY
	setvar VAR_TEMP_7, SPECIES_MANKEY
	return

StarterSelection_FuryPersonality_3:
	setvar VAR_TEMP_8, 4
	addobject 4
	applymovement 4, Common_Movement_FaceAwayPlayer
	setobjectxy 4, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_BUDEW
	setvar VAR_TEMP_7, SPECIES_BUDEW
	return

StarterSelection_FuryPersonality_4:
	setvar VAR_TEMP_8, 2
	addobject 2
	applymovement 2, Common_Movement_FaceAwayPlayer
	setobjectxy 2, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_TRAPINCH
	setvar VAR_TEMP_7, SPECIES_TRAPINCH
	return

StarterSelection_FuryPersonality_5:
	setvar VAR_TEMP_8, 1
	addobject 1
	applymovement 1, Common_Movement_FaceAwayPlayer
	setobjectxy 1, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_LITWICK
	setvar VAR_TEMP_7, SPECIES_LITWICK
	return

StarterSelection_FuryPersonality_6:
	setvar VAR_TEMP_8, 9
	addobject 9
	applymovement 9, Common_Movement_FaceAwayPlayer
	setobjectxy 9, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_HATENNA
	setvar VAR_TEMP_7, SPECIES_HATENNA
	return


StarterSelection_MischiefPersonality::
	debugprint StarterSelection_MischiefPersonality_Text_0
	dynmultichoice 9, 2, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, StarterSelection_MischiefPersonality_Text_1, StarterSelection_MischiefPersonality_Text_2, StarterSelection_MischiefPersonality_Text_3, StarterSelection_MischiefPersonality_Text_4, StarterSelection_MischiefPersonality_Text_5
	switch VAR_RESULT
	case 0, StarterSelection_MischiefPersonality_2
	case 1, StarterSelection_MischiefPersonality_3
	case 2, StarterSelection_MischiefPersonality_4
	case 3, StarterSelection_MischiefPersonality_5
	case 4, StarterSelection_MischiefPersonality_6
	return

StarterSelection_MischiefPersonality_2:
	setvar VAR_TEMP_8, 3
	addobject 3
	applymovement 3, Common_Movement_FaceAwayPlayer
	setobjectxy 3, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_TINKATINK
	setvar VAR_TEMP_7, SPECIES_TINKATINK
	return

StarterSelection_MischiefPersonality_3:
	setvar VAR_TEMP_8, 4
	addobject 4
	applymovement 4, Common_Movement_FaceAwayPlayer
	setobjectxy 4, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_BLIPBUG
	setvar VAR_TEMP_7, SPECIES_BLIPBUG
	return

StarterSelection_MischiefPersonality_4:
	setvar VAR_TEMP_8, 2
	addobject 2
	applymovement 2, Common_Movement_FaceAwayPlayer
	setobjectxy 2, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_FLABEBE
	setvar VAR_TEMP_7, SPECIES_FLABEBE
	return

StarterSelection_MischiefPersonality_5:
	setvar VAR_TEMP_8, 1
	addobject 1
	applymovement 1, Common_Movement_FaceAwayPlayer
	setobjectxy 1, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_ZUBAT
	setvar VAR_TEMP_7, SPECIES_ZUBAT
	return

StarterSelection_MischiefPersonality_6:
	setvar VAR_TEMP_8, 9
	addobject 9
	applymovement 9, Common_Movement_FaceAwayPlayer
	setobjectxy 9, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_GOTHITA
	setvar VAR_TEMP_7, SPECIES_GOTHITA
	return


StarterSelection_FriendshipPersonality::
	debugprint StarterSelection_FriendshipPersonality_Text_0
	dynmultichoice 9, 2, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, StarterSelection_FriendshipPersonality_Text_1, StarterSelection_FriendshipPersonality_Text_2, StarterSelection_FriendshipPersonality_Text_3, StarterSelection_FriendshipPersonality_Text_4, StarterSelection_FriendshipPersonality_Text_5
	switch VAR_RESULT
	case 0, StarterSelection_FriendshipPersonality_2
	case 1, StarterSelection_FriendshipPersonality_3
	case 2, StarterSelection_FriendshipPersonality_4
	case 3, StarterSelection_FriendshipPersonality_5
	case 4, StarterSelection_FriendshipPersonality_6
	return

StarterSelection_FriendshipPersonality_2:
	setvar VAR_TEMP_8, 3
	addobject 3
	applymovement 3, Common_Movement_FaceAwayPlayer
	setobjectxy 3, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_TEDDIURSA
	setvar VAR_TEMP_7, SPECIES_TEDDIURSA
	return

StarterSelection_FriendshipPersonality_3:
	setvar VAR_TEMP_8, 4
	addobject 4
	applymovement 4, Common_Movement_FaceAwayPlayer
	setobjectxy 4, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_DUSKULL
	setvar VAR_TEMP_7, SPECIES_DUSKULL
	return

StarterSelection_FriendshipPersonality_4:
	setvar VAR_TEMP_8, 2
	addobject 2
	applymovement 2, Common_Movement_FaceAwayPlayer
	setobjectxy 2, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_AZURILL
	setvar VAR_TEMP_7, SPECIES_AZURILL
	return

StarterSelection_FriendshipPersonality_5:
	setvar VAR_TEMP_8, 1
	addobject 1
	applymovement 1, Common_Movement_FaceAwayPlayer
	setobjectxy 1, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_ARON
	setvar VAR_TEMP_7, SPECIES_ARON
	return

StarterSelection_FriendshipPersonality_6:
	setvar VAR_TEMP_8, 9
	addobject 9
	applymovement 9, Common_Movement_FaceAwayPlayer
	setobjectxy 9, VAR_TEMP_5, VAR_TEMP_6
	bufferspeciesname STR_VAR_1, SPECIES_NACLI
	setvar VAR_TEMP_7, SPECIES_NACLI
	return


StarterSelection_FuryPersonality_Text_0:
	.string "running fury starter selection dynmultichoice$"

StarterSelection_FuryPersonality_Text_1:
	.string "Rage Monkey$"

StarterSelection_FuryPersonality_Text_2:
	.string "Bouquet$"

StarterSelection_FuryPersonality_Text_3:
	.string "Mystic$"

StarterSelection_FuryPersonality_Text_4:
	.string "Luring$"

StarterSelection_FuryPersonality_Text_5:
	.string "Silent$"

StarterSelection_MischiefPersonality_Text_0:
	.string "running mischief starter selection dynmultichoice$"

StarterSelection_MischiefPersonality_Text_1:
	.string "Hammer$"

StarterSelection_MischiefPersonality_Text_2:
	.string "Seven Spots$"

StarterSelection_MischiefPersonality_Text_3:
	.string "Garden$"

StarterSelection_MischiefPersonality_Text_4:
	.string "Bat$"

StarterSelection_MischiefPersonality_Text_5:
	.string "Astral Body$"

StarterSelection_FriendshipPersonality_Text_0:
	.string "running friend starter selection dynmultichoice$"

StarterSelection_FriendshipPersonality_Text_1:
	.string "Peat$"

StarterSelection_FriendshipPersonality_Text_2:
	.string "Gripper$"

StarterSelection_FriendshipPersonality_Text_3:
	.string "Aqua Rabbit$"

StarterSelection_FriendshipPersonality_Text_4:
	.string "Iron Armor$"

StarterSelection_FriendshipPersonality_Text_5:
	.string "Rock Salt$"
