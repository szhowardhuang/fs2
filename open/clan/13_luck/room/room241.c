inherit ROOM;
void create() {
	set( "short", "Ñ×Áú¹È" );
	set( "owner", "pighead" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 63,
		"amount8"  : 1,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 70,
		"amount5"  : 1,
		"amount4"  : 98,
		"file1"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "build", 10404 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room179",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ´«ËµÖĞµÄ[0;1;32m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[0m£¬Ò»½øÈë¹ÈÖĞ·¢ÏÖ¼¸Ö»¿É°®µÄĞ¡¶¯ÎïÔÚÎû
Ï·ÍæË£×Å£¬³¤×ÅĞ¡³á°ò£¬²»Ê±·ÉĞıÓÚ¿ÕÖĞ£¬ÈÃÄãÏëÒª°ÑËüÃÇ±§ÆğÀ´°Ñ
Íæ£¬¾ÍÔÚÄã±§ÆğËüµÄÍ¬Ê±£¬Ô¶´¦´«À´¾ß´óµÄ½Å²½Éù£¬ÈÃÄã¾õµÃĞÄÉúÎ·
¾å£¬ÄÑµ½ÕæµÄÓĞÁúµÄ´æÔÚ£¿µ±ÄãÔÚ¿¼ÂÇÒª²»ÒªÀë¿ªÊ±£¬ÔÚÑÛÇ°³öÏÖÒ»
Ö»¾ß´óµÄ»ğÁú£¬×ìÀïÕıÍÂ³öĞÜĞÜµÄ[0;1;31m¡õ[1m¡õ[1m¡õ[1mV[0m£¬ÄãÒ»¸ö½Å²½²»ÎÈ×øÔÚµØÃæ£¬
Ò»¸öÄîÍ·ÉÁ¹ı£¬ÄÑ²»³ÉÎÒ±§µÄÊÇ ­µÄĞ¡º¢Âğ£¿


LONG);
	setup();
	replace_program(ROOM);
}
