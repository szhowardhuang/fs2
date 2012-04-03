inherit ROOM;
void create() {
	set( "short", "$HIR$总$HIG$统$HIC$套$HIY$房$NOR$" );
	set( "owner", "laster" );
	set( "object", ([
		"file2"    : "/u/h/houng/eq/legging1",
		"amount1"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "light_up", 1 );
	set( "build", 10012 );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room81",
	]) );
	set( "long", @LONG

这是一间顶级的$HIR$总$HIG$统$HIC$套$HIY$房$NOR$，全欧式装潢，进入即看到一个超大$HIY$沙发$NOR$，
对面放着42寸的$HIC$超平面电视$NOR$，墙壁则摆着数幅看起来怪怪的$HIW$抽像画$NOR$，
定眼一看，你发现$HIM$碎心$NOR$正盯着你看，似乎不明白你因何而来。


LONG);
	setup();
	replace_program(ROOM);
}
