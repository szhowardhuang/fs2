inherit ROOM;
void create() {
	set( "short", "ÊÀ¼ä½ğµÀ" );
	set( "owner", "winder" );
	set( "object", ([
		"amount10" : 1,
		"file6"    : "/open/firedancer/npc/eq/r_boots",
		"amount2"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_head",
		"file2"    : "/open/firedancer/npc/eq/r_hands",
		"amount4"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_cape",
		"file4"    : "/open/firedancer/npc/eq/r_cloth",
		"file8"    : "/open/firedancer/npc/eq/r_armbands",
		"file10"   : "/open/firedancer/npc/eq/r_belt",
		"amount8"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_leg",
		"amount9"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_finger",
		"amount6"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_shield",
		"amount1"  : 1,
	]) );
	set( "build", 10164 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room277.c",
		"south"     : "/open/clan/13_luck/room/room318",
		"east"      : "/open/clan/13_luck/room/room305.c",
		"north"     : "/open/clan/13_luck/room/room273.c",
	]) );
	set( "long", @LONG

    ²×É£ËêÔÂ£¬ÊÀ¼ä³£±ä£¬À´µ½ÕâÌõÊ®Èı¼ªÏéµÄÊÀ¼äÎåĞĞµÀ£¬´ËµÀÎª[0;1;33m¡õ[1m¡õ[0m
[0;1;33m¡õ[1mD[0m£¬ÓÃÀ´±ÈÓ÷Ê®Èı¼ªÏéµÄ·ÀÓù£¬¶ø´ËµÀÉÏÃæ¶¼·Å×Å¸ø°ïÖÚµÄ·À¾ßÓëÎäÆ÷
£¬¶øÊÊÓÃ¶ÔÏóÎª£¬Ã»Ê±¼ä´ò·À¾ß¸úÎäÆ÷µÄ°ïÖÚ£¬ÓëĞÂ½ø°ïÖÚÃ»ÄÜÁ¦´ò·À
¾ßÓëÃ»×Ô¼ºµÄ·¿¼ä¿ÉÒÔ½èÓÃÒ»ÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
