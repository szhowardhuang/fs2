inherit ROOM;
void create() {
	set( "short", "–°ƒœº“¥Û√≈" );
	set( "owner", "son" );
	set( "object", ([
		"file5"    : "/open/magic-manor/obj/golden-ball",
		"file2"    : "/open/magic-manor/obj/water-ball",
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"file8"    : "/open/killer/outsea/dstone",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"amount6"  : 100,
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/soil-ball",
	]) );
	set( "build", 10200 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room54.c",
		"enter"     : "/open/clan/13_luck/room/room67",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

[0;1m [1m [1m [1m [1;37m°ı[1m°ı[1mF[1mS[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1md[1m°ı[1ms[1m°ı[1m@[1m°ı[1m~[1m°ı[1mC[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m}[1m°ı[1m°ı[1m°ı[1mA[1;32m°ı[1mp[1m°ı[1mn[1;37m°ı[1mN[1m°ı[1mU[1m°ı[1mw[1m°ı[1mM[1m°ı[1m°ı[1m°ı[1mn[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m~[1m°ı[1m°ı[1m°ı[1m°ı[0m
[0;1;37m°ı[1mN[1m°ı[1mb[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mm[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m@[1m°ı[1m°ı[1m°ı[1mv[1m°ı[1m°ı[1;35m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m\[1;37m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mF[1m°ı[1mL[1m°ı[1mi[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mC[0m
[0;1;37m°ı[1m°ı[1m°ı[1mX[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1mD[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m^[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m}[1m°ı[1mb[1m°ı[1m°ı[1m°ı[1m^[1m°ı[1m°ı[1m°ı[1mU[1;35m°ı[1mZ[1m°ı[1mL[1m°ı[1m°ı[1m°ı[1mD[1;37m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[0m
[0;1;37m°ı[1mM[1m°ı[1mo[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1m°ı[1m°ı[1m°ı[1;33m°ı[1mO[1m°ı[1ms[1m°ı[1mM[1;36m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mC[1;37m°ı[1mA[1m°ı[1m°ı[1m°ı[1mi[1;34m°ı[1m°ı[1m°ı[1mO[1m°ı[1m°ı[1m°ı[1mU[1;37m°ı[1mA[1;31m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mW[1m°ı[1mL[1;37m.[1m.[1m.[1m.[0m

LONG);
	setup();
	replace_program(ROOM);
}
