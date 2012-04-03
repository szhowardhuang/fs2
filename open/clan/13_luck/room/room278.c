inherit ROOM;
void create() {
	set( "short", "»ÃÎÆÑı×¦·¿" );
	set( "owner", "fighter" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room271",
	]) );
	set( "object", ([
		"amount5"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
		"file5"    : "/open/doctor/obj/needle9",
		"file1"    : "/open/gsword/obj/dragon-sword",
		"file7"    : "/open/marksman/obj/dragon_bow",
		"amount2"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "build", 10431 );
	set( "light_up", 1 );
	set( "long", @LONG

    ´Ë·À¾ß£¬ÎªÎÅÃûÎŞ²»ÏÅÆÆµ¨µÄÇ§ÄêÊ÷ÑıÎè·çÑïÉíÉÏËùÓĞµÄ£¬´ËÑıÓĞ
Ç§ÄêÖ®¹¦Á¦£¬³¤ÄêÔÚ³¤°×É½ÉÏĞŞÁ·£¬·¨Êõ¸üÊÇÎŞÈËÄÜµĞ£¬ÓëËûÎªµĞÖ»»á
Ò»¶Ç×Ó´ó±ãµÄ×´Ì¬£¬ÓÈÆäÊÇĞéÈõ£¬ËùÒÔËûµÄ·À¾ß²»ÊÇËµÓĞ¾ÍÓĞµÄ£¬Ò²Òª
¿´ÓĞÃ»ÓĞÈË¸ÒÈ¥´ò£¬ÎªÁËÄÇÒ»¼ş[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¡£

LONG);
	setup();
	replace_program(ROOM);
}
