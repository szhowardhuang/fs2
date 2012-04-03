inherit ROOM;
void create() {
	set( "short", "$HIG$卡$HIG$卡$HIG$西$NOR$的小套房 " );
	set( "object", ([
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/main/obj/et_sword",
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"file10"   : "/open/snow/obj/figring",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/main/obj/firesword",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
	]) );
	set( "owner", "snowman" );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room193",
	]) );
	set( "long", @LONG
卡卡西是木叶隐第一高手
拥有过人的速度及实力和帅气的外型
锻炼$HIW$忍术，$HIC$体术$NOR$和$HIY$幻术$NOR$是忍者最重要的课题
不过要当上火影也需要过人的智慧，所以努力求学是非常重要的
期待有一天卡卡西能成为忍界的第一高手
LONG);
	setup();
	replace_program(ROOM);
}
