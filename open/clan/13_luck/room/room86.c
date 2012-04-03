inherit ROOM;
void create() {
	set( "short", "ÄÚÓĞ¶ñÈ®" );
	set( "object", ([
		"file6"    : "/obj/gift/unknowdan",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/xiandan",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"amount3"  : 125,
		"file1"    : "/open/mogi/castle/obj/blood-water",
		"amount5"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/lingzhi",
		"amount1"  : 7,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount2"  : 471,
	]) );
	set( "owner", "roar" );
	set( "build", 10427 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room83.c",
		"enter"     : "/open/clan/13_luck/room/room88",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÄãÒÑÌ¤½øÕâµØ·½¾Í±»ÕâËÄ¸ö×ÖÏÅµ½ÁË¡±[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mc[1m¡õ[1m¡õ[0m¡±£¿£¿ĞÄÏë£¬×Ô¼ºÒ»
ÉúĞĞ×ß½­ºş£¬Ê²Ã´¶«Î÷Ã»¿´¹ı£¬µ«Õâ¡±[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mc[1m¡õ[1m¡õ[0m¡±ÊÇÖ¸Ê²Ã´ÄØ£¿×Ô¼ºÊ¼ÖÕ
ÊÇÂú»³ÒÉÎÊ£¬µ«»¹ÊÇÏëÒ»¿´¾¿¾¹£¬´ËÊ±ÅÜ³öÒ»Ö»²»ËãĞ¡µÄ¹·£¬¿´ËÆ¼´Îª¿É
°®£¬ÄãÈÌ²»×¡È¥ÃşËı£¬·¢ÏÖËı½Ğ[0;1;5;36m¡õ[1;5mD[1;5m¡õ[1;5mD[0m£¬Ô­À´ÊÇÎİÖ÷¹ÊÒâÒªÏÅÄ°ÉúÈËµÄ´ó¹·
¡£
LONG);
	setup();
	replace_program(ROOM);
}
