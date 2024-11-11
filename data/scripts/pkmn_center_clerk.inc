GeneralMart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE08_GET, GeneralMart_EventScript_Clerk_2
GeneralMart_EventScript_Clerk_1:
	goto_if_set FLAG_BADGE05_GET, GeneralMart_EventScript_Clerk_5
GeneralMart_EventScript_Clerk_4:
	goto_if_set FLAG_BADGE01_GET, GeneralMart_EventScript_Clerk_8
	pokemart Generic_MartItems_Tier0
GeneralMart_EventScript_Clerk_7:
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GeneralMart_EventScript_Clerk_2:
	pokemart Generic_MartItems_Tier3
	goto GeneralMart_EventScript_Clerk_1

GeneralMart_EventScript_Clerk_5:
	pokemart Generic_MartItems_Tier2
	goto GeneralMart_EventScript_Clerk_4

GeneralMart_EventScript_Clerk_8:
	pokemart Generic_MartItems_Tier1
	goto GeneralMart_EventScript_Clerk_7


	.align 2
Generic_MartItems_Tier0:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

	.align 2
Generic_MartItems_Tier1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_NONE

	.align 2
Generic_MartItems_Tier2:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_NONE

	.align 2
Generic_MartItems_Tier3:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_NONE
