#include <room.h>

 inherit ROOM;

 void create()
{
   set("short", "船上");
        set("long", @LONG
             
        
铁船之上仅能容纳数人，船身皆以乌钢所造，虽处在阳光下，船上却
为黑气笼罩，就好似六月雪，虽然艳阳高挂，船上倒是凉的令人不禁直
打哆唆.... 

LONG
        );

        set("exits", ([
		"up": "/open/gsword/room/ship2",
        ]) );
setup();

}
