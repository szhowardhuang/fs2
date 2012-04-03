#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
这里是雪苍派的走廊,藉着两旁忽暗忽明的火把,你可看到两旁的墙
壁显得有些斑驳!!看起来似乎有一段历史了!你心中暗想：不知有多少
的英雄好汉曾经过此地,心中也不禁得意自己是其中之一呢...
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
]));


   set("light_up",1);

  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
