IndigoPlateau_Exterior_MapScripts::
	.byte 0

IndigoPlateau_Exterior_EventScript_Charizard::
	lock
	faceplayer
    playmoncry SPECIES_CHARIZARD, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_NICK, IndigoPlateau_Exterior_EventScript_CharizardDefeated
	msgbox IndigoPlateau_Exterior_Text_Charizard MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_Text_Charizard:
	.string "Charizard snorts as it glares.$"

IndigoPlateau_Exterior_EventScript_DragonTamerNick::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_NICK, IndigoPlateau_Exterior_EventScript_MegaHintCharizard
	trainerbattle_single TRAINER_DRAGONTAMER_NICK, IndigoPlateau_Exterior_Text_NickIntro, IndigoPlateau_Exterior_Text_NickDefeat
	setflag FLAG_DEFEATED_NICK
	msgbox IndigoPlateau_Exterior_Text_NickPostBattle MSGBOX_AUTOCLOSE
	release
	end

IndigoPlateau_Exterior_Text_NickIntro:
	.string "Oh good! Practice!$"

IndigoPlateau_Exterior_Text_NickDefeat:
	.string "Ha ha, yes!$"

IndigoPlateau_Exterior_Text_NickPostBattle:
	.string "I'm all fired up now!$"

IndigoPlateau_Exterior_EventScript_MegaHintCharizard::    
    goto_if_set FLAG_GOT_CHARIZARDITE_X, IndigoPlateau_Exterior_EventScript_NickDefeated
    msgbox IndigoPlateau_Exterior_Text_CharizardMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
IndigoPlateau_Exterior_Text_CharizardMegaHint:
    .string "If you want a Charizard as impressive\n"
	.string "as mine, check the Pokémon Mansion.$"

IndigoPlateau_Exterior_EventScript_NickDefeated::
    msgbox NickDefeated_Text MSGBOX_DEFAULT
	release
	end

NickDefeated_Text:	
	.string "My Charizard's flame burns so strongly\n"
	.string "it is able to go swimming without\l"
	.string "its tail going out!$"

IndigoPlateau_Exterior_EventScript_CharizardDefeated::
	msgbox CharizardDefeated MSGBOX_DEFAULT
	release
	end

CharizardDefeated:	
	.string "Charizard looks annoyed with you.\n"
	.string "It swishes its tail, exhaling smoke.$"
