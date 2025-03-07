.set NUM_BOULDERS_PRESENT, VAR_TEMP_2

SeafoamIslands_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_B3F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SeafoamIslands_B3F_OnFrame
	.byte 0

SeafoamIslands_B3F_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, SeafoamIslands_B3F_EventScript_CheckStoppedCurrent
	call_if_set FLAG_STOPPED_SEAFOAM_B3F_CURRENT, SeafoamIslands_B3F_EventScript_SetNoCurrentLayout
	end

SeafoamIslands_B3F_EventScript_CheckStoppedCurrent::
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B3F_BOULDER_1, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B3F_BOULDER_2, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	call_if_eq NUM_BOULDERS_PRESENT, 2, SeafoamIslands_B3F_EventScript_StoppedCurrent
	return

SeafoamIslands_B3F_EventScript_StoppedCurrent::
	setflag FLAG_STOPPED_SEAFOAM_B3F_CURRENT
	return

SeafoamIslands_B3F_EventScript_SetNoCurrentLayout::
	setmaplayoutindex LAYOUT_SEAFOAM_ISLANDS_B3F_CURRENT_STOPPED
	return

SeafoamIslands_B3F_OnFrame::
	map_script_2 VAR_TEMP_1, 1, SeafoamIslands_B3F_EventScript_EnterByFalling
	.2byte 0

SeafoamIslands_B3F_EventScript_EnterByFalling::
	lockall
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B3F_BOULDER_1, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B3F_BOULDER_2, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	goto_if_eq NUM_BOULDERS_PRESENT, 2, SeafoamIslands_B3F_EventScript_CurrentBlocked
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_lt VAR_0x8008, 24, SeafoamIslands_B3F_EventScript_RideCurrentFar
	call_if_ge VAR_0x8008, 24, SeafoamIslands_B3F_EventScript_RideCurrentClose
	setvar VAR_SEAFOAM_ISLANDS_STATE, 1
	warp MAP_SEAFOAM_ISLANDS_B4F, 27, 21
	waitstate
	releaseall
	end

SeafoamIslands_B3F_EventScript_AddBoulderPresent::
	addvar NUM_BOULDERS_PRESENT, 1
	return

SeafoamIslands_B3F_EventScript_RideCurrentFar::
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B3F_Movement_RideCurrentFar
	waitmovement 0
	return

SeafoamIslands_B3F_EventScript_RideCurrentClose::
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B3F_Movement_RideCurrentClose
	waitmovement 0
	return

SeafoamIslands_B3F_EventScript_CurrentBlocked::
	setvar VAR_TEMP_1, 0
	releaseall
	end

SeafoamIslands_B3F_Movement_RideCurrentFar::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SeafoamIslands_B3F_Movement_RideCurrentClose::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SeafoamISlands_B3F_EventScript_BlackBeltMichael::
	trainerbattle_single TRAINER_BLACKBELT_MICHAEL SeafoamISlands_B3F_Text_MichaelIntro, SeafoamISlands_B3F_Text_MichaelDefeat
	msgbox SeafoamISlands_B3F_Text_MichaelPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

SeafoamISlands_B3F_Text_MichaelIntro:
	.string "I usually am alone training here.\n"
	.string "Come at us with all you got!$"

SeafoamISlands_B3F_Text_MichaelDefeat:
	.string "You're impressive!$"

SeafoamISlands_B3F_Text_MichaelPostBattle:
	.string "That was a great fight!\p"
	.string "My team and I are going to\n"
	.string "train harder than before!$"
