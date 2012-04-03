// room1.c by roger

inherit ROOM;
#include <ansi.h>
#include <mountain.msg>
void create () {
set ("short","冰蟾洞口");
set ("long","
看来这里就是传说中千年冰蟾的洞穴了。传说中千年冰蟾甚少外出觅
食除非进食时刻已到，但是每次外出所散发的毒气必定掀起一场腥风
血雨。因此虽然人人谈千年冰蟾为之色变，但其庐山真面目却几乎没
人知道，因为凡是见过他的人不是当场化为脓血便是成了他腹中之物
现在虽然只是在洞口，但其内所冲出之毒气已经使你感到阵阵头晕。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"hole",
       "down" : __DIR__"room29",
       "enter" : "/open/gsword/room1/blood1/r1.c",
      ]));
        setup();
}
int valid_leave(object me, string dir)
{
 string three_leaf;
  if(dir=="north" && !present("three_leaf",me)){
 tell_object(me,"想想你的爱人，父母。。。你愿意他们见到一滩脓血吗?\n"); 
  return 0;
                                               }
  if(dir=="north" && present("three_leaf",me)){
 tell_object(me,"你闻着三叶仙兰所散发的香气，使你勉强能抗拒毒气的侵袭\n");
  return 1;
                                              }
  if(dir=="enter" && me->query("bloodsword")<2){
 tell_object(me,"想想你的爱人，父母。。。你愿意他们见到一个无主幽魂吗?\n");
 return 0;
}
  if(dir=="enter" && me->query("bloodsword")>=2){
 tell_object(me,"你凭着身上的魔气..一步步的走进血魔堡中..\n");
 return 1;
}
  return 1;
}
