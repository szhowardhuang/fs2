inherit ROOM;
void create() {
	set( "short", "Ç°Ìü" );
	set( "owner", "raymond" );
	set( "object", ([
		"file2"    : "/open/killer/obj/k_ring",
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount10" : 1,
		"file3"    : "/open/prayer/obj/boris-boots",
		"amount5"  : 1,
		"file4"    : "/open/gsword/obj/yugem",
		"amount7"  : 1,
		"file5"    : "/daemon/class/fighter/figring",
		"amount9"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_leg",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount1"  : 1,
		"file8"    : "/open/mogi/village/obj/mskirt",
		"amount8"  : 1,
		"file10"   : "/open/mogi/village/obj/mamulet",
		"file6"    : "/open/ping/obj/gold_hand",
		"amount2"  : 1,
	]) );
	set( "build", 10975 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room122",
		"north"     : "/open/clan/13_luck/room/room125",
	]) );
	set( "long", @LONG
                 
                 [33mÇ°Ìü[0m
                                                         
ËÄÃæÒÔ[52mËØÖÊÖñ²Ä[0m²¼ÖÃ¶ø³É£¬µäÑÅ´ó·½£¬×óÓÒÁ½±ß
Öñ´°°ëÑÚ£¬ÔÚ´ËÌØÊâµÄµØĞÎ»·¾³ÏÂ[33mÑô¹â×ÜÊÇ²»¾­[0m
[33mÒâµÄĞ±Éä½øÀ´£¬Ã÷¶ø²»ÁÒ¡¢Èá¶øÅ¯ÎÂ£¬¿¿ÔÚ´°±ß[0m
[33mºÃËÆ[55mÇéÈËµÄÊÖ[33mÔÚÉíÉÏÓÎÒÆ£¬¾¡ÏÔã¼ÀÁÏĞÊÊÖ®Çé£¬[0m
ÎªĞ°Íõ½Ó´ıÖ¿ÓÑÖ®Ëù£¬ÄÜ½øÃÅµ±¿ÍµÄÎäÁÖÇüÖ¸¿ÉÊı
LONG);
	setup();
	replace_program(ROOM);
}
