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
	trainerbattle_single TRAINER_COOLTRAINER_ERIN, ViridianForest_Erin_House_Text_ErinIntro, ViridianForest_Erin_House_Text_ErinDefeat
	msgbox ViridianForest_Erin_House_Text_ErinPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

ViridianForest_Erin_House_Text_ErinIntro:
	.string "Oh, hello again! Congrats\n"
	.string "on becoming the Champion!\p"
	.string "You're ready now. Surprise!$"

ViridianForest_Erin_House_Text_ErinDefeat:
	.string "Wow, Champion indeed!$"

ViridianForest_Erin_House_Text_ErinPostBattle:
	.string "I'm very impressed with your\n"
	.string "team and the growth you all have\l"
	.string "achieved. Clefairy and I have\l"
	.string "always believed you would go far.$"

