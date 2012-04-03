// Room: /u/m/moner/room/room18.c
inherit ROOM;

void create ()
{
  set ("short", "书房");
  set ("long", @LONG

一踏入这, 映目所及都是书, 数不清的刀谱, 诗, 词、、、等,皆被分
门别列, 井然有序的放置于架上, 几张杰白的宣纸被镇在桌上, 一旁悬着
几只狼毫笔, 门栏外映着绿竹, 雕窗外传来薜荔藤萝的香味, 果然是一个
读书的好地方。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room17.c",
]));
  set("light_up", 1);

  setup();
}
