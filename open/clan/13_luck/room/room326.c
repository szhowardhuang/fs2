inherit ROOM;
void create() {
	set( "short", "Â·±êÇø" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount1"  : 27,
		"file8"    : "/daemon/class/blademan/obj/ublade",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/gsword/obj/ring-1",
		"amount6"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/ping/obj/poison_pill",
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/scholar/obj/icefan",
	]) );
	set( "owner", "woan" );
	set( "build", 11454 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room123.c",
		"west"      : "/open/clan/13_luck/room/room159",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
    ½øÀ´ºó..Äã¿´µ½Ò»¸ö±êÊ¾ÅÆ..ÉÏÃæĞ´×Å
      
       ÏëÌıwoan [0;1;31m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1m|[0mµÄÇëÍùÎ÷
      
       Ïë¿´woan [0;1;33m¡õ[1mm[1m¡õ[1m\[1m¡õ[1m¡õ[0mµÄÇëÍø¶« 
´ËÊ±ÄãÏë.woanÉíÎªÒ»¸ö[0;1;5;36m¡õ[1;5mT[1;5m¡õ[1;5mM[1;5m¡õ[1;5my[1;5;32m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mH[0m
ÓĞ[0;1;33m¡õ[1mm[1m¡õ[1m\[1m¡õ[1m¡õ[0m²»×ãÎªÆæ..µ«..Ò»¸öµ¶¿Í¾¹»á¿ª
[0;1;31m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1m|[0m...ÄãÒ²¾õµÄ.²»¿ÉÏàĞÅ.µ«.Ò»ÌõÌõ
[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÄ¸èÇú´òÂÒÁËÄãµÄË¼Ğ÷..¶øÄãËù²»Ïà
ĞÅµÄÊÂ.È´Ò»Ò»µÄ±äÊÂÊµÁË.¶øÄãÖ»Ïë×öÒ»
¼şÊÂ.¾ÍÊÇ¹ıÈ¥ÌıºÃÌıµÄ¸èÇú.


LONG);
	setup();
	replace_program(ROOM);
}
