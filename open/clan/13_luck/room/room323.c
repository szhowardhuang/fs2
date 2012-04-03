inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎï¹ñ¼×" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_cloth",
		"file4"    : "/open/firedancer/npc/eq/r_finger",
		"amount8"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_hands",
		"file2"    : "/open/firedancer/npc/eq/r_cape",
		"file7"    : "/open/firedancer/npc/eq/r_belt",
		"file1"    : "/open/port/obj/wolf_ring",
		"amount4"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_armbands",
		"amount7"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_boots",
	]) );
	set( "owner", "vickey" );
	set( "build", 10392 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room297",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[0;1;35m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1md[1m¡õ[1m¡õ[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬¸ºÖØ
È«Æ¾»ù´¡Á¦£¬¾¡¸ß¶ËÀµ¶°Áº²Ä£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
