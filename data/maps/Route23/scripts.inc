.set LOCALID_BEAUTY, 2
.set LOCALID_TANGELA, 3

Route23_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route23_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route23_OnResume
	.byte 0

Route23_OnTransition:
	clearflag FLAG_HIDE_VICTORY_ROAD_3F_BOULDER
	setflag FLAG_HIDE_VICTORY_ROAD_2F_BOULDER
	setflag FLAG_HIDE_GORDON
	setvar VAR_VICTORY_ROAD_1F_STATE, 0
	setvar VAR_VICTORY_ROAD_2F_BOULDER1, 0
	setvar VAR_VICTORY_ROAD_2F_BOULDER2, 0
	setvar VAR_VICTORY_ROAD_3F_STATE, 0
	call Common_EventScript_GetDayOrNight
	goto_if_unset FLAG_DEFEATED_PKMNRNGR_ALEX, Route23_EventScript_HideNSeek
	goto_if_set FLAG_DEFEATED_PKMNRNGR_ALEX, Route23_EventScript_ShowGordon
	end

Route23_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route23_EventScript_ShowGordon::
	clearflag FLAG_HIDE_GORDON
	end

Route23_EventScript_HideNSeek::
	clearflag FLAG_TANGELA_IN_PLACE
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

Route23_EventScript_RangerAlex::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PKMNRNGR_ALEX, Route23_EventScript_TalkAboutTangela
	goto_if_unset FLAG_TANGELA_IN_PLACE, Route23_EventScript_TangelaEvent
	trainerbattle_single TRAINER_POKEMONRANGER_ALEX, Route23_Text_AlexIntro, Route23_Text_AlexDefeat
	setflag FLAG_DEFEATED_PKMNRNGR_ALEX
	clearflag FLAG_HIDE_GORDON
	msgbox Route23_Text_AlexPostBattle MSGBOX_AUTOCLOSE
	release
	end

Route23_EventScript_TangelaEvent::
	msgbox Route23_Text_AlexGreeting, MSGBOX_NPC
	waitmessage
	playse SE_PIN
	applymovement LOCALID_BEAUTY, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route23_Text_AlexLooking, MSGBOX_NPC
	waitmessage
	applymovement LOCALID_BEAUTY, Movement_LookUpDownRightFacePlayer
	waitmovement 0
	playmoncry SPECIES_TANGELA, CRY_MODE_ENCOUNTER
	waitmoncry
    delay 20
	addobject LOCALID_TANGELA
	applymovement LOCALID_TANGELA, Movement_RunsDownStop1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FacesTangelaTurnsTangela1
	waitmovement 0
	applymovement LOCALID_TANGELA, Movement_RunsDownStop2
	waitmovement 0
	applymovement LOCALID_TANGELA, Movement_SneaksRightStop3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FacesTangelaTurnsTangela2
	waitmovement 0
	applymovement LOCALID_BEAUTY, Movement_FaceDownPlayer
	waitmovement 0
	applymovement LOCALID_TANGELA, Movement_SneaksRightStop4
	waitmovement 0
	applymovement LOCALID_TANGELA, Movement_RunsToPlayerStop5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FacesTangelaTurnsTangela3
	waitmovement 0
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setflag FLAG_TANGELA_IN_PLACE
	end

Route23_EventScript_Tangela::
	lock
    faceplayer
    playmoncry SPECIES_TANGELA, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
	msgbox Route23_Text_Tangela MSGBOX_DEFAULT
	release
	end

Route23_Text_Tangela:
	.string "Tangela is practicing soft\n"
	.string "and quiet feet in the grass.$"

Route23_Text_AlexIntro:
	.string "Tag, you're it?$"

Route23_Text_AlexDefeat:
	.string "Dang, now I'm it!$"

Route23_Text_AlexPostBattle:
	.string "Thanks for playing!$"

Route23_EventScript_TalkAboutTangela::    
    msgbox Route23_Text_TalkAboutTangela MSGBOX_DEFAULT
    waitmessage
    release
    end
    
Route23_Text_TalkAboutTangela:
    .string "No matter how hard Gordon tries,\n"
	.string "he can't quite seem to figure\l"
	.string "how to make quiet steps.$"

Route23_Text_AlexGreeting:
	.string "Oh... hi!\n"
	.string "You're not who I was expecting.\p"
	.string "I'm taking a break from training\n"
	.string "for the League to play with my\l"
	.string "amazing Pokémon.$"

Route23_Text_AlexLooking:
	.string "Speaking of which, it's not\n"
	.string "like Gordon to take this long\l"
	.string "during hide and seek...$"

Movement_LookUpDownRightFacePlayer::
	face_up
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Movement_RunsDownStop1::
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	walk_right
	step_end

Movement_FacesTangelaTurnsTangela1::
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Movement_RunsDownStop2::
	face_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Movement_SneaksRightStop3::
	walk_right
	face_right
	step_end

Movement_FacesTangelaTurnsTangela2::
	face_down
	step_end

Movement_FaceDownPlayer::
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Movement_SneaksRightStop4::
	walk_right
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Movement_RunsToPlayerStop5::
	face_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

Movement_FacesTangelaTurnsTangela3::
	face_left
	step_end
