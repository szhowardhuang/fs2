#include <room.h>

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
	"south":__DIR__"room8",
	"north":__DIR__"room20",
        ]) );
	set("light_up",1);
        setup();
}
