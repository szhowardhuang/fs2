// Room: /open/capital/room/h15.c

inherit ROOM;

void create ()
{
  set ("short", "萝卜胡同");
  set ("long", @LONG
这儿开始有行人走动了, 相对的, 也就热闹多了, 只是每个人都形
色匆匆的, 不知要赶着去哪? 不过这也不干你事, 还是逛逛四周, 欣赏
一下京城的景色要紧。南边是顶顶大名的悦来客栈, 同样的, 它也是干
通天的产业之一。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"inn",
  "west" : __DIR__"h14",
  "east" : __DIR__"h16",
]));
  set("outdoors", "/open/capital");

  setup();
}
