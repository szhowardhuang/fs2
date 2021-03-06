inherit ROOM;
void create() {
	set( "short", "隔世桥" );
	set( "object", ([
		"amount10" : 1,
		"amount3"  : 1,
		"file5"    : "/open/tendo/obj/chaosbelt",
		"amount9"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_boots",
		"amount7"  : 1,
		"file4"    : "/open/dancer/obj/yuawaist",
		"file7"    : "/daemon/class/fighter/armband",
		"amount1"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_hands",
		"amount4"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_pants",
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
	]) );
	set( "owner", "flight" );
	set( "build", 10004 );
	set( "exits", ([
		"enter"     : "/open/clan/sky-wu-chi/room/room259",
		"out"       : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
你漫步欣赏着这湖美丽的风光美景,发现在不远处有一条连接至
湖中小岛的桥,止时的你急着前往小岛去一探究竟是否为一个隐
居的好地方,正当你靠近桥时发现桥口有一块大石,石上写着不欢
迎外来客的拜访,只欢迎要来止安度晚年的人,看到止你心中一慌
不知是否要就只隐居去.
LONG);
	setup();
	replace_program(ROOM);
}
