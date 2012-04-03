inherit ROOM;
void create() {
	set( "short", "龙极殿" );
	set( "owner", "roick" );
	set( "light_up", 1 );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 112,
		"amount3"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 11680 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room46",
		"west"      : "/open/clan/sky-wu-chi/room/room194.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room30.c",
	]) );
	set( "long", @LONG
这里是帮主的卧室 当你一走进这里时你突然被一阵锋利的刀气给
吓得不知道如何是好 而这些刀气就是平常帮主所修炼出来的
他不但修为以到达天人进界 所以有如此强烈的刀气
所以此房间不是人人可以进入的 必须要有一定的修为才行 
LONG);
	setup();
	replace_program(ROOM);
}
