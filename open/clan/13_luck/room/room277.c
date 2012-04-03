inherit ROOM;
void create() {
	set( "short", "Îä¾ß·À¾ßÌü" );
	set( "object", ([
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10221 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room282.c",
		"east"      : "/open/clan/13_luck/room/room306.c",
		"west"      : "/open/clan/13_luck/room/room301",
		"out"       : "/open/clan/13_luck/room/room5.c",
	]) );
	set( "long", @LONG

    Õû²ã·Å×Å£¬·À¾ß¸úÎä¾ß£¬ÓÐ×Å¸÷Ê½¸÷ÑùµÄÎä¾ß¸ú·À¾ß£¬Ç¿Èç·çÎèÑï
¡£ÈÎÕýÇç¡£¹ùÏå....µÈ£¬Ò²ÌÓ²»¹ý¼ªÏé¸ßÊÖµÄÎ§½Ë£¬ËùÒÔÎªÐÂ½øµÜ×Ó³É
Á¢µÄeq¡£wpÊÒ£¬Ï£ÍûÄÜÓÐÒ»Ìì..

               [0;1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mH[1m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1m¡õ[1m¡õ[1ma[0m£¬[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mH[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1ma[0m
¡¡¡¡¡¡¡¡¡¡¡¡
     WEST £½ [0;1;31m¡õ[1mZ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m    SOUTH £½ [0;1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m    [0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m £½ EAST

LONG);
	setup();
	replace_program(ROOM);
}
