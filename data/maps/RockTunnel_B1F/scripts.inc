RockTunnel_B1F_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_ItemRevive::
	finditem ITEM_REVIVE, 1
	release
	end

RockTunnel_B1F_EventScript_ItemPowerStone::
    finditem ITEM_POWER_STONE, 1
    release
    end

RockTunnel_B1F_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	release
	end

RockTunnel_B1F_EventScript_Aerodactlyite::
    finditem ITEM_AERODACTYLITE, 1
    release
    end

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SofiaIntro::
    .string "Do you know how you can avoid\n"
    .string "getting lost in the mountains?\p"
    .string "You can bend twigs as trail\n"
    .string "markers.$"

RockTunnel_B1F_Text_SofiaDefeat::
    .string "Ohhh!\n"
    .string "I did my best!$"

RockTunnel_B1F_Text_SofiaPostBattle::
    .string "I want to go home!$"

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_MarthaIntro::
    .string "I don't often come here, but I will\n"
    .string "battle you.$"

RockTunnel_B1F_Text_MarthaDefeat::
    .string "Oh!\n"
    .string "I lost!$"

RockTunnel_B1F_Text_MarthaPostBattle::
    .string "I like tiny Pokémon.\n"
    .string "Big ones are too scary!$"

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_DudleyIntro::
    .string "Hahaha!\n"
    .string "Can you beat my power?$"

RockTunnel_B1F_Text_DudleyDefeat::
    .string "Oops!\n"
    .string "Outmuscled!$"

RockTunnel_B1F_Text_DudleyPostBattle::
    .string "I go for power because I hate\n"
    .string "thinking.$"

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_AllenIntro::
    .string "My Pokémon techniques will leave\n"
    .string "you crying!$"

RockTunnel_B1F_Text_AllenDefeat::
    .string "I give!\n"
    .string "You're a better technician!$"

RockTunnel_B1F_Text_AllenPostBattle::
    .string "In mountains, you'll often find\n"
    .string "Rock-type Pokémon.$"

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_EricIntro::
    .string "Hit me with your best shot!$"

RockTunnel_B1F_Text_EricDefeat::
    .string "Fire away!$"

RockTunnel_B1F_Text_EricPostBattle::
    .string "I'll raise my Pokémon to beat\n"
    .string "yours, kid.$"

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_CooperIntro::
    .string "You have a Pokédex?\n"
    .string "I want one, too.$"

RockTunnel_B1F_Text_CooperDefeat::
    .string "Shoot!\n"
    .string "I am so jealous!$"

RockTunnel_B1F_Text_CooperPostBattle::
    .string "When you finish your Pokédex,\n"
    .string "can I have it?$"

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SteveIntro::
    .string "Um… Do you know about Pokémon\n"
    .string "cosplay?$"

RockTunnel_B1F_Text_SteveDefeat::
    .string "Well, that's that.$"

RockTunnel_B1F_Text_StevePostBattle::
    .string "Pokémon cosplay is dressing up as\n"
    .string "Pokémon for fun.\p"
    .string "Clefairy is a favorite.$"

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_WinstonIntro::
    .string "I draw illustrations of Pokémon\n"
    .string "when I'm home.$"

RockTunnel_B1F_Text_WinstonDefeat::
    .string "Whew…\n"
    .string "I'm exhausted…$"

RockTunnel_B1F_Text_WinstonPostBattle::
    .string "I'm an artist, not a fighter.\n"
    .string "I'll go home to draw.$"

RockTunnel_B1F_EventScript_HelmetGuy::
    lock
    goto_if_set FLAG_GOT_ROCKY_HELMET, RockTunnel_B1F_EventScript_HelmetGuy2
    msgbox RockTunnel_B1F_Text_Helmet, MSGBOX_NPC
    giveitem ITEM_ROCKY_HELMET, 1
    setflag FLAG_GOT_ROCKY_HELMET
    release
    end

RockTunnel_B1F_Text_Helmet::
    .string "I was checking out the tunnel here\n"
    .string "when a Geodude used Self Destruct!\p"
    .string "It caused a small cave in.\n"
    .string "Good thing I was wearing a helmet.\p"
    .string "Here, you should take one too!$"

RockTunnel_B1F_EventScript_HelmetGuy2::
    lock
    msgbox RockTunnel_B1F_Text_Helmet2, MSGBOX_NPC
    release
    end

RockTunnel_B1F_Text_Helmet2::
    .string "Sometimes, rocks will contain items.\n"
    .string "But they could also contain Pokémon!$"
