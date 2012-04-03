// Room : /open/clan/ou-cloud-club/room/room107.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "build", 11433 );
	set( "cmkroom", 1 );
	set( "long", @LONG
Ò»×ù¹ã´óÎŞÛóµÄ»¨Ô°£¬ËÄ´¦³ÂÁĞÁËĞí¶à×ğ¸ß´óµÄÊ¯Ïñ£¬        
Ô­À´´Ë´¦ÊÇ°×¼ÒÀú´úµÛ»ÊµÄÍõÁê£¬¶øÃ¿Ò»×ğÊ¯Ïñ£¬½ÔÊÇÀúÈÎ    
º£»¢ÎäÉñÔÚÁÙÖÕÇ°ÒÔ[0;1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1mq[0mÒÔ¼°[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÇ¿»¯±£»¤µÄ£¬Ëù    
ÒÔ²ÅÄÜ±£´æÇ§ÄêÖ®¾Ã£¬´«ËµµÚ[0;1;33m7[1m4[1m3[0m´úº£»¢ÎäÉñ-°×[0;1;32m¡õ[1mB[1m¡õ[1mK[0m¾ÍÊÇÔÚ    
´ËÁìÎòÎŞµĞµÄ[0;1;30m¡õ[1m¡õ[1m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mD[0mÒÔ¼°[0;1;36m¡õ[1m¡õ[1m¡õ[1mZ[1m¡õ[1m¡õ[1m¡õ[1mD[0mµÈ¾ªÊÀ¾øÑ§£¬¶øÕâ¸ü    
½«±ùÑæÒıµ¼½øÈë´Å³¡×ª¶¯µÄ[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬µ«ÓÉÓÚÎ´ÄÜÍêÈ«ÕÆÎÕ    
[0;1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1mq[0m´øÀ´µÄÇ¿´ó·´ÊÉ£¬·ÇÔÚÉúËÀ¹ØÍ·£¬±ùÑæ²»»áÇáÒ×ÔÚ    
ÈËÇ°Õ¹Ê¾ÕâĞ©´«ËµÖĞµÄÎäÑ§¡£

LONG);
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/ou-cloud-club/room/room14.c",
		"west"      : "/open/clan/ou-cloud-club/room/room32",
]) );
	set( "clan_room", "°ÁÔÆÉ½×¯" );
	set( "short", "Ä¥µ¶·»" );
	set( "object", ([
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/gsword/obj/yuskirt",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file7"    : "/daemon/class/fighter/armband",
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/scholar/obj/s_hands",
		"amount5"  : 1,
	]) );
	set( "owner", "moblade" );
	set( "light_up", 1 );
	setup();

	}
