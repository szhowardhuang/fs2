inherit ROOM;
void create() {
	set( "short", "ÇúÖÕÈËÉ¢" );
	set( "owner", "woan" );
	set( "object", ([
		"amount7"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"amount6"  : 1,
		"file4"    : "/obj/gift/lingzhi",
		"file6"    : "/obj/gift/lingzhi",
		"file3"    : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"file5"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10926 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room329",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
    ÄãÈÃËûÓÃ[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[0m°ÑÄãÌ×ÉÏµÄÊ±ºò£¬ÎÒ²ì¾õµ½ÄãÁ³ÉÏ¸´ÔÓµÄĞ¦
Èİ¡£ÄÇÔ­±¾¸ÃÊÇÎÒ£¬¸¶ÓèÄãµÄ³ĞÅµ£¬ÏÖÔÚÎÒÖ»ÄÜÒşÉíÈÈÄÖÖĞ¡£
ÎÒ¸ú×ÅËùÓĞÈËÏòÄã×£ºØµÄÊ±ºò£¬Ö»ÓĞÄãÖªµÀÎÒ¶àºÈÁË¼¸±­¾Æ¡£
ÎÒ²»ÄÜÔÙ¿´Äã£¬¶àÒ»ÑÛ¶¼ÊÇÍ´£¬¼´Ê¹ÖªµÀ°µµØÀïÄãÓÖ»ØÍ·¡£ÎÒ
ÖÕÓÚÖªµÀ[0;1;5;32m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mH[1;5m¡õ[1;5m¡õ[0mµÄ[0;1;31m¡õ[1mI[1m¡õ[1m¡õ[0m£¬Ö»ÓĞÉËĞÄÈË²ÅÓĞ£¬Äã×îºóÒ»Éíºì£¬
[0;1;30m¡õ[1m¡õ[1m¡õ[1md[0mÔÚÎÒÑÛÖĞ£¬ÎÒÃ»ÓĞÔÙ[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÄ½å¿Ú¡£Ô­À´Õâ¾ÍÊÇ[0;1;5;32m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mH[1;5m¡õ[1;5m¡õ[0mµÄ
[0;1;31m¡õ[1mI[1m¡õ[1m¡õ[0m¡£ÎÒ»¹ÏëµÈÄãÊ²Ã´£¬Äã½ô½ôÀ­×¡ÎÒ[0;1;36m¡õ[1m¡õ[1m¡õ[1mS[0m£¬ÓÖ·Å¿ªÈÃÎÒ×ß£¬
ÕâÒ»´Î¸úÎÒ[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¡£ 


LONG);
	setup();
	replace_program(ROOM);
}
