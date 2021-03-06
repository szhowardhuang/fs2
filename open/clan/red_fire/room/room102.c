inherit ROOM;
void create() {
	set( "short", "$HIR$忘$NOR$$HIG$忧$NOR$$HIB$谷$NOR$" );
	set( "owner", "borchin" );
	set( "object", ([
		"amount8"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"file1"    : "/open/gsword/obj/silver_sword",
		"file9"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/open/main/obj/et_sword",
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/obj/gift/lingzhi",
		"amount2"  : 1,
		"file4"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
	]) );
	set( "build", 10080 );
	set( "exits", ([
		"south"     : "/open/clan/red_fire/room/room103.c",
		"home"      : "/open/clan/red_fire/room/hall.c",
		"west"      : "/open/clan/red_fire/room/room90.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

来到这里，仿佛是到了$HIM$世$NOR$$MAG$外$NOR$$HIC$桃$NOR$$CYN$源$NOR$般的世界，眼前所见的是
一片祥和的景像，令人忘却了种种的烦恼及忧愁。满地的
$HIR$花$NOR$$GRN$草$NOR$所散出来的香味洗涤了$HIR$尘世$NOR$中的$HIB$杀伐$NOR$之气，你心想这
里是什么地方时，只见前方的大石写着三个大字

                    --$HIR$忘$NOR$$HIG$忧$NOR$$HIB$谷$NOR$--


LONG);
	setup();
	replace_program(ROOM);
}
