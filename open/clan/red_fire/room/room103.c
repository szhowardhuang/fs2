inherit ROOM;
void create() {
	set( "short", "$HIR$忘$NOR$$HIG$忧$NOR$$HIC$雅$NOR$$HIM$筑$NOR$" );
	set( "owner", "borchin" );
	set( "light_up", 1 );
	set( "object", ([
		"amount3"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"amount6"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/capital/obj/blade2",
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/daemon/class/blademan/obj/ublade",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/daemon/class/blademan/obj/shield",
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/dragonar",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file8"    : "/open/mogi/castle/obj/blood-water",
		"file9"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 10062 );
	set( "exits", ([
		"enter"     : "/open/clan/red_fire/room/room104",
		"north"     : "/open/clan/red_fire/room/room102.c",
	]) );
	set( "long", @LONG

正当你沈浸于沿途的美景时，忽然见到前方有一间别致的
$MAG$小屋$NOR$。走近一看，屋前的摆放着一只$YEL$古琴$NOR$，旁边还有$HIC$仙鹤$NOR$
在一旁飞舞着，见此情形你喃喃自语道：「$HIM$抚琴为乐，以
鹤为友$NOR$”，这种生活真是羡煞旁人啊。


LONG);
	setup();
	replace_program(ROOM);
}
