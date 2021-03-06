inherit ROOM;
void create() {
	set( "short", "乾坤八卦殿" );
	set( "light_up", 1 );
	set( "owner", "diana" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room215",
	]) );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file2"    : "/open/marksman/obj/super_pill",
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 114,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/daemon/class/fighter/ywhand",
	]) );
	set( "build", 10350 );
	set( "long", @LONG
干无定，坤无常，乾坤殿堂上，挂着乾坤八卦图，此乃
五行幻化之八卦合一，堂堂大殿上，雄壮的气息总是不会缺
少，在乾坤八卦殿上，总觉得比一般的殿堂上还要有种不可思议
的力量存在，这里也像其他殿上那像的平佣，你不知不觉走入后
，仿佛被殿中的八卦阵给迷惑了，一时间竟不知如何是好....
LONG);
	setup();
	replace_program(ROOM);
}
