//written by wataru...../open/killer/mon/room/g10.c
inherit ROOM;

void create()
{
        set("short", "绿云组组长室门口");
        set("long", @LONG
	在你眼前的是一道看似门，但又不是门的一道屏障，

	此屏障雕功精细，精细到让你会怀疑这是人刻的吗？

	看来，周八伯应该就在这一道屏障的后面，

	不知道，他现在是否在组上，而没有出任务去呢？
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "eastnorth" : __DIR__"g4.c",
       "westnorth" : __DIR__"g9.c",
       "enter" : __DIR__"g11.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc4.c":2,
       "/open/killer/mon/npc/spy5.c":1,
   ]));

        set("no_clean_up", 0);

        setup();
        }
