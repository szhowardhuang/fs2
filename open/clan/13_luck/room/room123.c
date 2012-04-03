inherit ROOM;
void create() {
	set( "short", "ì­³µ¹ã³¡" );
	set( "owner", "woan" );
	set( "object", ([
		"file5"    : "/open/love/obj/cloth1",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 1,
		"file9"    : "/open/port/obj/wolf_ring",
		"file8"    : "/open/wu/npc/obj/armband",
		"file6"    : "/open/gsword/obj/ring-1",
		"file3"    : "/open/gsword/obj/yau_glove",
		"file4"    : "/open/wu/npc/obj/armband",
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount1"  : 47,
		"amount3"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/wu/npc/obj/armband",
		"amount10" : 1,
		"amount7"  : 1,
		"file10"   : "/open/gsword/obj/yuskirt",
	]) );
	set( "build", 10134 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room326",
		"south"     : "/open/clan/13_luck/room/room98.c",
	]) );
	set( "long", @LONG
ÑÛ¼û[0;1;30m¡õ[1m@[1m¡õ[1m¡õ[1m¡õ[1mL[1m¡õ[1m¡õ[0mµÄÂ·ÉÏ£¬Ö»¼ûÒ»Ì¨[0;1;5;36mS[1;5mV[0mÔÚÖĞì­³µ´©Ëõ£¬µ«´ËÂ·Ö®
³¤£¬·ÇÒ»Á½¸öĞ¡Ê±¿ÉÒÔ×ßÍêµÄ£¬µ«ÊÇÕâÌ¨[0;1;5;36mS[1;5mV[0mÔÚÖĞ´©Ëõ£¬À´»ØÈ´²»
ÓÃÒ»·ÖÖÓ£¬¿ÉÖªÕâÃû[0;1;34m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1mh[0mµÄÄÜÄÍ¸úÕâÌ¨[0;1;5;36mS[1;5mV[0mµÄÂíÁ¦£¬¶øÄãÍùÇ°
ÔÚ×ßÈ¥£¬¿´µ½Ò»¶ÑÒ»¶ÑµÄ[32mÀä¶³Ïä[0m£¬¶øÓĞ¸öÃÅÉÏÃæĞ´×Å¡£
  
             [0;1;5;31m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0;1;35m¡õ[1mh[1m¡õ[1mh[1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mq[0m
         
         [0;1;5;36mP[1;5mS[1;5m.[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m~[1;5m¡õ[1;5mL[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mA[1;5m1[1;5m¡õ[1;5mp[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mt[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5me[1;5m¡õ[1;5mF[0m

LONG);
	setup();
	replace_program(ROOM);
}
