// Room: /u/p/pokai/room/wu/tower1-2
inherit ROOM;

void create ()
{
  set ("short", "武威七杀塔一楼--");
  set ("long", @LONG
来到这里，你发现杀气越来越浓，由于紧张的关系。四周的景致你也无心看顾，
只觉得映入眼廉的是一片片的暗红色，你不禁感到有些头晕。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower1-1",
  "east" : __DIR__"tower1-3",
]));
  set("light_up", 1);

  setup();
}
