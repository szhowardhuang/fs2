inherit ROOM;
void create() {
	set( "short", "Ä§É­ÁÖ" );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10473 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room179",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    Ò»½øÀ´Õâ±ß·¢ÏÖÑÛÇ°ÊÇÆ¬Ò»ÍûÎÞ¼ÊµÄ[0;1;32m¡õ[1m¡õ[1m¡õ[1mL[0m£¬Èç¹û×ÐÏ¸¹Û²ìµÄ»°»á
·¢ÏÖ[0;1;32m¡õ[1m¡õ[1m¡õ[1mL[0mÖÐÓÐÐí¶à´ÓÀ´Ã»¼û¹ýµÄ[0;1;34m¡õ[1mJ[1m¡õ[1m¡õ[0m£¬¾ÍÔÚÄãÏëÒª¿¿½ü[0;1;34m¡õ[1mJ[1m¡õ[1m¡õ[0mµÄÍ¬Ê±£¬
Í»È»´Ó[0;1;34m¡õ[1mJ[1m¡õ[1m¡õ[0mÀïÃæ³å³öÒ»ÈºÃæÄ¿ÕøÄüµÄ[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬·è¿ñµØÏòÄã±Æ½ü£¬´Ë
Ê±ÄãÒÑ¾­ºó»Ú´¥¶¯»ú¹Ø£¬µ«ÊÇÒ»ÇÐ¶¼Ì«³ÙÁË....[0;1;31m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1me[1m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m][1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mD[1m¡õ[1mF[0m¡£

LONG);
	setup();
	replace_program(ROOM);
}
