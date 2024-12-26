Route_6_MapScripts::
	.byte 0


SetTheTime::
	msgbox SetTheTime_Text_0
	waitmessage
	closemessage
	settime 1, 22, 32
	releaseall
	return


Addtime::
	msgbox Addtime_Text_0
	waitmessage
	closemessage
	addtime 2, 20
	releaseall
	return


SetTheTime_Text_0:
	.string "This sets the time to Monday, 10:32 PM$"

Addtime_Text_0:
	.string "Adds 2 hours and 20 minutes$"
