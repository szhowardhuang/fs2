inherit ROOM;
void create() {
	set( "short", "Ñ§ÎäÖ®µÀ" );
	set( "owner", "haoman" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 7,
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/ping/obj/ring-2",
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/daemon/class/blademan/obj/gold-blade",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount7"  : 1,
	]) );
	set( "build", 11358 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room336",
		"south"     : "/open/clan/13_luck/room/room333.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ËÉÁÖÖĞ¾²ÇÎÇÎµØÃ»°ëµãÉùÏ¢£¬ÏÂÏÒÔÂ²»Éõ[0;1;33m¡õ[1m¡õ[1m¡õ[1mG[0m£¬Ó³×ÅÒ°[0;1;32m¡õ[1mQ[1m¡õ[1mL[0m¡£ÕÕ
µÃÈËÃæ½Ô×ª¹ıÁËÁ¼¾ÃºöÌıµÃÁÖÖĞÒ»ÉùºôÉÚ£¬×ó²àºÍÓÒ²à¸÷ÓĞÒ»ĞĞ[0;1;30;47m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
ºº×Ó±¼³ö£¬Ô­À´ÊÇ[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÄÃÅÍ½ÕıÔÚÅ¬Á¦Á·Ï°Çá¹¦¡£´ËÊ±ºñºñºÚºÚµÄ
ÔÆ²ã´µ¹ıÀ´£¬Ñ¹µÃÄã´­²»¹ıÆøÀ´£¬Á¬Ã¦[0;1;33m¡õ[1mB[1m¡õ[1m\[0m×Ô±£¡£


LONG);
	setup();
	replace_program(ROOM);
}
