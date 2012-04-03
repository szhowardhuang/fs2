inherit ROOM;
void create() {
	set( "short", "$CYN$Íû $RED$Æ¼ $GRN$Ğù$NOR$" );
	set( "object", ([
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount3"  : 1,
		"amount10" : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
	]) );
	set( "owner", "speed" );
	set( "build", 10232 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room257",
		"east"      : "/open/clan/ou-cloud-club/room/room246",
	]) );
	set( "long", @LONG
ÕâÀïÊÇspeed µÄ¼Ò, Ã¿µ±ÏëÆğ¼ÒÆ¼Ê±, Ëû¾Í»á
Ò»¸öÈËµ½ÕâÀïÀ´¾²¾²³ÁË¼, ºó»Úµ±Ê±×öµÄ´íÎó¾ö¶¨
ÏÖÔÚÖ»ÆÚÅÎÓĞÒ»Ìì¼ÒÆ¼»á»Øµ½ËûµÄÉí±ß. Ç½±ÚÉÏ¿Ì
×Åµ±³õËÍ¸ø¼ÒÆ¼µÄÊ«, ÉÏÃæĞ´×Å :

              ¾ä  ïñ Áî  [32mÆ¼[0m  [32m¼Ò[0m    
              ¾ä  [31m°®[0m [36mÎá[0m  Ë®  Ó÷
              Õæ  Ò» ³õ  Ïà  »§
              Çé  Éú Ê¶  ·ê  Ïş
              ½Ô  Òà ±ã  ¶«  Éù
              Îª  ²» Çê  Îâ  Èç
              [35mŠ…[0m  »Ú ĞÄ  Àï  İº                         



LONG);
	setup();
	replace_program(ROOM);
}
