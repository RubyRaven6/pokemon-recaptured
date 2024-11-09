DocksideCity_MapScripts::
	.byte 0


DocksideCity_EventScript_SailorMachoke::
	faceplayer
	msgbox DocksideCity_Text_SailorMachoke, MSGBOX_NPC
	waitmessage
	closemessage
	faceawayplayer 0
	end


DocksideCity_EventScript_SailorPoliwrath::
	msgbox DocksideCity_Text_SailorPoliwrath, MSGBOX_NPC
	waitmessage
	closemessage
	return


DocksideCity_EventScript_SailorSpectator::
	msgbox DocksideCity_Text_SailorSpectator, MSGBOX_NPC
	waitmessage
	closemessage
	return


DocksideCity_Text_SailorMachoke:
	.string "Im the Machoke trainer.$"

DocksideCity_Text_SailorPoliwrath:
	.string "Im the Poliwrath trainer.$"

DocksideCity_Text_SailorSpectator:
	.string "Im the spectator.$"
