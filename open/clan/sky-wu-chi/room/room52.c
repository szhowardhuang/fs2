// Room : /open/clan/sky-wu-chi/room/room52.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
ÑÛ¹ÛËÄÃæ£¬¶úÌı°Ë·½£¬À´µ½ÁË¶şÂ¥£¬²»½û¸Ğµ½
Ïë²»µ½ÊÀÉÏÃÀµÄµØ·½£¬¾¡ÊÇÔÚÑÛÇ°£¬ÕıÊÇ×ÔÒÑËùÉí
´¦µÄÊÀ½ç£¬Ïë²»µ½°ÑÑÛ¹â¿´µÃÔ¶Ò»µã£¬¾ÍÄÜµÃµ½Èç
´ËµÄÌå»á£¬ÄÇĞÄÀïÒ²Ïëµ½µÇ¸ß±Ø×ÔÃÖ£¬¾õµÃÈËÍâÓĞ
ÈË£¬É½ÍâÓĞÉ½£¬Õâ²ãµÀÀíÁË¡£

LONG);
	set( "short", "$HIC$Í¨Ìì¸ó¶şÂ¥$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/wu/npc/obj/armband",
		"file9"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
		"file7"    : "/open/port/obj/wolf_ring",
		"amount10" : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
	]) );
	set( "build", 10005 );
	set( "owner", "conpse" );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room40",
	]) );
	set( "light_up", 1 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "window" : "ÖĞÑëæäÕ¾ - 
    Õâ¶ù¾ÍÊÇ×î×î³öÃûµÄæäÕ¾£¬ïğ¾ÖµÄ³µ¶Ó, À´ÍùÓÚÉ³Ä®µÄÂæÍÕ¶Ó, Éõ
ÖÁÊÇÅ£ÂíÂâ³µ, ¼¸ºõÖ»ÒªÄã½ĞµÃ³öÃû×ÖµÄ½»Í¨¹¤¾ßÕâ¶ù¶¼ÓĞ¡£
    °×ÔÆÔÚÌì¿ÕÖĞÆ®À´Æ®È¥¡£
    Ì«Ñô¸Õ´Ó¶«·½µÄµØÆ½ÏßÉıÆğ¡£
   ¡¸[14mĞ¡À±½·[0m¡±Âô»ğ²ñµÄĞ¡À±ÃÃ(Sale girl)




¨ß¡«¡«¡«Õâ±ß¿´µÃµ½ÖĞÑëæäÕ¾Ò®
",
]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "ÌìµÀÎŞ¼«" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
