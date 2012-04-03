inherit ROOM;
void create() {
	set( "short", "ÊÀ¼äË®µÀ" );
	set( "object", ([
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"amount9"  : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount2"  : 1,
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"file8"    : "/open/mogi/castle/obj/lochagem",
	]) );
	set( "build", 10206 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room304.c",
		"south"     : "/open/clan/13_luck/room/room315",
		"east"      : "/open/clan/13_luck/room/room302.c",
		"north"     : "/open/clan/13_luck/room/room264.c",
	]) );
	set( "long", @LONG

    ²×É£ËêÔÂ£¬ÊÀ¼ä³£±ä£¬À´µ½ÕâÌõÊ®Èı¼ªÏéµÄÊÀ¼äÎåĞĞµÀ£¬´ËµÀÎª[0;1;36m¡õ[1m¡õ[0m
[0;1;36m¡õ[1mD[0m£¬ÓÃÀ´±ÈÓ÷Ê®Èı¼ªÏéµÄ·ÀÓù£¬¶ø´ËµÀÉÏÃæ¶¼·Å×Å¸ø°ïÖÚµÄ·À¾ßÓëÎäÆ÷
£¬¶øÊÊÓÃ¶ÔÏóÎª£¬Ã»Ê±¼ä´ò·À¾ß¸úÎäÆ÷µÄ°ïÖÚ£¬ÓëĞÂ½ø°ïÖÚÃ»ÄÜÁ¦´ò·À
¾ßÓëÃ»×Ô¼ºµÄ·¿¼ä¿ÉÒÔ½èÓÃÒ»ÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
