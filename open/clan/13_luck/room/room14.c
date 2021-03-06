inherit ROOM;
void create() {
	set( "short", "朱雀堂" );
	set( "owner", "aman" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file4"    : "/daemon/class/fighter/armband",
		"amount5"  : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount10" : 1,
		"file8"    : "/open/mogi/village/obj/mogi_ring",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/tendo/obj/chaosbelt",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 19190 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room15",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在朱雀堂的室内不少人忙进忙出的工作，这里是管十三吉祥的文书
中心，在这里你可以找到有关十三吉祥的事件与名册，叙述着它以前辉
煌的历史和创立十三吉祥时前人的为艰，并将永传下去与不灭绝有如凤
凰一般，更希望能勉励后人继承先人的遗志。

LONG);
	setup();
	replace_program(ROOM);
}
