LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_Text_DoYouBelieveInGhosts::
    .string "Do you believe in ghosts?$"

LavenderTown_Text_JustImaginingWhiteHand::
    .string "Hahaha, I guess not.\p"
    .string "That white hand on your shoulder…\n"
    .string "I'm just imagining it.$"


LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_Text_SoThereAreBelievers::
    .string "Really?\n"
    .string "So there are believers…$"

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_Text_TownKnownAsMonGraveSite::
    .string "This town is known as the grave\n"
    .string "site of Pokémon.\p"
    .string "Memorial services are held in\n"
    .string "Pokémon Tower.$"

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_Text_GhostsAppearedInTower::
    .string "Ghosts appeared in Pokémon Tower.\p"
    .string "I think they're the spirits of\n"
    .string "Pokémon that the Rockets killed.$"

LavenderTown_Text_TownSign::
    .string "Lavender Town\n"
    .string "The Noble Purple Town$"

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_TrainerTips::
	msgbox LavenderTown_Text_TrainerTips, MSGBOX_SIGN
	end

LavenderTown_Text_TrainerTips::
    .string "Trainer Tips!\n"
    .string "Hold the A Button to walk quietly\n"
    .string "when using your PokéNav!$"

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_Text_VolunteerPokemonHouse::
    .string "Lavender Volunteer\n"
    .string "Pokémon House$"

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokemonTowerSign::
    .string "Pokémon Tower\n"
    .string "Becalm the Spirits of Pokémon$"

LavenderTown_EventScript_Gengar::
	lock
	faceplayer
	playmoncry SPECIES_GENGAR, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_KISHI, LavenderTown_EventScript_GengarDefeated
	msgbox LavenderTown_Text_Gengar MSGBOX_DEFAULT
	release
	end

LavenderTown_Text_Gengar:
	.string "You hear the sound of a squeaky carousel\n"
	.string "spinning in an empty playground.\p"
	.string "Gengar chuckles as the noise fades.$"

LavenderTown_EventScript_BeautyKishi::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KISHI, LavenderTown_EventScript_MegaHintGengar
	goto_if_set FLAG_GOT_MEGA_RING, LavenderTown_EventScript_BeautyKishiBattle
	msgbox LavenderTown_Text_KishiDoYouBelieve MSGBOX_NPC
	release
	end

LavenderTown_Text_KishiDoYouBelieve:
	.string "Tell me, young one.\n"
	.string "Do you believe in ghosts?$"

LavenderTown_EventScript_BeautyKishiBattle::
	trainerbattle_single TRAINER_BEAUTY_KISHI, LavenderTown_Text_KishiIntro, LavenderTown_Text_KishiDefeat
	setflag FLAG_DEFEATED_KISHI
	msgbox LavenderTown_Text_KishiPostBattle MSGBOX_AUTOCLOSE
	release
	end

LavenderTown_Text_KishiIntro:
	.string "Tell me, young one.\n"
	.string "Do you believe in ghosts?\p"
	.string "Seeing is believing. Now that\n"
	.string "you can see, we can begin.$"

LavenderTown_Text_KishiDefeat:
	.string "All is well that ends well.$"

LavenderTown_Text_KishiPostBattle:
	.string "What you choose to believe in\n"
	.string "will haunt the world when you\l"
	.string "depart from this life.$"

LavenderTown_EventScript_MegaHintGengar::    
    goto_if_set FLAG_GOT_GENGARITE, LavenderTown_EventScript_KishiDefeated
    msgbox LavenderTown_Text_GengarMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
LavenderTown_Text_GengarMegaHint:
    .string "Marowak and I believe you are\n"
	.string "a kind trainer, so please\l"
	.string "climb to the top of the Tower.$"

LavenderTown_EventScript_KishiDefeated::
    msgbox KishiDefeated_Text MSGBOX_DEFAULT
	release
	end

KishiDefeated_Text:	
	.string "What you choose to believe in\n"
	.string "will haunt the world when you\l"
	.string "depart from this life.\p"
	.string "Believe there is good to be\n"
	.string "found in this world.$"

LavenderTown_EventScript_GengarDefeated::
	msgbox GengarDefeated MSGBOX_DEFAULT
	release
	end

GengarDefeated:	
	.string "Gengar rolls its eyes and sticks\n"
	.string "out its tongue in good fun.$"
