//open/prayer/room/youkoun/23.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","密道");
        set("long",@LONG

        这密道里鬼影幢幢, 内部还不时传来奇怪的声音, 听起来
        好像是男人的叫声!!可能吗??瑶光门不是禁止男性进来吗
        ??怎么会有男人的叫声??

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"24",    
        "south":__DIR__"22",    
 
        ]) );
        set("no_fight", 0);
                
  setup();
}
