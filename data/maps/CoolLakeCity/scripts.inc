.set LOCAL_ID_GRUNT_GYM, 1
.set LOCAL_ID_GRUNT_LEFT, 2
.set LOCAL_ID_GRUNT_RIGHT, 3
.set LOCAL_ID_GRUNT_BATTLE, 4

CoolLakeCity_MapScripts::
	.byte 0


CoolLakeCity_Event_CheatMon::
	givemon SPECIES_MEWTWO, 50, ITEM_NONE
	end

CoolLakeCity_Event_GetPositionLeft::
	setflag FLAG_TEMP_1
	call CoolLakeCity_Event_GruntsTalking
	end

	CoolLakeCity_Event_GetPositionDown::
	setflag FLAG_TEMP_2
	call CoolLakeCity_Event_GruntsTalking
	end

CoolLakeCity_Event_GetPositionRight::
	setflag FLAG_TEMP_3
	call CoolLakeCity_Event_GruntsTalking
	end

CoolLakeCity_Event_GruntsTalking::
	msgbox CoolLakeCity_Text_GruntsTalking1, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCAL_ID_GRUNT_LEFT, Common_Movement_FaceUp
	msgbox CoolLakeCity_Text_GruntsTalking2, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCAL_ID_GRUNT_LEFT, Common_Movement_FaceDown
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq CoolLakeCity_Event_GruntsTalkingShe
	compare VAR_RESULT, MALE
	goto_if_eq CoolLakeCity_Event_GruntsTalkingThey
	releaseall
	end

CoolLakeCity_Event_GruntsTalkingShe::
	msgbox CoolLakeCity_Text_GruntsTalking3_She
	waitmessage
	goto CoolLakeCity_Event_GruntsWalkAway
	end

CoolLakeCity_Event_GruntsTalkingThey::
	msgbox CoolLakeCity_Text_GruntsTalking3_She
	waitmessage
	goto CoolLakeCity_Event_GruntsWalkAway
	end

CoolLakeCity_Event_GruntsWalkAway::
	applymovement LOCAL_ID_GRUNT_LEFT, Common_Movement_WalkUp6
	applymovement LOCAL_ID_GRUNT_RIGHT, Common_Movement_WalkUp6
	waitmovement 0
	goto CoolLakeCity_Event_GruntBattle
	end

CoolLakeCity_Event_GruntBattle::
	goto_if_set FLAG_TEMP_1, CoolLakeCity_Event_BattleWalkLeft
	goto_if_set FLAG_TEMP_2, CoolLakeCity_Event_BattleWalkDown
	goto_if_set FLAG_TEMP_3, CoolLakeCity_Event_BattleWalkRight
	end

CoolLakeCity_Event_BattleWalkLeft::
	applymovement LOCAL_ID_GRUNT_BATTLE, CoolLakeCity_Movement_BattleLeft
	waitmovement 0
	goto CoolLakeCity_Event_BattleGrunt
	end

CoolLakeCity_Event_BattleWalkDown::
	applymovement LOCAL_ID_GRUNT_BATTLE, CoolLakeCity_Movement_BattleDown
	waitmovement 0
	goto CoolLakeCity_Event_BattleGrunt
	end

CoolLakeCity_Event_BattleWalkRight::
	applymovement LOCAL_ID_GRUNT_BATTLE, CoolLakeCity_Movement_BattleRight
	waitmovement 0
	goto CoolLakeCity_Event_BattleGrunt
	end


CoolLakeCity_Event_BattleGrunt::
	trainerbattle_single TRAINER_GRUNT_PETALBURG_WOODS, CoolLakeCity_Text_GruntIntro, CoolLakeCity_Text_GruntDefeated, CoolLakeCity_Event_BattleGrunt
	msgbox CoolLakeCity_Text_GruntBattleOver, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCAL_ID_GRUNT_BATTLE, Common_Movement_WalkUp6
	waitmovement 0
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	setvar VAR_SLATEPORT_CITY_STATE, 1
	removeobject LOCAL_ID_GRUNT_BATTLE
	removeobject LOCAL_ID_GRUNT_LEFT
	removeobject LOCAL_ID_GRUNT_RIGHT
	releaseall
	end

CoolLakeCity_Text_GruntsTalking1:
	.string "Alright, the boss said there's some rare\n"
	.string "POKEMON in the Aqurium.\p"
	.string "The two of us will break in\n"
	.string "and get to work.$"

CoolLakeCity_Text_GruntsTalking2:
	.string "Meanwhile you'll guard the entrance\p"
	.string "The Gym leader is away, so as long\n"
	.string "Any other trainers don't show up,\n"
	.string "We shouldn't have any problems$"

CoolLakeCity_Text_GruntsTalking3_She:
	.string "What's this punk doing here?\p"
	.string "Take care of them, we'll go get started.$"

CoolLakeCity_Text_GruntsTalking3_They:
	.string "What's this punk doing here?\p"
	.string "Take care of them, we'll go get started.$"

CoolLakeCity_Text_GruntIntro:
	.string "You better not get in our way!$"

CoolLakeCity_Text_GruntDefeated:
	.string "Hmph, you got lucky...$"

CoolLakeCity_Text_GruntBattleOver:
	.string "I don't know who you think you are,\n"
	.string "but if you know what's best for you\p"
	.string "You better turn around and leave.$"

CoolLakeCity_Movement_BattleLeft:
	walk_left
	walk_down
	step_end

CoolLakeCity_Movement_BattleDown:
	walk_down
	step_end

CoolLakeCity_Movement_BattleRight:
	walk_right
	walk_down
	step_end
