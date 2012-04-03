inherit ROOM;
void create() {
	set( "short", "ÖìÈ¸×ßÀÈ" );
	set( "owner", "tanger" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "object", ([
		"amount6"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file3"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount7"  : 1,
		"file5"    : "/daemon/class/fighter/armband",
		"amount9"  : 1,
		"file4"    : "/open/prayer/obj/boris-cloth",
		"amount4"  : 1,
		"file1"    : "/open/dancer/obj/yuaboots",
		"file9"    : "/open/scholar/obj/icefan",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/ping/obj/ring-2",
		"amount10" : 1,
		"amount3"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount8"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/capital/room/king/obj/km-cloak",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 12120 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room75.c",
		"north"     : "/open/clan/sky-wu-chi/room/room151",
	]) );
	set( "long", @LONG
Äã×ß½øÁËÒ»¸öÃûÎª[1;37m¡®[1;31mÖìÈ¸[1;37m¡¯[0m×ßÀÈµÄµØ·½£¬Äã²Å¸Õ×ß½øÀ´ÕâÀïÊ±ÄãÂíÉÏ
·¢ÏÖËÄÖÜµÄ¿ÕÆøÒòÎªÌ«¸ÉÔï¶ø²úÉúÒ»ÖÖ±¬ÁÑµÄÉùÒô£¬Äã×ĞÏ¸µÄÏëÁËÒ»ÏÂÎª
Ê²Ã´»áÕâÑù×Ó£¬ÔÚ¿´ÁËÒ»ÏÂËÄÖÜ¶¼ÊÇÓÃ»ğºìµÄÈÛÑÒËù×ö³ÉµÄ£¬ÂíÉÏÏëµ½Õâ
Àï¾ÍÊÇÊôÓÚÄÏ·½µÄÖìÈ¸Ö®ËùÔÚ£¬Äã¿ªÊ¼¾õµÃºÜÈÈ£¬ÇÒÔ½×ß½øÈ¥Äã·¢¾õÈÈ¶È
ÊÇÔ½À´Ô½¸ß£¬½¥½¥µÄÄãÒ²¿ìÊÜ²»ÁË£¬Í»È»¼äÄã¿´µ½ÁËÒ»Ö»»ğ·ï»Ë¾ÍÔÚÇ°Ãæ
ÕıÔÚÊáÀí ­×Ô¼ºµÄÓğÃ«£¬µ±Ëû¿´µ½ÄãÊ±£¬ ­ÖÜÎ§µÄ»ğÑæ¾ÍÍ»È»µÄÉÕµÄ¸üÁÒ
ÁËÆğÀ´£¬ºÃÏñÊÇÔÚÄãËµÒÑ¾­´³ÈëÁË²»¸Ã´³ÈëµÄµØ·½ËÆµÄ¡£

LONG);
	setup();
	replace_program(ROOM);
}
