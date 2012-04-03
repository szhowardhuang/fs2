//road1.c
inherit ROOM;

void create ()
{
  set ("short", "双龙道");
  set ("long", @LONG
昏暗的密道，两壁绘着两条栩栩如生的龙，黑暗中..你发现龙的双眼正盯着你看...
此处次乎只有一个出口..看样子..你只能乖乖的往前方走了....。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room2/road2",
]));
  set("no_magic", 1);
  set("no_transmit", 1);
  set("no_fight",1);
  setup();
}
