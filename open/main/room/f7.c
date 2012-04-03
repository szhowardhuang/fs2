// Room: /open/main/room/f7.c

inherit ROOM;

void create ()
{
  set ("short", "森林");
  set ("long", @LONG
这里一望无际的森林, 西边有一条河流, 却不知怎么下去
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/bat" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f8",
  "north" : __DIR__"f6",
]));

  setup();
}
