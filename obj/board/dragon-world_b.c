inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("[24mÁú[13mÖ®[25mÑÒ[0m",({"board"}));
	set("long","Ê¥ÓòÄÚËùÓĞµÄ´óĞ¡ÊÂÇé¶¼¹«²¼ÔÚÕâÁ£´óÑÒÖ®ÉÏ");
	set("board_id","dragon-world");
	set("capacity",50);
	set("make_clan","dragon-world");
	set("location","/open/clan/dragon-world/room/hall");
	setup();
}
