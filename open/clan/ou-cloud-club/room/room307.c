inherit ROOM;
void create() {
	set( "short", "[1;32mÇàËÉ²ÔÓô[0m" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room306.c",
		"lake"      : "/open/clan/ou-cloud-club/room/room308",
	]) );
	set( "long", @LONG
Å¡¸ÉÁËœáÍ¸µÄÒÂÉÀ£¬Äã·¢ÏÖ×Ô¼ºÕ¾ÔÚÒ»Æ¬Ê÷ÁÖÇ°Ãæ£¬ËÄ
ÖÜÎ§»·ÈÆ×ÅµÄÊÇ·çµÄ¶úÓï£¬Äñßù³æÃù£¬Ò»Ë²¼äÈÃÄãÍüÈ´ÉíÉÏ
µÄº®Àä£¬²»Ô¶´¦ÓĞÒ»ÓëÄãÉí¸ß²î²»¶àµÄ²İ´Ô£¬ÒşÔ¼´«À´Á÷Ë®
µÄÉùÒô£¬Ë¦ÁËË¦ÊÖÉÏµÄË®×Õ£¬ÖØĞÂ½ôÎÕÊÖÉÏµÄÎäÆ÷£¬²¦¿ª²İ
´ÔÏòÇ°ÂıÂı×ßÈ¥¡£
¡õ
LONG);
	setup();
	replace_program(ROOM);
}
