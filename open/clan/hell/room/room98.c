inherit ROOM;
void create() {
	set( "short", "$HIC$ÆëÔÆ·å$NOR$" );
	set( "owner", "creed" );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room99",
		"west"      : "/open/clan/hell/room/room97",
	]) );
	set( "long", @LONG
µ±ÄãĞÑÀ´Ö»¼û×Ô¼ºÕıÔÚÒ»¿ÃÍ»³öÓÚÉ½ÑÂÅÔµÄÀÏÊ÷ÉÏ,
Ö»Ìı¼ûÊ÷¸ÉÖ¨Ö¨µÄÏì×Å£¬ÏñÊÇÒª¶ÏÁÑ°ã, ´ËÊ±Äã¿´µ½Ê÷ÅÔ
ÓĞ¼¸ÌõÀÏÌÙÉÏÃæ²»ÖªÍ¨ÍùºÎ´¦, ÄãÏëÄã»òĞí¿ÉÒÔÊÔ×ÅÅÀÉÏ
È¥, »¹ÊÇÄãÏë¼ÌĞøÍùÏÂÌøÄØ??
  ¡¸[33mÉÙË§[0m¡±¿ÜÖÙ(Master kal)
  ¡¸[36mĞ°Íõ[0m¡±Ê¯Ö®Ğù(Shen)

LONG);
	setup();
	replace_program(ROOM);
}
