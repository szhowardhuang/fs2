inherit ROOM;
void create() {
	set( "short", "Á¶µ¤Æ«·¿" );
	set( "object", ([
		"file2"    : "/open/doctor/pill/gnd_pill",
		"amount2"  : 954,
		"amount1"  : 869,
		"file1"    : "/open/doctor/pill/sky_pill",
	]) );
	set( "build", 11526 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room362",
		"west"      : "/open/clan/13_luck/room/room144.c",
		"south"     : "/open/clan/13_luck/room/room361.c",
		"north"     : "/open/clan/13_luck/room/room360.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

[0;1m [1m [1m [1m [1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mu[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m@[1m¡õ[1mX[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m¡õ[1;33m¡õ[1m¡õ[1m¡õ[1mF[1m¡õ[1m¡õ[1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m\[0m
[0;1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1;32m¡õ[1mA[1m¡õ[1m¡õ[1;31m¡õ[1ma[1m¡õ[1mF[1m¡õ[1m¡õ[1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m\[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;35m¡õ[1m¡õ[1m¡õ[1mr[1;32m¡õ[1mA[1m¡õ[1mb[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mi[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mt[1m¡õ[1m@[1m¡õ[1m¡õ[0m
[0;1m¡õ[1m][1m¡õ[1mO[1m¡õ[1mi[1m¡õ[1mH[1;35m¡õ[1m¡õ[1m¡õ[1mr[1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mW[1m¡õ[1m¡õ[1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1mS[1;32m¡õ[1mA[1m¡õ[1mb[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1mu[1m¡õ[1m¡õ[1m¡õ[1m|[1m¡õ[1m¡õ[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1m¡õ[1m¡õ[1m¡õ[1mC[0m

LONG);
	setup();
	replace_program(ROOM);
}
