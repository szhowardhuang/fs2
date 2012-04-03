inherit ROOM;
void create() {
	set( "short", "Â–“£»Àº‰µ¿" );
	set( "object", ([
		"file9"    : "/open/firedancer/npc/eq/r_head",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_shield",
		"file7"    : "/open/firedancer/npc/eq/r_cape",
		"amount9"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_boots",
		"amount4"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_neck",
		"amount10" : 1,
		"amount6"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_pants",
		"amount7"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_cloth",
		"file5"    : "/open/firedancer/npc/eq/r_belt",
		"file8"    : "/open/firedancer/npc/eq/r_hands",
		"amount5"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_armbands",
	]) );
	set( "build", 10320 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room162",
		"south"     : "/open/clan/13_luck/room/room165.c",
	]) );
	set( "long", @LONG

°°°°[0;1;32m°ı[1m°ı[1m°ı[1mD[1m°ı[1m°ı[1m°ı[1mB[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mO[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1mD[1m°ı[1m°ı[1m°ı[1mj[1m°ı[1mM[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mR[1m°ı[1mW[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[0m
[0;1;32m°ı[1m°ı[1m°ı[1mA[1m°ı[1mj[1m°ı[1mM[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mg[1m°ı[1m`[1m°ı[1mh[1m°ı[1m°ı[1m°ı[1md[1m°ı[1m~[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mw[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m@[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1mO[1m°ı[1mD[1m°ı[1mE[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m][0m
[0;1;32m°ı[1m|[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mL[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1mL[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mo[1m°ı[1mF[1m°ı[1mA[1m°ı[1mh[1m°ı[1m@[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m|[1m°ı[1m°ı[1m°ı[1mL[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mO[1m°ı[1m@[1m°ı[1mO[1m°ı[1mA[1m°ı[1m°ı[0m
[0;1;32m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mt[1m°ı[1mC[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1ml[1m°ı[1m°ı[1m°ı[1mF[1m°ı[1mC[1m°ı[1m°ı[1m°ı[1mk[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mh[1m°ı[1mF[1m.[1m.[0m

LONG);
	setup();
	replace_program(ROOM);
}
