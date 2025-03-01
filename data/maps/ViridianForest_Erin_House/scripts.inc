ViridianForest_Erin_House_MapScripts::
	.byte 0

ViridianForest_Erin_House_EventScript_Clefairy::
	lock
	faceplayer
	msgbox ViridianForest_Erin_House_Text_Clefairy MSGBOX_DEFAULT
	waitmessage
	msgbox ViridianForest_Erin_House_Text_ClefairyBerryGiven MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_ORAN_BERRY, 1
	release
	end

ViridianForest_Erin_House_Text_Clefairy:
	.string "Clefairy?$"
	return

ViridianForest_Erin_House_Text_ClefairyBerryGiven:
	.string "Clef fairy!$"	
	return

ViridianForest_Erin_House_EventScript_CoolTrainerErin::
	goto_if_set FLAG_DEFEATED_ERIN, ViridianForest_Erin_House_Defeated
	trainerbattle_single TRAINER_COOLTRAINER_ERIN, ViridianForest_Erin_House_Text_ErinIntro, ViridianForest_Erin_House_Text_ErinDefeat
	setflag FLAG_DEFEATED_ERIN
	msgbox ViridianForest_Erin_House_Text_ErinPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

ViridianForest_Erin_House_Text_ErinIntro:
	.string "Oh, hello again {PLAYER}!\p"
	.string "Congrats on becoming the Champion!\p"
	.string "Hard to believe that new trainer\n"
	.string "I met a while back is now the new\l"
	.string "Champion of Kanto.\p"
	.string "...\p"
	.string "Champion {PLAYER}, I challenge\n"
	.string "you to a Pokémon battle!$"

ViridianForest_Erin_House_Text_ErinDefeat:
	.string "Wow, Champion indeed!$"

ViridianForest_Erin_House_Text_ErinPostBattle:
	.string "I'm very impressed with your\n"
	.string "team and the growth you all have\l"
	.string "achieved. Clefairy and I have\l"
	.string "always believed you would go far.$"
	
ViridianForest_Erin_House_ChampionCheck::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, ViridianForest_Erin_House_EventScript_CoolTrainerErin
	msgbox ViridianForest_Erin_House_Greetings MSGBOX_DEFAULT
	releaseall
	end

ViridianForest_Erin_House_Greetings:
	.string "Hello! Welcome to my home.\p"
	.string "My name is Erin. I live here with\n"
	.string "the friends I made along the way.\p"
	.string "Did you recently start traveling\n"
	.string "with your Pokémon?\p"
	.string "... I see. Go introduce yourself\n"
	.string "to my Clefairy! They have some\l"
	.string "Oran Berries that your Pokémon\l"
	.string "will love.$"

ViridianForest_Erin_House_Defeated::
	msgbox ViridianForest_Erin_House_DefeatedText MSGBOX_DEFAULT
	releaseall
	end

ViridianForest_Erin_House_DefeatedText:	
	.string "I'm very impressed with your\n"
	.string "team and the growth you all have\l"
	.string "achieved. Clefairy and I have\l"
	.string "always believed you would go far.$"

