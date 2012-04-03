// Room : /open/clan/ou-cloud-club/room/room9.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "傲云道(B2)" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "long", @LONG
通往恶魔城的道路，是傲云山庄内的主要道路，两
边的墙壁是以$HIC$玄离冰$NOR$打造而成的，不时透发出一股清透
凉意，火把更是以火龙幻境内的$HIR$火龙胆$NOR$点燃，据说可以
永不熄灭．而地板则是使用无坚不摧的金刚石所铺设而
成，一眼望去光芒万千．
LONG);
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "north" : "/open/clan/ou-cloud-club/room/room10.c",
  "south" : "/open/clan/ou-cloud-club/room/room8",
]) );
	set( "clan_room", "傲云山庄" );
	setup();

	}
