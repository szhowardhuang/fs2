inherit ROOM;
void create() {
	set( "short", "元素峡谷内" );
	set( "owner", "ywarter" );
	set( "object", ([
		"file2"    : "/open/gsword/obj1/ring",
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/gsword/obj1/ring",
		"amount4"  : 1,
		"file1"    : "/open/gsword/obj1/ring",
		"file6"    : "/open/gsword/npc2/sadsword",
		"amount2"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/gsword/obj1/bloodsword",
		"file5"    : "/open/main/obj/m_cloak",
		"file4"    : "/open/main/obj/bird_legging",
		"amount1"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 11028 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room338",
	]) );
	set( "long", @LONG
这里你看到了黑白红蓝绿黄这六种元素,而这六种元素正密集且不消散的
在这一空间里移动,在移动的同时你看到一些不同元素的磨擦产生的一些
微小电子,而你看到这空间的中心有一个神秘的圆球正在吸取这些微小的电子
你不知道这是什么东西,而且这圆球还不时的擩动着,仿佛像是一个活物
LONG);
	setup();
	replace_program(ROOM);
}
