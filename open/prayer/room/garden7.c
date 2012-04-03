//open/prayer/room/garden7.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花园");
        set("long",@LONG

	    不知道从那里来的浓雾，只见阴气沉沉，
	四周不时传来野兽的叫声，打从你走进来后就
	一直闻到一股薰人的恶臭，地上一堆一堆的骷
	髅还有尸体，让你不知道这些人到底是怪物的
	食物还是他们是因为走不出去的关系??

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden11",		//花园
        "south":"/open/prayer/room/garden3",		//花园
        "east":"/open/prayer/room/garden6",		// "
        "west":"/open/prayer/room/garden8",			// "
        ]) );
   setup();
}
