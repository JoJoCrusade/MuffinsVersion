Route1_MapScripts::
	.byte 0

Route1_EventScript_Nostarter::
	lockall
	msgbox Route1_Text_TalkToBirch, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

Route1_Text_TalkToBirch:
	.string "Wait, didn't the Professor need\n"
	.string "something?$"
