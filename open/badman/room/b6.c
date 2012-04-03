// Room: /open/badman/room/b6
inherit ROOM;

void create ()
{
  set ("short", "殿前大道");
  set ("long", @LONG
来到这里，你突然发现气氛变得异常凝重，南北两边的房间都
有重兵镇守着，应该是存放着什么重要物品吧！强烈的好奇心驱使
着你的双脚不自觉的一步步往前走去，打算看个究竟。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"b7",
  "south" : __DIR__"r8",
  "north" : __DIR__"r10",
  "east" : __DIR__"b5",
]));
  set("outdoors", "/open/badman");

  setup();
}
