inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎï¹ñ¶¡" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/daemon/class/blademan/obj/shield",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file1"    : "/open/gsword/obj/yuskirt",
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "owner", "vickey" );
	set( "build", 10293 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room300",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[0;1;34m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1md[1m¡õ[1mB[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬¸ºÖØ
È«Æ¾»ù´¡Á¦£¬¾¡¸ß¶ËÀµ¶°Áº²Ä£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
