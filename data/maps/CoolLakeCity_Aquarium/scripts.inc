.SET LOCAL_ID_GRUNT_DOWN, 5
.set LOCAL_ID_GRUNT_UP, 6
.set LOCAL_ID_GRUNT_LEFT, 8
.set LOCAL_ID_GRUNT_RIGHT, 9
.set LOCAL_ID_GYM_LEADER, 10

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

CoolLakeCity_Aquarium_Event_ConfrontGrunt_LeftDown::
	setvar VAR_0x8008, 1
	releaseall
	end

CoolLakeCity_Aquarium_Event_ConfrontGrunt_LeftUp::
	setvar VAR_0x8008, 2
	releaseall
	end

CoolLakeCity_Aquarium_Event_ConfrontGrunt3_RightUp::
	setvar VAR_0x8008, 3
	releaseall
	end

CoolLakeCity_Aquarium_Event_ConfrontGrunt4_RightDown::
	setvar VAR_0x8008, 4
	releaseall
	end

CoolLakeCity_Aquarium_Event_ConfrontGrunt_TalkToGruntUp::
	lock
	applymovement LOCAL_ID_GRUNT_UP, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_UP, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CoolLakeCity_Aquarium_Text_GruntConfronted, MSGBOX_NPC
	waitmessage
	goto CoolLakeCity_Aquarium_Event_GymLeaderSpawn
	end

CoolLakeCity_Aquarium_Event_ConfrontGrunt_TalkToGruntDown::
	lock
	applymovement LOCAL_ID_GRUNT_DOWN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_DOWN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CoolLakeCity_Aquarium_Text_GruntConfronted, MSGBOX_NPC
	waitmessage
	goto CoolLakeCity_Aquarium_Event_GymLeaderSpawn
	end

CoolLakeCity_Aquarium_Event_GymLeaderSpawn::
	addobject LOCAL_ID_GYM_LEADER,
	setobjectxy LOCAL_ID_GYM_LEADER, 6, 16
	compare VAR_0x8008, 1
	call_if_eq CoolLakeCity_Aquarium_Event_GymLeaderApproach1
	compare VAR_0x8008, 2
	call_if_eq CoolLakeCity_Aquarium_Event_GymLeaderApproach2
	compare VAR_0x8008, 3
	call_if_eq CoolLakeCity_Aquarium_Event_GymLeaderApproach3
	compare VAR_0x8008, 4
	call_if_eq CoolLakeCity_Aquarium_Event_GymLeaderApproach4
	applymovement LOCAL_ID_GYM_LEADER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CoolLakeCity_Aquarium_Text_GymLeader_HereToHelp, MSGBOX_DEFAULT
	waitmessage
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	releaseall
	end

CoolLakeCity_Aquarium_Event_GymLeaderApproach1::
	applymovement LOCAL_ID_GYM_LEADER, CoolLakeCity_Aquarium_Movement_GymApproach1
	waitmovement 0
	return

CoolLakeCity_Aquarium_Event_GymLeaderApproach2::
	applymovement LOCAL_ID_GYM_LEADER, CoolLakeCity_Aquarium_Movement_GymApproach2
	waitmovement 0
	return

CoolLakeCity_Aquarium_Event_GymLeaderApproach3::
	applymovement LOCAL_ID_GYM_LEADER, CoolLakeCity_Aquarium_Movement_GymApproach3
	waitmovement 0
	return

CoolLakeCity_Aquarium_Event_GymLeaderApproach4::
	applymovement LOCAL_ID_GYM_LEADER, CoolLakeCity_Aquarium_Movement_GymApproach1
	waitmovement 0
	return

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

CoolLakeCity_Aquarium_Text_GymLeader_HereToHelp:
	.string "Sorry I'm late!\p"
	.string "Looks like you're doing a good job,\n"
	.string "Mind if I help you out with these two?$"

CoolLakeCity_Aquarium_Text_GruntConfronted:
	.string "As if we don't have enough\n"
	.string "problems already.\p"
	.string "I don't know how you made it\n"
	.string "this far\p"
	.string "but it's the end of the line for you!$"


CoolLakeCity_Aquarium_Movement_GymApproach2:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CoolLakeCity_Aquarium_Movement_GymApproach3:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CoolLakeCity_Aquarium_Movement_GymApproach4:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

CoolLakeCity_Aquarium_Movement_GymApproach1:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
