inherit ROOM;
void create() {
	set( "short", "$HIC$聚灵武器封印区$HIY$(fan)$NOR$" );
	set( "light_up", 1 );
	set( "build", 11827 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room28",
	]) );
	set( "long", @LONG
地府的精兵战将们当年闯进聚灵山庄后,收集了不少聚灵八杰手中之物由于
其得来不易,地府的大飞哥提议将之分类封印起来,满足他变态收集欲望这里
是专门收藏八杰之中段家守护者所持武器的地方,有兴趣的人可以拿去试用,
不过用毕请记得归还,不然大飞哥会请你吃鼻屎的:D

LONG);
	setup();
	replace_program(ROOM);
}
