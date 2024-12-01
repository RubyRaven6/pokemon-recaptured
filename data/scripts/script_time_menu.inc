WaitingMenu::
	lockall
	dynmultichoice 1, 1, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, WaitingMenu_Text_0, WaitingMenu_Text_1
	switch VAR_RESULT
	case 0, WaitingMenu_3
	case 1, WaitingMenu_4
WaitingMenu_1:
	releaseall
	return

WaitingMenu_3:
	call Add_Time
	goto WaitingMenu_1

WaitingMenu_4:
	call Set_Time
	goto WaitingMenu_1


Add_Time:
	dynmultichoice 1, 1, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, Add_Time_Text_0, Add_Time_Text_1
	switch VAR_RESULT
	case 0, Add_Time_3
	case 1, Add_Time_4
Add_Time_1:
	releaseall
	return

Add_Time_3:
	call Add_Days
	goto Add_Time_1

Add_Time_4:
	call Add_Hours
	goto Add_Time_1


Add_Days:
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Add_Days_Text_0, Add_Days_Text_1, Add_Days_Text_2
	switch VAR_RESULT
	case 0, Add_Days_3
	case 1, Add_Days_4
	case 2, Add_Days_5
Add_Days_1:
	releaseall
	return

Add_Days_3:
	fadescreen FADE_TO_BLACK
	addday 1
	msgbox Add_Days_Text_3
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	goto Add_Days_1

Add_Days_4:
	fadescreen FADE_TO_BLACK
	addday 6
	msgbox Add_Days_Text_3
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	goto Add_Days_1

Add_Days_5:
	fadescreen FADE_TO_BLACK
	addday 12
	msgbox Add_Days_Text_3
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	goto Add_Days_1


Add_Hours:
	dynmultichoice 1, 1, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, Add_Days_Text_0, Add_Days_Text_1, Add_Days_Text_2
	switch VAR_RESULT
	case 0, Add_Hours_3
	case 1, Add_Hours_4
	case 2, Add_Hours_5
Add_Hours_1:
	releaseall
	return

Add_Hours_3:
	fadescreen FADE_TO_BLACK
	addhour 1
	msgbox Add_Days_Text_3
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	goto Add_Hours_1

Add_Hours_4:
	fadescreen FADE_TO_BLACK
	addhour 6
	msgbox Add_Days_Text_3
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	goto Add_Hours_1

Add_Hours_5:
	fadescreen FADE_TO_BLACK
	addhour 12
	msgbox Add_Days_Text_3
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	goto Add_Hours_1


Set_Time:
	dynmultichoice 1, 1, FALSE, 1, 0, DYN_MULTICHOICE_CB_NONE, Set_Time_Text_0, Set_Time_Text_1
	switch VAR_RESULT
	case 0, Set_Time_3
	case 1, Set_Time_4
Set_Time_1:
	releaseall
	return

Set_Time_3:
	call Set_Days
	goto Set_Time_1

Set_Time_4:
	call Set_Hours
	goto Set_Time_1


Set_Days:
	dynmultichoice 1, 1, FALSE, 7, 0, DYN_MULTICHOICE_CB_NONE, Set_Days_Text_0, Set_Days_Text_1, Set_Days_Text_2, Set_Days_Text_3, Set_Days_Text_4, Set_Days_Text_5, Set_Days_Text_6, Set_Days_Text_7, Set_Days_Text_8, Set_Days_Text_9, Set_Days_Text_10, Set_Days_Text_11, Set_Days_Text_12, Set_Days_Text_11, Set_Days_Text_13, Set_Days_Text_14, Set_Days_Text_15, Set_Days_Text_16, Set_Days_Text_17, Set_Days_Text_18, Set_Days_Text_19, Set_Days_Text_20, Set_Days_Text_21, Set_Days_Text_22, Set_Days_Text_23, Set_Days_Text_24, Set_Days_Text_25, Set_Days_Text_26, Set_Days_Text_27
	switch VAR_RESULT
	case 0, Set_Days_3
	case 1, Set_Days_4
	case 2, Set_Days_5
	case 3, Set_Days_6
	case 4, Set_Days_7
	case 5, Set_Days_8
	case 6, Set_Days_9
	case 7, Set_Days_10
	case 8, Set_Days_11
	case 9, Set_Days_12
	case 10, Set_Days_13
	case 11, Set_Days_14
	case 12, Set_Days_15
	case 13, Set_Days_16
	case 14, Set_Days_17
	case 15, Set_Days_18
	case 16, Set_Days_19
	case 17, Set_Days_20
	case 18, Set_Days_21
	case 19, Set_Days_22
	case 20, Set_Days_23
	case 21, Set_Days_24
	case 22, Set_Days_25
	case 23, Set_Days_26
	case 24, Set_Days_27
	case 25, Set_Days_28
	case 26, Set_Days_29
	case 27, Set_Days_30
Set_Days_1:
	releaseall
	return

Set_Days_3:
	setday 1
	releaseall
	goto Set_Days_1

