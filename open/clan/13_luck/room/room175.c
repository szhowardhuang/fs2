inherit ROOM;
void create() {
	set( "short", "¾ø³¾ÑÂµ×" );
	set( "owner", "mirage" );
	set( "object", ([
		"amount6"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10065 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room161",
	]) );
	set( "long", @LONG
[0;1;36m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1mi[1m¡õ[1mo[1m¡õ[1mV[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mM[1m¡õ[1mJ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1mq[1m¡õ[1mJ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m°ÙÕÉÆÙ²¼[0;1;36m¡õ[1m¡õ[1m¡õ[1my[0m
[0;1;36m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1mA[1m¡õ[1mR[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;33m¡õ[1m{[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;36m¡õ[1mA[1m¡õ[1my[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mE[1m¡õ[1m¡õ[1m¡õ[1me[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1mi[1m¡õ[1m¡õ[1m¡õ[1me[1m¡õ[1m¡õ[1m¡õ[1mL[1m¡õ[1m¡õ[0m
[0;1;36m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1m~[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[1m¡õ[1mN[1m¡õ[1mD[1m¡õ[1mb[1m¡õ[1mM[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mO[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1mC[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;35m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[1m¡õ[1mC[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mB[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1mn[1m¡õ[1mO[1m¡õ[1mH[1m¡õ[1my[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[0m
LONG);
	setup();
	replace_program(ROOM);
}
