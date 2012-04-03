inherit ROOM;
void create() {
	set( "short", "$HIC$威洛$NOR$的$HIW$阳台$NOR$" );
	set( "object", ([
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"amount4"  : 30,
		"amount5"  : 5,
		"amount3"  : 20,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file1"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount2"  : 58,
	]) );
	set( "build", 10005 );
	set( "owner", "welo" );
	set( "outdoors", "/open/clan/red_fire" );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/red_fire/room/room116",
	]) );
	set( "long", @LONG

这是$HIC$威洛$HIM$美丽$NOR$的$HIW$阳台$NOR$，$HIC$威洛$NOR$在$HIW$阳台$NOR$上种着各式各样的植
物，你定眼一瞧，有着现在时下最流行的来自番邦的$HIY$仙
人掌$NOR$，采自深山野岭的$HIM$兰花$NOR$，$HIR$五$HIC$颜$HIM$六$HIY$色$NOR$的南蛮植物，还
有几盆雕饰精美的$GRN$小松树$NOR$，走上$HIW$阳台$NOR$你可以感觉到阵阵
轻风吹抚着，让你不自觉的深深吸了一口气，享受沐浴
在$HIC$大自然$NOR$的时光。


LONG);
	setup();
	replace_program(ROOM);
}
