inherit ROOM;
void create() {
	set( "short", "心系何处的房间" );
	set( "object", ([
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 12,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/dancer/obj/yuawaist",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount5"  : 1,
		"amount1"  : 33,
		"file5"    : "/daemon/class/blademan/obj/ublade",
		"file9"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"file10"   : "/open/scholar/obj/icefan",
		"amount9"  : 1,
		"amount3"  : 6,
		"file3"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10140 );
	set( "owner", "konanii" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room342",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    这是心系何处的房间，只见门口站着风，地，水，火是大龙王，
那是心系何处向天堂的GM借来看守他的房间，走进去一看，有一个武
器架跟一个防具架，里面满满的放着一些看起来不起眼的装备，再进
去里面有一个书桌，桌上放一个电脑，那是心系何处在练供之余跟马
子聊天打屁用的，室内满是刀痕，突显心系何处急于长大的野心。


LONG);
	setup();
	replace_program(ROOM);
}
