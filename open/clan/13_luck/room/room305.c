inherit ROOM;
void create() {
	set( "short", "ÊÀ¼äÄ¾µÀ" );
	set( "object", ([
		"amount6"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/killer/headkill/obj/f_dag",
		"file6"    : "/open/killer/headkill/obj/w_dag",
		"file4"    : "/open/killer/headkill/obj/bluekill",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/killer/obj/dagger",
		"file5"    : "/open/killer/headkill/obj/e_dag",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/killer/headkill/obj/i_dag",
		"amount10" : 1,
	]) );
	set( "owner", "pigdevil" );
	set( "build", 10524 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room306.c",
		"south"     : "/open/clan/13_luck/room/room317",
		"east"      : "/open/clan/13_luck/room/room304.c",
		"north"     : "/open/clan/13_luck/room/room274.c",
	]) );
	set( "long", @LONG

    ²×É£ËêÔÂ£¬ÊÀ¼ä³£±ä£¬À´µ½ÕâÌõÊ®Èı¼ªÏéµÄÊÀ¼äÎåĞĞµÀ£¬´ËµÀÎª[0;1m¡õ[1m¡õ[0m
[0;1m¡õ[1mD[0m£¬ÓÃÀ´±ÈÓ÷Ê®Èı¼ªÏéµÄ·ÀÓù£¬¶ø´ËµÀÉÏÃæ¶¼·Å×Å¸ø°ïÖÚµÄ·À¾ßÓëÎäÆ÷
£¬¶øÊÊÓÃ¶ÔÏóÎª£¬Ã»Ê±¼ä´ò·À¾ß¸úÎäÆ÷µÄ°ïÖÚ£¬ÓëĞÂ½ø°ïÖÚÃ»ÄÜÁ¦´ò·À
¾ßÓëÃ»×Ô¼ºµÄ·¿¼ä¿ÉÒÔ½èÓÃÒ»ÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
