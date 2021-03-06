inherit ROOM;
void create() {
	set( "short", "幻舞之间" );
	set( "object", ([
		"file6"    : "/daemon/class/fighter/ywhand",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"file9"    : "/open/prayer/obj/boris-boots",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file10"   : "/open/killer/obj/s_pill",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/daemon/class/fighter/figring",
		"file7"    : "/open/wu/npc/obj/armband",
		"amount10" : 41,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/capital/guard/gring",
	]) );
	set( "owner", "diana" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room214",
	]) );
	set( "build", 10059 );
	set( "light_up", 1 );
	set( "long", @LONG
刚步入此间，只见到房内竟然光线朦朦胧胧的，隐隐
约约之中，仿佛见到一个身材窈窕的女子，其站在房间的
中央翩翩起舞，只见在其舞动之间，其身旁瞬时出现阵阵
火光及闪雷，令人惧怕，又见此女子舞动愈渐激烈，四周
突然出现无数幻影，令人不敢轻易接近此间。
LONG);
	setup();
	replace_program(ROOM);
}
