// Room: /open/main/room/r32.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
你走在灰尘滚滚的石子路上，望着四周空荡的丘陵与盆地，
是如此的孤独与沉寂，也许这就是身入江湖的悲哀吧..道路在此
呈南北走向，越往南则越远离中土，越近苗疆.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r34",
  "north" : __DIR__"r30",
  "west" : __DIR__"m23",
  "east" : __DIR__"m24",
]));

  setup();
}
