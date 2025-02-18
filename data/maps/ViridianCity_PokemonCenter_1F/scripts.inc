.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
    .string "Please feel free to use that PC in\n"
    .string "the corner.\p"
    .string "The receptionist told me so.\n"
    .string "It's so kind of her!$"

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
    .string "Pokémon Centers heal your tired,\n"
    .string "hurt, or fainted Pokémon.\p"
    .string "They make all Pokémon completely\n"
    .string "healthy.$"

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
    .string "There's a Pokémon Center in every\n"
    .string "town ahead.\p"
    .string "They charge no money, so don't\n"
    .string "be shy about healing Pokémon.\p"
	.string "The second floor of these centers\n"
	.string "act as a meet-up place for more\l"
	.string "serious trainers.\p"
	.string "You may be surprised what you\n"
	.string "find, so be sure when you visit\l"
	.string "a new center to check the second\l"
	.string "floor and introduce yourself!$"
