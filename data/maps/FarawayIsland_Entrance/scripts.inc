.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

FarawayIsland_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
	.byte 0

FarawayIsland_Entrance_OnTransition:
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
	setflag FLAG_HIDE_KAIRI
	goto_if_set FLAG_CAUGHT_MEW, FarawayIsland_Entrance_KairiAppear
	end

FarawayIsland_Entrance_KairiAppear::
	clearflag FLAG_HIDE_KAIRI
	return

FarawayIsland_Entrance_EventScript_Sailor::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_Return, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Entrance_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_CINNABAR_ISLAND, 11, 11
	waitstate
	release
	end

FarawayIsland_Entrance_Text_Return:
    .string "This was quite a journey!\p"
	.string "It's been a long time since I've\n"
	.string "had a chance to sail somewhere new.\n"
	.string "Have you already explored the island?\p"
	.string "Do you want to return to Cinnabar?$"

FarawayIsland_Entrance_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Entrance_EventScript_Sign::
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
	end

FarawayIsland_Entrance_EventScript_LassKairi::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, FarawayIsland_Entrance_EventScript_LassKairiBattle
	msgbox FarawayIsland_Entrance_Text_KairiNoBattle MSGBOX_DEFAULT
	releaseall
	end

FarawayIsland_Entrance_Text_KairiNoBattle:
	.string "Hi, I'm Kairi! How do you do?\p"
	.string "You're friends with Mew, too?\n"
	.string "That's wonderful!\p"
	.string "I sense you are on a grand\n"
	.string "adventure, yes?\p"
	.string "Please visit any time you like.$"

FarawayIsland_Entrance_EventScript_LassKairiBattle::
	trainerbattle_double TRAINER_LASS_KAIRI, FarawayIsland_Entrance_Text_KairiIntro, FarawayIsland_Entrance_Text_KairiDefeat, FarawayIsland_Entrance_Text_KairiNotEnoughMons
	msgbox FarawayIsland_Entrance_Text_KairiPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

FarawayIsland_Entrance_Text_KairiIntro:
	.string "Hello {PLAYER}, welcome back!\p"
	.string "... you've become Champion???\n"
	.string "Wow, I wonder if you can beat me?$"

FarawayIsland_Entrance_Text_KairiDefeat:
	.string "I see why a Mew chose you.$"

FarawayIsland_Entrance_Text_KairiPostBattle:
	.string "Pokémon battling is fun, but\n"
	.string "I aspire to be an artist!$"

FarawayIsland_Entrance_Text_KairiNotEnoughMons::
	.string "Where are your Pokémon friends?$"