Set_Days_4:
	setday 2
	releaseall
	goto Set_Days_1

Set_Days_5:
	setday 3
	releaseall
	goto Set_Days_1

Set_Days_6:
	setday 4
	releaseall
	goto Set_Days_1

Set_Days_7:
	setday 5
	releaseall
	goto Set_Days_1

Set_Days_8:
	setday 6
	releaseall
	goto Set_Days_1

Set_Days_9:
	setday 7
	releaseall
	goto Set_Days_1

Set_Days_10:
	setday 8
	releaseall
	goto Set_Days_1

Set_Days_11:
	setday 9
	releaseall
	goto Set_Days_1

Set_Days_12:
	setday 10
	releaseall
	goto Set_Days_1

Set_Days_13:
	setday 11
	releaseall
	goto Set_Days_1

Set_Days_14:
	setday 12
	releaseall
	goto Set_Days_1

Set_Days_15:
	setday 13
	releaseall
	goto Set_Days_1

Set_Days_16:
	setday 14
	releaseall
	goto Set_Days_1

Set_Days_17:
	setday 15
	releaseall
	goto Set_Days_1

Set_Days_18:
	setday 16
	releaseall
	goto Set_Days_1

Set_Days_19:
	setday 17
	releaseall
	goto Set_Days_1

Set_Days_20:
	setday 18
	releaseall
	goto Set_Days_1

Set_Days_21:
	setday 19
	releaseall
	goto Set_Days_1

Set_Days_22:
	setday 20
	releaseall
	goto Set_Days_1

Set_Days_23:
	setday 21
	releaseall
	goto Set_Days_1

Set_Days_24:
	setday 22
	releaseall
	goto Set_Days_1

Set_Days_25:
	setday 23
	releaseall
	goto Set_Days_1

Set_Days_26:
	setday 24
	releaseall
	goto Set_Days_1

Set_Days_27:
	setday 25
	releaseall
	goto Set_Days_1

Set_Days_28:
	setday 26
	releaseall
	goto Set_Days_1

Set_Days_29:
	setday 27
	releaseall
	goto Set_Days_1

Set_Days_30:
	setday 28
	releaseall
	goto Set_Days_1


Set_Hours:
	dynmultichoice 1, 1, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, Set_Hours_Text_0, Set_Hours_Text_1, Set_Hours_Text_2, Set_Hours_Text_3, Set_Hours_Text_4, Set_Hours_Text_5, Set_Hours_Text_6, Set_Hours_Text_7, Set_Hours_Text_8, Set_Hours_Text_9, Set_Hours_Text_10, Set_Hours_Text_11, Set_Hours_Text_12, Set_Hours_Text_13, Set_Hours_Text_14, Set_Hours_Text_15, Set_Hours_Text_16, Set_Hours_Text_17, Set_Hours_Text_18, Set_Hours_Text_19, Set_Hours_Text_20, Set_Hours_Text_21, Set_Hours_Text_22, Set_Hours_Text_23
	switch VAR_RESULT
	case 0, Set_Hours_3
	case 1, Set_Hours_4
	case 2, Set_Hours_5
	case 3, Set_Hours_6
	case 4, Set_Hours_7
	case 5, Set_Hours_8
	case 6, Set_Hours_9
	case 7, Set_Hours_10
	case 8, Set_Hours_11
	case 9, Set_Hours_12
	case 10, Set_Hours_13
	case 11, Set_Hours_14
	case 12, Set_Hours_15
	case 13, Set_Hours_16
	case 14, Set_Hours_17
	case 15, Set_Hours_18
	case 16, Set_Hours_19
	case 17, Set_Hours_20
	case 18, Set_Hours_21
	case 19, Set_Hours_22
	case 20, Set_Hours_23
	case 21, Set_Hours_24
	case 22, Set_Hours_25
	case 23, Set_Hours_26
Set_Hours_1:
	releaseall
	return

Set_Hours_3:
	sethour 0
	releaseall
	goto Set_Hours_1

Set_Hours_4:
	sethour 1
	releaseall
	goto Set_Hours_1

Set_Hours_5:
	sethour 2
	releaseall
	goto Set_Hours_1

Set_Hours_6:
	sethour 3
	releaseall
	goto Set_Hours_1

Set_Hours_7:
	sethour 4
	releaseall
	goto Set_Hours_1

Set_Hours_8:
	sethour 5
	releaseall
	goto Set_Hours_1

Set_Hours_9:
	sethour 6
	releaseall
	goto Set_Hours_1

Set_Hours_10:
	sethour 7
	releaseall
	goto Set_Hours_1

Set_Hours_11:
	sethour 8
	releaseall
	goto Set_Hours_1

Set_Hours_12:
	sethour 9
	releaseall
	goto Set_Hours_1

Set_Hours_13:
	sethour 10
	releaseall
	goto Set_Hours_1

Set_Hours_14:
	sethour 11
	releaseall
	goto Set_Hours_1

Set_Hours_15:
	sethour 12
	releaseall
	goto Set_Hours_1

