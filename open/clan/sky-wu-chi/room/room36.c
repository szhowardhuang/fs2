inherit ROOM;
void create() {
	set( "short", "S" );
	set( "exits", ([
		"scorpio"   : "/open/clan/sky-wu-chi/room/room346",
		"shih"      : "/open/clan/sky-wu-chi/room/room244",
		"salicili"  : "/open/clan/sky-wu-chi/room/room41.c",
		"supalu"    : "/open/clan/sky-wu-chi/room/room313.c",
		"scorpizo"  : "/open/clan/sky-wu-chi/room/room349",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"sogo"      : "/open/clan/sky-wu-chi/room/room316",
		"srat"      : "/open/clan/sky-wu-chi/room/room158.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÔÚÒ»ÕóÆß²ÊµÄ¹âÃ¢ÁıÕÖºó..Äã³öÏÖÔÙÒ»¸öÆæÒìµÄ¿Õ¼ä[0;1;34mS[0mÀï
ÓÉÓÚµ¶ÉñÑà×ĞµÄÁ¦Á¿...ÄãÔÚÕâÀïºô»½Äã×Ô¼ºµÄÃû×Ö.....
¾Í¿ÉÒÔµÃµ½ÌìµÀÎŞ¼«¸øÄãµÄÆæÒì»Ã½ç...ÔÚÕâ..Äã¿ÉÒÔĞŞÁ·
ÄãµÄÎäÑ§...ÒòÎªÔÚ½á½çµÄ±ÓÓÓÏÂ...ÏàĞÅ..Ò»¶¨ÄÜÔçÈÕ´ïµ½
Éî²»¿É²âµÄµØ²½.....
LONG);
	setup();
	replace_program(ROOM);
}
