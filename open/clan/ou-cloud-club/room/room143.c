inherit ROOM;
void create() {
	set( "short", "军火库大门" );
	set( "object", ([
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/prayer/obj/boris-cloth",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file6"    : "/open/dancer/obj/yuawaist",
		"amount2"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"file1"    : "/open/wu/npc/obj/armband",
		"amount9"  : 1,
	]) );
	set( "owner", "bbsboss" );
	set( "build", 11667 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room169",
		"west"      : "/open/clan/ou-cloud-club/room/room136",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
才一踏入此处...浓浓的杀气笼罩在心头....
抬头一看...原来才知道这边是小马四处搜括来的强大军火存放处
仔细一看...这全都是来自江湖各大门派的镇派之宝
圣火..泷山...风林山寨........
江湖的风风雨雨......
第一个房间是存放身体的防具....
LONG);
	setup();
	replace_program(ROOM);
}
