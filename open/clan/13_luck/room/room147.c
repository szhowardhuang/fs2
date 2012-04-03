inherit ROOM;
void create() {
	set( "short", "Ğ¡Ö¾ĞŞÁ·Çø" );
	set( "owner", "mwf" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/daemon/class/blademan/obj/shield",
		"file2"    : "/open/snow/obj/figring",
		"amount10" : 1,
		"amount5"  : 1,
		"file8"    : "/open/scholar/obj/icefan",
		"file7"    : "/open/wu/npc/obj/armband",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"file1"    : "/open/port/obj/wolf_ring",
		"amount1"  : 1,
		"file10"   : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "build", 10001 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room113",
	]) );
	set( "long", @LONG
ÕâÀïµ½´¦²¼ÂúÁË[0;1;35m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬ÔÚ¿ÕÆøÖĞÓÖ´ø×Å[0;1;33m¡õ[1mC[1m¡õ[1m¡õ[0m£¬¸Ğ¾õ
¾ÍºÃÏñµ½ÁËÒ»´¦½£Ê¿µÄĞŞÁ·Çø£¬ÔÚÔ¶´¦ÓĞÒ»µÀ¸ß´óµÄÈË
Ó°£¬×ĞÏ¸Ò»¿´Ô­À´ÊÇ[0;1;36m¡õ[1mp[1m¡õ[1m¡õ[0mÔÚÄÇÀïĞİÏ¢£¬Ô­À´ÕâÀïÊÇ[0;1;36m¡õ[1mp[1m¡õ[1m¡õ[0m
µÄ[35mÁ·¹¦Çø[0mºÍ[35mĞİÏ¢Çø[0m¡£
LONG);
	setup();
	replace_program(ROOM);
}
