SandPearlTown_MapScripts::
	.byte 0


SandPearlTown_SetPlayerHouseWarp::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SandPearlTown_SetWarp_They
	compare VAR_RESULT, FEMALE
	goto_if_eq SandPearlTown_SetWarp_She
	release
	end

SandPearlTown_SetWarp_They::
	setdynamicwarp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 8
	release
	end

SandPearlTown_SetWarp_She::
	setdynamicwarp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 255, 1, 8
	release
	end
