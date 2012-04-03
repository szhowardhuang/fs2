inherit ROOM;
void create() {
	set( "short", "ÁúÖ®ÑÂ" );
	set( "object", ([
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"file7"    : "/open/ping/obj/gold_hand",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/snow/obj/figring",
		"file5"    : "/open/dancer/obj/yuawaist",
		"amount4"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/open/scholar/obj/icefan",
		"file9"    : "/open/gsword/obj/yuskirt",
		"file2"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "owner", "fighter" );
	set( "item_desc", ([
		"ÃğÉ±Áú" : @ITEM
[22mÄãÑÛÇ°Ò»ºÚ£¬½Ó×ÅÊ²Ã´¶¼²»ÖªµÀÁË....[0m
ÄãËÀÁË
[31mÒõ²ÜÈë¿Ú[0m-
          ÄãÒÑ¾­À´µ½ÁËÒõ¼äµÄÈë¿Ú¡£ËäÈ»¾àÀëµØ¸®»¹ÓĞÒ»¶Î¾àÀë£¬µ«ÊÇÄãÒÑ¾­
¸ĞÊÜµ½ÕóÕó´Ì¹ÇµÄÒõ·ç¡£ËÄÖÜÒ»Æ¬»ÄÁ¹£¬µ«ÊÇÈ´¹íÓ°´±´±£¬¿´À´Õâ±ßµÄÒ¹
×Ü»áÂùÈÈÄÖµÄ£¬Ó¦¸Ã²»³îÃ»°é¡£ÄÏ±ßºÍÉÏÃæºÃÏñÊÇºÍÈËÊÀ¼äÏàÍ¨µÄ¹ÜµÀ£¬
²»¹ıºÃÏñÓĞÒ»¹ÉÎŞĞÎµÄÁ¦Á¿¸ô¿ªÕâÁ½¸ö²»Í¬µÄÊÀ½ç£¬¿´À´Òª´ÓÕâÁ½¸ö·½Ïò
»ØÈ¥²»ÊÇÄÇÃ´¼ò¡õäî¡õ©xC
    ÕâÀïÎ¨Ò»µÄ³ö¿ÚÊÇ north¡£
ITEM,
		"stone" : @ITEM

Ò»¸ö¾Ş´óµÄÊ¯Í·£¬ÆäÉÏÁôÏÂ×ÅÒ»¸öÉîÖØµÄÕÆÓ¡£¬ÏÂÃæ²¢ÀÓÏÂËÄ¸ö
¼«ÉîµÄ´ó×Ö 
               [22m¡ò  [5m[21m²¨  ¶¯  [0m[23m¡ñ  [5m[24m»Ê  È­  [0m[22m¡ò[0m 
ITEM,
	]) );
	set( "build", 10959 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room276",
		"north"     : "/open/clan/13_luck/room/room100.c",
	]) );
	set( "long", @LONG

[33m    [0mËÄ´¦¿Õµ´£¬Ò»×ß½øÕâĞüÑÂ£¬±ãÖ»Ìıµ½×Ô¼ºµÄ½Å²½Éù»Øµ´ÔÚÉ½¹ÈÖ®
ÖĞ²»¾øÓÚ¶ú£¬×ĞÏ¸ñöÌı£¬ËÆºõ¿ÉÌı¼û·çÖĞ´«À´Î¢ÈõµÄÁ·¹¦ßººÈÉù£¬±Õ
ÑÛ°´ÔËÄÚÁ¦¶úÌı°Ë·½£¬·çÖĞÖ®Éù¾¹ÊÇÊ§´«¼º¾ÃµÄ[0;1;31m¡õ[1mi[1;36m¡õ[1mi[1m¡õ[1m¡õ[1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1;31m¡õ[1mj[0mÖ»¼ûĞü
ÑÂÏÂÉ¢³öÇ§ÍòÕÉµÄ½ğ¹â£¬Ò»Ê±¼äÁúÌÚ¾ÅÌì»ØĞı¿Õ£¬Ë²¼äÏûÊ§ÎŞ×Ù£¬¾ª
¶òÖ®ÖĞÍ»È»Ò»µÀÉÁ¹â´ÓÉ½¹ÈÏÂ·É×İÖÁÄãÃæÇ°£¬ÑÛÇ°ÕıÊÇ
[33m            [0;1;31m¡õ[1mi[1;36m¡õ[1mi[1m¡õ[1m¡õ[1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1;31m¡õ[1mj[0mÎ¨Ò»´«ÈË£®[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ms[0m
$HIY$[33mÖ»¼ûÆäÉíÅÔ[0;1;5;33m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5ms[1;5m¡õ[1;5m¡õ[0m$HIY$[33m»¤ÉíÆø¾¢¹âÃ¢Î§ÈÆÆäĞŞÎªÖ®¸ßÁîÈË°µ×ÔÔŞÌ¾£¡[0m

LONG);
	setup();
	replace_program(ROOM);
}
