inherit ROOM;
void create() {
	set( "short", "ÈÀÍâ¶¨½®Â¥" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 14901 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room180",
		"down"      : "/open/clan/13_luck/room/room162.c",
	]) );
	set( "long", @LONG

    [0;1;33m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mN[1m¡õ[1m¡õ[1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mA[1m¡õ[1mX[1m¡õ[1m{[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m_[1m¡õ[1mH[1m¡õ[1m@[1m¡õ[1m¡õ[1;36m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1mP[1;37m¡õ[1m@[1m¡õ[1m¡õ[1;32m¡õ[1ms[1;37m¡õ[1mA[1m¡õ[1mb[1m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mN[0m
[0;1;37m¡õ[1m¡õ[0m³ÉÁ¢Ö®³õ£¬°Ù·Ï´ıĞË£¬µ±Ê±¾ÍÓÉ´ËÁ½ÈË°ï×ÅÊ®Èı¼ªÏéÔÚÍâ´òÏìÃûÉù
£¬À©´ó°ïÅÉÊÆÁ¦£¬³É¾ÍÁËÏÖÔÚµÄÊ®Èı¼ªÏé£¬µ«´ËÁ½ÈËÔÚ¹¦³Éºó¾ÍÉíÍË
ÁË£¬ÏĞÔÆÒ°º×²»¹Ü°ïÎñ£¬¶ÔÓÚËûÃÇµÄ³É¾Í½«ÊÇ°ïÖÚ½«ÓÀ¼ÇÓÚĞÄ¡£ 

LONG);
	setup();
	replace_program(ROOM);
}
