inherit ROOM;
void create() {
	set( "short", "世界末日" );
	set( "owner", "biwem" );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"file9"    : "/open/wu/npc/obj/armband",
		"file7"    : "/open/killer/outsea/dstone",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/capital/guard/gring",
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/capital/room/king/obj/km-cloak",
		"amount1"  : 1,
	]) );
	set( "build", 10692 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room278",
	]) );
	set( "long", @LONG
想笑 来伪装掉下的眼泪 点点头 承认自己会怕黑 
我只求 能借一点的时间来陪 你却连同情都不给 ;想哭 来试探自己麻痹了没 全世界 好象只有我疲惫 ;无所谓 反正难过就敷衍走一回 但愿绝望和无奈远走高飞 ;天灰灰 会不会 让我忘了你是谁 ;夜越黑 梦违背 难追难回味 ;我的世界将被摧毁 也许事与愿违 ;累不累 睡不睡 单影无人相依偎 ;夜越黑 梦违背 有谁肯安慰 ;我的世界将被摧毁 或许颓废也是另一种美 ;天灰灰 会不会 让我入睡 夜越黑 梦违背 有谁安慰
LONG);
	setup();
	replace_program(ROOM);
}
