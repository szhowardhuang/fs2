#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",HIY"绝情楼"NOR);
  set ("long", @LONG
这里就是有名的「绝情楼”，你可以看到这的摆宫设可比皇宫，
你抬头一看看到林枫坐在骷髅椅上，面带杀气的看着你，他旁边
站着一位身形矮小猥琐的人，正在商量怎么对付你，要命的话就
赶快跑吧。
LONG);

  set("objects", ([ /* sizeof() == 4 */
"/open/love/npc/1.c":1,
  ]));
  set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"room1-3.c",
  ]));
  set("light_up", 1);

  setup();
}

