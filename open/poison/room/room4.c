// Room: /open/poison/room/room4
inherit ROOM;

void create ()
{
  set ("short", "木屋");
  set ("long", @LONG
这是一间小木屋，里面只放置了几样的家具，看来十分
的简漏，墙上则挂了几把斧头 (axe)，看来这应该是樵夫的
家吧。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "axe" : "大部分斧头都已生锈，不堪使用了。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road3",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/son.c" : 1,
  "/open/poison/npc/woodcutter.c" : 1,
]));

  setup();
}
