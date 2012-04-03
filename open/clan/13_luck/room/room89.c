inherit ROOM;
void create() {
	set( "short", "¡Œ“˘∏Æ" );
	set( "owner", "joy" );
	set( "object", ([
		"file4"    : "/open/mogi/village/obj/mogi_ring",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount5"  : 1,
		"file2"    : "/open/gblade/obj/g-blade",
		"amount6"  : 1,
		"file7"    : "/open/gsword/obj/ring-1",
		"amount7"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file8"    : "/open/gsword/obj/ring-1",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount4"  : 1,
	]) );
	set( "build", 10125 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room105",
		"east"      : "/open/clan/13_luck/room/room83",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
[0;1;36m°ı[1m@[1m°ı[1m°ı[1m°ı[1mi[1m°ı[1mo[1m°ı[1mA[1m°ı[1mY[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m@[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1ms[1m°ı[1mP[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1mW[1m°ı[1mY[1m°ı[1mg[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mj[0m
[0;1;36m°ı[1m°ı[1m°ı[1mC[1m°ı[1m°ı[1m°ı[1mr[0;1;5;33m°ı[1;5mu[1;5m°ı[1;5m@[1;5m°ı[1;5m°ı[1;5m°ı[1;5m@[1;5m°ı[1;5mx[1;5m°ı[1;5m@[1;5m°ı[1;5mH[1;5m°ı[1;5m@[1;5m°ı[1;5m][1;5m°ı[1;5m@[1;5m°ı[1;5m°ı[1;5m°ı[1;5m@[1;5m°ı[1;5m°ı[1;5m°ı[1;5m@[1;5m°ı[1;5mU[1;5m°ı[1;5m@[1;5m°ı[1;5mv[0;1;36m°ı[1mA[1m°ı[1mb[0m
[0;1;36m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mh[1m°ı[1mA[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1m°ı[1;35m°ı[1m°ı[1m°ı[1mx[1m°ı[1mH[1;36m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1mA[1m°ı[1mb[1m°ı[1mM[1m°ı[1m@[1m°ı[1ms[1;31m°ı[1m°ı[0m
[0;1;31m°ı[1mk[1;36m°ı[1mj[1m°ı[1m°ı[1mS[1mM[1m°ı[1mC[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1mu[1m°ı[1mO[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1mQ[1m°ı[1mg[1m°ı[1mQ[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mp[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mA[1m°ı[1m°ı[0m
[0;1;36m°ı[1mH[1m°ı[1mA[1m°ı[1m°ı[1m°ı[1mO[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m}[1m°ı[1m°ı[1m°ı[1ma[1m°ı[1m°ı[1m°ı[1mn[1m°ı[1mA[1m°ı[1mK[1m°ı[1m°ı[1m°ı[1mQ[1m°ı[1mL[1m°ı[1m°ı[1m°ı[1mW[1m°ı[1mC[0m
LONG);
	setup();
	replace_program(ROOM);
}
