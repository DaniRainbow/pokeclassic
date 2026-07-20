Route23_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route23_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route23_OnResume
	.byte 0

Route23_OnTransition:
	clearflag FLAG_HIDE_VICTORY_ROAD_3F_BOULDER
	setflag FLAG_HIDE_VICTORY_ROAD_2F_BOULDER
	setvar VAR_VICTORY_ROAD_1F_STATE, 0
	setvar VAR_VICTORY_ROAD_2F_BOULDER1, 0
	setvar VAR_VICTORY_ROAD_2F_BOULDER2, 0
	setvar VAR_VICTORY_ROAD_3F_STATE, 0
	call Common_EventScript_GetDayOrNight
	end

Route23_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route23_EventScript_VictoryRoadGateSign::
	msgbox Route23_Text_VictoryRoadGateSign, MSGBOX_SIGN
	end

Route23_Text_VictoryRoadGateSign::
    .string "Victory Road Gate -\n"
    .string "Pokémon League$"

Route23_EventScript_ItemTM10::
	finditem ITEM_TM10, 1
	release
	end

Route23_EventScript_Tangela::
	lock
    faceplayer
    playmoncry SPECIES_TANGELA, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_PKMNRNGR_ALEX, Route23_EventScript_TangelaDefeated
	msgbox Route23_Text_Tangela MSGBOX_DEFAULT
	release
	end

Route23_Text_Tangela:
	.string "{PLAYER}.\p"
	.string "I will be a Tangela one day.$"

Route23_EventScript_PokemonRanger_Alex::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PKMNRNGR_ALEX, Route23_EventScript_TalkAboutTangela
	trainerbattle_single TRAINER_POKEMONRANGER_ALEX, Route23_Text_AlexIntro, Route23_Text_AlexDefeat
	setflag FLAG_DEFEATED_PKMNRNGR_ALEX
	msgbox Route23_Text_AlexPostBattle MSGBOX_AUTOCLOSE
	release
	end

Route23_Text_AlexIntro:
	.string "I need flavor text.$"

Route23_Text_AlexDefeat:
	.string "Incredible... how...?$"

Route23_Text_AlexPostBattle:
	.string "Is this a dream?$"

Route23_EventScript_TalkAboutTangela::    
    msgbox Route23_Text_TalkAboutTangela MSGBOX_DEFAULT
    waitmessage
    release
    end
    
Route23_Text_TalkAboutTangela:
    .string "Tag, you are it.$"

Route23_EventScript_TangelaDefeated::
	msgbox TangelaDefeated MSGBOX_DEFAULT
	release
	end

TangelaDefeated:	
	.string "I don't look like spaghetti\n"
	.string "but I will.$"
