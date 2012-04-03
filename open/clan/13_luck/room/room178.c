inherit ROOM;
void create() {
	set( "short", "ÌìĞ°·å" );
	set( "object", ([
		"amount10" : 1,
		"amount3"  : 1,
		"file5"    : "/daemon/class/fighter/armband",
		"amount9"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/gsword/obj/yuskirt",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file8"    : "/open/ping/obj/gold_hand",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10434 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room179",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ´Ó[0;1;33m¡õ[1m][1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÍù±±·½Ö±×ß£¬±ã¿ÉÒÔµ½´ï´Ë´¦£¬ÓĞ±ğÓÚ[0;1;32m¡õ[1m][1m¡õ[1m¡õ[1m¡õ[1mL[0mµÄ¹îÒìÆø
·Õ£¬ÈÃÄã¸Ğ¾õÕâÀïËÆºõÃ»ÄÇÃ´Î£ÏÕ£¬µ«ÊÇÑÛ¼âµÄÄã·¢ÏÖÔ¶·½ºÃÏñÓĞÀà
ËÆ[0;1;35m¡õ[1mJ[1m¡õ[1m¡õ[0mµÄÎïÆ·£¬Ë²¼äÄãÄÔÖĞÉÁ¹ıÒ»ÄîÍ·£¬²»»áÓÖÒªÔÙÀ´Ò»´Î°É£¿ÏëÆğ
ÔÚ[0;1;32m¡õ[1m][1m¡õ[1m¡õ[1m¡õ[1mL[0mµÄ¿Ö²À¾­Ñé£¬Äã¾ö¶¨ÊÕÆğÄãµÄºÃÆæĞÄ£¬Ô¶ÀëÕâĞ©[0;1;35m¡õ[1mJ[1m¡õ[1m¡õ[0m¡£¼ÇµÃ
Ä§½ç´åµÄÈËËµ¹ı£¬´«ÎÅÕâÀïÓĞÈıÖ»ÑıºüÇ§Íò²»ÄÜ¼û£¬ÒòÎª¼ûµ½µÄÈË´Ó
À´Ã»»ØÀ´¹ı¡£


LONG);
	setup();
	replace_program(ROOM);
}
