inherit ROOM;
void create() {
	set( "short", "世间电道" );
	set( "owner", "vickey" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/doctor/pill/gnd_pill",
		"amount7"  : 14,
		"file7"    : "/open/doctor/pill/f_pill",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
		"amount10" : 1,
		"file9"    : "/open/ping/obj/poison_pill",
		"file10"   : "/open/ping/obj/cloud",
		"amount5"  : 19,
		"amount9"  : 3,
		"file1"    : "/open/capital/obj/gold_pill",
		"file3"    : "/open/snow/obj/stone",
		"amount2"  : 1,
		"file2"    : "/open/ping/obj/poison_pill",
		"amount6"  : 7,
	]) );
	set( "build", 11130 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room323",
		"east"      : "/open/clan/13_luck/room/room298.c",
		"north"     : "/open/clan/13_luck/room/room268",
	]) );
	set( "long", @LONG

    沧桑岁月，世间常变，来到这条十三吉祥的世间五候道，此道为[0;1;35m□[1mq[0m
[0;1;35m□[1mD[0m，用来比喻十三吉祥的后劲，而此道上面都放着给帮众的防具与武器
，而适用对象为，没时间打防具跟武器的帮众，与新进帮众没能力打防
具与没自己的房间可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
