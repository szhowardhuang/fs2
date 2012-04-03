inherit ROOM;
void create() {
	set( "short", "小翰滴房间" );
	set( "owner", "poll" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room106",
	]) );
	set( "object", ([
		"file1"    : "/open/ping/obj/cloud_fan",
		"file8"    : "/open/killer/outsea/dstone",
		"file4"    : "/open/ping/obj/fu_weapon",
		"amount2"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"amount10" : 1,
		"amount4"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"file6"    : "/open/magic-manor/obj/magic-sign",
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file9"    : "/open/mogi/dragon/obj/key",
	]) );
	set( "build", 10146 );
	set( "light_up", 1 );
	set( "long", @LONG
看起来廖官人想强奸你！ 

廖官人大喝一声发出所有鸟劲!!!
一招鸡鸡斩终极式---‘天魔极乐’!!!

你闪躲不及，鸡鸡从胸膛贯穿而过！
( 你受伤过重，已经有如风中残烛，随时都可能断气。 ) 
结果听见「轰”地一声惊天巨响, 极度惊恐的你瞬间化成齎粉, 灰飞湮灭。

你的眼前一黑，接着什么也不知道了.... 

y
LONG);
	setup();
	replace_program(ROOM);
}
