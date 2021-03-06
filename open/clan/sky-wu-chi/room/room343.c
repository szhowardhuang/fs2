inherit ROOM;
void create() {
	set( "short", "‘Item’收藏一馆" );
	set( "object", ([
		"amount4"  : 149,
		"file1"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire_book",
		"file5"    : "/open/doctor/item/sick_item",
		"amount5"  : 395,
		"amount1"  : 1,
		"amount3"  : 176,
		"amount2"  : 165,
		"file3"    : "/open/doctor/item/ground_item",
		"amount8"  : 1,
		"file4"    : "/open/doctor/item/human_item",
		"file2"    : "/open/doctor/item/sky_item",
		"file6"    : "/open/killer/obj/kill_yar_head",
	]) );
	set( "build", 10040 );
	set( "light_up", 1 );
	set( "owner", "bbsman" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room342",
		"north"     : "/open/clan/sky-wu-chi/room/room122.c",
	]) );
	set( "long", @LONG
这里收藏着‘屠龙刀’从各地收集而来的丹药。天山
雪莲、高丽人蔘、东海冰精都是这里的常见物品。除了一
些常见的丹药外，如果你也有多余稀奇的丹药，也许大家
可以来交换一下。书柜中有本伤寒杂病论的精装本，是不
错的课外读物。
LONG);
	setup();
	replace_program(ROOM);
}
