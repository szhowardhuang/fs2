inherit ROOM;
void create() {
	set( "short", "B" );
	set( "exits", ([
		"bor"       : "/open/clan/sky-wu-chi/room/room315",
		"borstquc"  : "/open/clan/sky-wu-chi/room/room18",
		"biwem"     : "/open/clan/sky-wu-chi/room/room175",
		"bookman"   : "/open/clan/sky-wu-chi/room/room275",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"bbsman"    : "/open/clan/sky-wu-chi/room/room119",
		"bluefox"   : "/open/clan/sky-wu-chi/room/room94.c",
		"bacchus"   : "/open/clan/sky-wu-chi/room/room263",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÔÚÒ»ÕóÆß²ÊµÄ¹âÃ¢ÁıÕÖºó..Äã³öÏÖÔÙÒ»¸öÆæÒìµÄ¿Õ¼ä[0;1;35mB[0mÀï
ÓÉÓÚµ¶ÉñÑà×ĞµÄÁ¦Á¿...ÄãÔÚÕâÀïºô»½Äã×Ô¼ºµÄÃû×Ö.....
¾Í¿ÉÒÔµÃµ½ÌìµÀÎŞ¼«¸øÄãµÄÆæÒì»Ã½ç...ÔÚÕâ..Äã¿ÉÒÔĞŞÁ·
ÄãµÄÎäÑ§...ÒòÎªÔÚ½á½çµÄ±ÓÓÓÏÂ...ÏàĞÅ..Ò»¶¨ÄÜÔçÈÕ´ïµ½
Éî²»¿É²âµÄµØ²½.....
LONG);
	setup();
	replace_program(ROOM);
}
