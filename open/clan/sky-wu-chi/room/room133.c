inherit ROOM;
void create() {
	set( "short", "ÉñÃØºó»¨Ô°" );
	set( "owner", "ywarter" );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/killer/obj/k_ring",
		"file3"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file2"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ping/questsfan/obj/diamond_legging",
		"file6"    : "/open/magic-manor/obj/water-ball",
		"file1"    : "/open/ping/questsfan/obj/diamond_cloak",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room136",
	]) );
	set( "long", @LONG
ÕâÀïÊÇÕû¸ö¾ÓËùµÄºó»¨Ô°£¬Ò²ÊÇ¿ÕÆ¿×ÓºÍËûµÄ¼¸Î»·òÈËÒ»ÆğÉÍ»¨¿´·ç¾°
µÄµØ·½£¬ÕâÀïµÄ»¨¶¼ÊÇÒ»Ğ©ÆæÕäÒì²İ£¬ÆäÖĞÀïÃæÓĞÒ»Öê[1;37m¡®[1;35mÆ¼ÒôÀ¼²İ[1;37m¡¯[0m×îÊÇÕä
¹ó£¬¶øÄã¾ø¶ÔÏë²»µ½Õâ²İÓĞÔõÑùµÄ¹¦ÓÃ¡£ÎÊÁËÒ»ÏÂÔ­À´²ÅÖªµÀÕâÆæ²İÔ­À´ÊÇ
¸ö·Ç³£Ê±ÆÚµÄÑÓÄêĞøÃüµ¤Ö®¹¦ÓÃ£¬³ÔÏÂÈ¥Ö®ºóÄã»á¸Ğµ½ÄãÔÚÕâÊÀ½çÉÏÓĞ¶à¿É
ÒÔ¶à»î¸ö¶şÊ®¼¸Äê£¬Ö»ÊÇÄãÒ²Ö»ÄÜ¿´¶ø²»ÄÜ³Ô¡£ÒòÎªµ±ÄãÍµÕªÀ´³ÔÖ®Ê±Äã»á
±»¿ÕÆ¿×Óµ±³¡·¢³öÁÔÉ±Áî°ÑÄã¸øÉ±ÁË¡£ËùÒÔÒ²Ö»ÄÜ¿´¿´ÕâÀïµÄ·ç¾°£¬Õâ¸ö»¨
Ô°ÕæµÄÊÇºÜ´ó£¬ÓĞ×Å¹ã´óµÄ²İÆº»¹ÓĞÈºÈºµÄÑòºÍÂí¡£ÑÛ¾¦Ò»¿´ÄÇ´øÍ·µÄÂí¶ù
Ô­À´ÊÇÓĞÃûµÄÁú¾Ô¿´ ­ÑïÆğÍ·Ó¢×ËµÄÑù×Ó£¬Äã¿ªÊ¼¾õµÃÒ²Ö»ÓĞÕâÑù×ÓµÄºÃÂí
²ÅÅäµÄÉÏÕâ¸ö·¿×ÓµÄÖ÷ÈË¡£

LONG);
	setup();
	replace_program(ROOM);
}
