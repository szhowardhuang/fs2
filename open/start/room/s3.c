// Room: /open/start/room/s3.c

#include <../start.h>

inherit ROOM;

void create ()
{
  set ("short", "民舍");
  set ("long", @LONG
一个妇女正在忙着照顾强褓中的幼儿，但看着她脸上
似乎在担心着什么，正焦躁不安的喃喃自语。
    朴实的房舍，里面摆着的大部份是耕种用的农具，这
妇女的丈夫应该是位农夫吧。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/start/room/s2",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/baby" : 2,
  "/open/start/npc/woman" : 1,
]));

  setup();
}
