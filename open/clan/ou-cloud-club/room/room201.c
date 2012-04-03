inherit ROOM;
void create() {
	set( "short", "[1;36mÑÚ¹âÌì[0m" );
	set( "object", ([
		"file2"    : "/open/common/obj/liz_meat",
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file7"    : "/open/magic-manor/obj/evil-kill-claw",
		"file5"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"amount2"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/shenliwan",
		"file4"    : "/open/mogi/dragon/obj/key",
		"file3"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 2,
		"amount9"  : 1,
		"amount1"  : 3,
		"amount3"  : 9,
		"file6"    : "/open/mogi/dragon/obj/power",
	]) );
	set( "owner", "del" );
	set( "item_desc", ([
		"blade" : @ITEM
µ¶³¤Æß³ß£¬È«ºÚµÄµ¶ÉíÉÏÓĞÒ»»ğÑæ×´Ó¡¼Ç£¬É¢·¢Ò»¹É°ÔÆø£®
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10033 );
	set( "exits", ([
		"eastdown"  : "/open/clan/ou-cloud-club/room/room220",
		"south"     : "/open/clan/ou-cloud-club/room/room191.c",
	]) );
	set( "long", @LONG
ÄãÍÆ¿ª°ëÑÚµÄÄ¾ÃÅ£¬Ò»ÕóÇåµ­µÄÌ´ÏãÓ­Ãæ¶øÀ´£¬ÑÛÇ°ÊÇ
Ò»¼ä°ÚÉè¼òµ¥µÄÎİ×Ó£¬µ«È´ÓĞÒ»¹ÉÎŞĞÎµÄÉ±ÆøÈÃÈËÓĞµã´­²»
¹ıÆøÀ´£¬»·¹ËËÄÖÜ£¬Ô­À´É±ÆøÊÇÀ´×Ôºá¹ÒÔÚÇ½ÉÏµÄÒ»°Ñ÷îºÚ
µÄµ¶(Blade) £¬×óÊÖ±ßÓĞÌõÍùÏÂµÄÊ¯Ìİ£¬²»ÏşµÃÍ¨ÍùÄÄÀï¡£
¡õ
¡õ[1;31m[1;37m¹íÉñÖÁ×ğ[1;31m¡®¶ñ°ÔÁ¬»÷¡¯[0mĞ¡ĞÍ¶ñÈË(Badman)
¡õ[1;37m¿ñ±©¿áÁú[1;36m¡®ºÆå«ÎŞÛó¡¯[0m¿áË¹À­(Gozila)
LONG);
	setup();
	replace_program(ROOM);
}
