inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("[1m[31mÑæÑª[33mÐÞÂÞ[37mÕÕÑý¾µ[0m",({"board"}));
	set("long","[1m[32m¾µ×Ó²»¶ÏÒ¡»Î×Å...Ò¡»Î×Å... Ò¡»Î×Å...Ò¡»Î×Å...Ò¡»Î×Å... Ò¡»Î×Å...[0m");
	set("board_id","Fireblood");
	set("make_clan","Fireblood");
	set("location","/open/clan/Fireblood/room/hall");
	set("capacity",50);
	setup();
}
