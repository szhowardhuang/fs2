inherit ROOM;
void create() {
	set( "short", "杂具室" );
	set( "object", ([
		"amount10" : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"file3"    : "/open/gsword/obj/may_ring",
		"amount5"  : 1,
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file6"    : "/open/wu/npc/obj/armband",
		"file5"    : "/daemon/class/fighter/figring",
		"amount4"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
	]) );
	set( "build", 10646 );
	set( "light_up", 1 );
	set( "owner", "tsrak" );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room146",
	]) );
	set( "long", @LONG
    你被挂像放行走到这里,四处一片漆黑,当你再走近一步
天花板突然变成一片银河,四周也跟着亮了起来,这里只有一
张小桌子,桌上放着一顶帽子,帽子里藏着一把破破烂烂的剑
桌下堆着一些破破烂烂的武器和装备,突然一只猫头鹰从你
头上飞了过去并丢下一张纸,捡起来一看上面写着欢迎光临

LONG);
	setup();
	replace_program(ROOM);
}
