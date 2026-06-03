SafariZone_Center_MapScripts::
	.byte 0

SafariZone_Center_EventScript_RestHouseSign::
	msgbox SafariZone_Center_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_Center_Text_RestHouse::
    .string "Rest House$"

SafariZone_Center_EventScript_TrainerTips::
	msgbox SafariZone_Center_Text_PressStartToCheckTime, MSGBOX_SIGN
	end

SafariZone_Center_Text_PressStartToCheckTime::
    .string "Trainer Tips:\p"
	.string "If you put a {POKEBLOCK} in a Feeder,\n"
	.string "Pokémon will gather around.$"

SafariZone_Center_EventScript_AreaSign::
	msgbox SafariZone_Center_Text_CenterArea, MSGBOX_SIGN
	end

SafariZone_Center_Text_CenterArea::
    .string "Center Area$"


SafariZone_Center_EventScript_ItemNugget::
	finditem ITEM_NUGGET, 1
	release
	end

SafariZone_Center_EventScript_Pinsirte::
	finditem ITEM_PINSIRITE, 1
	setflag FLAG_GOT_PINSIRITE
	goto_if_unset FLAG_FIRST_MEGASTONE, SafariZone_Center_EventScript_FoundMegaStone
    end

SafariZone_Center_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end
