inherit ROOM;
void create() {
	set( "short", "Ë¼¶¨" );
	set( "object", ([
		"file6"    : "/open/firedancer/npc/eq/r_neck",
		"file4"    : "/open/firedancer/npc/eq/r_cape",
		"amount5"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_shield",
		"amount1"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_belt",
		"file9"    : "/open/firedancer/npc/eq/r_head",
		"file2"    : "/open/firedancer/npc/eq/r_boots",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_finger",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_cloth",
	]) );
	set( "owner", "raymond" );
	set( "build", 11226 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room124",
		"south"     : "/open/clan/13_luck/room/room121",
	]) );
	set( "long", @LONG
                
[53m                 [56mË¼¶¨[0m
[0m
ÓÉÇ°Ìü×ß½øÀ´Îª[56mË¼¶¨[0mÊÇĞ°ÍõµÄÁ·¹¦·¿£¬Îä¹¦µ½´ï
µ½ÕâÖÖ¼¶Êı£¬È­½ÅÖ»ÊôÄ©Á÷£¬[57m¸ßÊÖ¶Ô¾ö±ÈµÄ¾ÍÊÇ[0m
[57mĞÄÁé²ãÃæµÄË¼Î¬£¬¹Ê[31mĞ°Íõ[57mÒÔ[56mË¼¶¨[57mÎªÃû£¬³Á¾²×Ô¼º[0m
[57mµÄË¼Ğ÷£¬ÒÔ´ïµ½[0m [35m»ìÔª»ìÉ±[0m [57mµÄ¼«·å¾³½ç[0m£¬Ö»¿´Á½ÅÔ
¼òµ¥Ö±½ÓµÄ[56mÇà»¨Ê¯[0m²¼ÖÃ£¬¾Í¿ÉÒÔÁË½â[31mĞ°Íõ[0m¾ÍÊÇÖ»
Òªµ¥´¿µÄÒ»¸öÄ¿µÄ¾ÍÊÇÒª---       [5;53mÇ¿[0m
LONG);
	setup();
	replace_program(ROOM);
}
