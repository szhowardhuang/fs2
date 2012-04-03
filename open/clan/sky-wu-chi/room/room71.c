inherit ROOM;
void create() {
	set( "short", "Z" );
	set( "exits", ([
		"zsa"       : "/open/clan/sky-wu-chi/room/room256",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"zeros"     : "/open/clan/sky-wu-chi/room/room243",
		"zzxx"      : "/open/clan/sky-wu-chi/room/room269",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÔÚÒ»ÕóÆß²ÊµÄ¹âÃ¢ÁıÕÖºó..Äã³öÏÖÔÙÒ»¸öÆæÒìµÄ¿Õ¼ä[0;1;32mZ[0mÀï
ÓÉÓÚµ¶ÉñÑà×ĞµÄÁ¦Á¿...ÄãÔÚÕâÀïºô»½Äã×Ô¼ºµÄÃû×Ö.....
¾Í¿ÉÒÔµÃµ½ÌìµÀÎŞ¼«¸øÄãµÄÆæÒì»Ã½ç...ÔÚÕâ..Äã¿ÉÒÔĞŞÁ·
ÄãµÄÎäÑ§...ÒòÎªÔÚ½á½çµÄ±ÓÓÓÏÂ...ÏàĞÅ..Ò»¶¨ÄÜÔçÈÕ´ïµ½
Éî²»¿É²âµÄµØ²½.....
LONG);
	setup();
	replace_program(ROOM);
}
