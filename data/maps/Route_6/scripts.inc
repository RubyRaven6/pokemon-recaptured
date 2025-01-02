Route_6_MapScripts::
	.byte 0


SetTheTime::
	msgbox SetTheTime_Text_0
	dynmultichoice 3, 3, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, SetTheTime_Text_1, SetTheTime_Text_2
	switch VAR_RESULT
	case 0, SetTheTime_2
	case 1, SetTheTime_3
	return

SetTheTime_2:
	call SetTheTimeDate
	closemessage
	end

SetTheTime_3:
	call SetTheTimeJustTime
	closemessage
	end


SetTheTimeDate::
	dynmultichoice 3, 3, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, SetTheTimeDate_Text_0, SetTheTimeDate_Text_1, SetTheTimeDate_Text_2, SetTheTimeDate_Text_3, SetTheTimeDate_Text_4, SetTheTimeDate_Text_5, SetTheTimeDate_Text_6
	switch VAR_RESULT
	case 0, SetTheTimeDate_2
	case 1, SetTheTimeDate_3
	case 2, SetTheTimeDate_4
	case 3, SetTheTimeDate_5
	case 4, SetTheTimeDate_6
	case 5, SetTheTimeDate_7
	case 6, SetTheTimeDate_8
	return

SetTheTimeDate_2:
	setweekday 0
	closemessage
	end

SetTheTimeDate_3:
	setweekday 1
	closemessage
	end

SetTheTimeDate_4:
	setweekday 2
	closemessage
	end

SetTheTimeDate_5:
	setweekday 3
	closemessage
	end

SetTheTimeDate_6:
	setweekday 4
	closemessage
	end

SetTheTimeDate_7:
	setweekday 5
	closemessage
	end

SetTheTimeDate_8:
	setweekday 6
	closemessage
	end


SetTheTimeJustTime::
	dynmultichoice 3, 3, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, SetTheTimeJustTime_Text_0, SetTheTimeJustTime_Text_1, SetTheTimeJustTime_Text_2, SetTheTimeJustTime_Text_3
	switch VAR_RESULT
	case 0, SetTheTimeJustTime_2
	case 1, SetTheTimeJustTime_3
	case 2, SetTheTimeJustTime_4
	case 3, SetTheTimeJustTime_5
	return

SetTheTimeJustTime_2:
	forwardtime 0, 0
	closemessage
	end

SetTheTimeJustTime_3:
	forwardtime 6, 0
	closemessage
	end

SetTheTimeJustTime_4:
	forwardtime 12, 0
	closemessage
	end

SetTheTimeJustTime_5:
	forwardtime 18, 0
	closemessage
	end


Addtime::
	msgbox Addtime_Text_0
	waitmessage
	closemessage
	addtime 2, 20
	releaseall
	return


SetTheTime_Text_0:
	.string "Set the time you like.$"

SetTheTime_Text_1:
	.string "Weekday$"

SetTheTime_Text_2:
	.string "Time$"

SetTheTimeDate_Text_0:
	.string "Sunday$"

SetTheTimeDate_Text_1:
	.string "Monday$"

SetTheTimeDate_Text_2:
	.string "Tuesday$"

SetTheTimeDate_Text_3:
	.string "Wednesday$"

SetTheTimeDate_Text_4:
	.string "Thursday$"

SetTheTimeDate_Text_5:
	.string "Friday$"

SetTheTimeDate_Text_6:
	.string "Saturday$"

SetTheTimeJustTime_Text_0:
	.string "12 AM$"

SetTheTimeJustTime_Text_1:
	.string "6AM$"

SetTheTimeJustTime_Text_2:
	.string "12 PM$"

SetTheTimeJustTime_Text_3:
	.string "6 PM$"

Addtime_Text_0:
	.string "Adds 2 hours and 20 minutes$"
