inherit ROOM;
void create() {
	set( "short", "创意写作室1" );
	set( "owner", "kanno" );
	set( "object", ([
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount8"  : 1,
		"file1"    : "/open/killer/obj/bellstar",
		"amount5"  : 1,
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount10" : 1,
		"amount1"  : 250,
		"amount3"  : 1,
		"amount7"  : 1,
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"file2"    : "/open/killer/memory/static",
		"amount2"  : 1,
		"file4"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "light_up", 1 );
	set( "build", 10044 );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room114.c",
		"up"        : "/open/clan/red_fire/room/room55.c",
		"down"      : "/open/clan/red_fire/room/hall.c",
	]) );
	set( "long", @LONG

这里是一间创意写作室，你看到赶稿中正努力的埋头于
书桌上专心的写稿，听说那是小渡大大交代的暑假作业
，在放暑假之前，一定要交出来，否则......嘿....嘿
....嘿....后果不堪设想，会影响到每一位杀手喔，将
无法完成第二段的进阶，况且这样会让赶稿中越来越胖
喔......因为......常言道，食言而肥！！哈....哈..
..哈....


LONG);
	setup();
	replace_program(ROOM);
}
