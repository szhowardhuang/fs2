inherit ROOM;

void create()
{
	set("short","蛇寨");
	set("long",@LONG
这里放置着一张木桌与许多的椅子，看来是供蛇寨的守卫休息的
地方，东南边有着一个石制的蛇雕，看起来栩栩如生。
LONG);
	set("exits",([
"west":__DIR__"r-04",
"south":__DIR__"r-08",
]));
	setup();
}
