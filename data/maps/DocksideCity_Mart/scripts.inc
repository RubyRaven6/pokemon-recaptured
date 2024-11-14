DocksideCity_Mart_MapScripts::
	.byte 0


DocksideCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart DocksideCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end


	.align 2
DocksideCity_Mart_Pokemart:
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NONE
