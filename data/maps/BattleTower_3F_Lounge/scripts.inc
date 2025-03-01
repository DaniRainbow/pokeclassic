BattleTower_3F_Lounge_MapScripts::
	.byte 0

BattleTower_3F_Lounge_Text_HiIAmJiraiya:
	.string "I came to the Battle Tower to fight\n"
	.string "against the finest Trainers Kanto\l"
	.string "has to offer.\p"
	.string "Now that it is closed, I meditate\n"
	.string "to prepare myself for a challenger.\p"
	.string "... what's that? Are you saying\n"
	.string "you will battle me?$"

BattleTower_3F_Lounge_EventScript_Mewtwo::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_JIRAIYA, BattleTower_3F_Lounge_EventScript_MewtwoDefeated
	msgbox BattleTower_3F_Lounge_Text_Mewtwo MSGBOX_DEFAULT
	release
	end

BattleTower_3F_Lounge_Text_Mewtwo:
	.string "{PLAYER}.\p"
	.string "I have surpassed my natural limits.\n"
	.string "If you dare to challenge us, good luck.$"

BattleTower_3F_Lounge_EventScript_BlackBeltJiraiya::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_JIRAIYA, BattleTower_3F_Lounge_EventScript_BlackBeltJiraiyaDefeated
	msgbox BattleTower_3F_Lounge_Text_HiIAmJiraiya, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BlackBeltDeclined
	trainerbattle_single TRAINER_BLACKBELT_JIRAIYA, BattleTower_3F_Lounge_Text_JiraiyaIntro, BattleTower_3F_Lounge_Text_JiraiyaDefeat
	setflag FLAG_DEFEATED_JIRAIYA
	msgbox BattleTower_3F_Lounge_Text_JiraiyaPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

BattleTower_3F_Lounge_Text_JiraiyaIntro:
	.string "We are strong in mind and body.$"

BattleTower_3F_Lounge_Text_JiraiyaDefeat:
	.string "Incredible... how...?$"

BattleTower_3F_Lounge_Text_JiraiyaPostBattle:
	.string "Is this a dream?$"

BlackBeltDeclined::
	msgbox	Text_IWouldNotEither, MSGBOX_DEFAULT
	release
	end

Text_IWouldNotEither:
	.string "Do not interrupt my meditation.\n"
	.string "Move on, then.$"

BattleTower_3F_Lounge_EventScript_BlackBeltJiraiyaDefeated::
	msgbox JiraiyaDefeated MSGBOX_DEFAULT
	releaseall
	end

JiraiyaDefeated:	
	.string "I came here to fight the best\n"
	.string "and that's exactly what you are.$"


BattleTower_3F_Lounge_EventScript_MewtwoDefeated::
	msgbox MewtwoDefeated MSGBOX_DEFAULT
	releaseall
	end

MewtwoDefeated:	
	.string "You are a worthy opponent and\n"
	.string "have earned my respect.$"

