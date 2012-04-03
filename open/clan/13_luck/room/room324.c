inherit ROOM;
void create() {
	set( "short", "ËøÁú¿ß" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/capital/guard/gring",
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/lingzhi",
		"file7"    : "/open/mogi/castle/obj/leave",
		"file9"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount3"  : 44,
		"amount9"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-kill-claw",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount8"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"file6"    : "/open/capital/room/king/obj/dagger1",
		"file2"    : "/obj/gift/xiandan",
	]) );
	set( "owner", "fighter" );
	set( "build", 10395 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room276",
	]) );
	set( "long", @LONG

    Ò»ÕóÒõÉ­µÄ¸Ğ¾õÏ®À´£¬Ì¤Èë´Ë¶´Ö®ÖĞ£¬ĞÄÀï¸Ğµ½ÕóÕóµÄ²»°²£¬Ò»
ÉùÉùµÄÌúÁ´ÖØ»÷Éù²»¾øÓÚ¶ú£¬²»Ê±Ò²´«³öÕóÕóÅ­ºğÉù£¬±»À§ÓÚÄ§½ç½û
µØ[35mµØµ×ÀÎÁı[0mÖĞµÄ[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ms[0m(Goldendragon)£¬±»[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1mi[1;36m¡õ[1mi[1m¡õ[1m¡õ[1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1;31m¡õ[1mj[0mÖØ
´´ºó£¬±ãÒ»Ö±±»½ûïÀ´Ë´¦£¬ÎŞ·¨ÔÚÎ£º¦ÊÀÈË¡£


LONG);
	setup();
	replace_program(ROOM);
}
