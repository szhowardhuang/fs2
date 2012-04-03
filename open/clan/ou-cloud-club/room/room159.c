inherit ROOM;
void create() {
	set( "short", "$HIW$·âÓ¡Ö®³Ç $WHT$Ò¹$HIR$ÃÎ$HIC$Ìì$HIY$²Ï$HIG$±ä$NOR$" );
	set( "build", 10047 );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/dancer/obj/yuawaist",
		"file5"    : "/open/dancer/obj/yuawaist",
		"file4"    : "/open/dancer/obj/yuawaist",
		"amount4"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/dancer/obj/yuawaist",
		"amount3"  : 1,
		"amount10" : 1,
		"file10"   : "/open/dancer/obj/yuawaist",
	]) );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room158",
	]) );
	set( "long", @LONG

    ¼¸ĞíÓëÖÚ²»Í¬µÄÏ¸Ë¿´¹¹ÒÔÚ¿ÕÖĞÒıÆğÄãµÄ×¢Òâ,ÒòÎªÕâĞ©²»Ñ°³£µÄÏ¸Ë¿
³ıÁË·¢³öÉÁÉÁ½ğ¹âÖ®Íâ,¸üÒşÒş·º×ÅÒ»¹ÉÉñÊ¥µÄÏÉÆø,Ô­À´ÕâĞ©ÆæÒìµÄÎïÖÊ
Ô´ÓÚÏÉÓòµÄÇ§ÄêÌì²Ï,´«ËµµÃµ½Ìì[0;1m¡õ[1m¡õ[0mÊØ»¤µÄÈË,½«»áµÃµ½²»¿ÉË¼ÒéµÄÁ¦Á¿...

LONG);
	setup();
	replace_program(ROOM);
}
