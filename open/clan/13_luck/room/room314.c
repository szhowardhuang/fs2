inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎï¹ñ¹ï" );
	set( "object", ([
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file9"    : "/open/wu/npc/obj/armband",
		"file2"    : "/daemon/class/fighter/figring",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file6"    : "/open/port/obj/wolf_ring",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 10851 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room302",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[33m¼ªÏéÖÃÎï¹ñ¹ï[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬ÍòÀï
·çÔÆÖØ´ËÆğ£¬×ÜÓĞÒ»Ìì³É´óÆ÷£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
