inherit ROOM;
void create() {
	set( "short", "吉祥水道" );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
	]) );
	set( "build", 10954 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room3.c",
		"west"      : "/open/clan/13_luck/room/room27",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    过了秋阳流你真正的发现到四周真的是火红世界，尤其是四周的枫
树上都有随风摇曳的红叶子，只要风稍微大点就有水中火焰的错觉，微
风夹带着秋天的气氛，缓缓的吹来使你精神气爽，让你觉得这趟水之旅
拥有无数的回忆，有不虚此行的感觉。

LONG);
	setup();
	replace_program(ROOM);
}
