inherit ROOM;
void create() {
	set( "short", "[1;34mPACIFIC BLUE[0m" );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/soil-ball",
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/obj/water-ball",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount4"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"file3"    : "/open/magic-manor/obj/golden-ball",
		"file2"    : "/open/doctor/obj/d-mark",
		"amount2"  : 1,
		"file8"    : "/open/doctor/obj/feather",
		"amount1"  : 1,
	]) );
	set( "owner", "del" );
	set( "build", 10060 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room251.c",
	]) );
	set( "long", @LONG
      
×÷Çú¼ÒÇÇÄÇË¹£®¿Ë·²Ê·¶«ÓëÊ·µÙ·Ò£®ÊæÂüÁ½ÈËµÄÍêÃÀÑİ³ö£¬½«Ã¿Ò»
¸öÀËÆğ³±ÍËÆğ·ü£¬Éú¶¯¼ÍÂ¼£¬ÀËÆğµÄÅìÅÈ½Ú×à£¬´ØÓµ×Å¼±×ªÖ±ÏÂµÄ
³±ÍË¾²Ú×£»·Â·ğÖÃÉíºÆå«´óº££¬Ëæ×Å¾¨º½µÄÂÉ¶¯ºÍÍğÈçÇáÆïµÄº£ëà
ºô»½£¬¹´ÀÕ³öµ´ÑúĞÄ·¿µÄÒôÀÖĞıÂÉ£¬´øÁìĞÄÁé»Øµ½×îÔ­Ê¼µÄ¾³µØ¡£
  
LONG);
	setup();
	replace_program(ROOM);
}
