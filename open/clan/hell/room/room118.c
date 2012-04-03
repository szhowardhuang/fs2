inherit ROOM;
void create() {
	set( "short", "£Â£å£â£åµÄÉñÃØĞ¡Îİ" );
	set( "owner", "bebe" );
	set( "object", ([
		"file2"    : "/open/gsword/obj/spsword-4",
		"file1"    : "/open/gsword/obj/dragon-sword",
		"amount2"  : 1,
		"file4"    : "/open/scholar/obj/icefan",
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "item_desc", ([
		"c_room_item BEBEµÄ¿ÍÌü" : @ITEM
¡¡¡¡¡¡¡¡


¡¡¡¡¡¡¡¡¡¡¡õ[31m¡«¡«¡«ÕâÀïÊÇ£Â£Å£Â£ÅÉñÃØ»¨Ô°¡«¡«¡«[0m

¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10032 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room117",
		"west"      : "/open/clan/hell/room/room5.c",
	]) );
	set( "long", @LONG

¡¡¡¡Äã¸ÕÀ´µ½ÕâÀïµÄ´óÃÅ£¬¾Í¸Ğ¾õµ½Ò»¹É²»ÖªÄÄÀïÀ´µÄÉùÒô
¶ÔÄãËµ[31m¡®¡«¡«Ğ¡º¢×Ó¡«ÕâÀï²»ÊÇÄãÀ´µÄµØ·½à¸¡«¡«»¹²»¿ì»Ø[0m
[31m¼Ò¶ÁÊé¡¯[0m£¬ÄãÔÙ×ĞÏ¸µÄÒ»¿´£¬Ô­À´ÕâÀï¾ÍÊÇ´«ËµÖĞ[36m£Â£å£â£å[0m
µÄÉñÃØĞ¡Îİ£®
LONG);
	setup();
	replace_program(ROOM);
}
