.set LOCALID_MEWTWO, 12

CeruleanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_OnResume
	.byte 0

CeruleanCave_OnTransition::
	call_if_unset FLAG_CAUGHT_MEWTWO, CeruleanCave_EventScript_TryShowMewtwo
	end

CeruleanCave_EventScript_TryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_Return
	clearflag FLAG_DAILY_MEWTWO
	return

CeruleanCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CeruleanCave_EventScript_TryRemoveMewtwo
	end

CeruleanCave_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_MEWTWO
	return

CeruleanCave_EventScript_Mewtwo::
	lock
	faceplayer
	goto_if_set FLAG_CAUGHT_MEWTWO, CeruleanCave_EventScript_DailyMewtwo
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MEWTWO, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CeruleanCave_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CeruleanCave_EventScript_RanFromMewtwo
	setflag FLAG_CAUGHT_MEWTWO
	setflag FLAG_DAILY_MEWTWO
	release
	end

CeruleanCave_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

CeruleanCave_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

CeruleanCave_EventScript_DailyMewtwo::
	random 50
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_0x8004, 1, CeruleanCave_EventScript_Surprise_Mewtwo
	setvar VAR_0x8004, 0
	setwildbattle SPECIES_MEWTWO, 70
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CeruleanCave_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CeruleanCave_EventScript_RanFromMewtwo
	release
	end

CeruleanCave_EventScript_Surprise_Mewtwo::
	setvar VAR_0x8004, 0
	setflag FLAG_SHINY_CREATION
	setwildbattle SPECIES_MEWTWO, 70
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CeruleanCave_EventScript_DailyDefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave_EventScript_DailyRanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CeruleanCave_EventScript_DailyRanFromMewtwo
	release
	end

CeruleanCave_EventScript_DailyDefeatedMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	removeobject LOCALID_MEWTWO
	setflag FLAG_DAILY_MEWTWO
	release
	end

CeruleanCave_EventScript_DailyRanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	removeobject LOCALID_MEWTWO
	setflag FLAG_DAILY_MEWTWO
	release
	end

CeruleanCave_B1F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL, 1
	release
	end

CeruleanCave_B1F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end
