.set LOCAL_ID_TOTODILE, 4
.SET LOCAL_ID_GRUNT_DOWN, 5
.set LOCAL_ID_GRUNT_UP, 6
.set LOCAL_ID_GRUNT_POOL, 7
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
	releaseall
	goto CoolLakeCity_Aquarium_Event_EntranceBattleRight
	end
	
CoolLakeCity_Aquarium_Event_EntranceBattleLeft::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, CoolLakeCity_Aquarium_GruntIntro, CoolLakeCity_Aquarium_Text_GruntDefeated, CoolLakeCity_Aquarium_Event_EntranceBattleLeft
	msgbox CoolLakeCity_Aquarium_Text_GruntEntranceLeft_Defeated, MSGBOX_AUTOCLOSE
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	end

CoolLakeCity_Aquarium_Event_EntranceBattleRight::
	trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, CoolLakeCity_Aquarium_GruntIntro, CoolLakeCity_Aquarium_Text_GruntDefeated, CoolLakeCity_Aquarium_Event_EntranceBattleRight
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
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
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	clearflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	special SavePlayerParty
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	fadescreen FADE_TO_BLACK
	delay 15
	removeobject LOCAL_ID_GRUNT_LEFT
	removeobject LOCAL_ID_GRUNT_POOL
	removeobject LOCAL_ID_GRUNT_RIGHT
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	delay 2
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	setvar VAR_0x8004, SPECIAL_BATTLE_STEVEN
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, CoolLakeCity_Aquarium_Event_MultiBattleWon
	goto CoolLakeCity_Aquarium_Event_GoodEffort
	releaseall
	end

CoolLakeCity_Aquarium_Event_GoodEffort::
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	removeobject LOCAL_ID_GRUNT_UP
	removeobject LOCAL_ID_GRUNT_DOWN
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1
	delay 30
	fadescreen FADE_FROM_WHITE
	msgbox CoolLakeCity_Aquarium_Text_GoodEffort, MSGBOX_DEFAULT
	waitmessage
	goto CoolLakeCity_Aquarium_Event_GruntsGone
	end

CoolLakeCity_Aquarium_Event_MultiBattleWon::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCAL_ID_GRUNT_UP, Common_Movement_FaceDown
	applymovement LOCAL_ID_GRUNT_DOWN, Common_Movement_FaceUp
	waitmovement 0
	msgbox CoolLakeCity_Aquarium_Text_GruntsLeaving, MSGBOX_DEFAULT
	waitmessage
	closemessage
	switch VAR_0x8008
	case 1, CoolLakeCity_Aquarium_Event_GruntsLeaveRight
	case 2, CoolLakeCity_Aquarium_Event_GruntsLeaveRight
	goto CoolLakeCity_Aquarium_Event_GruntsLeaveDown
	end

CoolLakeCity_Aquarium_Event_GruntsLeaveDown::
	applymovement LOCAL_ID_GRUNT_UP, Common_Movement_FaceDown
	applymovement LOCAL_ID_GRUNT_DOWN, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_DOWN, CoolLakeCity_Aquarium_Movement_GruntsLeaveDown
	applymovement LOCAL_ID_GRUNT_UP, Common_Movement_WalkDown
	waitmovement LOCAL_ID_GRUNT_UP
	applymovement LOCAL_ID_GRUNT_UP, CoolLakeCity_Aquarium_Movement_GruntsLeaveDown
	waitmovement 0
	goto CoolLakeCity_Aquarium_Event_GruntsGone
	end

CoolLakeCity_Aquarium_Event_GruntsLeaveRight::
	applymovement LOCAL_ID_GRUNT_UP, Common_Movement_WalkRight
	applymovement LOCAL_ID_GRUNT_DOWN, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_DOWN, CoolLakeCity_Aquarium_Movement_GruntsLeaveRight
	applymovement LOCAL_ID_GRUNT_UP, Common_Movement_WalkDown
	waitmovement LOCAL_ID_GRUNT_UP
	applymovement LOCAL_ID_GRUNT_UP, CoolLakeCity_Aquarium_Movement_GruntsLeaveRight
	waitmovement 0
	goto CoolLakeCity_Aquarium_Event_GruntsGone
	end

