inherit ROOM;
void create() {
	set( "short", "$HIR$¡∞‰Ù$HIC$∑ø$NOR$" );
	set( "owner", "sunsword" );
	set( "object", ([
		"amount1"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"file3"    : "/open/love/obj/shield",
		"file5"    : "/open/love/obj/shield",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/clan/area/home/hae_bag",
		"file9"    : "/open/capital/obj/blade2",
		"file4"    : "/open/killer/obj/k_ring",
		"amount7"  : 1,
		"amount10" : 1,
		"file10"   : "/daemon/class/fighter/armband",
		"file8"    : "/open/scholar/obj/s_hands",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/prayer/obj/boris-boots",
	]) );
	set( "light_up", 1 );
	set( "build", 23465 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room15.c",
		"east"      : "/open/clan/ou-cloud-club/room/room233",
	]) );
	set( "long", @LONG
[0;1;33m°ı[1m°ı[1mF[1mS[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1md[1m°ı[1ms[1m°ı[1m@[1m°ı[1m~[1m°ı[1mC[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m}[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mN[1m°ı[1mU[1m°ı[1mw[1m°ı[1mM[1m°ı[1m°ı[1m°ı[1mn[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m~[1m°ı[1m°ı[1m°ı[1m°ı[0m
[0;1;33m°ı[1mN[1m°ı[1mb[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mm[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m@[1m°ı[1m°ı[1m°ı[1mv[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m\[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mF[1m°ı[1mL[1m°ı[1mi[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mC[0m
[0;1;33m°ı[1m°ı[1m°ı[1mX[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1mD[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m^[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m}[1m°ı[1mb[1m°ı[1m°ı[1m°ı[1m^[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1mZ[1m°ı[1mL[1m°ı[1m°ı[1m°ı[1mD[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[0m
[0;1;33m°ı[1mM[1m°ı[1mo[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mO[1m°ı[1ms[1m°ı[1mM[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mC[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1mi[1m°ı[1m°ı[1m°ı[1mO[1m°ı[1m°ı[1m°ı[1mU[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mW[1m°ı[1mL[1m.[1m.[1m.[1m.[0m


LONG);
	setup();
	replace_program(ROOM);
}
