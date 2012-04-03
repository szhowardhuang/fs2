inherit ROOM;
void create() {
	set( "short", "Ñ©Ó°ÊÒ" );
	set( "owner", "max" );
	set( "object", ([
		"file3"    : "/daemon/class/blademan/obj/iceblade",
		"file2"    : "/open/mogi/village/obj/mogi_ring",
		"file7"    : "/open/killer/obj/k_ring",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/daemon/class/blademan/obj/six-neck",
		"file1"    : "/open/killer/obj/k_ring",
		"amount4"  : 1,
	]) );
	set( "build", 10614 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room352",
	]) );
	set( "long", @LONG

    Ò»½øÈë´ËÊÒÖĞ£¬Ö»¼ûÇ½ÉÏ¹Ò×ÅÒ»°Ñ[0;1;36m¡õ[1m¡õ[1m¡õ[1mv[0m(Iceblade)£¬µ¶ÉÏ¿Ì×ÅÒ»
Ğ©Ï¸Ï¸Ğ¡Ğ¡µÄ×Ö£¬×ĞÏ¸¿´È¥Ô­À´ÊÇÄ§µ¶¡®ÈıÕ¶¹éÔª¡¯µ¶·¨Ö®Ò»Š…Ê©Õ¹
¾ÅÈËÖ®Æø£¬Ê¹³ö[35m¡¾ÈıÕ¶¹éÔª¡«Ñ©Ó°»¯Ôª¡¿[0m¡®[0;1;33m¡õ[1mg[1;36m¡õ[1ms[1;33m¡õ[1m¡õ[1;36m¡õ[1m_[0m¡«¡«[0;1;36m¡õ[1m¡õ[1;35m¡õ[1mv[1;37m¡õ[1mH[1;36m¡õ[1m¡õ[0m¡¯
Š…ÔËÆğÕæÔª£¬ÊÖ³Ö[0;1;36m¡õ[1m¡õ[1m¡õ[1mv[0mÍùÌìÒ»»Ó£¬¶ÙÊ±£¬É½Ò¡µØ¶¯£¬·çÔÆ±äÉ«£¬ÒÔÈÅ
ÂÒÁËËÄ¼¾µÄÔË×ª£¬²ÔÌìÍ»È»µØÆ®ÏÂÂşÌìÑ©²Ê¡£[0;1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1mA[1m¡õ[1mu[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mc[1m¡õ[1mT[0m
[0;1;36m¡õ[1m¡õ[1m¡õ[1mx[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mw[1m¡õ[1mQ[1m¡õ[1mM[1m¡õ[1mb[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mM[1m¡õ[1mb[1m¡õ[1mA[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mL[1m¡õ[1mA[1m¡õ[1ms[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mm[0m
[0;1;36m¡õ[1mA[1m¡õ[1mu[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mu[1m¡õ[1m¡õ[1m¡õ[1mx[1m¡õ[1mb[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mC[0m

LONG);
	setup();
	replace_program(ROOM);
}
