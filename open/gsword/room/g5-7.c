// Room: /open/gsword/room/gsword5-22.c
inherit ROOM;

void create ()
{
  set ("short", "客房");
  set ("long", @LONG
这是仙剑派用来招待远客住宿之客房 ,由于仙剑为剑士公会所在 ,兼之
身为武林第一大派 ,因此每天均有很多仿客 ,这里看起来干干净静的 ,简单
淡雅 ,左首一个小茶几 ,一盆兰花放置其上 ,西边开了个窗户 ,和栩的阳光
照射进来 ,十分舒服 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/g5-3.c",
]));

  set("light_up", 1);

  setup();
}
