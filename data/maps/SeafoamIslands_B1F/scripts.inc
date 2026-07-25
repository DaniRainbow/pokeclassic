SeafoamIslands_B1F_MapScripts::
	.byte 0

SeafoamIslands_B1F_EventScript_ItemRevive::
	finditem ITEM_REVIVE, 1
	release
	end

SeafoamIslands_B1F_EventScript_ItemWaterStone::
	finditem ITEM_WATER_STONE, 1
	release
	end

SeafoamIslands_B1F_EventScript_Gyaradosite::
	finditem ITEM_GYARADOSITE, 1
	setflag FLAG_GOT_GYARADOSITE
	goto_if_unset FLAG_FIRST_MEGASTONE, SeafoamIslands_B1F_EventScript_FoundMegaStone
    end

SeafoamIslands_B1F_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end

