// gather.c 
#include <combat.h> 
#include <ansi.h>
inherit SSERVER; 
int kee_out(object me,object target)
{
        if(me->query("s_kee")<10)
     {
          tell_object(me,"你的灵气修练不够。\n");
             return 1;
     }
     if(me->query_temp("super_god")==1) {
 tell_object(me,"你以经在使用【仙云之气】了!!!。\n");
 return 1; }
 message_vision(
          HIW "$N口中唸唸有词!!护身灵气浮动，"HIM"仙云之气"HIW"腾出！\n" NOR,me);
 message_vision(
          HIY "$N的全身被仙云之气所覆，发出奇幻般的光芒!!\n" NOR,me,target);
        if(((int)me->query("kee")) < ((int)me->query("max_kee")))
        {
        me->add("kee",1000);
        me->add("force",200);
        }
       me->set_temp("super_god",1);
        me->apply_condition("god_out",me->query("s_kee")/10);
        me->set("s_kee",0);
     return 1;
}

