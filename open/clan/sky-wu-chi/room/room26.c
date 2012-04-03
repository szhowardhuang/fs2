inherit ROOM;
void create() {
	set( "short", "H" );
	set( "build", 45 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room17",
		"heronotme" : "/open/clan/sky-wu-chi/room/room113",
		"hild"      : "/open/clan/sky-wu-chi/room/room168",
		"herozero"  : "/open/clan/sky-wu-chi/room/room97.c",
		"herononame" : "/open/clan/sky-wu-chi/room/room166.c",
		"holeman"   : "/open/clan/sky-wu-chi/room/room305",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÔÚÒ»ÕóÆß²ÊµÄ¹âÃ¢ÁıÕÖºó..Äã³öÏÖÔÙÒ»¸öÆæÒìµÄ¿Õ¼ä[0;1;35mH[0mÀï
ÓÉÓÚµ¶ÉñÑà×ĞµÄÁ¦Á¿...ÄãÔÚÕâÀïºô»½Äã×Ô¼ºµÄÃû×Ö.....
¾Í¿ÉÒÔµÃµ½ÌìµÀÎŞ¼«¸øÄãµÄÆæÒì»Ã½ç...ÔÚÕâ..Äã¿ÉÒÔĞŞÁ·
ÄãµÄÎäÑ§...ÒòÎªÔÚ½á½çµÄ±ÓÓÓÏÂ...ÏàĞÅ..Ò»¶¨ÄÜÔçÈÕ´ïµ½
Éî²»¿É²âµÄµØ²½.....
LONG);
	setup();
	replace_program(ROOM);
}
