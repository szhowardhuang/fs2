inherit ROOM;

void create ()
{
  set ("short","走廊");
  set ("long", @LONG
这是绝情门的主要通路，二旁是花园，往北一直走到底，你将会
看到一座笼罩着杀气的房子，令你有种想要回头的感觉，因为你
在这是不受欢迎的人，所有的人都想要致你于死地，你现在想回
头但已太迟，你要为自已的自大付出代价。
LONG);
  set("objects", ([ /* sizeof() == 1 */
"/open/love/npc/hero":2,
"/open/love/npc/6.c":1,
  ]));
  set("exits", ([ /* sizeof() == 4 */
"enter" :__DIR__"room33",
  "east" : __DIR__"room2-15",
  "west" : __DIR__"room2-14",
  "south" : __DIR__"room1-2",
  ]));
  set("light_up", 1);

  setup();
}

