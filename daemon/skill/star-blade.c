//星夜艳梦刀法 by roger && taifar
//金风细雨第九楼楼主李梦枕skill
#include <combat.h>
#include <ansi.h>
void sp_attack(object me,object victim,object weapon,int damage);
void sp_attack1(object me,object victim,object weapon,int damage);
void sp_attack2(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":HIC"$N轻舞$w使出一式"HIY"‘夜女清芬’"HIC"，刀光悠远，像丽人倩影圈撒淡淡香氲，艳烈的刀气瞬间直奔$n喉间"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍伤",
        "weapon"     :  "情刀",
        ]),
(["action":HIC"$N刀锋侧转使出一式"HIY"‘夕若蘅芷’"HIC"，伴着红红刀光沁出郁郁香气，刃随风卷，赤虹刀气如夕霞突落在$n眼前"NOR,
           "damage":           850,
           "force":            850,
           "damage_type":  "割伤",
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍伤",
           "weapon"     :  "情刀",
          ]),
(["action":HIC"$N倏地回刀，一式"HIY"‘梦醉风铃’"HIC"的破风声犹如一串风过时的铃响，刀气形成美丽的弧线高掠过空直坠$n脑门"NOR,
           "damage":      850,
           "force":       850,
           "damage_type":  "砍伤",

        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
           "weapon"     :  "情刀",
           ]),

(["action":HIC"$N飞身一式"HIY"‘星香蕉叶’"HIC"，刀光轮转，身影轻的就像一阵微风迫近$n，刃裂狂旋，乱扫$n的四肢"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤",
        "weapon"     :  "情刀",
            ]),
(["action":HIC"$N压身反转刀柄突刺$n的双膝使出"HIY"‘星夜醉梦刀法’"HIC"中的"HIY"‘睡露海棠’"HIC"，在眨眼间回刀上扬平扫落刃袭向$n$l"NOR,
        "damage":       850,
        "force":        850,
        "damage_type": "劈伤",
        "post_action":          (: sp_attack:),
        "weapon"     :  "情刀",
        ]),
(["action":HIC"$N提足划上"HIY"‘星夜醉梦刀法’"HIC"，使出了一式‘借柳挂月’，$w在空中旋出粼粼弧光飒成银月，月凛刀气直落$n$l"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤",
        "weapon"     :  "情刀",
        ]),
(["action":HIC"$N若有似无，藉由"HIY"‘星夜醉梦刀法’"HIC"刀意，使出了一式‘如梦似醉’，$w在$N手中划出阵阵银光直落$n$l"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (:sp_attack2:),
        "damage_type": "劈伤",
        "weapon"     :  "情刀",
        ]),

});

int valid_enable(string usage)
{
        return (usage=="blade")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

void sp_attack(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM"\n$N随风一笑，情刀流香郁郁，星光迷离，刀光一散如细细的雨般往$n洒去，令人陶醉 \n"NOR,me,victim);
  victim->start_busy(2);
  me->set_temp("conti",1);
   for(i=0;i<5;i++)
    
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                   
  me->delete_temp("conti");
                     }
}
void sp_attack1(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM"\n$N随风一笑，情刀流香郁郁，星光迷离，刀光一散如细细的雨般往$n洒去，令人陶醉 \n"NOR,me,victim);
  me->set_temp("conti",1);
   for(i=0;i<2;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

  me->delete_temp("conti");
                     }
}
void sp_attack2(object me,object victim, object weapon,int damage)
{
 message_vision(sprintf(HIC"$N人随意转，转眼间来到$n身后，$n发觉急忙转身回挡，只见$N绕到另一侧并使出其本身真气发出流星般的一击 \n"NOR),me,victim);
 victim->start_busy(2);
 message_vision(sprintf(HIC"$n中招后愣了一下，瞬间$N浩翰真气已席卷而至 \n"NOR),me,victim);
 victim->apply_condition("tsunami",random(4)+2);
 COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
 }

