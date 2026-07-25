.set LOCALID_SS_ANNE, 1
.set LOCALID_MEW, 2
.set LOCALID_SAILOR, 3
.set LOCALID_FUGITIVE, 4

SSAnne_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SSAnne_Exterior_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SSAnne_Exterior_OnResume
	.byte 0

SSAnne_Exterior_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

SSAnne_Exterior_OnWarp::
	map_script_2 VAR_SS_ANNE_STATE, 2, SSAnne_Exterior_BlockDock
	map_script_2 VAR_SS_ANNE_STATE, 3, SSAnne_Exterior_BlockDock
	.2byte 0

SSAnne_Exterior_OnResume:
	call Common_EventScript_GetDayOrNight
	end

SSAnne_Exterior_BlockDock::
	setmetatile 32, 14, 0x31D, 1
	special DrawWholeMapView
	end

SSAnne_Exterior_SSAnneDeparts::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_Delay48
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	fadenewbgm MUS_SURF
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	special DoSSAnneDepartureCutscene
	waitstate
	delay 10
	setobjectxyperm LOCALID_SAILOR, 31,5
	clearflag FLAG_HIDE_VERMILION_HARBOR_SAILOR
	addobject LOCALID_SAILOR
	applymovement LOCALID_SAILOR, Movement_MissedBoat
	waitmovement 5
	playse SE_PIN
	applymovement LOCALID_SAILOR, Common_Movement_ExclamationMark
	waitse
	removeobject LOCALID_SS_ANNE
	setvar VAR_SS_ANNE_STATE, 3
	setvar VAR_SS_TICKET_CHECK, 2
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	releaseall
	end

Movement_MissedBoat:
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	step_end

@This guy will be used later. This is mostly placeholder.
SSAnne_Exterior_EventScript_Sailor::
	msgbox SSAnne_Exterior_Text_MissedTheBoat, MSGBOX_NPC
	release
	end

SSAnne_Exterior_Text_MissedTheBoat::
	.string "Oh no! I missed the boat!$"

SSAnne_Exterior_EventScript_MewUnderTruck::
	goto_if_set FLAG_CHECKED_UNDER_TRUCK, SSAnne_Exterior_EventScript_MewNotUnderTruck
	goto_if_set FLAG_CAUGHT_MEW, SSAnne_Exterior_EventScript_MewNotUnderTruck
	goto_if_set FLAG_DEFEATED_MEW, SSAnne_Exterior_EventScript_MewNotUnderTruck
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadeoutbgm 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitse
	waitmovement 0
	clearflag FLAG_HIDE_MEW_UNDER_TRUCK
	addobject LOCALID_MEW
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	waitmoncry
	applymovement LOCALID_MEW, Movement_MewFlees
	waitmovement 3
	removeobject LOCALID_MEW
	setflag FLAG_CHECKED_UNDER_TRUCK
	delay 10
	fadeinbgm 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

Movement_MewFlees::
	delay_16
	delay_16
	emote_exclamation_mark
	face_right
	delay_16
	face_left
	delay_16
	walk_up
	walk_up
	walk_up
	set_invisible
	delay_16
	step_end

SSAnne_Exterior_EventScript_MewNotUnderTruck::
	lock
	msgbox SSAnne_Exterior_Text_MewNotUnderTruck, MSGBOX_DEFAULT
	release
	end

SSAnne_Exterior_Text_MewNotUnderTruck::
	.string "There's nothing there...$"

SSAnneExterior_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

SSAnneExterior_EventScript_Slowbro::
	lock
	faceplayer
    playmoncry SPECIES_SLOWBRO, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_DIAMOND, SSAnneExterior_EventScript_SlowbroDefeated
	msgbox SSAnneExterior_Text_Slowbro MSGBOX_DEFAULT
	release
	end

SSAnneExterior_Text_Slowbro:
	.string "SSSSSSSSSSSSSLLLLLLLLLOOOOOOOOOO\n"
	.string "OOOOOOOOOOOOOOOOOOOOOOWWWWWWWWWW$"

SSAnneExterior_EventScript_GentlemanDiamond::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DIAMOND, SSAnneExterior_EventScript_MegaHintSlowbro
	trainerbattle_single TRAINER_GENTLEMAN_DIAMOND, SSAnneExterior_Text_DiamondIntro, SSAnneExterior_Text_DiamondDefeat
	setflag FLAG_DEFEATED_DIAMOND
	msgbox SSAnneExterior_Text_DiamondPostBattle MSGBOX_AUTOCLOSE
	release
	end

SSAnneExterior_Text_DiamondIntro:
	.string "Ah, hello there. I'm on vacation with\n"
	.string "my Slowbro and my other friends.\p"
	.string "Care for a Pokémon match?$"

SSAnneExterior_Text_DiamondDefeat:
	.string "I'm impressed!$"

SSAnneExterior_Text_DiamondPostBattle:
	.string "Thank you so much for the good match!\p"
	.string "I think we will watch the ocean a bit\n"
	.string "more before surfing back to our city.$"

SSAnneExterior_EventScript_MegaHintSlowbro::    
    goto_if_set FLAG_GOT_SLOWBRONITE, SSAnneExterior_EventScript_DiamondDefeated
    msgbox SSAnneExterior_Text_SlowbroMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
SSAnneExterior_Text_SlowbroMegaHint:
    .string "There is some really lovely surfing\n"
	.string "to be found on your Route 20.\p"
	.string "Come to think of it, that is also the\n"
	.string "place I picked up our Slowbronite!$"

SSAnneExterior_EventScript_DiamondDefeated::
    msgbox DiamondDefeated_Text MSGBOX_DEFAULT
	release
	end

DiamondDefeated_Text:	
	.string "You only get one life and no one\n"
	.string "but yourself gets to live it.\p"
	.string "It's okay to work hard, but you\n"
	.string "must take time for play and rest.$"

SSAnneExterior_EventScript_SlowbroDefeated::
	msgbox SlowbroDefeated MSGBOX_DEFAULT
	release
	end

SlowbroDefeated:	
	.string "BBBBRRRRRRRRRRRRRRRRRRRRRRRRRROOOO\n"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO$"
