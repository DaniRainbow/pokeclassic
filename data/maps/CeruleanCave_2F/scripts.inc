CeruleanCave_2F_MapScripts::
	.byte 0

CeruleanCave_2F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE, 1
	release
	end

CeruleanCave_2F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL, 1
	release
	end

CeruleanCave_2F_EventScript_ItemPPUp::
	finditem ITEM_PP_UP, 1
	release
	end

CeruleanCave_2F_EventScript_MewtoniteY::
	finditem ITEM_MEWTWONITE_Y, 1
	setflag FLAG_GOT_MEWTWONITE_Y
	goto_if_unset FLAG_FIRST_MEGASTONE, CeruleanCave_2F_EventScript_FoundMegaStone
	end

CeruleanCave_2F_EventScript_MewtoniteX::
	finditem ITEM_MEWTWONITE_X, 1
	setflag FLAG_GOT_MEWTWONITE_X
	goto_if_unset FLAG_FIRST_MEGASTONE, CeruleanCave_2F_EventScript_FoundMegaStone
    end

CeruleanCave_2F_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end
