inherit ROOM;
void create() {
	set( "short", "·çÔÆ¸óÈë¿Ú" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
		"file6"    : "/open/capital/obj/chen_dagger",
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
	]) );
	set( "owner", "smalloo" );
	set( "build", 11214 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room76.c",
		"enter"     : "/open/clan/13_luck/room/room339",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    Ó³ÈëÄãÑÛÁ±µÄÊÇÒ»´±[0;1;30m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mv[0m£¬ËäÈ»Ã»ÓĞµñÁú·ÉÖù£¬µ«ÊÇ£¬ÃÅ
È´ÊÇÓÃ[0;1;34m¡õ[1m¡õ[0m¸ú[0;1;36m¡õ[1m¡õ[0mÁ½¸ö×ÖËù×öµÄÈë¿Ú¶øÔÚ[0;1;34m¡õ[1m¡õ[0m¸ú[0;1;36m¡õ[1m¡õ[0mÁ½¸ö×ÖÉÏÃæĞ´ÕâÒ»¾ä»°£¬
       [0;1;5;32m¡õ[1;5m¡õ[1;5m [1;5m [1;5m [1;5m¡õ[1;5m][1;5m [1;5m [1;5m [1;5m¡õ[1;5m¡õ[1;5m [1;5m [1;5m [1;5m¡õ[1;5m¡õ[0m
       [0;1;5;31m¡õ[1;5m¡õ[1;5m [1;5m [1;5m [1;5m¡õ[1;5m][1;5m [1;5m [1;5m [1;5m¡õ[1;5m¡õ[1;5m [1;5m [1;5m [1;5m¡õ[1;5m¡õ[0m
 
ÒÙÁ¢ÓÚÒ»´óÆ¬¿õÒ°ÉÏ£¬ÏÔµÃ¸ñÍâÆøÅÉÍşÎä£¬´ËÊ±Î¢·çĞìĞì´µÀ´£¬
ÌìÉÏµÄÔÆ²ãÒ²ÓĞµã¶ùÆ®ºö²»¶¨£¬ÁîÄã¾õµÄ[0;1;35m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mq[1m¡õ[1mM[1m¡õ[1mC[0m


LONG);
	setup();
	replace_program(ROOM);
}
