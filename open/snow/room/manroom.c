#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
       set("long","一个阴森森的洞穴内，在这里只有极微弱的光线，你勉强可以看到出口。\n");
        set("exits", ([
		"north":__DIR__"room3",
        ]) );
	set("light_up",1);
        setup();
}
