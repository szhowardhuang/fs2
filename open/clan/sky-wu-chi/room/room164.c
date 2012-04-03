inherit ROOM;
void create() {
	set( "short", "ÈçÃÎËÆ»Ã" );
	set( "owner", "pigpana" );
	set( "light_up", 1 );
	set( "build", 13208 );
	set( "object", ([
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file8"    : "/daemon/class/blademan/obj/six-neck",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/tendo/obj/chaosbelt",
		"file10"   : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/daemon/class/blademan/obj/six-neck",
		"amount5"  : 1,
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/obj/gift/bingtang",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room69",
	]) );
	set( "long", @LONG
Õıµ±ÄãÌ¤½øÕâ¸ö·¿¼äÖ®Ê±,ºöÈ»¼ä[31mÀ×Éù´óÏì[0m,Ë²¼äÒ»µÀ[32mÉÁµç[0mÒÑ¾­
ÅüÔÚÄãÉíÉÏ,½«ÄãµÄ[36m»¤ÉíÆø¾¢[0mÈ«Êı´òÉ¢,ÔÚ´ËÍ¬Ê±´«À´ÕóÕó³İÂÖ×ª¶¯
µÄÉùÏì,×ªÑÛ¼ä,ÒÑ¾­ÊÇÒ»Õó[33m±©Óê[0m,½«ÄãÁÜµÄÒ»ÉíÊª,¾ÍÔÚÄã»¹¸ã²»Çå
³ş×´¿öµÄÊ±ºò,È´ºöÈ»¾ª¾õ!Ò»ÇĞ[37m¶¼ÊÇ»Ã¾õ[0m,²»½ûÈÃÄãÏëÂíÉÏÀë¿ªÕâ
¸ö¿Ö²ÀÓÖÆæ»ÃµÄµØ·½.

LONG);
	setup();
	replace_program(ROOM);
}
