// Room : /open/clan/ou-cloud-club/room/room34.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$YEL$丝绸之路$NOR$" );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
沿途的景象渐渐多了些绿色的点缀了,不是沙漠中的绿洲,而是
因为这里已经接近地中海了,往西过去就是东欧了,完全不同于中国
和印度的另一种古老文明,据说民族主义及浪漫学在此非常盛行,西
边有一条河,河畔树林绵密,景色优美,这就是横亘欧陆的多瑙河.
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/ou-cloud-club/room/room31",
		"west"      : "/open/clan/ou-cloud-club/room/room35.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲云山庄" );
	setup();

	}
