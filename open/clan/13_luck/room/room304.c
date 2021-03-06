inherit ROOM;
void create() {
	set( "short", "世间火道" );
	set( "object", ([
		"amount10" : 1,
		"amount3"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_head",
		"amount9"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_hands",
		"amount2"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_boots",
		"file4"    : "/open/firedancer/npc/eq/r_leg",
		"amount1"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_cape",
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_shield",
		"file6"    : "/open/firedancer/npc/eq/r_armbands",
		"file3"    : "/open/firedancer/npc/eq/r_neck",
		"file9"    : "/open/firedancer/npc/eq/r_cloth",
		"amount6"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_finger",
		"amount5"  : 1,
	]) );
	set( "build", 11700 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room305.c",
		"south"     : "/open/clan/13_luck/room/room316",
		"east"      : "/open/clan/13_luck/room/room303.c",
		"north"     : "/open/clan/13_luck/room/room266.c",
	]) );
	set( "long", @LONG

    沧桑岁月，世间常变，来到这条十三吉祥的世间五行道，此道为[0;1;31m□[1m□[0m
[0;1;31m□[1mD[0m，用来比喻十三吉祥的防御，而此道上面都放着给帮众的防具与武器
，而适用对象为，没时间打防具跟武器的帮众，与新进帮众没能力打防
具与没自己的房间可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
