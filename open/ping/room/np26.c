#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "玄关");
  set ("long", @LONG
后堂到了这儿有个转角, 通向一间房间去, 角落处摆设着一瓶花
, 连着挂着几幅诗画, 一看之下似乎出自名家之手, 颇有一种非凡之
势。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"np27",
  "west" : __DIR__"np22",
]));
  set("light_up", 1);

  setup();
}
