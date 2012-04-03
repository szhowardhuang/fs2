inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎï¹ñ±û" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10053 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room299",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[0;1m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1md[1m¡õ[1m¡õ[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬¸ºÖØ
È«Æ¾»ù´¡Á¦£¬¾¡¸ß¶ËÀµ¶°Áº²Ä£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
