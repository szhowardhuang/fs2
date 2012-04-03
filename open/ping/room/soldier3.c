// Room: /open/ping/room/soldier3.c
inherit ROOM;

void create ()
{
  set ("short", "练兵场");
  set ("long", @LONG
你来到平南驻军的练兵场,许多士兵们正努力的操练着,为
保家护国供献他们的青春,你不禁对他们的精神感到钦配.南方
有几座帐棚,应是驻军的大营吧.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/soldier1" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"soldier2",
  "enter" : __DIR__"soldier4",
]));

  setup();
}
