//by Casey
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIR"火云峡"NOR);
  set ("long", @LONG
奋力的穿过窄仅通人的山缝 ,你来到一个全新的
地方。四周了无生机 ,遍地焦土 ,而且处处都有巨大
且深入的爪痕

LONG);
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
 "out" : __DIR__"d-18",
 
 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}


