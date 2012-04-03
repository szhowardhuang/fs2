inherit ROOM;
void create() {
	set( "short", "Éñ·çÌÃ´óÃÅ" );
	set( "object", ([
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 61,
		"file1"    : "/obj/gift/shenliwan",
		"amount3"  : 47,
		"file7"    : "/open/sky/obj8/summer_wind",
		"file5"    : "/open/capital/obj/chen_dagger",
		"amount1"  : 1,
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"amount4"  : 1,
		"file6"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "owner", "smalloo" );
	set( "build", 10929 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room332",
		"north"     : "/open/clan/13_luck/room/room333",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ÄãÊÕ»Ø[0;1;33m¡õ[1m¡õ[1m¡õ[1mO[0m£¬Í£ÁËÏÂÀ´£¬¿´µÄÇ°Ãæ£¬Äã»»ÏëÖÖµÄµØ·½µ½ÁË£¬[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;34m¡õ[1m¡õ[0m´óÃÅÄË¼á¹ÌÖ®¼«µÄ[0;1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[0mËùÖÆ£¬ÏâÒÔ[0;1;30m¡õ[1mK[1m¡õ[1m¡õ[0m£¬Ç¶ÒÔ[31mÍ­¶¤[0m£¬´óÃÅ»¹µñ×Å´«
ËµÖĞµÄÉñ»°ÈËÎï----[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬ÑÏËàÄş¾²£¬[0;1;5m¡õ[1;5mH[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m{[1;5m¡õ[1;5m¡õ[0m£¬Ê¹Äã²»½ûµÄÑÏËà
ÁËÆğÀ´¡£ 


LONG);
	setup();
	replace_program(ROOM);
}
