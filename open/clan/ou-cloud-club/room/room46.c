// Room : /open/clan/ou-cloud-club/room/room46.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$恶魔城$HIR$炼金研究栋$NOR$" );
	set( "build", 15502 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room28",
  "up" : "/open/clan/ou-cloud-club/room/room47.c",
]) );
	set( "clan_room", "傲云山庄" );
	set( "long", @LONG
这里已经没有通路了,不过墙上砌着一块块一尺见方的小平台
,呈螺旋型的围绕着圆柱型的墙壁蜿蜒而上,若是不在乎几个奇怪
小骨骸滴着黄绿色液体陪伴着前进的话,你可以藉着这些小石台
跳跃而上,远处似乎传来一阵教堂里才能听到的钟声..
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
