DocksideCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DocksideCity_PokemonCenter_1F_OnTransition
	.byte 0


DocksideCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_DOCKSIDE_CITY
	setvar VAR_DOCKED_CITY, 1
	end


DocksideCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

