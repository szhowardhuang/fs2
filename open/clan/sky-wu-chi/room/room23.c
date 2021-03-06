// Room : /open/clan/sky-wu-chi/room/room23.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
从走道转进到这里，你觉得空间好像变的十分狭窄。忽然你看到一扇小小门，
上面写着八个小小字◎◎欢迎来到小小世界◎◎。你好奇的打开门往里头瞧去，里
面漆黑一片，也看不清楚出口，你试着弄出一些光亮，却随即被黑暗吞噬，可是恐
惧之心终究敌不过好奇的力量，所以把身上多余的东西放在小小门旁边的柜子里，
鼓起勇气，向着未知的通道走进去．．．

                $BLU$→ → →   ██▇▇▆▆▅▅▄▄    → → →$NOR$

骤然的光亮让你一时无法接受，但是随即你发现身边的东西仿佛都小了好几号，似
乎来到了孩童的世界一般，果然是小小世界。

LONG);
	set( "short", "$HIW$【小小世界入口】$NOR$" );
	set( "object", ([
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/killer/obj/k_ring",
		"file4"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file9"    : "/daemon/class/fighter/armband",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/dancer/obj/yuawaist",
		"amount2"  : 1,
		"file6"    : "/open/dancer/obj/maple_ribbon",
	]) );
	set( "build", 10175 );
	set( "owner", "peiyi" );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"enter"     : "/open/clan/sky-wu-chi/room/room74.c",
		"west"      : "/open/clan/sky-wu-chi/room/room12.c",
]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道无极" );
	set( "no_transmit", 1 );
	setup();

	}
