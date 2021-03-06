inherit ROOM;
void create() {
	set( "short", "咏泉亭" );
	set( "build", 11257 );
	set( "object", ([
		"amount10" : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/main/obj/dragon-moon",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room154",
		"west"      : "/open/clan/13_luck/room/hall.c",
	]) );
	set( "long", @LONG

    在咏泉亭里只有一张石桌和几张石椅，看起来好像有些历史了当你
向前远望时，你感到非常高兴，因为目的地即将到达，而石桌上放着一
副棋子，正等着棋友下他一盘，从这里往外看去可以将柳月泉的风光尽
收眼底，这里也是让人最喜欢的地方。

LONG);
	setup();
	replace_program(ROOM);
}
