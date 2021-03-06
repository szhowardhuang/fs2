inherit ROOM;
void create() {
	set( "short", "云窟" );
	set( "object", ([
		"amount6"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/ping/obj/gold_hand",
		"file8"    : "/open/ping/obj/chilin_legging",
		"file5"    : "/open/scholar/obj/icefan",
		"file6"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
		"file2"    : "/daemon/class/fighter/figring",
		"amount5"  : 1,
		"amount4"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"file9"    : "/open/prayer/obj/boris-cloth",
		"file7"    : "/daemon/class/blademan/obj/ublade",
		"amount1"  : 1,
	]) );
	set( "build", 10209 );
	set( "owner", "ckn" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room71",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    这里充满一股飘邈云气，眼前景物一片朦胧，但仔细看却发现窟
中两旁陈列着许多上等翠玉打造的摆饰，看似整齐，其实是依五行八
卦阵排列。但最让你惊讶的是前方翡翠石壁上竟然刻着另一个世界的
‘相思碎梦刀’法。

LONG);
	setup();
	replace_program(ROOM);
}
