
#include <room.h>
inherit ROOM;

void create()
{
  set("short", "北边走廊");
  set("long", @LONG
你走到了屋子的内部,它不像镳局,反而倒像一户大户人家,树影阴阴,草木摇曳,这样
    的院子,你可以从东边的窗门看的一清二楚,向北方去是北厢,据说赵鼎天有个女儿
    长的十分漂亮.............
    你可以听到阵阵吆喝声从北边传来....
    东边有一扇小红门(door)。	
LONG
);

  set ("exits", ([
      "north": __DIR__"room7",
      "east": __DIR__"d_room0",
       "south": __DIR__"room0",
      ]) );
 	set("item_desc", ([     
  	"door": "一扇精巧的小红门,可以从门中看到另一边的景色.\n",
  	]));
  	setup();
        create_door("east","小红门","west",DOOR_CLOSED);
}
