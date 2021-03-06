inherit ROOM;
void create() {
	set( "short", "$HIW$【$HIB$蓝焰$MAG$紫羽$HIR$阁$HIW$】$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/prayer/obj/boris-boots",
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file8"    : "/open/snow/obj/figring",
		"file6"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/tendo/obj/chaosbelt",
		"amount8"  : 1,
		"file1"    : "/open/ping/obj/gold_hand",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/gsword/obj/yugem",
		"amount9"  : 1,
	]) );
	set( "build", 10080 );
	set( "owner", "enis" );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room9",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
斗室里青烟缭绕，置着一张横几、两个蒲团，一柄乌鞘金吞的古剑供
在几顶，粉壁上悬着一幅中堂，笔力遒劲，写的是唐代诗人贾岛的一
首$HIW$《侠客》$NOR$：「$HIY$十年磨一剑$NOR$，$HIR$霜刃未曾试$NOR$。$HIC$今日把示君$NOR$，$HIM$谁有不平事$NOR$
？”厅侧吊着一帘青幔，幔后透出些许灯光,周围隐隐显露出一股傲然
之气!!映入眼帘令你惊讶的是堆落满地的武功书籍,显示此处的主人亦
对于武学的涉略颇广!
LONG);
	setup();
	replace_program(ROOM);
}
