inherit ROOM;
void create() {
	set( "short", "毒人居" );
	set( "owner", "kris" );
	set( "object", ([
		"amount10" : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/wu/npc/obj/armband",
		"file10"   : "/open/doctor/obj/needle9",
		"amount5"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file1"    : "/open/poison/obj/bleed_whip",
		"file6"    : "/open/ping/obj/gold_hand",
		"amount3"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"file8"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"file2"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/scholar/obj/icefan",
		"amount6"  : 1,
	]) );
	set( "build", 10076 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room92",
		"east"      : "/open/clan/13_luck/room/room188",
	]) );
	set( "long", @LONG
来到这里空气中弥漫的一股令人作呕的气息，房间虽然布置的和
一般居家没什么两样，但隐隐约约的让人觉得四周的摆设一定大
有文章，令人想一探此处的主人究竟为何人。  往西走可以回到
绿茶园的前庭，往东走则是通往毒药房。
LONG);
	setup();
	replace_program(ROOM);
}
