inherit ROOM;
void create() {
	set( "short", "ĞşÎä×ßÀÈ" );
	set( "owner", "palapala" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10720 );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/capital/obj/4-3",
		"file2"    : "/open/capital/obj/4-1",
		"amount1"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount4"  : 30,
		"file8"    : "/daemon/class/fighter/ywhand",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"file10"   : "/daemon/class/fighter/armband",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"amount3"  : 49,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room151",
		"west"      : "/open/clan/sky-wu-chi/room/room146.c",
	]) );
	set( "long", @LONG
Äã×ßÔÚÃûÎª[1;37m¡®[1;30mĞşÎä[0m[1;37m¡¯[0m×ßÀÈÉÏÄã¸Ğ¾õµ½ÓĞÒ»ÖÖ²»º®¶øÀõµÄÉ±Æø£¬±ÈÄã¸Õ¸Õ
×ßµÄ[1;47m¡®[1;37m°×»¢[1;47m¡¯[0m×ßÀÈÓĞ¹ıÖ®¶øÎŞ²»¼°£¬Äã¸ĞÊÜµ½ÁË¿ÕÆøÖĞÓĞÒ»¹ÉËàÉ±µÄÆøÏ¢Õı
ÃÖÂûÔÚËÄÖÜ£¬ÔÚÒ»Æ¬µÄºÚ°µÀï£¬Äã¿´²»µ½ËÄÖÜÓĞĞ©Ê²Ã´£¬Ö»ÊÇ¸Ğ¾õµ½ÓĞºÃ¼¸
Ë«µÄÑÛ¾¦ÕıµÉ×ÅÄã¿´¡£ÃÍÈ»¼äÄã·¢ÏÖÌì»¨°åÑ¹ÁËÏÂÀ´£¬Äã¼¯Ã¦µÄÔËÁËÆø¾ÙÆğ
ÄãµÄË«ÊÖÏòÉÏÄÇÃ´Ò»³Å£¬Ê¹ÓÃÁËÇ§½ï×¹µÄ¹¦·òÓ²Í¦×Å£¬Ã»Ïëµ½´ÓËÄ´¦ÅÜ³öÀ´
ÁËËÄ¸ö»¤ÎÀ¡£ÄÇËÄÖ»»¤ÎÀ·Ö±ğÊÇ½Ğ¡®Ãğ¡¯¡®¿Õ¡¯¡®Îä¡¯¡®Éñ¡¯£¬¶¼ÄÃ³öÁËËû
ÃÇµÄÎäÆ÷ÃÍÈ»µÄÏòÄãµÄÉíÌåËÄ´¦ÃÍÈ»²åÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
