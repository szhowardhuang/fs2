inherit ROOM;
void create() {
	set( "short", "[1;37m¾²Ú×[0m" );
	set( "build", 4554 );
	set( "exits", ([
		"fly"       : "/open/clan/ou-cloud-club/room/room244",
		"enter"     : "/open/clan/ou-cloud-club/room/room313",
		"north"     : "/open/clan/ou-cloud-club/room/room307.c",
	]) );
	set( "long", @LONG
´©¹ıĞ¡¾¶£¬Ì¤ÉÏ¼¸²ãÊ¯Ìİ£¬ÑÛÇ°Í»È»¿ªÀ«ÆğÀ´£¬ÔÚÄãµÄ
ÕıÇ°·½ÊÇÒ»¶°ÆÓÊµÈ´ÓÖÈÃÈË°²ĞÄµÄÄ¾Îİ£¬ÎİÅÔµÄË®³µ°é×ÅÕó
ÕóÁ÷Ë®Éù£¬×óÊÖ±ßÓĞÒ»¿éÔ¼ÄªÁ½¸öÈË¸ßµÄÊ¯±®£¬¿Ì×Å»ğºìÉ«
µÄÁ½¸ö×Ö¡®[1;31m½£Ğ°[0m¡¯£¬ºÃÆæµÄÄãÔÙ¶¨ÉñÒ»¿´£¬ºÕÈ»·¢ÏÖ½£Ğ°¶ş
×ÖµÄ×ßÊÆ¾¹¾ÍÏñÒ»Ì×±ä»¯ÍòÇ§µÄ½£·¨£¬Äã²»½û¶ÔÕâÀïµÄÖ÷ÈË
ÊÇË­²úÉúÄª´óµÄĞËÈ¤¡£
¡õ
LONG);
	setup();
	replace_program(ROOM);
}
