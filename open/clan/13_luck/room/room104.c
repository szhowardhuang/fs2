inherit ROOM;
void create() {
	set( "short", "EMC 华亚营区" );
	set( "object", ([
		"amount6"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/tendo/obj/chaosbelt",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file8"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file1"    : "/daemon/class/blademan/obj/iceblade",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "wyld" );
	set( "build", 10224 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room75",
		"north"     : "/open/clan/13_luck/room/room111.c",
		"west"      : "/open/clan/13_luck/room/room110.c",
		"east"      : "/open/clan/13_luck/room/room112.c",
		"south"     : "/open/clan/13_luck/room/room109",
	]) );
	set( "long", @LONG
一进营区,看到一区区隔开的营办公室,旁边还有营长室,餐厅,作战室跟会客室
另一边有一区是军械室跟杂物库房,大门旁有绳索下去,放着悍马跟大卡的地方
在营办旁边有着RE-3000公尺跑步场地,CE-单杠场地,令一边有着RS-五百障碍场
CS-射击靶场,另一区更有ESD炸弹试爆场地,EFT 震撼教育场,等等个式场地
LONG);
	setup();
	replace_program(ROOM);
}
