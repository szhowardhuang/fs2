#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
  int value,k_level,unit=1,much;
  int kangfun=me->query("functions/kang-power/level");
  string msg;
  object ob;
  string *name;
  if( !target ) target = offensive_target(me);
  if(me->query_skill("haoforce",1) < 100 - ( me->query("con") + me->query("cps")*1.2 ) )
   return notify_fail("你的浩日心法不够纯熟，无法聚气指尖。\n");
  if( (string)me->query_skill_mapped("unarmed")!= "lungshan")
return notify_fail("浩日罡\气必须配合泷山绝学才能用。\n");
  if( me->query("family/family_name") != "泷山派" )
return notify_fail("浩日罡\气只有泷山派的门人才可以使用。\n");
  if(!(ob=me->query_temp("weapon")))
  {
   if(me->query_temp("secondary_weapon"))
    return notify_fail("不空手怎么发浩日诀?\n");}
   if(ob=me->query_temp("weapon"))
    {
     if((string)ob->query("skill_type") != "unarmed")
      return   notify_fail("不空手怎么发浩日诀?\n");
    }
   if(me->query("force")<400)
     return notify_fail("你的内力不够。\n");
   if(me->query("kee")<250)
     return notify_fail("你的气不够。\n");
   if(!me->is_fighting(target))
    {
     tell_object(me,"浩日罡\气唯在战斗中才能使用。\n");
     return 0;
    }
    value = me->query("functions/kang_kee/level");
    value=value+((int)me->query_skill("haoforce",1) / 2);

    k_level = value;

    if(!target) return notify_fail("你找不到敌人在那!!\n");
   if ( (k_level > 110) && (me->query_skill("fire-kee",1) > 60))
   {
    message_vision(
       "[1m$N双手合十向前指去，使出浩日罡\气中的必杀奥义★★--[1;31m烈日诀[0m[1m--★★\n
          霎时间$N的烈日护身气劲逆流，一股至阳刚烈的真气充斥在$N的手上\n
          $N的双掌散发出炙热的光芒，指尖聚集了无数颗的明亮的光球\n\n",me,target);
    message_vision(
       "[1m$N狂吼一声，无数的「烈日罡\气”向$n射去！[1;31m\n
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
          -------------------------------------------------------------*
    [0m\n",me,target);
    me->add("kee",-70);
    me->add("force",-(k_level*4));
   }else
   if ( (k_level > 90) && (me->query_skill("fire-kee",1) > 30))
   {
    message_vision(
       "[1m$N将双掌成虎形，使出浩日罡\气中的必杀技☆☆--[1;31m浩日诀[0m[1m--☆☆\n
          $N将十尺内的热气集中在双掌之内，只见$N的双掌发出阵阵闷热的气劲\n
          $N双掌发光炙热，掌中聚集一颗明亮的光球\n\n",me,target);
    message_vision(
       "[1m$N双掌向前一推，掌中的「浩日罡\气”向$n射出！[1;31m\n
          -------------------------------------------------------------*
          =============================================================***
          -------------------------------------------------------------*
    [0m\n",me,target);
    me->add("kee",-50);
    me->add("force",-(k_level*3));
   }else
   if ( k_level > 70)
   {
    message_vision(
       "[1m$N将手向天一指，运起浩日罡\气中的「[1;33m赤日诀[0m[1m”\n
          $N把太阳的光线集中在手中，一股至阳刚烈的内劲从丹田升起，\n
          $N全身发光炙热，指尖聚集一颗明亮的光球\n\n",me,target);
    message_vision(
       "[1m$N运劲指尖，一道「赤日罡\气”向$n射去！[1;33m\n
                                                             * *
         =====================================================* *
                                                             * *
       [0m\n",me,target);
    me->add("kee",-40);
    me->add("force",-(k_level*2));
   }else
   {
    message_vision(
       "[1m$N低吼一声!!跃至空中使出浩日罡\气中的「[1;33m旭日诀[0m[1m”\n
          $N在半空如太阳般散出至阳刚烈的真气，$N将真气聚在掌上\n
          真气的聚集使$N的双掌炙热通红，发出辉眼光芒!!\n\n",me,target);
    message_vision(
       "[1m$N运劲以足，将「旭日罡\气”从天空向$n射去！[0m\n",me,target);
    me->add("kee",-30);
    me->add("force",-(k_level));
   }
if(80>random(100))
    {
     message_vision(
     "\n[1;31m$n躲避不及，被罡\气击中，霎时烈火笼罩$n全身，嘶嚎不断！\n[0m",me,target);
     message_vision( NOR,me);

if(me->query_temp("kang-power")&&me->query("id")==("master jen")) {
message_vision(HIW"$N身上的‘烈焰浩气’与‘浩日罡\气’相辅相成提升了威力重创了$n。"NOR,me,target);
message_vision("\n",me);
target->receive_wound("kee",4000);
}

     target->apply_condition("burn",random(15)+1);
     target->receive_wound("kee",(k_level*4)+200);
     COMBAT_D->report_status(target);
    }
   else
    {
     if (((string)target->query_skill_mapped("parry") == "fire-kee") &&
         (random(target->query_skill("fire-kee")) > 40))
      {
       message_vision(
"[1;37m\n$n使出浩日护身气劲之终极绝招【[1;33m--烈--火--无--限--[1;37m】\n
只见$N的罡\气和$n护身气劲相撞，轰～～一声二人四周发出漫天炙热气劲。[0m\n",me,target);
       message_vision( NOR,me);
      }
     else
     if (((string)target->query_skill_mapped("parry") == "snow-kee") &&
         (random(target->query_skill("snow-kee")) > 50))
      {
       message_vision(
      "[1;36m\n$n使出雪苍寒劲之终极绝招【[1;37m--冰--风--雪--暴--[1;36m】\n
只见$N的罡\n气和$n护身寒劲相撞，轰～～一声四周散出雾气。[0m\n",me,target);
       message_vision( NOR,me);
      }
     else
      {
       message_vision(
       "[31m$n运功避开，但仍受罡\气侵袭，只见$n的伤口焦黑一块。[0m\n",me,target);
       message_vision( NOR,me);
       target->apply_condition("burn",random(15)+1);
       COMBAT_D->report_status(target);
      }
    }
    message_vision(
    "「浩日罡\气”射出后，$N大耗内力、赶紧趁机调息内息\n",me,target);
    me->start_busy(1);
    if(me->query("functions/kang_kee/level") < 100)
    function_improved("kang_kee",random(me->query("max_force")/10));
    message_vision( NOR,me);
    return 1;
  }
