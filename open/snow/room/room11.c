#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
	set("short","走廊");
          set("long",@LONG
这里是雪苍派的内厅，里头的装饰看起来有一段历史了，由于
这里是雪苍派的根据地，这儿的建筑有两百多年，相传雪苍派
开山祖师当年开派时似乎有建造一些暗室密门之类的。
LONG);
        set("exits", ([
	"east":__DIR__"room18",
	"north":__DIR__"room12",
        ]) );
set("objects",([
	SNOW_NPC"greeting_child":1,
	]));
	set("light_up",1);

  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

        setup();
}
