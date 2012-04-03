inherit ROOM;
void create() {
	set( "short", "Ñı»ÃÍ·´øÊÒ" );
	set( "owner", "turtle" );
	set( "object", ([
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount9"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"file6"    : "/open/ping/obj/ring-2",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file3"    : "/open/ping/obj/gold_hand",
		"file5"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"amount1"  : 1,
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room311",
		"south"     : "/open/clan/13_luck/room/room306.c",
	]) );
	set( "build", 10275 );
	set( "light_up", 1 );
	set( "long", @LONG

    ´Ë·À¾ß£¬ÎªÎÅÃûÎŞ²»ÏÅÆÆµ¨µÄÇ§ÄêÊ÷ÑıÎè·çÑïÉíÉÏËùÓĞµÄ£¬´ËÑıÓĞ
Ç§ÄêÖ®¹¦Á¦£¬³¤ÄêÔÚ³¤°×É½ÉÏĞŞÁ·£¬·¨Êõ¸üÊÇÎŞÈËÄÜµĞ£¬ÓëËûÎªµĞÖ»»á
Ò»¶Ç×Ó´ó±ãµÄ×´Ì¬£¬ÓÈÆäÊÇĞéÈõ£¬ËùÒÔËûµÄ·À¾ß²»ÊÇËµÓĞ¾ÍÓĞµÄ£¬Ò²Òª
¿´ÓĞÃ»ÓĞÈË¸ÒÈ¥´òÎªÁËÄÇÒ»¼ş[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mY[1m¡õ[1ma[0m¡£

LONG);
	setup();
	replace_program(ROOM);
}
