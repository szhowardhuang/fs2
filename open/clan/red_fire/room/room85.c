inherit ROOM;
void create() {
	set( "short", "$HIC$【$HIM$大饭店 $HIY$走廊$HIW$二楼$HIC$】$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"r209"      : "/open/clan/red_fire/room/room133",
		"r210"      : "/open/clan/red_fire/room/room109.c",
		"south"     : "/open/clan/red_fire/room/room84.c",
		"enter"     : "/open/clan/red_fire/room/room80.c",
	]) );
	set( "long", @LONG
哇......好宽敞的$HIY$走廊$NOR$喔，地面用的红色高级$HIR$地毯$NOR$是波斯进口的，天
花板的灯具，全部是用法国来的$HIC$水晶$NOR$灯组，两边的墙面竟然还用最上等的
$HIM$桧木$NOR$作扶手及装饰，一幅一幅名画挂在墙面上更显现出走廊的优雅和高级
，难怪$HIR$爱玫$NOR$教主说这是引进未来最新的$HIR$建$HIG$筑$HIY$科$HIC$技$NOR$所完成的高级住宅区；两
侧的房间分别是 209 号和 210 号，哈哈....前面还有$HIY$电梯$NOR$可以搭乘耶！
真棒！！


LONG);
	setup();
	replace_program(ROOM);
}
