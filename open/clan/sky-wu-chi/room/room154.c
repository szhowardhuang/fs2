inherit ROOM;
void create() {
	set( "short", "$HIC$【$NOR$大厅$HIC$】$NOR$小新家" );
	set( "object", ([
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/gblade/obj/dragon_book",
		"amount5"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"file9"    : "/open/mogi/castle/obj/blood-water",
		"amount7"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/obj/gift/bingtang",
		"amount9"  : 3,
		"amount3"  : 1,
		"file3"    : "/open/sky/obj4/rigid_shells",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"amount6"  : 62,
		"amount2"  : 1,
	]) );
	set( "owner", "eric" );
	set( "build", 10017 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room24.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room55.c",
		"out"       : "/open/clan/sky-wu-chi/room/room14.c",
		"east"      : "/open/clan/sky-wu-chi/room/room46.c",
		"west"      : "/open/clan/sky-wu-chi/room/room172.c",
	]) );
	set( "long", @LONG
这里是小新家的大厅，往上是小新家主要存放东西的地方。平
常没事的话应该都不会上去，所以如果有事的话都是在这里详谈，
往下走是小新家唯一没事做的人，破剑一把的小窝，主要也是放他
专用东西的房间。其他还有小新家的金刀小生小孤寂和魔刀小弟，
平常都可见到许多的人在这聊天，可见小新家的人都有点给他懒。

LONG);
	setup();
	replace_program(ROOM);
}













































































































































































































































































