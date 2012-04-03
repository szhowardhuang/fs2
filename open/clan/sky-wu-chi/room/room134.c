inherit ROOM;
void create() {
	set( "short", "ÃÀåúµÄÎÔÊÒ" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount10" : 1,
		"amount7"  : 1,
		"file1"    : "/daemon/class/fighter/ywhand",
		"file10"   : "/daemon/class/fighter/armband",
		"file6"    : "/open/gsword/obj/yuskirt",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/prayer/obj/boris-cloth",
		"amount5"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "light_up", 1 );
	set( "owner", "ywarter" );
	set( "build", 12000 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room136",
	]) );
	set( "long", @LONG
ÕâÀïÊÇ¿ÕÆ¿×ÓµÄ·òÈË[1;37m¡®[1;35mÃÀåú[1;37m¡¯[0mµÄÎÔÊÒ£¬µ±ÄãÒ»×ß½øÕâÀïÊ±Äã¾Í¸ĞÊÜ
Ò»ÖÖÖ»ÓĞÆæÌØÅ®×Ó²ÅÓĞµÄÏãÎ¶£¬ÄÇÒ»ÖÖÏãÎ¶²¢²»ÊÇºÜÖØºÜÖØµÄÄÇÖÖÏãÎ¶
¶øÊÇÒ»ÖÖ×ÔÈ»µÄÌåÏã£¬ÒòÎªÈËÃÇÓÖ½ĞËıÎª¡®Ïãåú¡¯¡£ÇÒÓÖÒòÎªËıÊÇÊ¹ÓÃ
µ¶µÄ×¨¼Ò£¬ËùÒÔÈËÃÇÓÖÒ²½ĞËû[1;37m¡®[1;36m¾ø»êµ¶¼§[1;37m¡¯[0m£¬ËûÓĞÒ»°ÑÉÏ¹ÅÃûÆ÷£¬´Ëµ¶
¿ªÇÊºóÒ»¶¨Òª¼ûÑª¡£Õâ°Ñµ¶¾ÍÊÇ[1;37m¡®[1;33mÌ«»Êµ¶©¤[1;34mÀ¶ÑÀ[1;37m¡¯[0m¶øÕâ°Ñµ¶Ò»¶¨ÒªÃÀ
åú²ÅÄÜÊ¹ÓÃµÄµÃĞÄÓ¦ÊÖ¡£ÕâÒ²ÄÑ¹ÖÁË£¬ÒòÎªÕâ°Ñµ¶ÊÇÓĞÁéĞÔµÄ£¬Ö»¸úËæ
ËıµÄÖ÷ÈË£¬¶øËüµÄÖ÷ÈË¾ÍÊÇÃÀåú¡£

LONG);
	setup();
	replace_program(ROOM);
}
