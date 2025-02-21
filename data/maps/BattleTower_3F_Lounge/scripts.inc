BattleTower_3F_Lounge_MapScripts::
	.byte 0

//BattleTower_3F_Lounge_Text_HiIAmJiraiya:
	//.string "UGH it's infuriating, I tell you!\p"
	//.string "I came all this way for a battle\n"
	//.string "against the finest Trainers Kanto\l"
	//.string "has to offer and the owner shut\l"
	//.string "down all the matches!\p"
	//.string "Come back later and I will prove\n"
	//.string "I'm the best there ever was!$"
	//return

BattleTower_3F_Lounge_EventScript_Mewtwo::
	lock
	faceplayer
	msgbox BattleTower_3F_Lounge_Text_Mewtwo MSGBOX_DEFAULT
	release
	end

BattleTower_3F_Lounge_Text_Mewtwo:
	.string "What's up, {PLAYER}?\p"
	.string "I should warn you, the Pokémon on our\n"
	.string "team are capable of Mega Evolution.\p" 
	.string "I have surpassed my natural limits.\n"
	.string "If you dare to challenge us, good luck.$"
	return

BattleTower_3F_Lounge_EventScript_BlackBeltJiraiya::
	trainerbattle_single TRAINER_BLACKBELT_JIRAIYA, BattleTower_3F_Lounge_Text_JiraiyaIntro, BattleTower_3F_Lounge_Text_JiraiyaDefeat
	msgbox BattleTower_3F_Lounge_Text_JiraiyaPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

BattleTower_3F_Lounge_Text_JiraiyaIntro:
	.string "First impressions\n"
	.string "are important.$"

BattleTower_3F_Lounge_Text_JiraiyaDefeat:
	.string "What you want to say!$"

BattleTower_3F_Lounge_Text_JiraiyaPostBattle:
	.string "What you want to say!$"

