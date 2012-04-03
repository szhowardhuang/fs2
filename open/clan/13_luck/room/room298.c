inherit ROOM;
void create() {
	set( "short", "ÊÀ¼äÀ×µÀ" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"file6"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/daemon/class/fighter/figring",
		"amount1"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10236 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room297.c",
		"south"     : "/open/clan/13_luck/room/room322",
		"east"      : "/open/clan/13_luck/room/room299.c",
		"north"     : "/open/clan/13_luck/room/room269",
	]) );
	set( "long", @LONG

    ²×É£ËêÔÂ£¬ÊÀ¼ä³£±ä£¬À´µ½ÕâÌõÊ®Èı¼ªÏéµÄÊÀ¼äÎåºòµÀ£¬´ËµÀÎª[33mÀ×[0m
[33mµÀ[0m£¬ÓÃÀ´±ÈÓ÷Ê®Èı¼ªÏéµÄÍşÁ¦£¬¶ø´ËµÀÉÏÃæ¶¼·Å×Å¸ø°ïÖÚµÄ·À¾ßÓëÎäÆ÷
£¬¶øÊÊÓÃ¶ÔÏóÎª£¬Ã»Ê±¼ä´ò·À¾ß¸úÎäÆ÷µÄ°ïÖÚ£¬ÓëĞÂ½ø°ïÖÚÃ»ÄÜÁ¦´ò·À
¾ßÓëÃ»×Ô¼ºµÄ·¿¼ä¿ÉÒÔ½èÓÃÒ»ÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
