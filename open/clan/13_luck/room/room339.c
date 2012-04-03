inherit ROOM;
void create() {
	set( "short", "·çÔÆµÀ" );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"file6"    : "/daemon/class/bonze/puty_pullium",
		"file1"    : "/open/gblade/obj/sa-head",
		"amount10" : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/capital/obj/chen_dagger",
		"amount3"  : 1,
	]) );
	set( "owner", "smalloo" );
	set( "build", 10650 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room340",
		"south"     : "/open/clan/13_luck/room/room338",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    Äã¼±Ô¾¶øÆğ×ªÉíËÄÍû£¬ÀäÔÂµ±¿Õ£¬[0;1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1ma[0m£¬[0;1;33m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1mI[1m¡õ[1mI[0m£¬»¨Ó°ÖØ
ÖØËÄÏÂÀïÉ½¹ÈÎØÏì£¬Äã¼ÌĞø¼±±¼Ç°È¥¡£ÔÙ¹ıÈ­ÖùÏãÊ±·Ö£¬Äã¿ç¿ª´ó²½
£¬¾õµÃ·çÉú¶ú¼Ê£¬Á½[0;1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m²»×¡µÄµ¹ÍË£¬àSµØÓĞÈç¿ìÂí±¼³Û¡£Äã´ó
ĞäÆ®Æ®Å¬Á¦Ç°È¥¡£´ËÊ±Î¢·çĞìĞì´µÀ´£¬ÌìÉÏµÄÔÆ²ãÒ²ÓĞµã¶ùÆ®ºö²»¶¨
£¬ÁîÄã¾õµÄÃ«¹ÇËÊÈ»¡£

LONG);
	setup();
	replace_program(ROOM);
}
