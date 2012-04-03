// Room: /open/main/room/s1.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
  set ("long", @LONG
这里是大草原的西边, 往西边看过去, 是黑压压的密林, 也充满许多不
思议的怪物, 还是少进去为妙
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/brownhorse" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"F3",
  "south" : __DIR__"s4",
  "east" : __DIR__"s2",
]));

  setup();
}
