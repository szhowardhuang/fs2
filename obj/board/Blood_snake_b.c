inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("[1m[31mÊÈÑª[33mËÀÍö[35mÅÅĞĞ°ñ[0m",({"board"}));
	set("long","Çë(read)..");
	set("location","/open/clan/Blood_snake/room/hall");
	set("board_id","Blood_snake");
	set("capacity",50);
	set("make_clan","Blood_snake");
	setup();
}
