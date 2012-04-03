inherit ROOM;
void create() {
	set( "short", "ÁúÖ®Ñ¨" );
	set( "owner", "fighter" );
	set( "object", ([
		"file8"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount7"  : 1,
		"amount9"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/hobowdan",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/gblade/obj/dragon_book",
		"amount10" : 1,
	]) );
	set( "build", 10194 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room348",
		"out"       : "/open/clan/13_luck/room/room265.c",
		"south"     : "/open/clan/13_luck/room/room324.c",
	]) );
	set( "long", @LONG

    ¼òµ¥µÄÊ¯´²£¬¼¸ÕÅÊ¯ÒÎÊ¯×À£¬ÉÏÃæ¼¸±¾µÄÎä¹¦Êé¼®É¢ÂÒ·ÅÖÃ£¬Õû
ÌìÉò½şÓÚÎäÑ§µÄ¾¿¼«¾³½ç¡£ÅÔ±ß¾Í·Å×ÅÒ»Ğ©Ö÷ÈËËù°®´©µÄÒÂ·ş·À¾ß£¬
ÅÔ±ß»¹ÓĞ¼¸Ö»ÆæÒìµÄĞ¡¶¯ÎïÔÚÎûÏ·ÍæË£×Å£¬³¤×ÅĞ¡³á°ò£¬²»Ê±·ÉĞıÓÚ
¿ÕÖĞ£¬¿ÚÖĞÅ¼¶ø»¹»áÍÂ×ÅĞ¡Ğ¡µÄ»ğÑæ£¬»á²»»áÊÇÎäÁÖÖĞµÄ´«ÑÔÉñÊŞ©¤
[0;1;32m¡õ[1mt[1m¡õ[1m~[0m£®[0;1;31m¡õ[1mW[0m


LONG);
	setup();
	replace_program(ROOM);
}
