.set LOCALID_MOM, 1

PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition:
	call SecretBase_EventScript_SetDecorationFlags
	setrespawn HEAL_LOCATION_PLAYERS_HOUSE
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

PalletTown_PlayersHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

PlayersHouse_2F_EventScript_NewGameStart1::
	lockall
	addobject LOCALID_MOM
	playse SE_DOOR
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs1
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame1::
	lockall
	addobject LOCALID_MOM
	playse SE_DOOR
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs1
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

PlayersHouse_2F_EventScript_NewGameStart2::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairsAlt
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs2
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame2::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairsAlt
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs2
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

PlayersHouse_2F_EventScript_NewGameStart3::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs3
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame3::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs3
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

MomWalksUpstairs:
	walk_right
	walk_down
	step_end

MomWalksUpstairsAlt:
	walk_right
	walk_down
	walk_down
	step_end

WalkToPlayer1:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WalkToPlayer2:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

WalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

WalkToStairs1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

WalkToStairs2:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WalkToStairs3:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MomGoesDownstairs:
	walk_up
	walk_left
	step_end

PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor:
	.string "Mom: {PLAYER}! I should have\p"
	.string "known I'd find you playing\n"
	.string "games up here again.\p"
	.string "You should head downstairs.\n"
	.string "Someone is here to see you!$"

PalletTown_PlayersHouse_2F_Text_LookAtTheTime:
	.string "Mom: {PLAYER}! There you are!\p"
	.string "Have you been playing games\n"
	.string "up here this whole time?\p"
	.string "Weren't you supposed to meet\n"
	.string "Professor Oak at his lab today?\p"
	.string "Do you even know what time it is?$"

PalletTown_PlayersHouse_2F_Text_GoingToBeLate:
	.string "You should hurry over to the lab,\n"
	.string "you're going to miss the Professor!$"

PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry:
	.string "Oh! If you want to change your\n"
	.string "clothes before you go out, \l"
	.string "I put your laundry in your dresser.$"


PlayersHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_EventScript_Console::
	lock
	msgbox PlayersHouse_2F_Text_Console, MSGBOX_DEFAULT
	release
	end

PlayersHouse_2F_Text_Console:
	.string "It's an old game console.\p"
	.string "Retro-gaming is all the rage!$"

PlayersHouse_2F_EventScript_ChangeClock::
	lock
	msgbox PlayersHouse_2F_ChangeClockText
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	releaseall
	end
	
PlayersHouse_2F_ChangeClockText:
	.string "Times are changing.\n"
	.string "Let's change the time.$"
	return

PlayersHouse_2F_EventScript_CheckWallClock2::
	lock
	msgbox PlayersHouse_2F_BeautifulView
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end
	
PlayersHouse_2F_BeautifulView:
	.string "Pokémon play in the forest.\n"
	.string "You smile and check the time.$"
	return
	
PlayersHouse_2F_WelcomeNewPlayers::
	msgbox PlayersHouse_2F_WelcomeNewPlayersText
	releaseall
	end
	
PlayersHouse_2F_WelcomeNewPlayersText:	
	.string "Press START to access the Main Menu.\n"
	.string "Save often as you advance your story.\p"
	.string "To check the time, you may look out\n"
	.string "the window on the right. If you find\l"
	.string "a need to change the time, inspect\l"
	.string "the magic left curtain.\p"
	.string "You may change your clothes using\n"
	.string "the dresser left of your shelves.\p"
	.string "Finally, sit at your desk any time\n"
	.string "to enjoy your own PC!$"
	return

PlayersHouse_2F_LetterFromDad::
	lock
	faceplayer
	msgbox Text_LetterOnTower, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LetterOnTower_PlayerAnsweredNo
	msgbox Text_HappyBirthdayLetter, MSGBOX_DEFAULT
	release
	end

LetterOnTower_PlayerAnsweredNo::
	msgbox Text_NoTimeToRead, MSGBOX_DEFAULT
	release
	end

Text_LetterOnTower:
	.string "An envelope is taped to the side\n"
	.string "of your computer tower. It reads\l"
	.string "'From Dad' on the outside.\p"
	.string "Would you like to read it?$"

Text_HappyBirthdayLetter:
	.string "Dad: Hey {PLAYER}!\n"
	.string "Happy Birthday, kiddo!\p"
	.string "I can't believe you're old enough to\n"
	.string "go out on your own Pokémon Journey.\p"
	.string "It's a scary and thrilling experience.\p"
	.string "I'm very sorry that due to my business\n"
	.string "trip in Hoenn I can't be there with\l"
	.string "your mother to send you off.\p"
	.string "I left some items for you with Mom and\n"
	.string "she will put them in your PC storage in\l"
	.string "time for you to grab before you leave.\p"
	.string "These items are great when you are\n"
	.string "first starting out. My Mom gave them\l"
	.string "to me when I tried to get into Pokémon\l"
	.string "training at 10 years old.\p"
	.string "During my journey I found two golden\n"
	.string "Nuggets and kept them for a rainy day\l"
	.string "if I was short on money and potions.\p"
	.string "I've held onto them all these years and\n"
	.string "now I pass them on to you for your\l"
	.string "rainy days.\p"
	.string "Treat your Pokémon with love and\n"
	.string "kindness for Pokémon will return what\l"
	.string "they are given.\p"
	.string "Camping is fun until your clothes get\n"
	.string "wet, so pick your camping grounds\l"
	.string "carefully and always use the rain\l"
	.string "cover on your tent.\p"
	.string "Hold true to your friends and help\n"
	.string "others who may be without friends of\l"
	.string "their own.\p"
	.string "There will be unexpected things you\n"
	.string "need to overcome along your journey but\l"
	.string "be patient with yourself. Give yourself\l"
	.string "grace as you learn new things.\p" 
	.string "You cannot control what others will do\n"
	.string "but you are responsible for how you\l"
	.string "choose to respond.\p"
	.string "Don’t waste your time bearing grudges,\n"
	.string "and live life with love in your heart.\p"
	.string "A destination is a good goal to have,\n"
	.string "but don’t forget to enjoy the journey.\p"
	.string "Never give up chasing your dreams.\p"
	.string "Understand that your dreams may change,\n"
	.string "and that’s okay.\p"
	.string "I am so proud of the person you have\n"
	.string "become and I know you will go far.\p"
	.string "With Love,\n"
	.string "Dad\p"
	.string "P.S\n"
	.string "I hope you enjoy the cookies!\p"
	.string "They are a Hoenn speciality. I got the\n"
	.string "recipe from a very kind woman when I\l"
	.string "went hiking up by Lavaridge Town.$"
	

Text_NoTimeToRead:
	.string "Not now, you have places to be!$"

