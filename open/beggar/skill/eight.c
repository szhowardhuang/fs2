#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object ob;
        string *name;

        if( !target ) target = offensive_target(me);

        if(me->query_skill("dragonforce",1) < 50 )
              return notify_fail("你的降龙心法不够纯熟，使出八方风雨\n");
        if( (string)me->query_skill_mapped("force")!= "dragonforce")
                return notify_fail("八方风雨须配合降龙心法才能用。\n");
if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="staff")
       return notify_fail("只有在拿棒子才能使用喔。\n");
          if(me->query("force")<300)
                           return notify_fail("你的内力不够。\n");
                  if(me->query("kee")<200)
                           return notify_fail("你的气不够。\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"八方风雨只在战斗中才能使用。\n");
                return 0;
        }
       if(me->query("force")<300)
                           return notify_fail("你的内力不够。\n");
                  if(me->query("kee")<200)
                           return notify_fail("你的气不够。\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"八方风雨只在战斗中才能使用。\n");
                return 0;
        }
        message_vision(
HIR"$N忽然向天怒吼,形化八方、棒化风雨使出打狗棒法之绝学"HIW"「八方风雨”"HIR"只见$N挥舞棒子,越舞越快形成无数的棒影\n"NOR,me,target);
        {
        message_vision(
            HIW"只见天地变色、漫天的棒影铺天盖地般向$n袭去\n"NOR,me,target);
            me->add("kee",-30);
             me->add("force",-(100 + ((int)me->query_skill("dragonforce",1)))*3)
;
        if(random(me->query_skill("staff")+20)>random(target->query_skill("dodge
")))
        {
 message_vision(
HIR"\n$n面对漫天的棒势无法躲避,被无数的棒子击中要害,棒棒致命、痛苦异常!!!\n"NOR,me,target);
                message_vision( NOR,me);
target->receive_wound("kee",me->query_skill("pd-staff",1)*3+random(me->query_skill("dragonforce",1)*2));
                COMBAT_D->report_status(target);
        }
        else
      {
                message_vision(
HIW"$n看出棒势的漏洞，千均一发之际,躲过‘八方风雨’的攻击!!!\n"NOR,me,target);
                message_vision( NOR,me);
       }
        message_vision(
            "‘八方风雨’使用后，$N大耗气力、运功调息，无法移动\n",me,target);
        me->start_busy(2);
        me->kill_ob(target);
          function_improved("eight",random(me->query("force")/10));
        message_vision( NOR,me);
        return 1;
  }
}
