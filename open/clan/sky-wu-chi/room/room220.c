inherit ROOM;
void create() {
	set( "short", "幽幻小筑" );
	set( "owner", "clodsnow" );
	set( "object", ([
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/gsword/obj/may_ring",
		"amount8"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"amount10" : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/wu/npc/obj/armband",
		"amount9"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file3"    : "/open/tendo/obj/chaosbelt",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 10054 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room219",
	]) );
	set( "long", @LONG
你的灵魂飘飘荡荡的飘浮了许久，等你醒来却发现自己毫发无伤
是回廊未寒的尸骨所残留的痛苦的回忆?你定眼一看，你下意识
的走出了回廊，来到了一座典雅的小屋，四周的枫林伴着那不搭
调的杀气，当你想在往前时，四周卷起了一阵旋风，凛冽的杀气，
环绕在你的四周，多踏一步，似乎就要了你的性命，你----还敢
向前吗??
LONG);
	setup();
	replace_program(ROOM);
}
