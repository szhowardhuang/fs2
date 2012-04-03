inherit ROOM;
void create() {
	set( "short", "ÒäÂ®" );
	set( "owner", "raymond" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/prayer/obj/kylin-belt",
		"amount5"  : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/tendo/obj/chaosbelt",
		"amount8"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/killer/obj/k_ring",
		"file6"    : "/open/tendo/obj/luboot",
		"file2"    : "/open/gsword/obj/silver_sword",
	]) );
	set( "build", 10734 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room125",
	]) );
	set( "long", @LONG
                 
                 [57mÒäÂ®[0m
                 
´Ó[56mË¼¶¨[0m×ß½øÀ´ÎªĞ°ÍõµÄÎäÆ÷·¿[57mÒäÂ®[0m£¬ËÄÖÜÒÔÈû±±
ÖÁº®[57m°×ÓñÊ¯[0mÎª±Ú£¬[54mÈôÄãÄÚÁ¦¾«ÉîÒÔ´ïÈçÒâ×Ô×ªµÄ[0m
[54m¾³½çµ±¿ÉÒÔ¾¢²âÖª£¬´ËÇ½ºñ¹ıÁ½ÈË¿í£¬Õæ²»Öªµ±Ê±ÊÇ[0m
[54mÈçºÎÔË¹ıÀ´µÄ£¬Õâ¾ø·ÇÈËÁ¦ËùÄÜÎª£¬µ«Æ«Æ«¾ÍÔÚ[0m
[54mÄãÑÛÇ°[0m£¬[50mÕâ·ÅÖÃ×ÅĞ°Íõ³öµÀÖÁ½ñËùÓÃµÄÎäÆ÷£¬ÏàĞÅµ±[0m
[50mĞ°ÍõÕ¾ÔÚÕâÊ±¶¨µ±»ØÒäÆğÒÔÍùÖÁ½ñ´óĞ¡µÄÃÍÕ½£¬Ã¿[0m
[50m´Î¶¼ÊÇÒÔ¼áÒãµÄĞÅÄî¶È¹ı£¬¶ø½ñ¿ÉÒÔÔÚ´Ë»ØÎ¶£¬[0m
[33m·Â·ğ²»¹ı×òÈÕ....[0m
È»ºóºóÃæ¾ÍÊÇĞ°ÍõºÍÆäÆŞµÄ[55m¹ë·¿[0mÁË
LONG);
	setup();
	replace_program(ROOM);
}
