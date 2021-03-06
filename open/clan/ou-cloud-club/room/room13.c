// Room : /open/clan/ou-cloud-club/room/room13.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIC$寒冰$HIR$玉床$NOR$" );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/prayer/obj/boris-cloth",
		"file3"    : "/daemon/class/fighter/armband",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"file1"    : "/open/dancer/obj/yuawaist",
		"file6"    : "/open/scholar/obj/s_hands",
		"amount5"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10529 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/ou-cloud-club/room/room180",
		"west"      : "/open/clan/ou-cloud-club/room/room119.c",
]) );
	set( "clan_room", "傲云山庄" );
	set( "long", @LONG
帮主的主卧房，只见左边墙上放着一幅五百张的狗狗
拼图，图上小狗极其可爱，右边墙上挂满着主人四处征战
所获得的战利品，一些武林中极其稀有的武器防具尽在墙
上，居中放着一张寒冰玉床，正是他从古墓中取回来，一
阵阵寒气逼来，真怀疑这要怎么睡人．

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	setup();

	}
