inherit ROOM;
void create() {
	set( "short", "无尘室-" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount2"  : 10,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount7"  : 87,
		"amount8"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file6"    : "/daemon/class/fighter/ywhand",
		"file7"    : "/open/killer/obj/s_pill",
		"file2"    : "/open/ping/obj/poison_pill",
		"file10"   : "/open/killer/obj/dagger",
		"amount5"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10604 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room135.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room174",
	]) );
	set( "long", @LONG

     「傲云杀手”，斗大的招牌悬在门口，令你感觉到一股压力
一进入房间，一股刺鼻的药味，呛得你一阵头晕目眩，令人做恶，
却看到一个白影迅速地在各药水、火炉间移动，拿着你看不大懂的
器具，在数片薄薄白白的玻璃上切切割割，大概是波又突发奇想，
准备研发什么新暗器了，令你迫不及待地想与他的新武器较量一番

LONG);
	setup();
	replace_program(ROOM);
}
