CeladonCity_DepartmentStore_Roof_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_Roof_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeladonCity_DepartmentStore_Roof_OnResume
	.byte 0

CeladonCity_DepartmentStore_Roof_OnTransition::
	call Common_EventScript_GetDayOrNight
	setescapewarp MAP_CELADON_CITY, 15, 16
	end

CeladonCity_DepartmentStore_Roof_OnResume::
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_DepartmentStore_Roof_EventScript_ThirstyGirl::
	lock
	faceplayer
	call CeladonCity_DepartmentStore_Roof_EventScript_CheckPlayerHasDrinks
	goto_if_eq VAR_TEMP_1, 0, CeladonCity_DepartmentStore_Roof_EventScript_IWantDrink
	goto CeladonCity_DepartmentStore_Roof_EventScript_AskGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_CheckPlayerHasDrinks::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_FRESH_WATER, 1
	call_if_eq VAR_RESULT, TRUE, CeladonCity_DepartmentStore_Roof_EventScript_SetHasFreshWater
	checkitem ITEM_SODA_POP, 1
	call_if_eq  VAR_RESULT, TRUE, CeladonCity_DepartmentStore_Roof_EventScript_SetHasSodaPop
	checkitem ITEM_LEMONADE, 1
	call_if_eq VAR_RESULT, TRUE, CeladonCity_DepartmentStore_Roof_EventScript_SetHasLemonade
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasFreshWater::
	addvar VAR_TEMP_1, 1
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasSodaPop::
	addvar VAR_TEMP_1, 2
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasLemonade::
	addvar VAR_TEMP_1, 4
	return

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveDrink::
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImThirstyGiveHerDrink, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	message CeladonCity_DepartmentStore_Roof_Text_GiveWhichDrink
	waitmessage
	switch VAR_TEMP_1
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWater
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPop
	case 3, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterSodaPop
	case 4, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveLemonade
	case 5, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterLemonade
	case 6, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPopLemonade
	case 7, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveAllDrinks
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWater::
	multichoice 0, 0, MULTI_FRESH_WATER, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPop::
	multichoice 0, 0, MULTI_SODA_POP, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterSodaPop::
	multichoice 0, 0, MULTI_FRESH_WATER_SODA_POP, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveLemonade::
	multichoice 0, 0, MULTI_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterLemonade::
	multichoice 0, 0, MULTI_FRESH_WATER_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPopLemonade::
	multichoice 0, 0, MULTI_SODA_POP_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveAllDrinks::
	multichoice 0, 0, MULTI_ALL_DRINKS, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 3, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater::
	setvar VAR_0x8008, ITEM_FRESH_WATER
	setvar VAR_0x8009, ITEM_TM16
	goto_if_set FLAG_GOT_TM16_FROM_THIRSTY_GIRL, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YayFreshWaterHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop::
	setvar VAR_0x8008, ITEM_SODA_POP
	setvar VAR_0x8009, ITEM_TM20
	goto_if_set FLAG_GOT_TM20_FROM_THIRSTY_GIRL, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YaySodaPopHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade::
	setvar VAR_0x8008, ITEM_LEMONADE
	setvar VAR_0x8009, ITEM_TM33
	goto_if_set FLAG_GOT_TM33_FROM_THIRSTY_GIRL, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YayLemonadeHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink::
	getitemname 0, VAR_0x8008
	getitemname 1, VAR_0x8009
	removeitem VAR_0x8008, 1
	checkitemspace VAR_0x8009, 1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForReward
	giveitem VAR_0x8009
	playfanfare MUS_LEVEL_UP
	waitmessage
	waitfanfare
	call_if_eq VAR_0x8008, ITEM_FRESH_WATER, CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM16
	call_if_eq VAR_0x8008, ITEM_SODA_POP, CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM20
	call_if_eq VAR_0x8008, ITEM_LEMONADE, CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM33
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM16::
	setflag FLAG_GOT_TM16_FROM_THIRSTY_GIRL
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM16
	return

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM20::
	setflag FLAG_GOT_TM20_FROM_THIRSTY_GIRL
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM20
	return

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM33::
	setflag FLAG_GOT_TM33_FROM_THIRSTY_GIRL
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM33
	return

CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForReward::
	msgbox CeladonCity_DepartmentStore_Roof_Text_DontHaveSpaceForThis
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink::
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_IWantDrink::
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImThirstyIWantDrink
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll::
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImNotThirstyAfterAll
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_CooltrainerM::
	msgbox CeladonCity_DepartmentStore_Roof_Text_MySisterIsImmature, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_Roof_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_Roof_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_Roof_EventScript_VendingMachine::
	lockall
	message CeladonCity_DepartmentStore_Roof_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	setvar VAR_TEMP_3, 0
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink::
	switch VAR_TEMP_3
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink_FreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink_SodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink_Lemonade
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink_FreshWater::
	multichoicedefault 16, 0, MULTI_VENDING_MACHINE, 0, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_FreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_SodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_Lemonade
	msgbox CeladonCity_DepartmentStore_Roof_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink_SodaPop::
	multichoicedefault 16, 0, MULTI_VENDING_MACHINE, 1, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_FreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_SodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_Lemonade
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink_Lemonade::
	multichoicedefault 16, 0, MULTI_VENDING_MACHINE, 2, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_FreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_SodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_Lemonade
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_FreshWater::
	setvar VAR_TEMP_2, ITEM_FRESH_WATER
	setvar VAR_TEMP_3, 0
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_SodaPop::
	setvar VAR_TEMP_2, ITEM_SODA_POP
	setvar VAR_TEMP_3, 1
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_Lemonade::
	setvar VAR_TEMP_2, ITEM_LEMONADE
	setvar VAR_TEMP_3, 2
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_2
	playse SE_VEND
	msgbox CeladonCity_DepartmentStore_Roof_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_2
	bufferitemname STR_VAR_2, VAR_TEMP_2
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 16  @ 1/16 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_2
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_2
	bufferitemname STR_VAR_2, VAR_TEMP_2
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 32  @ 1/32 * the prev 1/16 chance of a third additional drink dropping,
	goto_if_ne VAR_RESULT, 0, CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_2
	goto_if_eq VAR_RESULT, 0, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_2
	bufferitemname STR_VAR_2, VAR_TEMP_2
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink::
	message CeladonCity_DepartmentStore_Roof_Text_WhichDrinkWouldYouLike
	waitmessage
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_NotEnoughMoneyForDrink::
	msgbox CeladonCity_DepartmentStore_Roof_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

CeladonCity_DepartmentStore_Roof_Text_ImThirstyGiveHerDrink::
    .string "I'm thirsty!\n"
    .string "I want something to drink!\p"
    .string "Give her a drink?$"

CeladonCity_DepartmentStore_Roof_Text_GiveWhichDrink::
    .string "Give her which drink?$"

CeladonCity_DepartmentStore_Roof_Text_YayFreshWaterHaveThis::
    .string "Yay!\p"
    .string "Fresh Water!\p"
    .string "Thank you!\n"
    .string "You can have this from me!$"

Text_ReceivedItemFromLittleGirl::
    .string "{PLAYER} received a {STR_VAR_2}\n"
    .string "from the little girl.$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM16::
    .string "TM16 contains Light Screen.\p"
    .string "It's a move that weakens the power\n"
    .string "of special attacks by your foe.$"

CeladonCity_DepartmentStore_Roof_Text_YaySodaPopHaveThis::
    .string "Yay!\p"
    .string "Soda Pop!\p"
    .string "Thank you!\n"
    .string "You can have this from me!$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM20::
    .string "TM20 contains Safeguard.\p"
    .string "It's a move that prevents status\n"
    .string "problems among your POKéMON.$"

CeladonCity_DepartmentStore_Roof_Text_YayLemonadeHaveThis::
    .string "Yay!\p"
    .string "Lemonade!\p"
    .string "Thank you!\n"
    .string "You can have this from me!$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM33::
    .string "TM33 contains Reflect.\p"
    .string "It's a move that weakens the power\n"
    .string "of physical attacks by your foe.$"

CeladonCity_DepartmentStore_Roof_Text_DontHaveSpaceForThis::
    .string "You don't have space for this!$"

CeladonCity_DepartmentStore_Roof_Text_ImNotThirstyAfterAll::
    .string "No, thank you!\n"
    .string "I'm not thirsty after all!$"

CeladonCity_DepartmentStore_Roof_Text_MySisterIsImmature::
    .string "My sister is a trainer, believe it\n"
    .string "or not.\p"
    .string "But, she's so immature, she drives\n"
    .string "me nuts!$"

CeladonCity_DepartmentStore_Roof_Text_ImThirstyIWantDrink::
    .string "I'm thirsty!\n"
    .string "I want something to drink!$"

CeladonCity_DepartmentStore_Roof_Text_FloorSign::
    .string "Rooftop Square:\n"
    .string "Vending Machines$"

CeladonCity_DepartmentStore_Roof_Text_WhichDrinkWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

CeladonCity_DepartmentStore_Roof_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

CeladonCity_DepartmentStore_Roof_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

CeladonCity_DepartmentStore_Roof_Text_NotEnoughMoney:
	.string "Not enough money…$"

CeladonCity_DepartmentStore_Roof_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"
