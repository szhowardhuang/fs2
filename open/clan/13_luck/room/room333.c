inherit ROOM;
void create() {
	set( "short", "Éñ·çÖ®µÀ" );
	set( "object", ([
		"file3"    : "/daemon/class/blademan/obj/shield",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/capital/obj/chen_dagger",
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount6"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 1,
	]) );
	set( "owner", "smalloo" );
	set( "build", 10374 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room334",
		"north"     : "/open/clan/13_luck/room/room335.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ÄãµÄÖ±¾õ¸æËßÄã£¬¾Í¿ìµ½[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÁË¡£ÄãĞÄÖĞ³åÂúÁË[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[0mºÍ[0;1;35m¡õ[1m¡õ[1m¡õ[1mQ[0m¡£
Òõ·ç´µÏ®µÄÓúÀ´ÓúÇ¿ÁÒ£¬·Â·ğÏñÄãËµµÀ£¬Ïëµ½[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬Çá¹¦²»¹»µÈÓÚ
ËÀÂ·Ò»Ìõ£¬´ËÊ±Äã±»Òõ·ç´µµÄÄã¿ìÎÈ²»×¡½Å²½¡£ÄãÔËÆğ[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬²»Í£µÄ
¼Ó¿ì½Å²½ÏòÇ°×ßÈ¥¡£´ËÊ±ºñºñºÚºÚµÄÔÆ²ã´µ¹ıÀ´£¬Ñ¹µÃÄã´­²»¹ıÆøÀ´
£¬Á¬Ã¦[0;1;33m¡õ[1mB[1m¡õ[1m\[0m×Ô±£¡£


LONG);
	setup();
	replace_program(ROOM);
}
