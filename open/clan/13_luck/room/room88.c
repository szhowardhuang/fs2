inherit ROOM;
void create() {
	set( "short", "ÀË×Ó¾ÓÕıµî" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/daemon/class/fighter/figring",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file9"    : "/open/wu/npc/obj/armband",
		"file5"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount7"  : 1,
	]) );
	set( "owner", "roar" );
	set( "light_up", 1 );
	set( "build", 12380 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room86.c",
		"west"      : "/open/clan/13_luck/room/room103.c",
		"north"     : "/open/clan/13_luck/room/room186",
		"east"      : "/open/clan/13_luck/room/room117.c",
	]) );
	set( "long", @LONG
Îİ¶¥±¦[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÄÁğÁ§Íß±»ÖËÈÈµÄ[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÕÕµÄÉÁÉÁ·¢ÁÁ£¬Á½ÅÔÁ½Í·¾Ş´óµÄ[0;1;30m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ml[0m£¬
ÕòÊØ×Å¡®[0;1;35m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1m~[0m¡¯µÄÕıÃÅ¡£ÏòÄÚÍûÈ¥£¬Äã²»¾­ÏÅÁËÒ»Ìø£¬ÄÚ²¿µÄ×°äê°ÚÉè²»Êä¸ø
µ±½ñµÄ[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¡£´óµîµÄÉÏÊ×ØùÁ¢×ÅÒ»µÀ[0;1;30m¡õ[1mH[1m¡õ[1mv[0m£¬ÕâÈËÈÃÈËÓĞÄªÃûµÄ¾´Î·¸Ğ£¬ÆäÈ«ÉíÉ¢
·¢×ÅÇ¿ÁÒµÄ[0;1;5;32m¡õ[1;5mM[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mQ[1;5m¡õ[1;5m¡õ[0m¡£Õâ¹É°ÔÆø×ãÒÔ³Æ[0;1;5;31m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0mÕû¸ö[0;1;5;31m¡õ[1;5mZ[1;5m¡õ[1;5mL[0m£¬²»¶ÔÈÎºÎÈË·şÊä¡£Ëûµ½µ×
ÊÇË­£¿Ëû¾ÍÊÇ[0;1;35m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1m~[0mµÄÖ÷ÈË£¬ÈÃÎäÁÖÈËÊ¿[0;1;36m¡õ[1mD[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mx[0mµÄ[0;1;5;32m¡õ[1;5mM[1;5m¡õ[1;5m¡õ[0m--[0;1;5;34m¡õ[1;5m¡õ[1;5m¡õ[1;5m][1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5ml[0m¡£
LONG);
	setup();
	replace_program(ROOM);
}
