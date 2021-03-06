inherit ROOM;
void create() {
	set( "short", "神秘地带" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"file4"    : "/open/love/obj/shield",
	]) );
	set( "owner", "assassin" );
	set( "item_desc", ([
		"制造" : @ITEM
test
ITEM,
	]) );
	set( "build", 12795 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room184",
	]) );
	set( "long", @LONG
来到此区你感到莫名的神秘, 据说武林中最神秘的神秘人物藏神秘就是藏身于此,
从来无人能够了解他的经历与背景, 或许你也是对于如此神秘的人物感兴趣才来到这里
四周黑暗却不断出现的七彩光芒, 更是把此人神秘的色彩加深, 传闻中来此探查秘密者
都一去不归, 你最好提高警觉免得成为下一个失踪人口
LONG);
	setup();
	replace_program(ROOM);
}
