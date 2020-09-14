Route2_MapScripts::
	.byte 0

Route2_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route2_Text_CalvinIntro, Route2_Text_CalvinDefeated
	msgbox Route2_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route2_Text_TianaIntro, Route2_Text_TianaDefeated
	msgbox Route2_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route2_Text_RickIntro, Route2_Text_RickDefeated
	msgbox Route2_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_Text_CalvinIntro:
	.string "I bet you're a strong trainer!$"

Route2_Text_CalvinDefeated:
	.string "Looks like I was right.$"

Route2_Text_CalvinPostBattle:
	.string "You're just helping the professor?\n"
	.string "Sorry for boterhing you!$"

Route2_Text_TianaIntro:
	.string "My Slowpoke is different thant other Slowpokes$"

Route2_Text_TianaDefeated:
	.string "But my Slowpoke is\n"
	.string "in the top percentage of Slowpokes$"

Route2_Text_TianaPostBattle:
	.string "I spent days catching for perfect values...\p"
	.string "Maybe there's more to Pokemon than stats$"

Route2_Text_RickIntro:
	.string "My mom says I'll be a Pokemon master!$"

Route2_Text_RickDefeated:
	.string "I'm sorry mom...$"

Route2_Text_RickPostBattle:
	.string "I'll just have to train even harder.\n"
	.string "I'm not giving up that easily!$"
