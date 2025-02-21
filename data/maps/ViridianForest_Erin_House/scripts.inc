ViridianForest_Erin_House_MapScripts::
	.byte 0

ViridianForest_Erin_House_EventScript_CoolTrainerErin::
	lock
	faceplayer
	msgbox ViridianForest_Erin_House_Text_HiIAmErin MSGBOX_DEFAULT
	release
	end

ViridianForest_Erin_House_Text_HiIAmErin:
	.string "Hi, welcome to my home! I'm Erin!\p"
	.string "I live here with my friends.\n"
	.string "Come visit me when you are the Champ!$"
	return

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

