// Room: /open/capital/room/r21.c

inherit ROOM;

void create ()
{
  set ("short", "丰安桥");
  set ("long", @LONG
往南是日落驰道，往北有条较小的胡同。这是座白色的大拱桥，跨
过一条不算小的溪，溪里的水流得很缓慢，几乎没有在动。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/capital/room/r20",
  "south" : "/open/capital/room/r22",
]));

  set("gopath", "north");

  setup();
}
