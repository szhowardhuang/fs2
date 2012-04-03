inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎï¹ñÒÒ" );
	set( "owner", "vickey" );
	set( "object", ([
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/ping/obj/ring-2",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount1"  : 32,
		"file2"    : "/open/wu/npc/obj/armband",
		"file9"    : "/open/poison/obj/feather",
		"file8"    : "/open/capital/guard/gring",
		"file5"    : "/open/dancer/obj/yuawaist",
	]) );
	set( "build", 10074 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room298",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[0;1;33m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1md[1m¡õ[1mA[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬¸ºÖØ
È«Æ¾»ù´¡Á¦£¬¾¡¸ß¶ËÀµ¶°Áº²Ä£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
