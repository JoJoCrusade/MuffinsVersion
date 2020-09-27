.set LOCAL_ID_FISHER, 1
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

SandPearlTown_Event_Snorlax::
	lockall
	msgbox SandpearlTown_Text_Snorlax, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
	end

SandPearlTown_Event_Fisherwoman::
	lock
	applymovement LOCAL_ID_FISHER, Common_Movement_FacePlayer
	msgbox SandPearlTown_Text_FisherGreeting, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto_if_set FLAG_RECEIVED_OLD_ROD, SandPearlTown_Event_HowsFishing
	msgbox SandPearlTown_Text_GetRod, MSGBOX_DEFAULT
	waitmessage
	closemessage
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox SandPearlTown_Text_GotRod, MSGBOX_AUTOCLOSE
	applymovement LOCAL_ID_FISHER Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SandPearlTown_Event_HowsFishing::
	applymovement LOCAL_ID_FISHER Common_Movement_FacePlayer
	msgbox SandPearlTown_Text_GotRod, MSGBOX_AUTOCLOSE
	applymovement LOCAL_ID_FISHER Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SandPearlTown_Text_FisherGreeting:
	.string "Howdy Neighbor!$"

SandPearlTown_Text_GetRod:
	.string "Would you care to join me?\p"
	.string "The fish are biting good today!\p"
	.string "Here you can have my old rod\n"
	.string "to get you started.$"

SandPearlTown_Text_GotRod:
	.string "May the Sea give you luck.$"

SandpearlTown_Text_Snorlax:
	.string "Uh oh, there's a Snorlax\n"
	.string "in the way.\p"
	.string "Maybe this will be ready\n"
	.string "by the next demo.$"
