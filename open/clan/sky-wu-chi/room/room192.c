inherit ROOM;
void create() {
	set( "short", "艾尼斯小窝" );
	set( "owner", "enis" );
	set( "build", 12 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room193",
	]) );
	set( "long", @LONG
斗室里青烟缭绕，置着一张横几、两个蒲团，一柄乌鞘金吞的古
剑供在几顶，粉壁上悬着一幅中堂，笔力遒劲，写的是唐代诗人贾岛
的一首《侠客》：「十年磨一剑，霜刃未曾试。今日把示君，谁有不
平事？”厅侧吊着一帘青幔，幔后透出些许灯光,周围隐隐显露出
一股侠客之气!! 
映入眼帘令你惊讶的是堆落满地的武功书籍,显示此处的主人亦是武林侠客之一!

LONG);
	setup();
	replace_program(ROOM);
}
