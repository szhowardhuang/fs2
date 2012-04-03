inherit ROOM;
void create() {
	set( "short", "[1;36m°Á[37mÔÆ[0m¸ó[0m" );
	set( "build", 10038 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room236",
		"west"      : "/open/clan/ou-cloud-club/room/room225.c",
		"south"     : "/open/clan/ou-cloud-club/room/room214.c",
		"east"      : "/open/clan/ou-cloud-club/room/room221.c",
	]) );
	set( "long", @LONG
ÕâÀïÊÇ°ÁÔÆÉ½×¯µÄ¸ßÊÖÃÇËù¾Ó×¡µÄ¶şÂ¥£¬°ÁÔÆÉ½×¯ÄÚµÄ
ÈË¶¼¾Ó×¡ÓÚ´Ë£¬ÓµÓĞÅ¨ÁÒµÄËàÉ±Î¶µÀ£¬ËùÒÔ£¬ÔÚÕâÀïÄãÒªÌØ
±ğµÄĞ¡ĞÄ½÷É÷£¬ÒÔÃâ½øÈëÁË²»¸Ã½øÈëµÄ·¿¼ä¡£
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
×ó±ßÊÇÏòÈÕ¿û(flower)µÄ·¿¼ä£¬ÓÒ±ßÔòÊÇË®Ö®Áµ(mosia)µÄ·¿¼ä¡£

LONG);
	setup();
	replace_program(ROOM);
}
