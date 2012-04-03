inherit ROOM;
void create() {
	set( "short", "[1;36m°Á[37mÔÆ[0m¸ó[1;31mÖÕµãÕ¾[0m" );
	set( "build", 10020 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room240",
		"south"     : "/open/clan/ou-cloud-club/room/room217.c",
	]) );
	set( "long", @LONG
ÕâÀïÊÇ°ÁÔÆÉ½×¯µÄ¸ßÊÖÃÇËù¾Ó×¡µÄ¶şÂ¥£¬°ÁÔÆÉ½×¯ÄÚµÄ
ÈË¶¼¾Ó×¡ÓÚ´Ë£¬ÓµÓĞÅ¨ÁÒµÄËàÉ±Î¶µÀ£¬ËùÒÔ£¬ÔÚÕâÀïÄãÒªÌØ
±ğµÄĞ¡ĞÄ½÷É÷£¬ÒÔÃâ½øÈëÁË²»¸Ã½øÈëµÄ·¿¼ä¡£
¡¡
×ó±ßÏÖÔÚÊÇÓ±Ó±(sakira)µÄÒşÉíĞ¡Îİ£¬ÓÒ±ßµÄ·¿¼äÕıÔÚÊ©¹¤ÖĞ¡£
LONG);
	setup();
	replace_program(ROOM);
}
