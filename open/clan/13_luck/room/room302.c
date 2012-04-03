inherit ROOM;
void create() {
	set( "short", "ÊÀ¼äÍÁµÀ" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"amount5"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 12087 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room303.c",
		"south"     : "/open/clan/13_luck/room/room314",
		"north"     : "/open/clan/13_luck/room/room275.c",
	]) );
	set( "long", @LONG

    ²×É£ËêÔÂ£¬ÊÀ¼ä³£±ä£¬À´µ½ÕâÌõÊ®Èı¼ªÏéµÄÊÀ¼äÎåĞĞµÀ£¬´ËµÀÎª[33mÍÁ[0m
[33mµÀ[0m£¬ÓÃÀ´±ÈÓ÷Ê®Èı¼ªÏéµÄÎÈ¹Ì£¬¶ø´ËµÀÉÏÃæ¶¼·Å×Å¸ø°ïÖÚµÄ·À¾ßÓëÎäÆ÷
£¬¶øÊÊÓÃ¶ÔÏóÎª£¬Ã»Ê±¼ä´ò·À¾ß¸úÎäÆ÷µÄ°ïÖÚ£¬ÓëĞÂ½ø°ïÖÚÃ»ÄÜÁ¦´ò·À
¾ßÓëÃ»×Ô¼ºµÄ·¿¼ä¿ÉÒÔ½èÓÃÒ»ÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
