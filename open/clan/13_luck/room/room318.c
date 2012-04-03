inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎï¹ñ¼º" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file4"    : "/open/gsword/obj/ring-1",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/gsword/obj/ring-1",
		"file9"    : "/open/love/obj/cloth1",
		"file6"    : "/open/love/obj/cloth1",
		"file7"    : "/open/port/obj/wolf_ring",
		"file1"    : "/open/love/obj/cloth1",
		"file5"    : "/open/port/obj/wolf_ring",
		"amount4"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/gsword/obj/ring-1",
		"amount7"  : 1,
	]) );
	set( "build", 10137 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room306",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[0;1;33m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1md[1m¡õ[1mv[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬ÍòÀï
·çÔÆæëÒâæ÷×ã£¬°ÙÄêÖéÊ÷·ï»ËÖ¦£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
