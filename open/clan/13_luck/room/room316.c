inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎï¹ñĞÁ" );
	set( "object", ([
		"amount3"  : 1,
		"amount9"  : 1,
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"amount7"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/port/obj/wolf_ring",
		"file4"    : "/open/prayer/obj/kylin-belt",
		"file7"    : "/open/ping/obj/ring-2",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/badman/obj/evil_claw",
		"file6"    : "/open/badman/obj/badhelmet",
		"file3"    : "/open/prayer/obj/boris-hands",
		"file9"    : "/open/firedancer/npc/eq/r_pants",
		"amount6"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_belt",
		"amount5"  : 1,
	]) );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room304",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[0;1;31m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1md[1m¡õ[1m¡õ[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬³¤¼Ç
´È»İ´«ºóÊÀ£¬ÓÀÁôµã·¶ÔÚÊ®Èı£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
