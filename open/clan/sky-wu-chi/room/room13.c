inherit ROOM;
void create() {
	set( "short", "A" );
	set( "light_up", 1 );
	set( "exits", ([
		"anaid"     : "/open/clan/sky-wu-chi/room/room257",
		"amei"      : "/open/clan/sky-wu-chi/room/room251",
		"adede"     : "/open/clan/sky-wu-chi/room/room119",
		"aow"       : "/open/clan/sky-wu-chi/room/room18",
		"atropos"   : "/open/clan/sky-wu-chi/room/room138",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
	]) );
	set( "long", @LONG
ÔÚÒ»ÕóÆß²ÊµÄ¹âÃ¢ÁıÕÖºó..Äã³öÏÖÔÙÒ»¸öÆæÒìµÄ¿Õ¼ä[0;1;33mA[0mÀï
ÓÉÓÚµ¶ÉñÑà×ĞµÄÁ¦Á¿...ÄãÔÚÕâÀïºô»½Äã×Ô¼ºµÄÃû×Ö.....
¾Í¿ÉÒÔµÃµ½ÌìµÀÎŞ¼«¸øÄãµÄÆæÒì»Ã½ç...ÔÚÕâ..Äã¿ÉÒÔĞŞÁ·
ÄãµÄÎäÑ§...ÒòÎªÔÚ½á½çµÄ±ÓÓÓÏÂ...ÏàĞÅ..Ò»¶¨ÄÜÔçÈÕ´ïµ½
Éî²»¿É²âµÄµØ²½.....
LONG);
	setup();
	replace_program(ROOM);
}