CoolLakeCity_Aquarium_Event_GruntsGone::
	msgbox CoolLakeCity_Aquarium_Text_MultiBattleWon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1
	removeobject LOCAL_ID_GRUNT_DOWN
	removeobject LOCAL_ID_GRUNT_UP
	applymovement LOCAL_ID_TOTODILE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCAL_ID_TOTODILE, Common_Movement_HeartMark
	waitmovement 0
	msgbox CoolLakeCity_Aquarium_Text_Totodile, MSGBOX_DEFAULT
	waitmessage
	goto CoolLakeCity_Aquarium_Event_GetTotodile
	end

CoolLakeCity_Aquarium_Event_GetTotodile::
	bufferspeciesname 0, SPECIES_TOTODILE
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq CoolLakeCity_EventScript_SendTotodileToParty
	compare VAR_RESULT, 1
	goto_if_eq CoolLakeCity_EventScript_SendTotodileToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

CoolLakeCity_EventScript_SendTotodileToParty::
	playfanfare MUS_OBTAIN_ITEM
	msgbox CoolLakeCity_Aquarium_Text_TotodileRecieved, MSGBOX_AUTOCLOSE
	removeobject LOCAL_ID_TOTODILE
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CoolLakeCity_Aquarium_Event_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CoolLakeCity_Aquarium_Event_ReceivedTotodile
	end

CoolLakeCity_EventScript_SendTotodileToPC::
	playfanfare MUS_OBTAIN_ITEM
	msgbox CoolLakeCity_Aquarium_Text_TotodileRecieved, MSGBOX_AUTOCLOSE
	removeobject LOCAL_ID_TOTODILE
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CoolLakeCity_Aquarium_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CoolLakeCity_Aquarium_EventScript_TotodileTransferredToPC
	end

CoolLakeCity_Aquarium_EventScript_TotodileTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto CoolLakeCity_Aquarium_Event_ReceivedTotodile
	end

CoolLakeCity_Aquarium_Event_ReceivedTotodile::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2
	msgbox CoolLakeCity_Aquarium_Text_VisitMyGym, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject LOCAL_ID_GYM_LEADER
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 2
	fadescreen FADE_FROM_BLACK
	releaseall
	end

CoolLakeCity_Aquarium_Event_GruntTainer_F::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_GRUNT_AQUA_HIDEOUT_3, 0, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
	end

CoolLakeCity_Aquarium_Event_GruntTainer_M::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_GRUNT_AQUA_HIDEOUT_4, 0, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
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

CoolLakeCity_Aquarium_Text_MultiBattleWon:
	.string "Good battling out there!\p"
	.string "We shouldn't have any problems\n"
	.string "with them after that beatdown.$"

CoolLakeCity_Aquarium_Text_GoodEffort:
	.string "Are you ok?.\n"
	.string "Don't worry,\p"
	.string "I managed to scare them off\n"
	.string "Thanks to your help.$"

CoolLakeCity_Aquarium_Text_Totodile:
	.string "Oh, Totodile seems really\n"
	.string "greatfull for the help!\p"
	.string "You know what, I think\p"
	.string "Totodile can tell you have\n"
	.string "a kind heart. I know!\p"
	.string "How about you\n"
	.string "let Totodile join your adventure!\p"
	.string "I insist, and it looks\n"
	.string "Totodile does too.\p"
	.string "Ha, so it's settled!$"

CoolLakeCity_Aquarium_Text_VisitMyGym:
	.string "Phew, well I'm glad that's over\p"
	.string "I should get back to the gym\n"
	.string "You're heading to the mountains?\p"
	.string "Make sure you stop by\n"
	.string "I have something that\p"
	.string "Can help you out\n"
	.string "on your journey.$"

CoolLakeCity_Aquarium_Text_GruntsLeaving:
	.string "Forget the POKEMON We need\n"
	.string "to get out of here.\p"
	.string "You'll regret messing with us!$"

CoolLakeCity_Aquarium_Text_TotodileRecieved:
	.string "{PLAYER} RECIEVED TOTODILE$"


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

CoolLakeCity_Aquarium_Movement_GruntsLeaveDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

CoolLakeCity_Aquarium_Movement_GruntsLeaveRight:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end
