// 如来神掌  by weiwei and smooth
#include <combat.h>
inherit SKILL;

void ru10(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);

mapping *action = ({
([ "action" : "$N吐气扬眉,身形一顿,一道[1;33m金光[0m自右掌中浮出,正是一招[5;1;33m ‘佛光初现’[0m。",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    50,
                "force"      :    50,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N闭目[1m合眉[0m,双掌合什,倏然欺身而上,一招 [5;1;33m ‘金顶佛灯’[0m,$n已笼罩$n周身七十二大穴。",
                "dodge"      :    -30,
                "parry"      :    -20,
                "damage"     :     60,
                "force"      :     60,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N大喝一声,气冲丹田,一招[5;1;33m ‘佛动山河’[0m顺势而出,只见掌影飘飘,当真有开山劈石之势。",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    70,
                "force"      :    70,
                "damage_type":   "瘀伤",
             ]),
([ "action" : "$N气凝丹田,纳气回身,掌缘微微上扬,[5;1;33m ‘佛问迦罗’[0m凌厉的掌气已使$n挡无可挡,避无可避。",
                "dodge"      :   -50,
                "parry"      :   -30,
                "damage"     :    80,
                "force"      :    80,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N心中一动,挥掌拧身,突地向$n右肩[1m‘肩井’[0m穴拍下,只见$n一个[1;32m鹞子翻身[0m,高高跃起,$N身随意动,掌影顺势上扬,一招[5;1;33m ‘迎佛西天’[0m ,便向$n冲去。",
                "dodge"      :   -50,
                "parry"      :   -20,
                "damage"     :    90,
                "force"      :    90,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N身形似箭,足不着地,掌缘隐隐有[1m佛光围绕[0m,霎时一招失传已久的[5;1;33m[佛光普照][0m ,自掌中发出,[1;31m惊雷[0m般的向$n直射而去。",
                "dodge"      :   -60,
                "parry"      :   -20,
                "damage"     :    100,
                "force"      :    100,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N双膝盘合,两掌沉地,身形冉冉向上浮起。[5;1;33m ‘天佛降世’[0m挟着飞砂走石,雷霆万钧之势扑面迎向$n。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    110,
                "force"      :    110,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N[1m左手[1;36m离火[0m,[1m右手[31m玄冰[0m,[1m脸色[1;36m忽青[0m[1;31m忽红[0m,赫然便是[1m如来秘技之[5;1;33m ‘万佛朝宗’[0m ,煞时间天地变色,佛影飘然,只见$n低下斗大的汗珠,[1m如坠[31m炼狱[0m,[1m如堕[36m冰窟[0m。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    120,
                "force"      :    120,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N[1m心如止水,拈叶微笑[0m。低诵一声[5;1;33m ‘ 佛 法 无 边 ’[0m,只见$N[1;33m佛光聚顶,祥瑞之气环身[0m。便
在此时,$n胆颤惊叫[1m‘如来..如来再现’[0m,霎时$N双眼精光暴射,喝道:[1;32m‘八式齐发,毁天灭地’[0m,浑身佛影幢幢,真气自掌中激射而出。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    130,
                "force"      :    130,
                "damage_type":   "瘀伤",
                "post_action": (: conti :),
           ]),
  });

void conti(object me, object victim, object weapon, int damage)
{
        int i;
        int level=(int)(me->query_skill("rulai",1)/10);
        if (level > 6)
        {
  if( me->query_temp("rulai") == 0 && me->query("class")=="bonze" )
          {
              me->set_temp("rulai",1);
              message_vision(sprintf("\n[35;1m$N一手指天，一手指地，大喝一声[5;37m ‘ 上天下地，唯我独尊！ ’[0m\n"),me);
              for(i=1;i<=10;i++)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              me->delete_temp("rulai");
             me->start_busy(1);
          }
        } 
}
mapping query_action(object me,object weapon)
{
int skill_level, limit;
        skill_level = (int)(me->query_skill("rulai", 1));
        limit= (int)(skill_level/10);
        if (limit < 4 )
                return action[random(4)];
        if (limit < 7 )
                return action[random(limit)];
        else
                    return action[random(4)+5];
}

int valid_enable(string usage) 
{
       return (usage=="unarmed")||(usage=="parry");
}
int valid_learn(object me)
{
     return 1;
}
int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("练如来神掌还是要空手吧....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不够，无法练习。\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前内力不足,休息一会儿再练吧.\n");
        if( me->query("max_force") < 3000 )
          return notify_fail("你的内力不够高,强加练习将会走火入魔。\n");
         if( me->query_skill("literate",1) < me->query_skill("rulai",1) )
          return notify_fail("你的知识不足以体会如来神掌的高深。\n");
        me->receive_damage("gin", 5);
        me->add("force", -1);
        return 1;
}


