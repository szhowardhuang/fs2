// Room: /open/poison/room/path11.c
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
  set ("short", "小山洞");
  set ("long", @LONG
这里是一个小小的山洞，东边和南边的石壁上均刻有圣
火像，仔细一看，北边墙上有一个不明显的小孔存在，东边
石壁较光滑，南面石壁则是千疮百孔的，此外看不出任何特
殊的地方。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"road6",
]));
  setup();
}
void init()
{
 object me = this_player();
 if(present("stonekey",me))
        tell_object(me,HIC"东面石门有感于你身上磁石而发出喀喀的声响。\n"NOR);
 add_action("do_go","go");
 add_action("do_press","press");
}
int do_go(string str)
{
  object me = this_player();
  object ob = this_object();
  if(str == "south" )
        if(me->query("family/family_name")=="冥蛊魔教")
               {
                message_vision("$N熟练地开启南面石门，翻身而入。\n",me);
                tell_room(ob,"石门随即被关上。\n");
                me->move(POISON_ROOM"path2");
                return 1;
               }
  if(str == "east" )
        if(present("stonekey",me))
            {
             tell_room(ob,"东面石门感应到磁石的接近，开起了一道门。\n");
             message_vision("$N不慌不忙地走了进去。\n",me);
             tell_room(ob,"随着磁石离去，石门自动关上。\n");
             me->move(POISON_ROOM"path12");
             return 1;
            }
}
int do_press(string str)
{
  object me = this_player();
  object ob = this_object();
  if(str != "fire")
        return notify_fail("你想按哪里?\n");
  if(!me->query("quests/poison_help"))
    {

        tell_object(me, "由于你不清楚压法，不小心触动机关。\n");
        tell_object(me, "突然咻咻数响，你感到一股寒气注入体内。\n");
	me->apply_condition("rose_poison", 3);
	return 1;
    }
  message_vision("$N正确地启动石门开关，石门随之开起。\n",me);
  message_vision("$N不慌不忙地走了进去。\n",me);
  message_vision("随着$N走过，石门自动关上。\n", me);
  me->move(POISON_ROOM"path12");
  return 1;
}
