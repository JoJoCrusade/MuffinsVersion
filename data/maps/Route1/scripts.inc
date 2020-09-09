Route1_MapScripts::
	.byte 0

Route1_EventScript_Nostarter::
	lockall
	msgbox Route1_Text_TalkToBirch, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	releaseall
	end

Route1_Text_TalkToBirch:
	.string "Wait, didn't the\p"
	.string "Professor need something?$"
