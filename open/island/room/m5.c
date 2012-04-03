//by chilice casey
#include <ansi.h>
inherit ROOM;

void create ()
{
   set  ("short", HIR"火山口"NOR);
  set ("long", @LONG
一股热流往你袭来，四周的高温令人口干舌燥
心烦不已，传闻在火山中，有一个终年冰霜不化之
地，而唯一的路便是由此跳入。

LONG);

  set("exits", ([ /* sizeof() == 2 */
"jump"  : __DIR__"c23",
"west"  : __DIR__"m2",
]));
   set("outdoors", "/open/main");


  set("light_up", 1);

 
  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="jump" && (int)me->query("combat_exp") < 400000 ) {
write(HIR"你承受不了火山口的高温而退了回来 !!\n"NOR);
write(RANK_D->query_respect(me)+"看来你的能力还不足以跃入火山口!\n");
        return 0;
}
return 1;
return ::valid_leave(me,dir);
}



