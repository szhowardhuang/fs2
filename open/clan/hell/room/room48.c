inherit ROOM;
void create() {
	set( "short", "$HIW$ºÚÂÖÎÔ·¿ - $HIC$·À¾ßÊÒ$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file4"    : "/open/killer/obj/k_ring",
		"amount1"  : 1,
		"file3"    : "/open/killer/obj/k_ring",
		"amount4"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"file2"    : "/open/killer/obj/k_ring",
		"amount3"  : 1,
	]) );
	set( "build", 10224 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room41.c",
		"south"     : "/open/clan/hell/room/room52",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÕâÀï±ãÊÇ·¿¾ßÊÒÁË£¬ÕâÀïÂúÊÇÄÑµÃÒ»¼ûµÄ·¿¾ß
²»ÂÛÊÇ[0;1;32m¡õ[1mK[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¡¢[0;1;37m¡õ[1;31m¡õ[1;37m¡õ[1;31m\[1;37m¡õ[1;31m¡õ[0m¡¢ÉõÖÁ[0;1;31m¡õ[1mI[1m¡õ[1m¡õ[1;37m¡õ[1m][1m¡õ[1m¡õ[0mËù´©´÷Ö®·¿
¾ß£¬¶¼Ã»ÓĞÒÅÂ©£¬Äã²»½ûĞÄÏë¾¿¾¹ºÚÂÖÊÇÓĞºÎÍ¨Ìì
µÄ±¾ÁìÄÜÈ¡µÃÕâĞ©¶«Î÷°¢£®

LONG);
	setup();
	replace_program(ROOM);
}
