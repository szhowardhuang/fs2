//written by wataru...../open/killer/mon/room/g11.c
inherit ROOM;

void create()
{
        set("short", "绿云组组长室");
        set("long", @LONG
	此处并没有任何特别奢华之处，甚至让你感到是否来到道观之中？
	
	相传周八伯精通灵异知识，甚至具有通灵之力。

	这项特异功能，让叶秀沙放心的将后山这广大的区域交给他管理。

	因为，就算是在细微之处，他也可以算命数得知。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "out" : __DIR__"g10.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/hu_fa5.c":1,
   ]));
        setup();
}
