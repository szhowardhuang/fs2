inherit ROOM;
void create() {
	set( "short", "Ğ¡Ö¾µÄ¼Ò" );
	set( "owner", "mwf" );
	set( "object", ([
		"amount9"  : 160,
		"amount1"  : 1,
		"file4"    : "/obj/gift/lingzhi",
		"file2"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount5"  : 29,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 1,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"file10"   : "/open/fire-hole/obj/g-pill",
		"amount4"  : 1,
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 1,
		"amount8"  : 38,
		"amount10" : 10,
		"file1"    : "/obj/gift/xiandan",
	]) );
	set( "build", 12169 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room94",
		"enter"     : "/open/clan/13_luck/room/room147",
	]) );
	set( "long", @LONG
´Ë´¦µ½´¦²¼ÂúÁË[0;1;35m¡õ[1mC[1m¡õ[1m¡õ[0m£¬ÔÚµØÉÏ³äÂúÁË½£ºÛ£¬ºÃÏñÓĞ
ÈËÔÚÕâĞŞÁ·ÁËºÜ¾ÃµÄÑù×Ó£¬×ĞÏ¸Ò»¿´Ô­À´ÊÇ[0;1;33m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mN[1m¡õ[1m¡õ[0mµÄ
           ¡¸[0;1;36m¡õ[1mC[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¡±[0;1;31m¡õ[1mp[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
ÔÚµØÉÏÓĞÒ»¿éÊ¯±®ÉÏÃæĞ´×Å£º
      ·ÇÇëÎğÈëÕß...Ö»ÓĞÒ»ÌõÂ·  
               ¡®[0;1;31m¡õ[1m¡õ[0m¡¯
            [0;1;36m*[1m^[1m_[1m^[1m*[1m.[1m.[1m¡õ[1mp[1m¡õ[1m¡õ[1m.[1m.[0m
LONG);
	setup();
	replace_program(ROOM);
}
