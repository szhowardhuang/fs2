inherit ROOM;
void create() {
	set( "short", "Éñ·çÊ¥ÌÃ" );
	set( "owner", "smalloo" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 5,
		"amount3"  : 364,
		"file9"    : "/open/mogi/castle/obj/blood-water",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/killer/obj/s_pill",
		"amount4"  : 26,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/ping/obj/poison_pill",
		"amount1"  : 348,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 7,
		"amount5"  : 2,
	]) );
	set( "build", 12369 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room334",
		"enter"     : "/open/clan/13_luck/room/room331",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ÖÕÓÚÀ´µ½ÁË[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mt[1m¡õ[1m¡õ[0m£¬ÑÛÇ°Õ¾×ÅÒ»Î»¸ßÈË£¬Ëû²¢²»ÊÇÌìÏÂ»áµÄ
Éñ·çÌÃÖ÷--->[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¡£ËûÇáÆ®Æ®µÄÉíÓ°£¬Çá¹¦ÒÑ¾­´ïµ½Éñ¶øÃ÷Ö®µÄ[0;1;36m¡õ[1mW[0m
[0;1;36m¡õ[1mZ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬¼á¶¨µÄÄ¿¹â£¬Í¸Â¶³ö[0;1;32m¡õ[1m¡õ[1m¡õ[1mj[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÖ®Æø¶øÊÇ´ò°Ü[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÄ[0;1;33m¡õ[1m¡õ[1m¡õ[1m][1;35m¡õ[1mp[0m
[0;1;35m¡õ[1m¡õ[1m¡õ[1mk[0m£¬¶ø[0;1;35m¡õ[1mp[1m¡õ[1m¡õ[1m¡õ[1mk[0mÏ²°®ÈË²Å£¬Áô[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÏÂÀ´½Ìµ¼ÎäÑ§£¬Ò²Ï£ÍûÏ¯ÈÕÄô·ç
¿ÉÒÔÕ½Ê¤[0;1;35m¡õ[1mp[1m¡õ[1m¡õ[1m¡õ[1mk[0m¡£


LONG);
	setup();
	replace_program(ROOM);
}
