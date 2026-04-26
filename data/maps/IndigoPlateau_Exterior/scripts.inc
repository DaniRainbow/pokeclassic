IndigoPlateau_Exterior_MapScripts::
	.byte 0

IndigoPlateau_Exterior_EventScript_Charizard::
	lock
	faceplayer
    goto_if_set FLAG_DEFEATED_NICK, IndigoPlateau_Exterior_EventScript_CharizardDefeated
	msgbox IndigoPlateau_Exterior_Text_Charizard MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_Text_Charizard:
	.string "{PLAYER}.\p"
	.string "I have surpassed my natural limits.\n"
	.string "If you dare to challenge us, good luck.$"

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
	.string "I came to the Battle Tower to fight\n"
	.string "against the finest Trainers Kanto\l"
	.string "has to offer.\p"
	.string "Now that it is closed, I meditate\n"
	.string "to prepare myself for a challenger.\p"
	.string "We are strong in mind and body.$"

IndigoPlateau_Exterior_Text_NickDefeat:
	.string "Incredible... how...?$"

IndigoPlateau_Exterior_Text_NickPostBattle:
	.string "Is this a dream?$"

IndigoPlateau_Exterior_EventScript_MegaHintCharizard::    
    goto_if_set FLAG_GOT_CHARIZARDITE_X, IndigoPlateau_Exterior_EventScript_NickDefeated
    msgbox IndigoPlateau_Exterior_Text_CharizardMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
IndigoPlateau_Exterior_Text_CharizardMegaHint:
    .string "Pokemon Mansion.$"

IndigoPlateau_Exterior_EventScript_NickDefeated::
    msgbox NickDefeated_Text MSGBOX_DEFAULT
	release
	end

NickDefeated_Text:	
	.string "I came here to fight the best\n"
	.string "and that's exactly what you are.$"

IndigoPlateau_Exterior_EventScript_CharizardDefeated::
	msgbox CharizardDefeated MSGBOX_DEFAULT
	release
	end

CharizardDefeated:	
	.string "You are a worthy opponent and\n"
	.string "have earned my respect.$"
