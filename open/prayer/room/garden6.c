//open/prayer/room/garden6.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花园");
        set("long",@LONG

	邪气愈来愈浓,四周不时传来野兽的叫声........... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden10",		//花园
        "east":"/open/prayer/room/garden2",			// "
        "west":"/open/prayer/room/garden7",		// "
        ]) );
   setup();
}
