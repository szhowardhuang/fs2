// Room : /open/clan/ou-cloud-club/room/room99.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "傲云山庄" );
	set( "short", "$HIW$恶魔城$HIR$地下水脉$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/mon/obj/ghost-cloak",
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10016 );
	set( "light_up", 1 );
	set( "long", @LONG
这里有几处突起的地面坐落在水中,看来踩着这些地方也能
前进,慢慢走吧,由于溼度的关系,地面上可是长满了青苔呢.可
小心点不要掉下去了呢,传说恶魔城存在着能在水里吐发火焰
的怪鱼,若掉下去真的被魔物逮着了,那可就大擭喽~~~
LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room100.c",
  "west" : "/open/clan/ou-cloud-club/room/room98",
]) );
	set( "no_transmit", 1 );
	setup();

	}
