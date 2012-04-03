inherit ROOM;
void create() {
	set( "short", "¦ÆÐ¡ÄÏ¼Ò×ßÀÈ¦Æ" );
	set( "owner", "son" );
	set( "build", 10007 );
	set( "exits", ([
		"east"      : "/open/clan/demon_castle/room/room17",
		"south"     : "/open/clan/demon_castle/room/room18.c",
		"west"      : "/open/clan/demon_castle/room/room21.c",
	]) );
	set( "long", @LONG

[0;1m [1m [1m [1m [1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1mp[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mt[1m¡õ[1m@[1m¡õ[1m¡õ[1;36m¡õ[1m@[1m¡õ[1m~[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mS[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;37m¡õ[1mR[1m¡õ[1m¡õ[1m¡õ[1mF[1;33m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1mC[1m¡õ[1m¡õ[1m¡õ[1mx[1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m^[1m¡õ[1mA[1m¡õ[1m|[1m¡õ[1mP[1m¡õ[1m¡õ[1m¡õ[1mR[1m¡õ[1m¡õ[1m¡õ[1mF[1m¡õ[1mg[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1mT[1m¡õ[1m`[1m¡õ[1m`[1m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1mF[1m¡õ[1m@[0m
[0;1;37m¡õ[1mf[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1ml[1m¡õ[1mJ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1mP[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mP[1;32m¡õ[1m¡õ[1m¡õ[1mO[1;37m¡õ[1mA[1m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;37m¡õ[1ma[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mU[1m¡õ[1mB[1m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1m¡õ[1mO[1;37m¡õ[1mA[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mv[1m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mW[1m¡õ[1mi[1m¡õ[1mF[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[0m


[0;1;34m¡õ[1mp[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mg[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mb[1m¡õ[1mp[1m¡õ[1m|[1m¡õ[1mP[0m

LONG);
	setup();
	replace_program(ROOM);
}
