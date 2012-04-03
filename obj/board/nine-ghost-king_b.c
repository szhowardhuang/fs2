inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("[21mÆÚ´ı¾ÅÌì»ØÀ´[0m",({"board"}));
	set("long","Ãğ°ïºóÁÙÊ±¹«²¼À¸");
	set("board_id","nine-ghost-king");
	set("make_clan","nine-ghost-king");
	set("capacity",25);
	set("location","/open/clan/nine-ghost-king/room/hall");
	setup();
}
