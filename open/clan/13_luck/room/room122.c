inherit ROOM;
void create() {
	set( "short", "¡¶ Óê Ù» Öñ ¡·" );
	set( "object", ([
		"file6"    : "/open/prayer/obj/boris-hands",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/castle/obj/blood-water",
		"amount5"  : 1,
		"amount1"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file3"    : "/open/sky/obj11/red-crystal",
		"file7"    : "/open/prayer/obj/boris-boots",
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "owner", "raymond" );
	set( "item_desc", ([
		"test" : @ITEM
ÕâÊÇ²âÊÔ
ITEM,
	]) );
	set( "build", 10131 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room98",
		"enter"     : "/open/clan/13_luck/room/room121",
	]) );
	set( "long", @LONG
[0m
[52m©°©¤©¤©¤©¤©´[0m
[52m©¦[57m Òä  Â® [52m©¦[0m     [33m¡¶[0m [36mÓê[0m Ù» [52mÖñ[0m [33m¡·[0m
[52m©À©¤©¤©¤©È©¦[0m   ÖñÖşÍ¬Òô£¬´Ë¡¶ÓêÙ»ÖñÖş¡·ÄËÊ¯Ö®Ğù
[52m©¦        ©¦[0mÓëÆäÆŞÓêÙ»Ë«ÆÜÖ®Ëù¡£Ê¯Ö®ĞùÉí¼¯½ü°ÙÄê¡õ[52m©¦[0m [56mË¼ ¶¨ [0m [52m©¦[0mÄ§¹¦´ó³É£¬³ıÁË±È½ğÖÓÕÖ¸üÇ¿µÄ[53mÌìÄ§½ğÉí[0mÍâ
[52m©¦        ©¦[0m×³Äê¸ü´´³öÎäÁÖÎÅÃûÉ¥µ¨µÄ[51m¶ñ»¯Ä§¹¦[0m(badforce)
[52m©¦©À©¤©¤©¤©È[0m
[52m©¦[0m  [33mÇ°Ìü [0m [52m©¦[0m        [35m»ìÔª»ìÉ±»÷[0m
[52m©¦        ©¦[0m
[52m©¸©¤©È©À©¤©¼[0m×Ô´Ë½­ºşÈË³Æ[31mĞ°Íõ[0m
    ´óÃÅ
[0m
´ËÖş½á¹¹·ÖÈı¾¶£¬ÓÉ´óÃÅ½øÀ´·Ö±ğÎª[33mÇ°Ìü[0m¡¢[56mË¼¶¨[0m¡¢[57mÒäÂ®[0m
È»ºóºóÃæ¾ÍÊÇĞ°ÍõºÍÆäÆŞµÄ[55m¹ë·¿[0mÁË
LONG);
	setup();
	replace_program(ROOM);
}
