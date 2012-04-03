inherit ROOM;
void create() {
	set( "short", "Î÷Æ«·¿" );
	set( "owner", "titanic" );
	set( "object", ([
		"amount10" : 1,
		"amount2"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10050 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room171.c",
		"east"      : "/open/clan/13_luck/room/room139.c",
	]) );
	set( "long", @LONG

[0;1m [1m [1m [1m [1;35m¡õ[1m¡õ[1m¡õ[1m¡õ[1;32m¡õ[1m¡õ[1m¡õ[1m\[1m¡õ[1m¡õ[1m¡õ[1mD[1m¡õ[1m`[1m¡õ[1m¡õ[1m¡õ[1mh[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1m\[1m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1m¡õ[1m¡õ[1mQ[1m¡õ[1m@[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m{[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;32m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1m¡õ[1m¡õ[1m@[1m¡õ[1mZ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mn[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m@[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1mF[1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;32m¡õ[1mt[1m¡õ[1mW[1;35m¡õ[1m¡õ[1m¡õ[1m¡õ[1;32m¡õ[1mA[1m¡õ[1mb[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mn[1m¡õ[1m¡õ[0m
[0;1;32m¡õ[1mv[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mg[1m¡õ[1mL[1;36m¡õ[1mC[1m¡õ[1mC[1m¡õ[1m|[1m¡õ[1mQ[1m¡õ[1mE[1m¡õ[1m¡õ[1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m_[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mN[1m¡õ[1mi[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1mX[1;31m¡õ[1m¡õ[1m¡õ[1m@[1m¡õ[1mZ[1m¡õ[1m¡õ[1;32m¡õ[1mA[0m
[0;1;32m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mv[1m¡õ[1m¡õ[1;31m¡õ[1mA[1m¡õ[1m¡õ[1;32m¡õ[1m}[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m|[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1mZ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;34m¡õ[1mF[1m¡õ[1m¡õ[1;32m¡õ[1mC[0m

LONG);
	setup();
	replace_program(ROOM);
}
