inherit ROOM;
void create() {
	set( "short", "[1;31mĞŞ£®ÂŞ£®µÀ[0m" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/lin-cloud-fan",
		"file8"    : "/open/mogi/dragon/obj/key",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 2,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 19,
		"amount3"  : 19,
		"amount5"  : 1,
		"amount2"  : 46,
		"file9"    : "/open/ping/obj/poison_pill",
		"amount10" : 1,
		"amount9"  : 10,
		"file4"    : "/open/wu/npc/obj/armband",
		"amount6"  : 1,
		"file5"    : "/open/killer/obj/k_ring",
		"file6"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 1,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 1,
	]) );
	set( "owner", "rings" );
	set( "build", 10036 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room230.c",
		"west"      : "/open/clan/ou-cloud-club/room/room33.c",
	]) );
	set( "long", @LONG
ÑØ×ÅĞ¡¾¶»º»ºÇ°½ø£¬À´µ½ÁËÒ»¼ä¿ÕÎŞÒ»ÎïµÄÊ¯ÊÒ£¬¹âÏß
ÊÇ´Ó½ÏÎªÉÏ²ãµÄÊ¯±ÚÍ¸¹â¶øÀ´£¬×ĞÏ¸¶ËÏê²Å·¢ÏÖËÄÖÜÎ§µÄÇ½
ÉÏ£¬µØÃæ£¬ÉõÖÁÊÇÌì»¨°å¶¼ÓĞ×ÅÃÜÃÜÂéÂé¡¢ÉîÇ³²»Ò»µÄµ¶ºÛ
£¬¿´À´ÏñÊÇÀú¾­¶à´Îµ¶ÒâµÄ´ãÁ¶²Å»áÈç´Ë¡£ÔÚÊ¯ÊÒÓÒ²àµÄÇ½
ÉÏ¿Ì×ÅÑªºìµÄ¼¸ĞĞ×Ö£º
  
  [31mĞŞÉÆÄÑ£¬ÎªÄ§Ò×£»Ç§ÄêĞŞµÀ£¬²»¼°Ò»Ò¹³ÉÄ§[0m
  
Í»È»¼äÒ»¹ÉÀä·ç´ÓÄã±³ºóÉ¨¹ı£¬Äã²»½û´òÁËÒ»¸öÀä²ü¡£
LONG);
	setup();
	replace_program(ROOM);
}
