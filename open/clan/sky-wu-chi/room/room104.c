// Room : /open/clan/sky-wu-chi/room/room104.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道无极" );
	set( "short", " 碎石小路 1" );
	set( "light_up", 1 );
	set( "build", 93 );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"file1"    : "/open/dancer/obj/yuaboots",
		"amount2"  : 1,
		"file2"    : "/open/gsword/obj/yugem",
	]) );
	set( "long", @LONG
东方是众所皆知的天极殿，西方则是雄伟豪放的镇
天西门，往天极殿的路程虽不长，但却也是一个鸟鸣常
叫的美好地方。路旁的树丛有着许许多多的可爱动物，
活泼的向你讨食物呢！看来并不只有天道无极的帮众们
喜爱这里了。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/sky-wu-chi/room/room103.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
