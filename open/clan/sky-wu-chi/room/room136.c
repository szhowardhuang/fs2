inherit ROOM;
void create() {
	set( "short", "¿ÕÆ¿×ÓÎÔ·¿" );
	set( "object", ([
		"file7"    : "/open/killer/obj/knief3",
		"amount6"  : 46330,
		"amount7"  : 46302,
		"file1"    : "/open/dancer/obj/yuawaist",
		"amount5"  : 66411,
		"file8"    : "/open/killer/obj/lustar",
		"amount9"  : 16745,
		"file6"    : "/open/killer/obj/knief2",
		"amount1"  : 1,
		"file5"    : "/open/killer/obj/knife",
		"file9"    : "/open/killer/obj/needle",
		"amount8"  : 74076,
	]) );
	set( "owner", "ywarter" );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room137.c",
		"south"     : "/open/clan/sky-wu-chi/room/room134.c",
		"east"      : "/open/clan/sky-wu-chi/room/room133",
		"north"     : "/open/clan/sky-wu-chi/room/room135.c",
	]) );
	set( "long", @LONG
ÕâÀïÊÇÕâÕû¸ö×¯ÔºµÄÖ÷ÈË[1;37m¿ÕÆ¿×Ó[0mµÄÎÔÊÒ£¬ÀïÃæÆÓËØµÄ×ÔÈ»£¬Ò»µã
Ò²Ã»ÓĞÏñÊÇÓµÓĞ¾øÊÀÎäÑ§¼°¹ã´óµÄ×¯ÔºµÄµÄÈËËùÓ¦¸ÃÓĞµÄ»ªÀö£¬¼òµ¥
µÄÒ»ÕÅ´óÀíÊ¯Ô²×À¼°Ë«ÈËÍ¨ÆÌÍâ£¬ÆäËüµÄ¶¼²»ÖµÒ»Ìá¡£Î¨Ò»ÌØ±ğµÄÊÇ
Ç½ÉÏËù¹ÒµÄÒ»¶Ô×¦×Ó£¬ÏñÊÇÓĞµãÏñ¶¯ÎïÒ»ÑùµÄ×¦×Ó£¬µ«ÊÇÑÕÉ«È´ÊÇÓĞ
Èç»Æ½ğ°ãµÄÈÃÈË¸Ğ¾õ´ËÎï±Ø¶¨À´×ÔÌìÍâÖ®ÎïËùÓĞ£¬ÇÒÏñÊÇÓĞÁéĞÔ°ãµÄ
µ±ÄãÒ»×ß½øÀ´Ê±¾ÓÈ»·¢³öÎËÎËÎËµÄÉùÏì¡£ËÆºõ¶ÔÄãµÄ´³Èë¸Ğµ½ÓĞÖÖÍş
Ğ²¶øÒª×ö·´»÷µÄÉùÒô¡£

LONG);
	setup();
	replace_program(ROOM);
}
