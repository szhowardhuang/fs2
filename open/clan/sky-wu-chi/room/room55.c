inherit ROOM;
void create() {
	set( "short", "$HIB$¦µ $HIY$Ê¥Õß»Ã½ç $HIB$¦µ$NOR$" );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"limit"     : "/open/clan/sky-wu-chi/room/room304",
		"lazycancer" : "/open/clan/sky-wu-chi/room/room111.c",
		"lord"      : "/open/clan/sky-wu-chi/room/room239",
		"east"      : "/open/clan/sky-wu-chi/room/room33",
		"lts"       : "/open/clan/sky-wu-chi/room/room72.c",
		"lonsan"    : "/open/clan/sky-wu-chi/room/room140",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÔÚÒ»ÕóÆß²ÊµÄ¹âÃ¢ÁıÕÖºó..Äã³öÏÖÔÙÒ»¸öÆæÒìµÄ¿Õ¼ä[0;1;34mL[0mÀï
ÓÉÓÚµ¶ÉñÑà×ĞµÄÁ¦Á¿...ÄãÔÚÕâÀïºô»½Äã×Ô¼ºµÄÃû×Ö.....
¾Í¿ÉÒÔµÃµ½ÌìµÀÎŞ¼«¸øÄãµÄÆæÒì»Ã½ç...ÔÚÕâ..Äã¿ÉÒÔĞŞÁ·
ÄãµÄÎäÑ§...ÒòÎªÔÚ½á½çµÄ±ÓÓÓÏÂ...ÏàĞÅ..Ò»¶¨ÄÜÔçÈÕ´ïµ½
Éî²»¿É²âµÄµØ²½.....
LONG);
	setup();
	replace_program(ROOM);
}
