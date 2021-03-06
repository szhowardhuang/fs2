inherit ROOM;
void create() {
	set( "short", "血痕居" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/doctor/obj/feather",
	]) );
	set( "light_up", 1 );
	set( "build", 10444 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room300.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room301.c",
		"north"     : "/open/clan/sky-wu-chi/room/room298",
	]) );
	set( "owner", "holeman" );
	set( "long", @LONG
原以为从外表看来完全不起眼的房子，没想到在一打开大门
之后，竟然有一股惊天的杀气向你直冲而来，令你不得不运
起十成的功力来抵挡，但完全没想到这股杀气在你面前却消
失的无影无踪，看来此屋的主人功力以达到随心所欲的境界
了。当你进来此屋之后却惊讶的发觉，原来屋子里面除了简
单的装潢之外并没有看到任何人，看来还是不要继续逗留或
许会比较安全吧。
LONG);
	setup();
	replace_program(ROOM);
}
