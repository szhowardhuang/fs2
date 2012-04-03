inherit ROOM;
void create() {
	set( "short", "ÍŞÍŞ±¦µî" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/dancer/obj/yuawaist",
		"amount5"  : 1,
		"amount10" : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount2"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/ping/obj/ring-2",
		"amount8"  : 1,
		"amount1"  : 1,
		"file1"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/prayer/obj/boris-hat",
		"file10"   : "/open/ping/obj/chilin_legging",
		"amount6"  : 1,
		"file6"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "owner", "wawaneko" );
	set( "build", 10230 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room97.c",
	]) );
	set( "long", @LONG
Ò»×ùĞÛÎ°×³¹ÛµÄËÂÔºÓ³ÈëÑÛÁ±£¬Ì§Í·Ò»¿´£¬ÃÅ¶¥¹ÒÁËÒ»¿éÄ¾ÔìµÄØÒ¶î£¬
ÉÏÃæÀ¶µ×ºì×ÖĞ´×Å¡¸[33mÍŞÍŞ±¦µî[0m¡±ËÄ¸ö´ó×Ö¡£´ËËÄ×ÖĞ´µÃÉõÊÇ²Ô¾¢ÓĞÁ¦£¬
¿´µÃÄãÉå¶¨ÈëÉñ£¬ĞÄÏë£º¡¸Ìá´ËËÄ×ÖµÄÈË£¬¶¨ÊÇÎÄÎäÈ«²ÅµÄ´ó¸ßÈË¡£¡± 
ÑÛÇ°ØùÁ¢×ÅÒ»¿éÁùÈË³¤£¬¶şÈË¸ßµÄ´óÊ¯±®£¬±®ÉÏ¿Ì×ÅÎå¸ö´ó×Ö£º¡¸[34mÌìÏÂµÚÒ»ËÂ[0m¡±¡£

LONG);
	setup();
	replace_program(ROOM);
}
