inherit ROOM;
void create() {
	set( "short", "死亡深渊" );
	set( "owner", "zero" );
	set( "object", ([
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"file10"   : "/open/fire-hole/obj/g-pill",
		"file2"    : "/obj/gift/unknowdan",
		"file1"    : "/open/sky/obj1/wind_emblem",
		"amount9"  : 200,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/mogi/dragon/obj/key",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount10" : 150,
		"amount8"  : 200,
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount5"  : 1,
		"file7"    : "/daemon/class/blademan/obj/six-neck",
	]) );
	set( "build", 10398 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room6",
		"hole"      : "/open/clan/hell/room/room62",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

        走入这个地方之后发现四周的光线越来越少，前方有如太空中的黑洞
        ，吞噬掉一切物质，甚至连光线也不能存在，是一切能量的尽头吗！
        或是通往另一个空间的入口！正在思考这个问题的时候，突然一股不
        可抗拒的吸力将你拉入死亡深渊的中心。


LONG);
	setup();
	replace_program(ROOM);
}
