// Room : /open/clan/sky-wu-chi/room/room76.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "short", "白色水晶结界" );
	set( "owner", "sski" );
	set( "object", ([
		"file3"    : "/open/capital/room/king/obj/dagger1",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/prayer/obj/boris-cloth",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount10" : 1,
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"amount7"  : 1,
		"file9"    : "/open/dancer/obj/yuawaist",
		"amount6"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 12321 );
	set( "long", @LONG
你走进这里时，你发现了这个地方怎么烟雾迷漫的，令人摸不清
处方向，你点了起来木材来照明，只是四周还是一样并未让你有觉得
有亮了一些，所以你找好放弃靠外界的照明工具，而改采用你自己本
身的敏感度去感觉四周气流的变动，突然间你发现了超时空的生物就
出现在这四周的烟雾之中，只是当你在这样想的同时，那生物正以时
速一百十二公里朝你冲了过来。

LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/sky-wu-chi/room/room78.c",
		"south"     : "/open/clan/sky-wu-chi/room/room50.c",
		"west"      : "/open/clan/sky-wu-chi/room/room213",
		"north"     : "/open/clan/sky-wu-chi/room/room145.c",
]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道无极" );
	setup();

	}
