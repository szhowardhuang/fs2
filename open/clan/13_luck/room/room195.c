inherit ROOM;
void create() {
	set( "short", "夜梦宫" );
	set( "owner", "dancer" );
	set( "object", ([
		"amount10" : 241,
		"amount3"  : 1,
		"file5"    : "/open/sky/obj5/uiw_jade",
		"amount9"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"amount7"  : 1,
		"file7"    : "/open/sky/obj6/sun_diamond",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file10"   : "/open/doctor/pill/gnd_pill",
		"amount4"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/sky/obj6/meteor_diamond",
		"file1"    : "/open/sky/obj6/ocean_diamond",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/capital/obj/blade2",
		"file8"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10072 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room119",
	]) );
	set( "long", @LONG
这里是位于湖心小筑的中心,空气中散布着阵阵的花香和异常强大的灵力,
强大的灵力仿佛形成一道无形的防护结界,不轻易让外来客进出,四周的动
植物们似乎不是非常的欢迎外来客的到访,前方的黑影像是一个人,而黑影
的后面是一座美轮美奂的建筑物,你忽然想到前面就是传说中的夜梦宫,
而那道黑影想必就是---夜梦宫宫主--「千水凝冰”--剑如冰.


LONG);
	setup();
	replace_program(ROOM);
}
