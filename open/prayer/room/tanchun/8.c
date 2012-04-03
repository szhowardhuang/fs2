///open/prayer/room/tanchun/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","议事厅");
        set("long",@LONG

	这里是天权门的议事厅，往南则是玄关, 你可以打开木雕门(open 
	 door)．大厅出去后是天权门的练武场．往北则是到门主的宝座．
	两旁站着许多教头级以上的干部，个个面无表情! 

LONG );
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"5",		//议事厅
        "south":__DIR__"1-door",	//玄关
        "east":__DIR__"7",		//议事厅
        "west":__DIR__"9",		//议事厅
        ]) );

        set("light_up", 1);
        create_door("south","圣火刻纹木雕门", "north",DOOR_CLOSED);
   setup();
}
