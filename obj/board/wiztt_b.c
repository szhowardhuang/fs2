inherit BULLETIN_BOARD;
void create()

{


set_name("内阁版",({ "wizthing board ","board"}));
	set("location","/open/wiz/hall3");

	set("board_id","wiztt_b");
	set("long", "就是人事异动啦,报告啦,考核啦,都要post在这哦");

	setup();
	set("capacity", 100);
	}
