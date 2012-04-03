inherit ROOM;
void create() {
	set( "short", "Ğ¡ÖíÍ·µÄ¼Ò" );
	set( "owner", "pighead" );
	set( "object", ([
		"amount6"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/tendo/obj/chaosbelt",
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"amount10" : 1,
		"amount1"  : 1,
		"file2"    : "/daemon/class/fighter/figring",
		"file9"    : "/daemon/class/fighter/armband",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount2"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/gsword/obj/may_ring",
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11194 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room90",
		"enter"     : "/open/clan/13_luck/room/room127",
	]) );
	set( "long", @LONG

    ÕâÀï¾ÍÊÇ´«ËµÖĞµÄ[0;1;33m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mN[1m¡õ[1m¡õ[0mÕò°ïÖíÍ·£¬[0;1;36m¡õ[1mi[1m¡õ[1mR[1m¡õ[1mp[1m¡õ[1m¡õ[1m¡õ[1mY[0mµÄ¼Ò£¬ÓĞÓÚÊÜ
µ½[0;1;33m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mN[1m¡õ[1m¡õ[0m¸÷Î»Ç°±²µÄ°ïÃ¦£¬Ğ¡ÖíÍ·²ÅÄÜ³¤´ó³ÉÎª´óÖíÍ·£¬ÆÚ´ıÓĞÒ»
ÌìÒ²ÄÜºÍÇ°±²Ò»Ñù£¬´³µ´½­ºş´ò±éÌìÏÂÎŞµĞÊÖ£¬²¢ÇÒ°ïÖú°ïÄÚµÄ»ï°é
ÃÇ£¬¾ÍÏñÇ°±²µ±³õ°ïÖúĞ¡ÖíÍ·Ò»Ñù£¬ÈÃ[0;1m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mN[1m¡õ[1m¡õ[0m³ÉÎªµÚÒ»´ó°ïÅÉ¡£


LONG);
	setup();
	replace_program(ROOM);
}
