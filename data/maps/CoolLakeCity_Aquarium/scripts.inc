.SET LOCAL_ID_GRUNT_DOWN, 5
.set LOCAL_ID_GRUNT_UP, 6
.set LOCAL_ID_GRUNT_LEFT, 8
.set LOCAL_ID_GRUNT_RIGHT, 9

CoolLakeCity_Aquarium_MapScripts::
	.byte 0


CoolLakeCity_Aquarium_Event_LeftEntrance::
	lock
	applymovement LOCAL_ID_GRUNT_LEFT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_LEFT, Common_Movement_WalkDown
	waitmovement 0
	msgbox CoolLakeCity_Aquarium_Text_EntranceMessage, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	releaseall
	goto CoolLakeCity_Aquarium_Event_EntranceBattleLeft
	end

CoolLakeCity_Aquarium_Event_RightEntrance::
	lock
	applymovement LOCAL_ID_GRUNT_RIGHT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_LEFT, Common_Movement_WalkDown
	waitmovement 0
	msgbox CoolLakeCity_Aquarium_Text_EntranceMessage, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	releaseall
	goto CoolLakeCity_Aquarium_Event_EntranceBattleRight
	end
	
CoolLakeCity_Aquarium_Event_EntranceBattleLeft::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, CoolLakeCity_Aquarium_GruntIntro, CoolLakeCity_Aquarium_Text_GruntDefeated
	msgbox CoolLakeCity_Aquarium_Text_GruntEntranceLeft_Defeated, MSGBOX_AUTOCLOSE
	end

CoolLakeCity_Aquarium_Event_EntranceBattleRight::
	trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, CoolLakeCity_Aquarium_GruntIntro, CoolLakeCity_Aquarium_Text_GruntDefeated
	msgbox CoolLakeCity_Aquarium_Text_GruntEntranceLeft_Defeated, MSGBOX_AUTOCLOSE
	end


CoolLakeCity_Aquarium_GruntIntro:
	.string "Don't get in our way!$"

CoolLakeCity_Aquarium_Text_GruntDefeated:
	.string "The boss isn't going to be happy\n"
	.string "about this.$"

CoolLakeCity_Aquarium_Text_GruntEntranceLeft_Defeated:
	.string "I'm in so much trouble.$"

CoolLakeCity_Aquarium_Text_EntranceMessage:
	.string "Hey, how did this kid\n"
	.string "get in here?\p"
	.string "You're in trouble now!$"
