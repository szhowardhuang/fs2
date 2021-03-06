inherit ROOM;
void create() {
	set( "short", "世间风道" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_pants",
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_belt",
		"file1"    : "/open/firedancer/npc/eq/r_cape",
		"file4"    : "/open/firedancer/npc/eq/r_hands",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_shield",
		"file2"    : "/open/firedancer/npc/eq/r_boots",
		"amount6"  : 1,
	]) );
	set( "build", 10998 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room300.c",
		"south"     : "/open/clan/13_luck/room/room319",
		"east"      : "/open/clan/13_luck/room/room277.c",
		"north"     : "/open/clan/13_luck/room/room272.c",
	]) );
	set( "long", @LONG

    沧桑岁月，世间常变，来到这条十三吉祥的世间五候道，此道为[0;1;36m□[1m□[0m
[0;1;36m□[1mD[0m，用来比喻十三吉祥的威力，而此道上面都放着给帮众的防具与武器
，而适用对象为，没时间打防具跟武器的帮众，与新进帮众没能力打防
具与没自己的房间可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
