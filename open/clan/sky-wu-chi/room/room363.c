inherit ROOM;
void create() {
	set( "short", "Ğ¡ÎäÕß¨ÉÎÂÅ¯¨ÉÎÑ" );
	set( "object", ([
		"amount7"  : 1,
		"file7"    : "/open/snow/obj/figring",
	]) );
	set( "item_desc", ([
		"É½" : @ITEM
Ò»×ù·Û´ó¨ÉÉ½
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10159 );
	set( "owner", "tony" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"up"        : "/open/clan/sky-wu-chi/room/room21",
	]) );
	set( "long", @LONG
    ÕâÀïÊÇ[36mĞ¡ÎäÕß[0mµÄÃÅ¿Ú£¬Ö»¼ûÇ½ÉÏ¹Ò×ÅÅÆ×ÓĞ´×Å£º
     
       ¡¾ Ë§¸çÅÉµÚÈı´úÕÆÃÅ ¡¸[31m³¬¼¶Ë§¸ç[0m¡±[36mĞ¡ÎäÕß[0mÖ®ÁêÇŞ ¡¿
 
       ¡¾ »Æ ¡¿                               ¡¾ Ò» ¡¿
       ¡¾ ÔÆ ¡¿                               ¡¾ Éú ¡¿
       ¡¾ °× ¡¿                               ¡¾ Ò» ¡¿
       ¡¾ ·¢ ¡¿                               ¡¾ Ğ¦ ¡¿
       ¡¾ Ñ© ¡¿                               ¡¾ Äª ¡¿
       ¡¾ ²Ô ¡¿                               ¡¾ Öª ¡¿
       ¡¾ ²Ô ¡¿                               ¡¾ ³î ¡¿
 
 

LONG);
	setup();
	replace_program(ROOM);
}
