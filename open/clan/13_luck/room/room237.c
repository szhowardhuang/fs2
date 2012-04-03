inherit ROOM;
void create() {
	set( "short", "¼«Îäµî" );
	set( "object", ([
		"amount8"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/ping/obj/gold_hand",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/port/obj/wolf_ring",
		"amount4"  : 1,
		"file9"    : "/open/gsword/obj/silver_sword",
		"amount9"  : 1,
		"file1"    : "/open/gsword/obj/dragon-sword",
		"amount2"  : 1,
		"amount1"  : 1,
	]) );
	set( "item_desc", ([
		"½ğ¸ÖÊ¯" : @ITEM
Ò»Á£³ó²»À­¼¸µÄÊ¯Í·£¬ÉÏÃæ¿Ì×Å£¬¡²[22m[5m¼«ÎäÉÏ×ğÊÇ´óÖíÍ·[0m¡³
ITEM,
	]) );
	set( "build", 10102 );
	set( "light_up", 1 );
	set( "owner", "kingnight" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room100",
	]) );
	set( "long", @LONG
    ³ØÌÁÀïµÄÁ«»¨É¢·¢×ÅàÛ±ÇµÄÇåÏã,ÁîÈËĞÄ‘ÈÉñâù.²½¹ıĞ¡ÇÅ²İµØÉÏÂúÊÇ
°ÙºÏ»¨²İ,ÆäÖĞ¸üÓĞ¼¸ÖêÆæ»¨Òì²İ,ËÆºõÊ¹ÈË¾õµÃ´Ë´¦µÄÖ÷ÈËÆÓÊµÖĞÒş²Ø²»
·²µÄÆø¶È.ÃÅÉÏ¡®[24m  ¼«  Îä[0m  ¡¯¶ş×Ö,ÕıÓëÖĞÍ¥Á½ÅÔÅÅÁĞÕûÆëµÄ¸÷Ê½ÎäÆ÷ÏÔ
Ê¾Ï°ÎäÖ®ÈË×·ÇóµÄ¼«ÖÂ¾³½ç.ÆäÖĞÒ»°Ñ,ÖÃÓÚÖĞÑëÒÔ¼«Æä¼áÓ²¡²[21m½ğ¸ÖÊ¯[0m¡³µÄ
Ïë±ØÄÜ°Ñ´Ë½£²åÈë´ËÊ¯ÄÚ,´ËÈËµÄÎä¹¦·ÇÒ»°ã¼¶ÊıµÄ¸ßÊÖ¿É¼°,¸üÏÔÊ¾³ö´Ë
½£µÄ·æÀûÑ½!!Õæ¿ÉÎ½Ï°½£Ö®ÈË±ØÕùÏà¾º¶áµÄ[41m[24mÍüÈ»ÉñÆ÷[0m°¡!!


LONG);
	setup();
	replace_program(ROOM);
}
