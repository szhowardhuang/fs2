inherit ROOM;
void create() {
	set( "short", "ÊÀ¼ä¸¡»ªÂ¥" );
	set( "object", ([
		"file2"    : "/open/firedancer/npc/eq/r_shield",
		"file1"    : "/open/firedancer/npc/eq/r_leg",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_neck",
		"amount1"  : 1,
		"file3"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10779 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room244",
		"up"        : "/open/clan/13_luck/room/room242",
	]) );
	set( "long", @LONG

    ´Ë¼äÎªÁËÒÔÇ°µÄÀÖÍ¸É±ÊÖËù½¨Á¢µÄ...
[0;1;32m¡õ[1mX[1m¡õ[1m¡õ[1m¡õ[1mb[1m¡õ[1mh[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mC[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mh[1m¡õ[1mF[1m¡õ[1mC[1m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m^[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[0m
[0;1;32m¡õ[1mP[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mP[1m¡õ[1mC[1m¡õ[1mY[1m¡õ[1mm[1m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m_[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[0m
[0;1;32m¡õ[1mi[1m¡õ[1mH[1m¡õ[1mR[1m¡õ[1mO[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[1m¡õ[1mL[1m¡õ[1mx[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mL[1m¡õ[1m[[1m¡õ[1mZ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[0m
[0;1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1mC[0m           
            Îá×ÔÔÆ£º[0;1;5;31m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m~[1;5m¡õ[1;5m¡õ[0m£¡

LONG);
	setup();
	replace_program(ROOM);
}
