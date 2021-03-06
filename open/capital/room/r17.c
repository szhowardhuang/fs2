// Room: /open/capital/room/r17.c

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG
远远看到左前方有座富丽堂皇的房子，大概是宰相府了。云洋大街
上住了三个撼动天下的人，一是当今宰相，二是战功彪炳的镇远侯，三是
全国首富干通天，皇上行事也都会先征询他们意见，可见他们对王朝的影
响力。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/capital/room/r51",
  "north" : "/open/capital/room/r14",
]));

  set("gopath", "south");

  setup();
}
