inherit ROOM;
void create() {
	set( "short", "[1;36mÎŞÑÌºş[0m" );
	set( "exits", ([
		"northeast" : "/open/clan/ou-cloud-club/room/room312",
		"west"      : "/open/clan/ou-cloud-club/room/room310.c",
		"south"     : "/open/clan/ou-cloud-club/room/room308.c",
	]) );
	set( "long", @LONG
±ùÀäµÄºşË®ÈÃÄãµÄÊÖ½ÅÓĞµã²»ÌıÊ¹»½£¬µ«ÇóÉúµÄÔ­Ê¼±¾
ÄÜÈ´ÈÃÄã²»×Ô¾õµÄ»®¶¯ÊÖ½ÅÇ°½ø£¬ÂıÂıµÄÒ²ÄÜÊÊÓ¦¶øÔÚÆäÖĞ
ÓÆÓÎ£¬»·¹ËËÄÏÂ£¬³ıÁËÑô¹âÍ¸¹ıË®ÃæµÄĞ©Î¢¹âÏßÖ®Íâ£¬ºşµ×
¾¡ÊÇÒ»Æ¬²»¿É²âµÄ²ÒÂÌ£¬Å¼¶øÒ»Ğ¡ÈºÓÎÓã´ÓÄãÉíÅÔÓÎ¹ı£¬È´
²»ÒòÎªÄãµÄÍ»È»³öÏÖ¶øÓĞËù¾ªÏÅ£¬ËãÁË£¬»¹ÊÇ¿ìÕÒ³ö¿Ú°É¡£
¡õ
LONG);
	setup();
	replace_program(ROOM);
}
