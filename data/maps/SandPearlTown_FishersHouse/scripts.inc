.set LOCALID_FISHERMAN, 1

SandPearlTown_FishersHouse_MapScripts::
	.byte 0

SandPearlTown_FishersHouse_EventScrip_TalkToFisher::
	lock
	faceplayer
	msgbox SandPearlTown_FishersHouse_Text_TalkToFisher, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

SandPearlTown_FishersHouse_Text_TalkToFisher:
	.string "Hey {PLAYER}!\n"
	.string "Hopefully the fish are biting good today.\p"
	.string "You should come join me\p"
	.string "by the shore after I finish\n"
	.string "my coffee.\p"
	.string "Afterall, fishing is better with friends.$"
