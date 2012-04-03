inherit ROOM;
void create() {
	set( "short", "¼ªÏéÖÃÎïÏä¸ı" );
	set( "object", ([
		"file9"    : "/open/killer/obj/dagger",
		"amount1"  : 7338,
		"file1"    : "/open/killer/obj/lustar",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/dancer/obj/yuawaist",
		"file4"    : "/open/mogi/castle/obj/leave",
		"file3"    : "/open/mogi/castle/obj/fire_book",
		"file8"    : "/open/port/obj/wolf_ring",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"file5"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "owner", "pigdevil" );
	set( "build", 10122 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room305",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ[0;1;32m¡õ[1mN[1m¡õ[1m¡õ[1m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1md[1m¡õ[1m¡õ[0m£¬×¨ÃÅÎª»¹Ã»ÓĞ·¿¼äµÄĞÂ½ø°ïÖÚËùÉèÁ¢µÄ£¬´Ë
»·¾³ÓÅÑÅÊæÊÊ£¬ÈÃĞÂ½øµÄ°ïÖÚÓĞ¸ö¿ÉÒÔÈ¥µÄµØ·½¸úĞİÏ¢µÄµØ·½£¬Ê¹ËûÃÇ
¿ìµã³ÉÎªÊ®Èı¼ªÏéµÄÕ½Á¦£¬Ò»ÆğÎª°ïÅÉµÄÎ´À´¶øÅ¬Á¦£¬Ò»Í¬´òÆ´£¬ÈË¾Ó
ÓñÓîÇ§ÄêÃ¯£¬ÈÕÓ¡»ªÌÃ°ÙÒµĞË£¬Ï£ÍûÄÜÎªÌìÏÂµÚÒ»´ó°ï¶øÂõ½ø¡£

LONG);
	setup();
	replace_program(ROOM);
}
