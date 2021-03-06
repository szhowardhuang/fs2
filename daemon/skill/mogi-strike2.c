// 天残手 by roger
// 这是魔界mob 的专用skill之一
#include <ansi.h>
#include <combat.h>
inherit SKILL;

void blood(object me, object victim, object  weapon, int damage);
void super(object me, object victim, object  weapon, int damage);
string *parry_msg= ({
   "$n双手往上一翻, 双脚蹲了个马步, 使出一招「妖魔聚鼎”, 将妖气凝聚于全身上下, 硬生生的把$N的招式接了下来!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖拦路”, 三指由中宫飞快的探向$n的咽喉, 破解了$N的攻势。\n",
});

mapping *action = ({
([ "action" : HIM"$N使出魔域"HIB"‘"HIM"天残手"HIB"’"HIM"中的绝招"HIB"‘"HIM"天残刀气"HIB"’"HIM"，右手一动一道刀气便直奔向$n刹那间$n的$l已被割伤...\n"NOR,
        "dodge":   20,
        "parry":   20,
        "damage":   250,
        "force":    290,        
        "damage_type" : "割伤"
        
]),

([ "action" :HIM"$N使出魔域"HIB"‘"HIM"天残手"HIB"’"HIM"中的"HIB"‘"HIM"天残锁功手"HIB"’"HIM"伸手遥抓一探便使得$n的内息无法发挥，功力尽被$N锁住!!\n"NOR,
        "dodge":   30,
        "parry":   30,
        "damage":   250,
        "force":    270,
        "damage_type" : "气血逆行"
]),

([ "action" :HIM"$N使出"HIB"‘"HIM"天残手"HIB"’"HIM"中的"HIB"‘"HIM"分筋错骨"HIB"’"HIM"，双手一探，顺势一扭，一挫，$n嚎叫连连原来$n的筋脉已被错开，手法之残忍不禁令人毛骨悚然...\n"NOR,
        "dodge":   30,
        "parry":    30,
        "damage":   250,
        "force":    290,
        "damage_type" : "筋脉挫伤"
]),

([ "action" :HIM "$N使出了"HIB"‘"HIM"天残一气指"HIB"’"HIM"食指一伸一道凌厉的指力往$n的$l射出，四周生物被这到凌厉之气所扫，非死即碎!!\n"NOR,
        "dodge":    30,
        "parry":    30,
        "damage":   270,
        "force":    300,
        "damage_type" : "刺伤"
]),

([ "action" :HIM"$N将全身真气聚于胸前，聚气凝功，四周地面刹那间不断震动，狂风大作，正是"HIB"‘"HIM"天残手"HIB"’"HIM"的超级绝招"HIB"‘"HIM"天残轰天击"HIB"’"HIM"的前奏!!蓦然$N一声大喝，将所聚之真气一次激出，狠狠地射向$n的胸口!!\n"NOR,
        "dodge":   100,
        "parry":   100,
        "damage":   240,
        "force":    270,
        "post_action":  (:super:),
        "damage_type" : "炸伤"
]),


});


void super(object me, object victim, object  weapon, int damage)
{
  message_vision(HIR"结果$N所凝的真气在$n的胸口疯狂炸开，血花四溅，令人触目心惊!!\n"NOR,me,victim);
  victim->receive_damage("kee",190,me);
  COMBAT_D->report_status(victim);
}
int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="parry");
}


mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
    return parry_msg[random(sizeof(parry_msg))];
}
