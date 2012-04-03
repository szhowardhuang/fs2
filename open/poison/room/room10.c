// Room: /open/poison/room/room9
inherit ROOM;

void create ()
{
  set ("short", "执法堂侧厅");
  set ("long", @LONG
这里是执法堂的侧厅，在此有一位使者坐在精细华丽的
檀木椅上，眼光精敛直视正厅，他就是魔界顶顶有名，无人
不晓的索魄使者，在此协助执法大长老办案。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room8",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/envoy4" : 1,
]));

  setup();
}
