inherit ROOM;
void create() {
	set( "short", "½£Ú£" );
	set( "object", ([
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
		"file3"    : "/open/ping/obj/gold_hand",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/gsword/obj/dragon-sword",
		"amount10" : 1,
		"amount3"  : 1,
		"file4"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/mogi/village/obj/mogi_ring",
		"amount4"  : 1,
	]) );
	set( "owner", "konan" );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room267",
		"east"      : "/open/clan/13_luck/room/room100",
	]) );
	set( "build", 10186 );
	set( "light_up", 1 );
	set( "long", @LONG
ÕâÀï¾ÍÊÇÌìÏÂÃû½£×îÖÕ¹éÎ»Ö®Ëù£¬Ò»¸ö°×·¢ĞëĞëµÄÀÏÕßÕı¸ß×øÊ¯±®Ö®
ÉÏ¡£ÓÚ¸÷Ãû½£ÖĞ£¬Òò¸÷½£Ê¿±¾ÉíÖ®ĞŞÎªĞËÔìÒè£¬Ê¹¸÷½£ÁéĞÔåÄÈ»²»Í¬£¬Ö»
¼ûÖĞÑë´¦°ÚÉèÒ»ÎåÃ¢ĞÇÕó£¬¡¾[0;1;31m¡õ[1m][1m¡õ[1my[1m¡õ[1mC[0m£®[0;1;36m¡õ[1m¡õ[0m¡¿±»·âÓ¡ÆäÖĞ£¬Ö»ÎÅÆä½£·¢³öÕó
ÕóµÄÎËÃùÉùÏì£¬Æä×´åÄÒìÓÚÆäËüÃû½££¬ºÕ¼ûËÄÖ»½ğÁú³åÌì¶øÆğ£¬·ÖÁ¢ËÄ·½
¡£ÊØ»¤²¢·âÓ¡×Å¡¾[0;1;36m¡õ[1m¡õ[0m¡¿£¬³¤¾ÃÒÔÀ´Ê¹Ò»Ö±ÓÉ¶µÉ½´óÎòËù¿´ÊØ²¢ÆÚÍû×ÅÓĞÌì
ÄÜ¼İÓù´Ë½£ĞĞ×ßÌìÏÂ¡£

LONG);
	setup();
	replace_program(ROOM);
}
