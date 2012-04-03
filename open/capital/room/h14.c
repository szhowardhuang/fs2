// Room: /open/capital/room/h14.c

inherit ROOM;

void create ()
{
  set ("short", "萝卜胡同");
  set ("long", @LONG
你看到有一群小孩子正蹲在门口, 聚精会神的不知道在观察什么东
东, 好奇的走过去一看, 原来是....不提也罢。小孩子就是小孩子。除
此之外, 你发现到这儿的空气清新, 不禁深深的吸了几口气。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h13",
  "east" : __DIR__"h15",
]));
  set("outdoors", "/open/capital");

  setup();
}
