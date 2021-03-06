inherit ROOM;
void create() {
	set( "short", "$HIC$【医药宝物专柜】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 15,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/fire-ball",
		"amount10" : 1,
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/wood-ball",
		"file7"    : "/open/doctor/pill/ice_pill",
		"file9"    : "/open/doctor/pill/ff_pill",
		"file10"   : "/open/capital/guard/gring",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"amount7"  : 198,
		"amount9"  : 123,
		"amount6"  : 1,
	]) );
	set( "build", 10231 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room226",
	]) );
	set( "long", @LONG
    你打开北边的小柜子，迎面扑鼻而来的是一阵阵淡淡清香的丹药味
道，很明显这里放着小佩佩个人收藏的奇珍妙药，不过你仔细的观察，
可以发现其实里面还是有一些很「家常”的药，像是恢复体力，恢复状
态等等平常可见的药。在药品的旁边，也放了一些有趣的宝物，特别的
宝物，或者是神奇妙用的宝物，这一些宝物是小佩佩周游各地，与各地
方的先进耆老们请教交换或者讨来的，有一些是你看也没看过的东西，
真是让人好奇这些是从哪里来的。
LONG);
	setup();
	replace_program(ROOM);
}
