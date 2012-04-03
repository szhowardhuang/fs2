// /u/j/judd/room/r25.c
inherit ROOM;

void create ()
{
set("short", "土之通道");
set("long", @LONG
看到前面的路，你不禁倒吸一口气，只见两旁都是看不到底的空
洞，想要通过这里，只有小心翼翼的沿着那弯弯曲曲的小路前进，往
底下看，黑压压的一片，让你觉得有点头晕，最好赶快通过，掉下去
大概就完蛋了．
LONG
);
set("light_up", 1);
set("exits", ([ /* sizeof() == 2 */
 "southeast" : __DIR__"land.c",
 "northwest" : __DIR__"r21.c",
]));
setup();
}