Set_Hours_16:
	sethour 13
	releaseall
	goto Set_Hours_1

Set_Hours_17:
	sethour 14
	releaseall
	goto Set_Hours_1

Set_Hours_18:
	sethour 15
	releaseall
	goto Set_Hours_1

Set_Hours_19:
	sethour 16
	releaseall
	goto Set_Hours_1

Set_Hours_20:
	sethour 17
	releaseall
	goto Set_Hours_1

Set_Hours_21:
	sethour 18
	releaseall
	goto Set_Hours_1

Set_Hours_22:
	sethour 19
	releaseall
	goto Set_Hours_1

Set_Hours_23:
	sethour 20
	releaseall
	goto Set_Hours_1

Set_Hours_24:
	sethour 21
	releaseall
	goto Set_Hours_1

Set_Hours_25:
	sethour 22
	releaseall
	goto Set_Hours_1

Set_Hours_26:
	sethour 23
	releaseall
	goto Set_Hours_1


WaitingMenu_Text_0:
	.string "Add time$"

WaitingMenu_Text_1:
	.string "Set time$"

Add_Time_Text_0:
	.string "Add Day$"

Add_Time_Text_1:
	.string "Add Hour$"

Add_Days_Text_0:
	.string "Add 1$"

Add_Days_Text_1:
	.string "Add 6$"

Add_Days_Text_2:
	.string "Add 12$"

Add_Days_Text_3:
	.string "You wait for a while…$"

Set_Time_Text_0:
	.string "Set Day$"

Set_Time_Text_1:
	.string "Set Hour$"

Set_Days_Text_0:
	.string "Set Day 1$"

Set_Days_Text_1:
	.string "Set Day 2$"

Set_Days_Text_2:
	.string "Set Day 3$"

Set_Days_Text_3:
	.string "Set Day 4$"

Set_Days_Text_4:
	.string "Set Day 5$"

Set_Days_Text_5:
	.string "Set Day 6$"

Set_Days_Text_6:
	.string "Set Day 7$"

Set_Days_Text_7:
	.string "Set Day 8$"

Set_Days_Text_8:
	.string "Set Day 9$"

Set_Days_Text_9:
	.string "Set Day 10$"

Set_Days_Text_10:
	.string "Set Day 11$"

Set_Days_Text_11:
	.string "Set Day 12$"

Set_Days_Text_12:
	.string "Set Day 13$"

Set_Days_Text_13:
	.string "Set Day 14$"

Set_Days_Text_14:
	.string "Set Day 15$"

Set_Days_Text_15:
	.string "Set Day 16$"

Set_Days_Text_16:
	.string "Set Day 17$"

Set_Days_Text_17:
	.string "Set Day 18$"

Set_Days_Text_18:
	.string "Set Day 19$"

Set_Days_Text_19:
	.string "Set Day 20$"

Set_Days_Text_20:
	.string "Set Day 21$"

Set_Days_Text_21:
	.string "Set Day 22$"

Set_Days_Text_22:
	.string "Set Day 23$"

Set_Days_Text_23:
	.string "Set Day 24$"

Set_Days_Text_24:
	.string "Set Day 25$"

Set_Days_Text_25:
	.string "Set Day 26$"

Set_Days_Text_26:
	.string "Set Day 27$"

Set_Days_Text_27:
	.string "Set Day 28$"

Set_Hours_Text_0:
	.string "Set Hour 0$"

Set_Hours_Text_1:
	.string "Set Hour 1$"

Set_Hours_Text_2:
	.string "Set Hour 2$"

Set_Hours_Text_3:
	.string "Set Hour 3$"

Set_Hours_Text_4:
	.string "Set Hour 4$"

Set_Hours_Text_5:
	.string "Set Hour 5$"

Set_Hours_Text_6:
	.string "Set Hour 6$"

Set_Hours_Text_7:
	.string "Set Hour 7$"

Set_Hours_Text_8:
	.string "Set Hour 8$"

Set_Hours_Text_9:
	.string "Set Hour 9$"

Set_Hours_Text_10:
	.string "Set Hour 10$"

Set_Hours_Text_11:
	.string "Set Hour 11$"

Set_Hours_Text_12:
	.string "Set Hour 12$"

Set_Hours_Text_13:
	.string "Set Hour 13$"

Set_Hours_Text_14:
	.string "Set Hour 14$"

Set_Hours_Text_15:
	.string "Set Hour 15$"

Set_Hours_Text_16:
	.string "Set Hour 16$"

Set_Hours_Text_17:
	.string "Set Hour 17$"

Set_Hours_Text_18:
	.string "Set Hour 18$"

Set_Hours_Text_19:
	.string "Set Hour 19$"

Set_Hours_Text_20:
	.string "Set Hour 20$"

Set_Hours_Text_21:
	.string "Set Hour 21$"

Set_Hours_Text_22:
	.string "Set Hour 22$"

Set_Hours_Text_23:
	.string "Set Hour 23$"
