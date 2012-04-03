inherit ROOM;
void create() {
	set( "short", "   $HIR$ÄãµÄÑÛÇ°Ò»ºÚ£¬½Ó×ÅÊ²Ã´Ò²²»ÖªµÀÁË....$NOR$" );
	set( "light_up", 1 );
	set( "build", 28 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room55.c",
	]) );
	set( "long", @LONG

ÄãËÀÁË¡£

[31mÒõ²ÜÈë¿Ú[0m - 
    ÄãÒÑ¾­À´µ½ÁËÒõ¼äµÄÈë¿Ú¡£ËäÈ»¾àÀëµØ¸®»¹ÓÐÒ»¶Î¾àÀë£¬µ«ÊÇÄãÒÑ¾­
¸ÐÊÜµ½ÕóÕó´Ì¹ÇµÄÒõ·ç¡£ËÄÖÜÒ»Æ¬»ÄÁ¹£¬µ«ÊÇÈ´¹íÓ°´±´±£¬¿´À´Õâ±ßµÄÒ¹
×Ü»áÂùÈÈÄÖµÄ£¬Ó¦¸Ã²»³îÃ»°é¡£ÄÏ±ßºÍÉÏÃæºÃÏñÊÇºÍÈËÊÀ¼äÏàÍ¨µÄ¹ÜµÀ£¬
²»¹ýºÃÏñÓÐÒ»¹ÉÎÞÐÎµÄÁ¦Á¿¸ô¿ªÕâÁ½¸ö²»Í¬µÄÊÀ½ç£¬¿´À´Òª´ÓÕâÁ½¸ö·½Ïò
»ØÈ¥²»ÊÇÄÇÃ´¼òµ¥µÄÊÂÇé¡£
    
LONG);
	setup();
	replace_program(ROOM);
}
