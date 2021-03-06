inherit ROOM;
void create() {
	set( "short", "皇城大道" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/mogi/dragon/obj/power",
		"amount10" : 1,
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 10,
		"amount3"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount8"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"file6"    : "/open/killer/headkill/obj/world_dag",
	]) );
	set( "build", 10006 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room6",
		"south"     : "/open/clan/13_luck/room/room4.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    这里是十三吉祥的大本营--皇城，放眼望去尽是深宫穹楼，一股庄
严的气氛笼罩着整个皇城，使你望之却步，脚下石版上刻着面龙腾凤舞
之浮雕，乃十三吉祥花费无数人力所凿造而成，非帮中之人，一但踏入
皇城之中再难回头, 只有落的丧生残体之下场...

LONG);
	setup();
	replace_program(ROOM);
}
