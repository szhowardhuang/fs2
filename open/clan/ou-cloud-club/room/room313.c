inherit ROOM;
void create() {
	set( "short", "[1;36mÂªÊÒ[0m" );
	set( "owner", "del" );
	set( "object", ([
		"amount6"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_boots",
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_pants",
		"amount1"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_hands",
		"amount2"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "build", 10039 );
	set( "item_desc", ([
		"swordsman" : @ITEM
ç³Ìì½£Ð°Í»È»×ª¹ýÍ·À´µÉÄãÒ»ÑÛ¡£
ç³Ìì½£Ð°ÀäÐ¦µÀ: ¡¸Æ¾ÄãÕâ·Ï²ñ¸ù±¾¾Í²»ÊÇÎÒµÄ°àÊý, Ò²ÏëÀ´¸úÎÒ¶·, Õâ¾Í¸øÎÒÈ¥ÆÍ½Ö°É¡±
¡õ
[1;31m¿´ÆðÀ´ç³Ìì½£Ð°ÏëÉ±ËÀÄã£¡
¡õ
[1;37mç³Ìì½£Ð°ºðµÀ: ¼ûÑÖÍõÈ¥°É£¡¿´ÎÒµÄ¡®É±ìøÆß½£¡¯£¡£¡
¡õ
[1;36mö®Ê±¼ä·çÔÆ±äÉ«£¬À×Éù´ó×÷£¬ç³Ìì½£Ð°ÊÖÖÐµÄ[1;33mÉ±ìø[1;36mÒÑ´©Ìå¶ø¹ý£¡£¡
[31m[0m( Äã[31mÒÑ¾­ÏÝÈë°ë»èÃÔ×´Ì¬£¬ËæÊ±¶¼¿ÉÄÜË¤µ¹ÔÎÈ¥¡£[0m )
        [ [31m¾«Á¦: -1  ÆøÑª: -1  Éñî¨: -1[0m ]
¡õ
[1;31mÄãµÄÑÛÇ°Ò»ºÚ£¬½Ó×ÅÊ²Ã´Ò²²»ÖªµÀÁË.... 
[0m¡õ
ÄãËÀÁË
¡õ
[31mÒõ²ÜÈë¿Ú[0m  -
¡õ¡õÄãÒÑ¾­À´µ½ÁËÒõ¼äµÄÈë¿Ú¡£ËäÈ»¾àÀëµØ¸®»¹ÓÐÒ»¶Î¾àÀë£¬µ«ÊÇÄãÒÑ¾­
¸ÐÊÜµ½ÕóÕó´Ì¹ÇµÄÒõ·ç¡£ËÄÖÜÒ»Æ¬»ÄÁ¹£¬µ«ÊÇÈ´¹íÓ°´±´±£¬¿´À´Õâ±ßµÄÒ¹
×Ü»áÂùÈÈÄÖµÄ£¬Ó¦¸Ã²»³îÃ»°é¡£ÄÏ±ßºÍÉÏÃæºÃÏñÊÇºÍÈËÊÀ¼äÏàÍ¨µÄ¹ÜµÀ£¬
²»¹ýºÃÏñÓÐÒ»¹ÉÎÞÐÎµÄÁ¦Á¿¸ô¿ªÕâÁ½¸ö²»Í¬µÄÊÀ½ç£¬¿´À´Òª´ÓÕâÁ½¸ö·½Ïò
»ØÈ¥²»ÊÇÄÇÃ´¼òµ¥µÄÊÂÇé¡£
¡õ
¡õ¡õÕâÀïÃ÷ÏÔµÄ³ö¿ÚÊÇ [1;37mnorth[0m
¡õ
ITEM,
	]) );
	set( "exits", ([
		"fly"       : "/open/clan/ou-cloud-club/room/hall",
		"out"       : "/open/clan/ou-cloud-club/room/room306.c",
	]) );
	set( "long", @LONG
ÍÆ¿ª°ëÑÚµÄÄ¾ÃÅ£¬ÕóÕóÇåÏãÓ­Ãæ¶øÀ´£¬ÁîÈË¾«ÉñÎªÖ®Ò»
Õñ£¬»·¹ËËÄÖÜ£¬Ö»ÓÐ¼òµ¥µÄ°ÚÉè£¬È´ÓÖ²»»á¾õµÃ¼òÂª£¬Õâ´ó
¸Å¸úÖ÷ÈËµÄ¶ÀÌØÆøÖÊÓÐ¹Ø°É¡£²»Ô¶´¦ÓÐÒ»ÓÃÉîÀ¶É«²¼Ä»¸ô¿ª
µÄÐ¡ÃÅ£¬ÒþÔ¼´«À´É³É³µÄÉùÒô£¬²»ÏþµÃ²Ø×ÅÊ²Ã´¡£
¡õ
¡õ[1;36m°ÁÔÆÆßÊ¥[1;37m¡®½£ÐÄ½£Òâ½£Í¨Éñ¡¯[1;33mç³Ìì½£Ð°[0m(Evil_swordsman)
¡õ
LONG);
	setup();
	replace_program(ROOM);
}
