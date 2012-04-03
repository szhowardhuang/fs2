inherit ROOM;
void create() {
	set( "short", "ĞÇ¿Õ" );
	set( "object", ([
		"amount6"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file1"    : "/open/love/obj/cloth1",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/love/obj/cloth1",
	]) );
	set( "owner", "woan" );
	set( "build", 11574 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room159.c",
		"west"      : "/open/clan/13_luck/room/room328",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ÔÚ[0;1;5;36m¡õ[1;5mP[1;5m¡õ[1;5m¡õ[0m·±»ªµÄÒ¹Àï£¬ÎÒÃÇÊÖÇ£×ÅÊÖÔÚÒ»Æğ£¬  
ÎÒÒªÈ«ÊÀ½ç¶¼ÌıÌı£¬ÌıÎÒÀ´Ö¤Ã÷Õâ°®µÄ¶¨Òå£¬ÓÀ
²»»áÏ¨¡£´ÓÎÒ¸Õ¿ªÊ¼ÈÏÊ¶Äã£¬ÎÒ¾ÍÏëÓÀÔ¶×ßÏÂÈ¥
£¬ÎÒËµ©¤ÈÃ°®Î¬³ÖÏÂÈ¥£®ÄãËµ©¤Äãº¦ÅÂµÄÊÂÇé£¬  
ÊÇ°®£¬Ïñ×¹Âä[0;1;35m¡õ[1my[1m¡õ[1mP[0m¡£Èç¹û¿ÉÒÔÎÒ»áÎªÄã£¬ÍµÒ»¿Å
[35mÁ÷ĞÇ[0m£¬ÒòÎªÊÀÉÏ[0;1;34m¡õ[1m¡õ[1m¡õ[1mR[1m¡õ[1m¡õ[1m¡õ[1mH[0mÊÇÄã£¬Ï£ÍûÄã±ğÍü¼Ç£¬  
ÎÒÃÇ¿´µÄµÚÒ»´Î[0;1;31m¡õ[1my[1m¡õ[1mP[1m¡õ[1mB[0m¡£ÎÒËµ³ö[0;1;32m¡õ[1mu[1m¡õ[1m¡õ[0m£¬Äã¾²¾²µÄ
Ìı£¬ÄãÎÒµÄĞÄÒÑ¾­[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mP[1m¡õ[1m¡õ[0m£¬´Ó½ñºóµ½ÓÀ¾Ã£¬
       
          ÃÀÀöµÄ¹ÊÊÂ¶¼±»·ÅÔÚ[0;1;5;36m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0m

LONG);
	setup();
	replace_program(ROOM);
}
