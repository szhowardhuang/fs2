inherit ROOM;
void create() {
	set( "short", "红尘居二楼" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room96",
		"up"        : "/open/clan/13_luck/room/room135",
	]) );
	set( "long", @LONG

　　从一楼大厅你用绝妙轻功走下来到二楼，以自己十年前的功力，
飞岩走壁已如行平地般自然，何况现在。想想不过莞尔，红尘居楼层
之间不设梯阶刚刚提气而上真的有走下来的感觉，这里果真是高手封
尘之处，刚才壁间似有人题字
           
           [31m人若多情[0m  [35m憔悴憔悴...[0m
          　[31m人若无情[0m  [33m活着还有何滋味？[0m
     [0;1m [1m [1m [1m [1m [1m [0m　[0;1;36m□[1m□[1m□[1mp[1m□[1mB[1m□[1ms[1;31m□[1m□[1m□[1m□[1m□[1m~[0m

LONG);
	setup();
	replace_program(ROOM);
}
