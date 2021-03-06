// Room : /open/clan/ou-cloud-club/room/room122.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 4 */
  "south" : "/open/clan/ou-cloud-club/room/room118",
  "north" : "/open/clan/ou-cloud-club/room/room16.c",
  "east" : "/open/clan/ou-cloud-club/room/room5.c",
  "west" : "/open/clan/ou-cloud-club/room/room123.c",
]) );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "clan_room", "傲云山庄" );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的地方，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是火焰女皇小Ｐ(ppp)的家，右边则是闲云野鹤(andyabc)之发呆房．

LONG);
	set( "light_up", 1 );
	set( "short", "$HIY$傲$HIC$云$NOR$居" );
	set( "object", ([
		"amount2"  : 1,
		"file10"   : "/daemon/class/bonze/puty_pullium",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 25,
		"amount5"  : 1,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 1,
		"file9"    : "/open/gsword/obj/yuskirt",
		"file4"    : "/open/scholar/obj/s_hands",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 22,
		"file1"    : "/daemon/class/fighter/armband",
		"amount3"  : 1,
	]) );
	set( "owner", "miko" );
	set( "build", 10396 );
	setup();

	}
