// Room : /open/clan/ou-cloud-club/room/room54.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$恶魔城$HIR$大礼拜堂$NOR$" );
	set( "build", 10203 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/ou-cloud-club/room/room49",
]) );
	set( "clan_room", "傲云山庄" );
	set( "long", @LONG
前方是一座长直的朝圣阶梯,每二十阶便会有一名手持钢盾
以及利剑的亡灵骑士把守,要阻止任何人前进,也许他们把守的
就是另一个世界的信仰之源吧!!你可以感觉到强烈的宗教气息
,却无法确认其根源本质究竟为神圣或者邪恶.
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
