//玄宇宙的归真!! by bss
//写得长了一点，不过先充充数吧!!!
#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;
int perform(object me, object target)
{
        int fun,flag,stat;
        int fun1,fun2,fun3,fun4,fun5;
        string dodge_skill,parry_skill;
        stat=0;
        flag=0;
        fun=me->query("functions/gwe_jen/level");
fun1=me->query("functions/black/level");
fun2=me->query("functions/bluesea/level");
fun3=me->query("functions/goldsun/level");
fun4=me->query("functions/blood/level");
fun5=me->query("functions/green/level");
if(me->query("class")!="prayer")
          return notify_fail("你的职业无法使用此技能。\n");
if( fun1 < 50 ) return notify_fail ("你的玄浑沌等级不足。\n");
if( fun2 < 70 ) return notify_fail ("你的靛沧海等级不足。\n");
if( fun3 < 90 ) return notify_fail ("你的金晨曦等级不足。\n");
if( fun4 < 110 ) return notify_fail ("你的血穹苍等级不足。\n");
if( fun5 < 130 ) return notify_fail ("你的玄宇宙等级不足。\n");

        if( !me->is_fighting() )
          return notify_fail("归真只能在战斗中才能使用。\n");
        if(!target) target = offensive_target(me);
        if(!target) return notify_fail("找不到敌人!!\n");
        if( target == me )
          return notify_fail("不能对付自己呀!!\n");
        if( me->query("force") < 500)
          return notify_fail("你的内力不够。\n");
        dodge_skill = target->query_skill_mapped("dodge");
        if(!dodge_skill) stat+=1;
        parry_skill = target->query_skill_mapped("parry");
        if(!parry_skill) stat+=2;
        if(stat==3) return notify_fail("这个对手没办法用归真，或已经被你打得失去了闪避及招架的能力了!!!\n");
        me->add("force",-40*((fun/10)+1));
        message_vision(HBGRN+HIY"$N使出「玄宇宙”中的归真，一掌往$n的脑袋打去!!\n"NOR,me,target);
        if(fun >=0 && fun <25)
        {
                if(10 > random(100)){
                  switch(stat)
                  {
                      case 0:
                        if(random(2)){
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        }
                        else{
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        }
                        target->start_busy(1);
                        target->add("kee",-100);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 1:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-100);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 2:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-100);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 3:
                        return notify_fail("这个对手没办法用归真，或已经被你打得失去了闪避及招架的能力了!!!\n");
                        break;
                      default:
                        break;
                  }
                }
                else{
                        message_vision(HIY"$n看准了$N掌势的漏洞，急运身法，闪开了这一击!!\n"NOR,me,target);
                        flag=1;
                        COMBAT_D->report_status(target);
                }
        }
        if(fun >=25 && fun <50)
        {
                if(20 > random(100)){
                  switch(stat)
                  {
                      case 0:
                        if(random(2)){
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        }
                        else{
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        }
                        target->start_busy(1);
                        target->add("kee",-200);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 1:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-200);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 2:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-200);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 3:
                        return notify_fail("这个对手没办法用归真，或已经被你打得失去了闪避及招架的能力了!!!\n");
                        break;
                      default:
                        break;
                  }
                }
                else{
                        message_vision(HIY"$n看准了$N掌势的漏洞，急运身法，闪开了这一击!!\n"NOR,me,target);
                        flag=1;
                        COMBAT_D->report_status(target);
                }
        }
        if(fun >=50 && fun <75)
        {
                if(30 > random(100)){
                  switch(stat)
                  {
                      case 0:
                        if(random(2)){
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        }
                        else{
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        }
                        target->start_busy(1);
                        target->add("kee",-300);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 1:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-300);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 2:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-300);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 3:
                        return notify_fail("这个对手没办法用归真，或已经被你打得失去了闪避及招架的能力了!!!\n");
                        break;
                      default:
                        break;
                  }
                }
                else{
                        message_vision(HIY"$n看准了$N掌势的漏洞，急运身法，闪开了这一击!!\n"NOR,me,target);
                        flag=1;
                        COMBAT_D->report_status(target);
                }
        }
        if(fun >=75 && fun <100)
        {
                if(40 > random(100)){
                  switch(stat)
                  {
                      case 0:
                        if(random(2)){
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        }
                        else{
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        }
                        target->start_busy(1);
                        target->add("kee",-400);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 1:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-400);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 2:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-400);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 3:
                        return notify_fail("这个对手没办法用归真，或已经被你打得失去了闪避及招架的能力了!!!\n");
                        break;
                      default:
                        break;
                  }
                }
                else{
                        message_vision(HIY"$n看准了$N掌势的漏洞，急运身法，闪开了这一击!!\n"NOR,me,target);
                        flag=1;
                        COMBAT_D->report_status(target);
                }
        }
if(fun >= 100)
        {
                if(50 > random(100)){
                  switch(stat)
                  {
                      case 0:
                        if(random(2)){
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        }
                        else{
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        }
                        target->start_busy(1);
                        target->add("kee",-500);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 1:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了招架的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_parry",1);
                        target->map_skill("parry");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-500);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 2:
                        message_vision(HIR"结果一击命中，$n的头脑因为被$N内功中的奇异真气侵入，顿时变得昏昏沉沉，像是失去了闪躲的能力了!!!\n"NOR,me,target);
                        target->set_temp("no_en_dodge",1);
                        target->map_skill("dodge");
                        target->reset_action();
                        target->start_busy(1);
                        target->add("kee",-500);
                        flag=2;
                        COMBAT_D->report_status(target);
                        break;
                      case 3:
                        return notify_fail("这个对手没办法用归真，或已经被你打得失去了闪避及招架的能力了!!!\n");
                        break;
                      default:
                        break;
                  }
                }
                else{
                        message_vision(HIY"$n看准了$N掌势的漏洞，急运身法，闪开了这一击!!\n"NOR,me,target);
                        flag=1;
                        COMBAT_D->report_status(target);
                }
        }
        message_vision(HIG"$N因为使出了这非常耗真劲的一掌，不得不闭目养神，以求快速的恢复!!\n"NOR,me);
        me->start_busy(1);
        if(!flag) flag=1;
        if( fun < 100 )
        function_improved ("gwe_jen",random(500)*flag);
        return 1;
}
