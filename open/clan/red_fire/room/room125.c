inherit ROOM;
void create() {
	set( "short", "$HIW$● 碎 石 路 $HIC$路标$NOR$ $HIW$●$NOR$" );
	set( "outdoors", "/open/clan/red_fire" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/red_fire/room/room131",
		"east"      : "/open/clan/red_fire/room/room124.c",
		"north"     : "/open/clan/red_fire/room/room126.c",
	]) );
	set( "long", @LONG
        
                  $HIC$╭══════════════╮
                  ║$BLU$◤                        ◥$HIC$║
                  ║   $HIM$北边$NOR$----$HIW$【$HIR$红叶$HIY$枫树林$HIW$】$HIC$   ║
                  ║                            ║
                  ║   $HIM$南边$NOR$----$HIW$【$HIG$绿叶$HIY$青竹林$HIW$】$HIC$   ║
                  ║$BLU$◣                        ◢$HIC$║
                  ╰═══╦╦════╦╦═══╯
                          ║║        ║║
                          ║║        ║║
                    $HIG$▲▲▲▲▲▲▲▲▲▲▲▲▲▲$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
