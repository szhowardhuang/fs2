inherit ROOM;
void create() {
	set( "short", "$HIY$灵珠封印区$NOR$" );
	set( "light_up", 1 );
	set( "build", 10195 );
	set( "exits", ([
		"fire"      : "/open/clan/hell/room/room82.c",
		"soil"      : "/open/clan/hell/room/room85.c",
		"out"       : "/open/clan/hell/room/room28",
		"wood"      : "/open/clan/hell/room/room83.c",
		"golden"    : "/open/clan/hell/room/room84.c",
		"water"     : "/open/clan/hell/room/room79.c",
	]) );
	set( "long", @LONG
地府的精兵战将们当年闯进聚灵山庄后,收集了不少聚灵八杰手中之物由于
其得来不易,地府的大飞哥提议将之分类封印起来,满足他变态收集欲望这里
是专门收藏八杰之中段家守护者所持武器的地方,有兴趣的人可以拿去试用,
不过用毕请记得归还,不然大飞哥会请你吃鼻屎的 :D

LONG);
	setup();
	replace_program(ROOM);
}
