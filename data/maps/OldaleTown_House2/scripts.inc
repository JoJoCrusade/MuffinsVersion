OldaleTown_House2_MapScripts:: @ 81FBF5A
	.byte 0

OldaleTown_House2_EventScript_Woman:: @ 81FBF5B
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man:: @ 81FBF64
	goto_if_unset FLAG_ITEM_ROUTE_102_POTION, OldaleTown_House2_EventScript_Man_GivePotion
	msgbox OldaleTown_House2_Text_ToBeYouthful, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man_GivePotion::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	waitmessage
	closemessage
	giveitem ITEM_POTION
	setflag FLAG_ITEM_ROUTE_102_POTION
	closemessage
	end

OldaleTown_House2_Text_PokemonLevelUp: @ 81FBF6D
	.string "The caterpies here sure are strange.$"


OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon: @ 81FBFB0
	.string "You're just starting your adventure?\n"
	.string "Oh to be youthful again.\p"
	.string "Have this, it should help you out.$"

OldaleTown_House2_Text_ToBeYouthful: @ 81FBFB0
	.string "Oh to be youthful again.$\p"
