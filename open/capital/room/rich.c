// Room: /open/capital/room/rich
inherit ROOM;

void create ()
{
  set ("short", "干通天宅前庭院");
  set ("long", @LONG
干通天的庭院, 到处绿草茵茵, 花团处处, 但似乎干通天十分喜爱
茶花的样子, 因为大部分的花种均是名贵的茶花, 「十八学士”、「美
人倚栏娇”、、「花开落地”、「三色菱”等等。据京城里的居民说,
设计这个花园的工匠还是干通天远从云南聘请来的, 难怪有如此南疆风
味。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"rich1",
  "south" : __DIR__"r62",
]));

  setup();
}
