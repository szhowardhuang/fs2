// pkr1.c by konn
// pkr1.c by konn
inherit ROOM;

void create ()
{
  set ("short", "第一武道馆");
  set ("long", @LONG
四周站满了五排人墙, 每人各敲着一张牛皮鼓, 咚咚咚咚的敲着, 一阵阵
鼓声传入你的耳里, 有如千军万马般的军队蜂涌而至, 这里是武道馆的一
角, 四面墙挂满了虎皮, 更增添了几分雄伟的气势。人墙外则是一群士兵
在跑场, 一圈又一圈, 一圈再一圈, 你不禁感到豪气抖生。




LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pkr4",
  "east" : __DIR__"pkr2",
]));
  set("light_up", 1);
  set("no_transmit", 1);
set("no_scale",1);
  setup();
}


