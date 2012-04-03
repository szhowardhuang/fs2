// Room : /open/clan/sky-wu-chi/room/room22.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
你现在所在的地方就是空瓶子的居所的外头，在这里你并无感觉到有什么的
不同你看了一下四周的景色。远处的峻秀高山林立，且七彩烟雾迷曼。在这里你
其实已经感到身体方面有点怪异了。看了门外的两只石狮，像是用一种你完全都
不知道的石头做的。四周的景色十分的漂亮，当你正想走进一点进去里头时。你
发现有一股抗拒的力量，且这股力量也随你的前进越来越重。之后你看到了一个
石碑上头写着‘入内者死’。你心中的一股不服气于是你更是要往前而行。
LONG);
	set( "short", "空瓶子居外头" );
	set( "build", 318 );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/sky-wu-chi/room/room11",
  "enter" : "/open/clan/sky-wu-chi/room/room50.c",
]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道无极" );
	setup();

	}
