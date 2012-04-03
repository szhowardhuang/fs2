inherit ROOM;
void create() {
	set( "short", "ÊÀ¼ä·çµÀ" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_pants",
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_belt",
		"file1"    : "/open/firedancer/npc/eq/r_cape",
		"file4"    : "/open/firedancer/npc/eq/r_hands",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_shield",
		"file2"    : "/open/firedancer/npc/eq/r_boots",
		"amount6"  : 1,
	]) );
	set( "build", 10998 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room300.c",
		"south"     : "/open/clan/13_luck/room/room319",
		"east"      : "/open/clan/13_luck/room/room277.c",
		"north"     : "/open/clan/13_luck/room/room272.c",
	]) );
	set( "long", @LONG

    ²×É£ËêÔÂ£¬ÊÀ¼ä³£±ä£¬À´µ½ÕâÌõÊ®Èı¼ªÏéµÄÊÀ¼äÎåºòµÀ£¬´ËµÀÎª[0;1;36m¡õ[1m¡õ[0m
[0;1;36m¡õ[1mD[0m£¬ÓÃÀ´±ÈÓ÷Ê®Èı¼ªÏéµÄÍşÁ¦£¬¶ø´ËµÀÉÏÃæ¶¼·Å×Å¸ø°ïÖÚµÄ·À¾ßÓëÎäÆ÷
£¬¶øÊÊÓÃ¶ÔÏóÎª£¬Ã»Ê±¼ä´ò·À¾ß¸úÎäÆ÷µÄ°ïÖÚ£¬ÓëĞÂ½ø°ïÖÚÃ»ÄÜÁ¦´ò·À
¾ßÓëÃ»×Ô¼ºµÄ·¿¼ä¿ÉÒÔ½èÓÃÒ»ÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
