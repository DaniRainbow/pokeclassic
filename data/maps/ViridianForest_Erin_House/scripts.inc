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


