// Room : /open/clan/ou-cloud-club/room/room103.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你感觉到水面下似乎有点古怪,低头往水里一看,赫然发现
已看不见水底了,心理升起一股好奇心,或许在这下面有着什么
宝物或机关也不一定,正所谓不入虎穴,焉得虎子,危险的地方,
也就是藏有宝物的地方,要下去一睹究竟吗?
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲云山庄" );
	set( "short", "$HIW$恶魔城$HIR$地下水脉$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount4"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
	]) );
	set( "build", 10005 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/ou-cloud-club/room/room104.c",
		"west"      : "/open/clan/ou-cloud-club/room/room100",
		"down"      : "/open/clan/ou-cloud-club/room/room102",
]) );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	setup();

	}
