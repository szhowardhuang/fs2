inherit BULLETIN_BOARD;

void create()
{
	set_name("录音室", ({ "board" }) );
	set("location", "/open/wiz/meeting");
	set("board_id", "wiz_record_b");
	set("long",	"\n");
	setup();
	set("capacity", 100);
	// 设这样就能让那些人 discard post 啰
	set("master", ({"wade", "chan"}) );
}
