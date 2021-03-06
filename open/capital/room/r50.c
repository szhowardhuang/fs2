// Room: /open/capital/room/r50.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
  set ("long", @LONG
北方的道路就是通往三大城门之一的撼东门，西方的街道便是所谓
的云洋大街, 唯有一些权大势大的人物才住的起这条街。由于这里邻近
皇城，附近又多是达官贵人们的住所，所以禁卫军的巡逻也特别严密，
别想在这儿闹事，那对你绝对没好处。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/capital/room/r51",
  "south" : "/open/capital/room/r49",
  "west" : "/open/capital/room/r64",
]));

  set("gopath", "south");

  setup();
}
