inherit ROOM;

void create()
{
	set("short","蛇寨");
	set("long",@LONG
这是蛇寨的右阶梯，往西回到蛇寨的大门入口。
LONG);
	set("exits",([
"west":__DIR__"r-02",
"up":__DIR__"r-15",
]));
	setup();
}
