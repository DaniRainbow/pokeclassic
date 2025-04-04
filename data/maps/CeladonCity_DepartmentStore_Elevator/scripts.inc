CeladonCity_DepartmentStore_Elevator_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelect::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	call_if_unset FLAG_TEMP_2, CeladonCity_DepartmentStore_Elevator_EventScript_SetFloor
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
	special ShowDeptStoreElevatorFloorSelect
	message Text_DepartmentWhichFloorWillYouPick
	waitmessage
	specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom5th
	case 1, CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom4th
	case 2, CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom3rd
	case 3, CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom2nd
	case 4, CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom1st
	end

Text_DepartmentWhichFloorWillYouPick::
	.string "Which floor will you pick?$"

@ Below scripts ensure the cursor for floor select always starts on the current floor
CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom5th::
	multichoicedefault 0, 0, MULTI_FLOORS, 0, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom4th::
	multichoicedefault 0, 0, MULTI_FLOORS, 1, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom3rd::
	multichoicedefault 0, 0, MULTI_FLOORS, 2, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom2nd::
	multichoicedefault 0, 0, MULTI_FLOORS, 3, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloorFrom1st::
	multichoicedefault 0, 0, MULTI_FLOORS, 4, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Elevator_EventScript_5thFloor
	case 1, CeladonCity_DepartmentStore_Elevator_EventScript_4thFloor
	case 2, CeladonCity_DepartmentStore_Elevator_EventScript_3rdFloor
	case 3, CeladonCity_DepartmentStore_Elevator_EventScript_2ndFloor
	case 4, CeladonCity_DepartmentStore_Elevator_EventScript_1stFloor
	case 5, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	case MULTI_B_PRESSED, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_1stFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_1F, 6, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_2ndFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_2F, 6, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_3rdFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_3F, 6, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_4thFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_4F
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_4F, 6, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_5thFloor::
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_5F
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_5F, 6, 1
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect::
	special CloseDeptStoreElevatorWindow
	release
	end

CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	special CloseDeptStoreElevatorWindow
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	waitse
	special MoveElevator
	waitstate
	setflag FLAG_TEMP_2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

CeladonCity_DepartmentStore_Elevator_EventScript_SetFloor::
	special SetDeptStoreFloor
	return
