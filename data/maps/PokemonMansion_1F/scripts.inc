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
	msgbox PokemonMansion_1F_Text_Alakazam MSGBOX_DEFAULT
	release
	end

PokemonMansion_1F_Text_Alakazam:
	.string "Alakazam reaches into your mind.\n"
	.string "It wishes to battle your team.$"

PokemonMansion_1F_EventScript_GentlemanJustice::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_JUSTICE, PokemonMansion_1F_EventScript_MegaHintAlakazam
	trainerbattle_single TRAINER_GENTLEMAN_JUSTICE, PokemonMansion_1F_Text_JusticeIntro, PokemonMansion_1F_Text_JusticeDefeat
	setflag FLAG_DEFEATED_JUSTICE
	msgbox PokemonMansion_1F_Text_JusticePostBattle MSGBOX_AUTOCLOSE
	release
	end

PokemonMansion_1F_Text_JusticeIntro:
	.string "Greetings! I'm Justice.\p"
	.string "I had an acquiantence who lived\n"
	.string "here decades ago and wanted to\l"
	.string "journey down memory lane.\p"
	.string "You're the Champion! Well well.\n"
	.string "How about a match?$"

PokemonMansion_1F_Text_JusticeDefeat:
	.string "You live up to the title!$"

PokemonMansion_1F_Text_JusticePostBattle:
	.string "The best battles happen in the\n"
	.string "most unexpected places, I find.$"

PokemonMansion_1F_EventScript_MegaHintAlakazam::    
    goto_if_set FLAG_GOT_ALAKAZITE, PokemonMansion_1F_EventScript_JusticeDefeated
    msgbox PokemonMansion_1F_Text_AlakazamMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
PokemonMansion_1F_Text_AlakazamMegaHint:
    .string "Visit an acquiantence in Saffron.$"

PokemonMansion_1F_EventScript_JusticeDefeated::
    msgbox JusticeDefeated_Text MSGBOX_DEFAULT
	release
	end

JusticeDefeated_Text:	
	.string "Do you happen to know Professor Oak?\p"
	.string "... I see, so you are one of his\n"
	.string "assistants he sends out for data.\p"
	.string "... Oh, you've defeated him in a\n"
	.string "Champion match as well? Fascinating!\p"
	.string "I knew Samuel Oak back when he was a\n"
	.string "child competing in the League.\p"
	.string "I held the Chamption Title for many\n"
	.string "years until he challenged me.\p"
	.string "I'm honored to have witnessed two\n"
	.string "prodigies rise above my heights.$"

PokemonMansion_1F_EventScript_AlakazamDefeated::
	msgbox AlakazamDefeated MSGBOX_DEFAULT
	release
	end

AlakazamDefeated:	
	.string "KA ZAM!\p"
	.string "... images of a Mega Alakazam\n"
	.string "holding a Life Orb and Mega Stone\l"
	.string "aggressively flood your mind.$"
