inherit ROOM;
void create() {
	set( "short", "É³Ä®" );
	set( "object", ([
		"amount6"  : 1,
		"amount8"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file1"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/hobowdan",
		"file9"    : "/obj/gift/lingzhi",
		"amount2"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "owner", "dancer" );
	set( "build", 12166 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room54",
	]) );
	set( "long", @LONG
ÄãÔÚ²»Öª²»¾õÖĞ×ßµ½ÁËÕâÆ¬»ÄÎŞµÄ[0;1;32m¡õ[1mF[1m¡õ[1mz[0m£¬ÒÑ²»ÖªÉí
´¦ÔÚºÎ·½£¬·ÅÑÛÍûÈ¥Ò»Æ¬[0;1;32m¡õ[1mF[1m¡õ[1ma[0m£¬ÈÃÉí´¦ÔÚÕâµÄÄã²»Öª¸Ã
ÍùºÎ´¦×ßÈ¥£¬ÕâÊ±ÔÚÄãµÄÉíÅÔ´µÆğÁËÒ»Õó[0;1;33m¡õ[1mg[1m¡õ[1m¡õ[0m£¬ºÃÏñÔÚ
¾¯Ê¾ÄãÌ¤ÈëÁË²»¸ÃÌ¤ÈëµÄ[0;1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬Äã¹ÄÆğÁËÓÂÆøÄæ×Å¿ñ·ç
£¬Ñ°ÕÒ×ÅÕâÕó¿ñ·çµÄÔ´Í·£¬ÕâÊ±Äã·¢ÏÖÔÚ¿ñ·çÖĞÓĞÒ»´¦
[0;1;31m¡õ[1m¡õ[1m¡õ[1mH[0m£¬ÓÚÊÇÄãÏò×ÅÕâ¸ö[36mÎ´ÖªµØ[0mÇ°½ø¡£
LONG);
	setup();
	replace_program(ROOM);
}
