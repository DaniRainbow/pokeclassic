PokemonMansion_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_1F_OnTransition
	.byte 0

PokemonMansion_1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_1F
	end

PokemonMansion_1F_OnTransition::
	end

PokemonMansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_SCIENTIST_TED, PokemonMansion_1F_Text_TedIntro, PokemonMansion_1F_Text_TedDefeat
	msgbox PokemonMansion_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_TedIntro::
    .string "Who are you?\n"
    .string "There shouldn't be anyone here.$"

PokemonMansion_1F_Text_TedDefeat::
    .string "Ouch!$"

PokemonMansion_1F_Text_TedPostBattle::
    .string "A key? I don't know what you're\n"
    .string "talking about.$"

PokemonMansion_1F_EventScript_Johnson::
	trainerbattle_single TRAINER_YOUNGSTER_JOHNSON, PokemonMansion_1F_Text_JohnsonIntro, PokemonMansion_1F_Text_JohnsonDefeat
	msgbox PokemonMansion_1F_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_JohnsonIntro::
    .string "W-w-waah! You startled me!\n"
    .string "I thought you were a ghost.$"

PokemonMansion_1F_Text_JohnsonDefeat::
    .string "Tch!\n"
    .string "I can't get any wins.$"

PokemonMansion_1F_Text_JohnsonPostBattle::
    .string "I was exploring here by myself,\n"
    .string "but I feel spooked.\p"
    .string "I ought to go soon.$"

PokemonMansion_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

PokemonMansion_1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN, 1
	release
	end

PokemonMansion_1F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS, 1
	release
	end

PokemonMansion_1F_EventScript_ItemBlackSludge::
	finditem ITEM_BLACK_SLUDGE, 1
	release
	end

PokemonMansion_1F_EventScript_Alakazam::
	lock
	faceplayer
    goto_if_set FLAG_DEFEATED_JUSTICE, PokemonMansion_1F_EventScript_AlakazamDefeated
	msgbox PokemonMansion_1F_Text_Alazakam MSGBOX_DEFAULT
	release
	end

PokemonMansion_1F_Text_Alakazam:
	.string "{PLAYER}.\p"
	.string "I have surpassed my natural limits.\n"
	.string "If you dare to challenge us, good luck.$"

PokemonMansion_1F_EventScript_GentlemanJustice::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_JUSTICE, PokemonMansion_1F_EventScript_MegaHintAlakazam
	trainerbattle_single TRAINER_GENTLEMAN_JUSTICE, PokemonMansion_1F_Text_JusticeIntro, PokemonMansion_1F_Text_JusticeDefeat
	setflag FLAG_DEFEATED_JUSTICE
	msgbox PokemonMansion_1F_Text_JusticePostBattle MSGBOX_AUTOCLOSE
	release
	end

PokemonMansion_1F_Text_JusticerIntro:
	.string "I came to the Battle Tower to fight\n"
	.string "against the finest Trainers Kanto\l"
	.string "has to offer.\p"
	.string "Now that it is closed, I meditate\n"
	.string "to prepare myself for a challenger.\p"
	.string "We are strong in mind and body.$"

PokemonMansion_1F_Text_JusticeDefeat:
	.string "Incredible... how...?$"

PokemonMansion_1F_Text_JusticePostBattle:
	.string "Is this a dream?$"

PokemonMansion_1F_EventScript_MegaHintAlakazam::    
    goto_if_set FLAG_GOT_MEGAITEM, PokemonMansion_1F_EventScript_TrainerDefeated
    msgbox PokemonMansion_1F_Text_PokemonMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
PokemonMansion_1F_Text_PokemonMegaHint:
    .string "Hint where to find Mega Stone.$"

PokemonMansion_1F_EventScript_TrainerDefeated::
    msgbox TrainerDefeated_Text MSGBOX_DEFAULT
	release
	end

TrainerDefeated_Text:	
	.string "I came here to fight the best\n"
	.string "and that's exactly what you are.$"

PokemonMansion_1F_EventScript_PokemonDefeated::
	msgbox PokemonDefeated MSGBOX_DEFAULT
	release
	end

PokemonDefeated:	
	.string "You are a worthy opponent and\n"
	.string "have earned my respect.$"
