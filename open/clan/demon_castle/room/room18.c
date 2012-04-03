inherit ROOM;
void create() {
	set( "short", "¦ÆÐ¡ÄÏ¼ÒÇ°Ìü¦Æ" );
	set( "object", ([
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount3"  : 1,
		"file5"    : "/open/capital/obj/4-4",
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/obj/soil-ball",
	]) );
	set( "build", 10270 );
	set( "owner", "son" );
	set( "exits", ([
		"east"      : "/open/clan/demon_castle/room/room14.c",
		"out"       : "/open/clan/demon_castle/room/room7.c",
		"north"     : "/open/clan/demon_castle/room/room4",
		"west"      : "/open/clan/demon_castle/room/room16.c",
	]) );
	set( "long", @LONG

[0;1m¡õ[1m@[1m¡õ[1m@[1;37m¡õ[1mw[1m¡õ[1m¡õ[1;33m¡õ[1mz[1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1;32m¡õ[1mp[1m¡õ[1mn[1;37m¡õ[1m¡õ[1;36m¡õ[1m¡õ[1m¡õ[1m|[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mA[1m¡õ[1m@[1m¡õ[1m_[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;32m¡õ[1mp[1m¡õ[1mn[1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m\[1m¡õ[1m¡õ[1m¡õ[1m~[0m
[0;1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mR[1m¡õ[1m¡õ[1m¡õ[1mF[1;34;47m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37;40m¡õ[1m¡õ[1m¡õ[1mL[1m¡õ[1mp[1m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1mA[1m¡õ[1mO[1m¡õ[1m¡õ[1;30m¡õ[1m¡õ[1m¡õ[1ma[1m¡õ[1mH[1;37m¡õ[1mT[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;37m¡õ[1m¡õ[1;33m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1;34m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1;30m¡õ[1mg[1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;36m¡õ[1mu[1m¡õ[1m¡õ[1;37m¡õ[1mA[1m¡õ[1ml[1m¡õ[1mJ[1;32m¡õ[1mp[1m¡õ[1mn[1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mX[1m¡õ[1mF[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mE[1m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mC[0m


[0;1;34m¡õ[1mp[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mg[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mb[1m¡õ[1mp[1m¡õ[1m|[1m¡õ[1mP[0m

LONG);
	setup();
	replace_program(ROOM);
}
