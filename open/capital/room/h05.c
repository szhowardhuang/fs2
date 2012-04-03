// Room: /open/capital/room/h05.c

inherit ROOM;

void create ()
{
  set ("short", "扁鹊胡同");
  set ("long", @LONG
步入扁鹊胡同, 最特别的地方便是地上出奇的干净, 两旁柳树摇曳
, 但地上却连一片叶子也没有, 四处都扫的干干净净。仔细的嗅一嗅,
空气中似乎弥漫着一股浓郁的药味, 大概是京城里大部分的药店都设在
这儿的缘故。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/r67",
  "east" : "/open/capital/room/h06",
]));

  set("outdoors", "/open/capital");


  setup();
}
