//written by acelan...../u/a/acelan/ghost/room/ghost20.c

inherit ROOM;

void create()
{
        set("short", "墓园小径");
        set("long", @LONG
这是一条在墓园中的小径, 四通八达, 可以通往各个坟墓, 小径
向北不断地延伸, 西边尸骨散落满地, 看起来应该是乱葬岗, 东边则
是一堆小坟墓, 看起来杂乱无章的。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost27.c",
       "south" : __DIR__"ghost13.c",
       "east"  : __DIR__"ghost21.c",
       "west"  : __DIR__"ghost19.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/black4.c" : 1,
  "/open/killer/mon/ghost/npc/black4.c" : 1,
]));
   setup();
}
