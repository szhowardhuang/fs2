inherit ROOM;
void create() {
	set( "short", "Çà¶ùÎÔ·¿" );
	set( "light_up", 1 );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/fire-ball",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/magic-manor/obj/wood-ball",
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"file3"    : "/open/capital/guard/gring",
		"file10"   : "/open/magic-manor/obj/soil-ball",
		"file4"    : "/open/capital/guard/gring",
		"amount4"  : 1,
	]) );
	set( "owner", "ywarter" );
	set( "build", 12000 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room136",
	]) );
	set( "long", @LONG
ÕâÀïÊÇ¿ÕÆ¿×ÓµÄ·òÈË[1;37m¡®[1;36mÇà¶ù[1;37m¡¯[0mµÄÎÔÊÒ£¬µ±ÄãÒ»×ß½øÕâÀïÊ±ÄãÎÅµ½ÁË
Ò»¹ÉÇåµ­µÄ×ÏÂŞÀ¶ÏãÎ¶£¬ÔÚÆäÎÔÊÒÖĞ¼äÓĞÒ»ºìÄ¾µÄÄ¾µñÔ²×À£¬ÉÏÃæ·Å×Å
Ò»°Ñ¿´ËÆÓĞºÃ³¤Ò»¶ÎÀúÊ·µÄ¹Åóİ£¬Äã²¦ÁËÒ»²¦óİÏÒ£¬·¢³öÁËÒ»Õóï¬µÄÉù
Òô£¬Äã¶ÙÊ±¾õµÃÄÇÕæÊÇÒ»°ÑºÃÇÙ¨Ú£¬ÔÚ¿´¿´ÆäÇ½ÉÏ¹ÒÓĞÒ»°Ñ[1;37m¡®[1;34mº®²Ô¹­[1;37m¡¯[0m
ËÆÒ²ÏñÓĞÁéĞÔ°ãµÄ·¢³ö±ùÀäµÄ¹âÏß¡£Õû¼ä·¿¼äÀïÍ·ÓĞÒ»Ğ©»¨»¨²İ²İ¶¼ºÃ
ÏñÊÇÄãÍêÈ«Ã»¼û¹ıµÄÒ»Ñù£¬ÈÃÄã¸Ğµ½¾ªÑÈÍò·Ö¡£´ËÊ±ÄãµÄĞÄÀïÍ·Ïë×Å¿Õ
Æ¿×ÓµÄ·òÈË¿´À´Ò²ÊÇÍòÖĞÑ¡Ò»µÄºÃÅ®×Ó¡£

LONG);
	setup();
	replace_program(ROOM);
}
