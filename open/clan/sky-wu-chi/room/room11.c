// Room : /open/clan/sky-wu-chi/room/room11.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
这里是休闲区，刚好来到这里看歌星表演，现
在在台上的是恰克与。。。飞鸟怎又不见了？算了
，那我们请媚儿来客串一下吧，不过媚儿小妞，请
不要跳钢管舞，这边有儿童勿宜外加十八禁。。。
节目也到了尾声了，回家的时候快到了。大家上车
往下站去吧。
LONG);
	set( "exits", ([ /* sizeof() == 4 */
		"north"     : "/open/clan/sky-wu-chi/room/room12.c",
		"south"     : "/open/clan/sky-wu-chi/room/room10.c",
		"east"      : "/open/clan/sky-wu-chi/room/room22.c",
]) );
	set( "short", "走 廊 4" );
	set( "build", 76 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道无极" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	setup();

	}
