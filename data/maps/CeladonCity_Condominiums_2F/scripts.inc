CeladonCity_Condominiums_2F_MapScripts::
	.byte 0

CeladonCity_Condominiums_2F_EventScript_MeetingRoomSign::
	msgbox CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom::
    .string "Pokémon Journal Meeting Room$"

CeladonCity_Condominiums_2F_EventScript_PokemonJournalErika::
	msgbox PokemonJournal_Text_SpecialFeatureErika, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureErika::
	.string "Pokémon Journal:\p"
	.string "Special Feature: Celadon Gym\n"
	.string "Leader Erika!\p"
	.string "Rumor has it that if you peek into\n"
	.string "Celadon Gym, you can often\l"
	.string "see Erika snoozing.$"

CeladonCity_Condominiums_2F_EventScript_danenders::
	lock
	faceplayer
	msgbox CeladonCity_Condominiums_2F_Text_danenders, MSGBOX_NPC
	waitmessage
	turnobject 1, DIR_SOUTH
	release
	end

CeladonCity_Condominiums_2F_Text_danenders:
	.string "Hi there, I'm danenders.\p"
	.string "I created the game you are playing!\p"
	.string "I'm working on other projects now,\n"
	.string "but thanks for saying hi.$"

CeladonCity_Condominiums_2F_EventScript_DaniRainbow::
	lock
	faceplayer
	goto_if_set FLAG_MET_MAGAZINE_DANI, CeladonCity_Condominiums_2F_EventScript_DaniRainbowAlreadyMet
	msgbox CeladonCity_Condominiums_2F_Text_DaniRainbowIntroduction, MSGBOX_NPC
	waitmessage
	setflag FLAG_MET_MAGAZINE_DANI
	release
	end

CeladonCity_Condominiums_2F_EventScript_DaniRainbowAlreadyMet::
	msgbox CeladonCity_Condominiums_2F_Text_DaniRainbowAlreadyMet, MSGBOX_NPC
	waitmessage
	release
	end

CeladonCity_Condominiums_2F_Text_DaniRainbowIntroduction:
	.string "Is it time for our interview?\p"
	.string "...\p"
	.string "Oh, you're not an employee of\n"
	.string "the publication upstairs.\p"
	.string "My bad!\n"
	.string "I'm Dani, aka the bug reporter\l"
	.string "turned developer.\p"
	.string "I'm sure poor danenders is absolutely\n"
	.string "sick of me by this point.\p"
	.string "I began to work on this game when\n"
	.string "he went on to other projects.\p"
	.string "I am more of an editor than an\n"
	.string "actual developer, but I hope you\l"
	.string "are enjoying your time in Classic!$"

CeladonCity_Condominiums_2F_Text_DaniRainbowAlreadyMet:
	.string "Hello again!\n"
	.string "I'm Dani, aka the bug reporter\l"
	.string "turned developer.\p"
	.string "I'm sure poor danenders is absolutely\n"
	.string "sick of me by this point.\p"
	.string "I began to work on this game when\n"
	.string "he went on to other projects.\p"
	.string "I am more of an editor than an\n"
	.string "actual developer, but I hope you\l"
	.string "are enjoying your time in Classic!$"

CeladonCity_Condominiums_2F_EventScript_LiquidJustice::
	lock
	faceplayer
	msgbox CeladonCity_Condominiums_2F_Text_LiquidJustice, MSGBOX_NPC
	waitmessage
	turnobject 5, DIR_SOUTH
	release
	end

CeladonCity_Condominiums_2F_Text_LiquidJustice:
	.string "How's it going?\p"
	.string "I'm LiquidJustice, one of\n"
	.string "the designers for the game.\p"
	.string "Kanto.\n"
	.string "Every time I get out,\l"
	.string "they drag me back in.\p"
	.string "Have you beat the Mega trainers yet?$"

CeladonCity_Condominiums_2F_EventScript_Headlocker::
	lock
	faceplayer
	msgbox CeladonCity_Condominiums_2F_Text_Headlocker, MSGBOX_NPC
	waitmessage
	turnobject 6, DIR_WEST
	release
	end

CeladonCity_Condominiums_2F_Text_Headlocker:
	.string "I'm Headlocker03, a humble\n"
	.string "designer for this game!\p"
	.string "I just lucked into soul-linking\n"
	.string "with these guys.\p"
	.string "Shout-out to danenders and
	.string "DaniRainbow for their hard work\n"
	.string "on this trip through Kanto!$"

CeladonCity_Condominiums_2F_EventScript_THEWALL::
	lock
	faceplayer
	playmoncry SPECIES_UMBREON, CRY_MODE_NORMAL
	waitmoncry
	msgbox CeladonCity_Condominiums_2F_Text_THEWALL, MSGBOX_DEFAULT
	waitmessage
	release
	end

CeladonCity_Condominiums_2F_Text_THEWALL:
	.string "Cherry Pie gives you the blankest stare.$"

CeladonCity_Condominiums_2F_EventScript_CherryPie::
	lock
	faceplayer
	playmoncry SPECIES_WIGGLYTUFF, CRY_MODE_NORMAL
	waitmoncry
	msgbox CeladonCity_Condominiums_2F_Text_CherryPie, MSGBOX_DEFAULT
	waitmessage
	release
	end

CeladonCity_Condominiums_2F_Text_CherryPie:
	.string "Cherry Pie gives you the blankest stare.$"

CeladonCity_Condominiums_2F_EventScript_danPikachu::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	release
	end

CeladonCity_Condominiums_2F_EventScript_LiquidArcanine::
	lock
	faceplayer
	playmoncry SPECIES_ARCANINE, CRY_MODE_NORMAL
	waitmoncry
	release
	end

//CeladonCity_Condominiums_2F_EventScript_HeadlockerPokemon::
	//lock
	//faceplayer
	//playmoncry SPECIES_NONE, CRY_MODE_NORMAL
	//waitmoncry
	//msgbox CeladonCity_Condominiums_2F_Text_NONE, MSGBOX_DEFAULT
	//waitmessage
	//release
	//end
