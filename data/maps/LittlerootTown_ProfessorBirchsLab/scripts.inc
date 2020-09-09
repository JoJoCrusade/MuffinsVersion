.set LOCALID_BIRCH, 1
.set LOCALID_WAIDE, 2
.set LOCALID_AIDE, 3
.set LOCALID_WAILMER, 4
.set LOCALID_PIKACHU, 5
.set LOCALID_SANDSHREW, 6

LittlerootTown_ProfessorBirchsLab_MapScripts::
	.byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_TalkToProfessor::
	faceplayer
	lockall
	compare VAR_BIRCH_LAB_STATE, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_IntroGreeting
	compare VAR_BIRCH_LAB_STATE, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_WaitingStarterChoice
	compare VAR_BIRCH_LAB_STATE, 2
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_StartJourney
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_IntroGreeting::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_IntroGreeting, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_BIRCH_LAB_STATE, 1
	call LittlerootTown_ProfessorBirchsLab_EventScript_PlaceStarters
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_PlaceStarters::
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_ProfPlacePokemon
	waitmovement LOCALID_BIRCH
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceDown
	waitmovement LOCALID_BIRCH
	addobject LOCALID_WAILMER
	delay 16
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceDown
	waitmovement LOCALID_BIRCH
	addobject LOCALID_PIKACHU
	delay 16
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceDown
	waitmovement LOCALID_BIRCH
	addobject LOCALID_SANDSHREW
	delay 16
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_StartJourney::
	msgbox LittlerootTown_ProfessorBirchsLab_TEXT_IntroJourneystart, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

 LittlerootTown_ProfessorBirchsLab_Event_StarterBeforeTalking::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_StarterBeforeTalking, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WaitingStarterChoicePreventLeaving::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WaitingStarterChoice, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WaitingStarterChoice::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WaitingStarterChoice, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WAILMERBALL::
	compare VAR_BIRCH_LAB_STATE, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_StarterBeforeTalking
	compare VAR_BIRCH_LAB_STATE, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ChoosingWailmer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_PIKACHUBALL::
	compare VAR_BIRCH_LAB_STATE, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_StarterBeforeTalking
	compare VAR_BIRCH_LAB_STATE, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ChoosingPikachu
	end
LittlerootTown_ProfessorBirchsLab_EventScript_SANDSHREWBALL::
	compare VAR_BIRCH_LAB_STATE, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_StarterBeforeTalking
	compare VAR_BIRCH_LAB_STATE, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ChoosingSandshrew
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChoosingWailmer::
	showmonpic SPECIES_WAILMER, 8, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeWailmer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveWailmer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChoosingPikachu::
	showmonpic SPECIES_PIKACHU, 9, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakePikachu, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePikachu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChoosingSandshrew::
	showmonpic SPECIES_SANDSHREW, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeSandshrew, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveSandshrew
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveWailmer::
	bufferspeciesname 0, SPECIES_WAILMER
	setvar VAR_TEMP_1, SPECIES_WAILMER
	givemon SPECIES_WAILMER, 10, ITEM_NONE
	removeobject LOCALID_WAILMER
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedWailmer
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedWailmer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePikachu::
	bufferspeciesname 0, SPECIES_PIKACHU
	setvar VAR_TEMP_1, SPECIES_PIKACHU
	givemon SPECIES_PIKACHU, 10, ITEM_NONE
	removeobject LOCALID_PIKACHU
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedWailmer
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedWailmer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveSandshrew::
	bufferspeciesname 0, SPECIES_SANDSHREW
	setvar VAR_TEMP_1, SPECIES_SANDSHREW
	givemon SPECIES_SANDSHREW, 10, ITEM_NONE
	removeobject LOCALID_SANDSHREW
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedWailmer
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedWailmer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedWailmer::
	hidemonpic
	setvar VAR_BIRCH_LAB_STATE, 2
	call LittlerootTown_ProfessorBirchsLab_EventScript_StartJourney
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime:: @ 81FA061
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WaitingStarterChoice, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine:: @ 81FA3E3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_PC:: @ 81FA4BB
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf:: @ 81FA4C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Book:: @ 81FA4CD
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall:: @ 81FA4D6
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_ProfPlacePokemon:
	face_up
	walk_up
	face_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end


LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork: @ 81FA4E2
	.string "Hunh? PROF. BIRCH?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork: @ 81FA641
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo: @ 81FA6CE
	.string "PROF. BIRCH is studying the habitats\n"
	.string "and distribution of POKéMON.\p"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon: @ 81FA74D
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "I've heard that you don't have your\n"
	.string "own POKéMON yet.\p"
	.string "But the way you battled earlier,\n"
	.string "you pulled it off with aplomb!\p"
	.string "I guess you have your father's blood\n"
	.string "in your veins after all!\p"
	.string "Oh, yes. As thanks for rescuing me,\n"
	.string "I'd like you to have the POKéMON you\l"
	.string "used earlier.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon: @ 81FA8B1
	.string "PROF. BIRCH: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival: @ 81FA8F6
	.string "PROF. BIRCH: If you work at POKéMON\n"
	.string "and gain experience, I think you'll make\l"
	.string "an extremely good TRAINER.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "POKéMON while helping me out.\p"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou: @ 81FA9D5
	.string "PROF. BIRCH: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a TRAINER.$"

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay: @ 81FAA35
	.string "PROF. BIRCH: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome: @ 81FAA74
	.string "PROF. BIRCH: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your POKéMON get tired,\n"
	.string "you should get some rest at home.$"

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex: @ 81FAB22
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
	.string "I heard you beat {RIVAL} on\n"
	.string "your first try. That's excellent!\p"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "{RIVAL} has an extensive history as\n"
	.string "a TRAINER already.\p"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
	.string "research, but I think you should have\l"
	.string "this POKéDEX.$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex: @ 81FAC32
	.string "{PLAYER} received the POKéDEX!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex: @ 81FAC4B
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any POKéMON you meet or catch.\p"
	.string "My kid, {RIVAL}, goes everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare POKéMON\n"
	.string "and records its data in the POKéDEX,\l"
	.string "why, {RIVAL} looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait: @ 81FAD6F
	.string "PROF. BIRCH: Countless POKéMON\n"
	.string "await you!\p"
	.string "Argh, I'm getting the itch to get out\n"
	.string "and do fieldwork again!$"

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese: @ 81FADD7
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
	.string "You got a POKéDEX, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls: @ 81FAE40
	.string "MAY: It's fun if you can get a lot of\n"
	.string "POKéMON!\p"
	.string "I'm going to look all over the place\n"
	.string "because I want different POKéMON.\p"
	.string "If I find any cute POKéMON, I'll catch\n"
	.string "them with POKé BALLS!$"

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull: @ 81FAEF3
	.string "Oh? Your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext: @ 81FAF08
	.string "MAY: I wonder where I should go look\n"
	.string "for POKéMON next?$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese: @ 81FAF3F
	.string "BRENDAN: Huh…\n"
	.string "So you got a POKéDEX, too.\p"
	.string "Well then, here.\n"
	.string "I'll give you these.$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls: @ 81FAF8E
	.string "BRENDAN: You know it's more fun to\n"
	.string "have a whole bunch of POKéMON.\p"
	.string "I'm going to explore all over the place\n"
	.string "to find different POKéMON.\p"
	.string "If I find any cool POKéMON, you bet\n"
	.string "I'll try to get them with POKé BALLS.$"

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull: @ 81FB05D
	.string "Hey, your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext: @ 81FB073
	.string "BRENDAN: Where should I look for\n"
	.string "POKéMON next…$"

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine: @ 81FB0A2
	.string "It's a serious-looking machine.\n"
	.string "The PROF must use this for research.$"

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch: @ 81FB0E7
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon: @ 81FB124
	.string "It's crammed with books on POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead: @ 81FB148
	.string "It's a book that's too hard to read.$"

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational: @ 81FB16D
	.string "PROF. BIRCH: Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
	.string "of you help me study POKéMON.\p"
	.string "Thanks to your help, new facts\n"
	.string "are coming to light.\p"
	.string "It appears that in the HOENN region,\n"
	.string "there are also POKéMON from other\l"
	.string "regions.\p"
	.string "It goes to show how rich and varied\n"
	.string "the natural environments of HOENN\l"
	.string "happen to be.\p"
	.string "That's why I think it's necessary for\n"
	.string "me to upgrade your POKéDEX to\l"
	.string "the NATIONAL Mode.\p"
	.string "Here, let me see your POKéDEX units.$"

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool: @ 81FB30F
	.string "MAY: Eheheh!\p"
	.string "It's so cool that even my POKéDEX\n"
	.string "is getting updated!\p"
	.string "It's because you went out and caught\n"
	.string "so many POKéMON, {PLAYER}{KUN}!$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe: @ 81FB38E
	.string "BRENDAN: I went out all over HOENN\n"
	.string "and checked out POKéMON.\p"
	.string "You can thank me for getting\n"
	.string "the NATIONAL Mode POKéDEX.\p"
	.string "Yep, you're lucky, {PLAYER}!$"

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone: @ 81FB419
	.string "PROF. BIRCH: Okay, all done!$"

LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational: @ 81FB436
	.string "{PLAYER}'s POKéDEX was upgraded\n"
	.string "to the NATIONAL Mode!$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2: @ 81FB466
	.string "PROF. BIRCH: But listen.\n"
	.string "You've become the CHAMPION,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork: @ 81FB528
	.string "MAY: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the PROF here for\n"
	.string "a while.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork: @ 81FB58A
	.string "BRENDAN: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the PROF here\n"
	.string "for a while.$"

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon: @ 81FB5F9
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Yes, there's no doubt about it.\p"
	.string "You really have completed the HOENN\n"
	.string "region's POKéDEX.\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is a rare POKéMON only found\n"
	.string "in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon: @ 81FB787
	.string "PROF. BIRCH: These are rare POKéMON\n"
	.string "only found in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil: @ 81FB7F6
	.string "PROF. BIRCH: The FIRE POKéMON\n"
	.string "CYNDAQUIL caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So the CYNDAQUIL is your choice?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile: @ 81FB869
	.string "PROF. BIRCH: The WATER POKéMON\n"
	.string "TOTODILE is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TOTODILE?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita: @ 81FB8E0
	.string "PROF. BIRCH: The GRASS POKéMON\n"
	.string "CHIKORITA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CHIKORITA?$"

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable: @ 81FB959
	.string "PROF. BIRCH: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable POKéMON.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon: @ 81FB9A8
	.string "PROF. BIRCH: I see!\n"
	.string "You picked a fine POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter: @ 81FB9D7
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter: @ 81FB9FC
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_1} you received?$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting: @ 81FBA2C
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
	.string "You've completed the HOENN POKéDEX,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone: @ 81FBAF8
	.string "You received the promised POKéMON.\n"
	.string "Better leave the others alone.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon: @ 81FBB3A
	.string "Oh, you don't have any room for\n"
	.string "this POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere: @ 81FBB68
	.string "MAY: {PLAYER}{KUN}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the NATIONAL POKéDEX?\p"
	.string "I'm staying here to help the PROF.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly: @ 81FBC2D
	.string "BRENDAN: Rather than collecting\n"
	.string "POKéMON, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier: @ 81FBC8D
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
	.string "Have you gone to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier: @ 81FBCD2
	.string "BRENDAN: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall: @ 81FBD1A
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
	.string "It's me, SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like to\n"
	.string "invite you to for a visit.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SLATEPORT or LILYCOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

LittlerootTown_ProfessorBirchsLab_Text_IntroGreeting:
	.string "Ah, just who I was waiting to see!\n"
	.string "Hello {PLAYER}, thank you for stopping by\p"
	.string "I appreciate the help\n"
	.string "There have been rumors of a rare POKéMON\p"
	.string "being seen in the mountain far north from here.\n"
	.string "Everyone has been so busy\p"
	.string "collecting gym badges.\n"
	.string "They're not interested in the joy\p"
	.string "of discovery!\n"
	.string "Which is where you come in!\n"
	.string "I know you have dreams other than\p"
	.string "a POKéMON master. I need someone\n"
	.string "with your love for the world\p"
	.string "to go check out those rumors\n"
	.string "Please, take one of my POKéMON\p"
	.string "It'll be dangerous without one.\n"
	.string "They're on the table next to me\p"
	.string "Don't worry you'll pick up on it quickly!$"

LittlerootTown_ProfessorBirchsLab_TEXT_IntroJourneystart:
	.string "Thank you, I know you can do it!\n"
	.string "Head north of here to the next town\p"
	.string "You'll be able to find supplies and maybe even\n"
	.string "some trainers who will help you out\p"
	.string "Good luck!$"

LittlerootTown_ProfessorBirchsLab_Text_WaitingStarterChoice:
	.string "It can be dangerous to go alone\p"
	.string "go ahead and take one of my POKéMON$"

LittlerootTown_ProfessorBirchsLab_Text_StarterBeforeTalking:
	.string "I better not take this\p"
	.string "without asking the Professor$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeWailmer:
	.string "That's Wailmer, be careful\p"
	.string "they're lighter thank you think.\n"
	.string "I had one float away from me\p"
	.string "like a balloon!$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakePikachu:
	.string "That's Pikachu, although you\p"
	.string "probably already knew that.\n"
	.string "It's shocking how cute they can be!$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeSandshrew:
	.string "That's Sandshrew, they're known\p"
	.string "to be a little shy at first but\n"
	.string "don't worry, it's Sandshrew\p"
	.string "not Sandshrewd!$"
