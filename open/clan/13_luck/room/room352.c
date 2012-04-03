inherit ROOM;
void create() {
	set( "short", "ÓãÁúÊÒ" );
	set( "owner", "max" );
	set( "object", ([
		"file2"    : "/open/gsword/obj/yuskirt",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file6"    : "/open/killer/obj/k_ring",
		"amount5"  : 1,
		"file9"    : "/daemon/class/fighter/armband",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount3"  : 1,
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"amount8"  : 1,
		"file3"    : "/daemon/class/blademan/obj/ublade",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount9"  : 1,
		"amount1"  : 2,
		"file5"    : "/open/mogi/village/obj/mogi_ring",
		"amount2"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10170 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room351.c",
		"west"      : "/open/clan/13_luck/room/room350",
		"out"       : "/open/clan/13_luck/room/room347.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    Ò»½øÈë´ËÊÒÖÐ£¬Ö»¼ûÇ½ÉÏ¹Ò×ÅÒ»°Ñ[0;1;33m¡õ[1m¡õ[1m¡õ[1ms[0m(Ublade)£¬µ¶ÉÏ¿Ì×ÅÒ»Ð©
Ï¸Ï¸Ð¡Ð¡µÄ×Ö£¬×ÐÏ¸¿´È¥Ô­À´ÊÇÄ§µ¶¡®ÈýÕ¶¹éÔª¡¯µ¶·¨Ö®Ò»£¬Š…ÔËÓÃ
¾ÅµØÖ®Æø£¬Ê¹³ö[35m¡¾ÈýÕ¶¹éÔª¡«ÓãÁúÊÈÔª¡¿[0m¡®[0;1;33m¡õ[1m¡õ[1;36m¡õ[1ms[1;33m¡õ[1mr[1;36m¡õ[1m}[0m¡«¡«[0;1;33m¡õ[1m¡õ[1;35m¡õ[1mP[1;32m¡õ[1mO[1;31m¡õ[1m¡õ[0m¡¯
ÃØÖäÓïÒôÓÌÔÚ¶ú£¬ö®ÄÇ¼ä£¬´Ó[0;1;33m¡õ[1m¡õ[1m¡õ[1ms[0m´Ü³ö¾Å²ÊÑÌÎí£¬Ë²Ê±±ßÅÔÖÜÎ§µÄÉú
ÎïËÀÖ®´ù¾¡¡£[0;1;33m¡õ[1mA[1m¡õ[1mB[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1mA[1m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1mu[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mu[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mX[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1mb[1m¡õ[1m¡õ[1m¡õ[1mc[1m¡õ[1mT[0m
[0;1;33m¡õ[1m¡õ[1m¡õ[1mx[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[1m¡õ[1mA[1m¡õ[1ml[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mr[1m¡õ[1m¡õ[1m¡õ[1mB[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1mA[1m¡õ[1mK[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1mb[1m¡õ[1m¡õ[1m¡õ[1mo[1m¡õ[1mX[1m¡õ[1m¡õ[1m¡õ[1mH[0m
[0;1;33m¡õ[1mb[1m¡õ[1mr[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1mn[1m¡õ[1m|[1m¡õ[1m¡õ[1m¡õ[1mC[0m


LONG);
	setup();
	replace_program(ROOM);
}
