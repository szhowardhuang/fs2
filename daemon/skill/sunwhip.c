// 落日鞭法 ------by rence
// by hana 1997/3/2
 
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void hurt(object me, object victim, object weapon, int damage);
void bleed(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
int age = this_player()->query("age",1);
int lv  = this_player()->query_skill("sunwhip",1);

mapping *action = ({
        ([      "action":"\n$N使出落日鞭法第一式[33m「日落西山”[0m，手中$w横扫$n的$l\n",
                "dodge":                -20,
                "damage":              30,
                "damage_type": "鞭伤",
        ]),

        ([      "action":"\n$N使出落日鞭法的第二式[33m「日下无双”[0m，手中$w在空中连划几个圈之后向$n$l劈下\n",
                "dodge":                -20,
                "damage":                   40,
                "damage_type":  "割伤",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n$N一个飞身, 如大鹰觅食, 落日鞭法第三式[33m「夸父追日”[0m，手中$w拂向$n$l\n",
                "dodge":                -30,
                "damage":              50,
                "damage_type":  "割伤",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$N手中$w盘旋数圈，落日鞭法第四式[33m「如日中天”[0m对准$n$l由下往上直掼了过去\n",
                "dodge":                -40,
                "damage":              60,
                "damage_type":  "刺伤",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N纵身一跃，手中$w使出第五式[33m「日升月恒”[0m往$n$l直直落下\n",
                "dodge":                -40,
                "damage":              70,
                "damage_type":  "淤伤",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$N的$w如长蛇游戏一般，活灵活现, 第六式[33m「扶摇直上”[0m诡谲地向$n的$l卷去\n",
                "dodge":                -20,
                "damage":              80,
                "damage_type":  "刺伤",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n$N双手握住$w，劲贯于上, 使出落日鞭法第七式[33m「日月如梭”[0m, 鞭尾化成利剑向$n$l刺去\n",
                "dodge":                -20,
                "damage":              90,
                "damage_type":  "刺伤",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N大吼一声，落日鞭法第八式[33m「日月重光”[0m在半空挥出一道圆弧后, 斜斜扫向$n$l\n",
                "dodge":                -30,
                "damage":               100,
                "damage_type":  "砍伤",
                "post_action": (: bleed :),
        ]),

        ([      "action":"\n$N使出落日鞭法第九式[33m「日落归雁”[0m，劲透长鞭, 手中$w如剑一般疾点$n的$l\n",
                "dodge":                -30,
                "damage":              110,
                "damage_type":  "刺伤",
                "post_action": (: hurt :),
        ]),

        ([      "action":"\n$N身形连续打转，使出鞭法第十式[33m「日暮途穷”[0m，$w化成弧光冲向$n的退路\n",
                "dodge":                -30,
                "damage":              120,
                "damage_type":  "瘀伤",
                "post_action": (: conti :),
        ]),

        ([      "action":"\n\t\t[36m突然间风声大作，日月无光！$领悟了落日鞭法之最高境界！\n\n\t\t\t\t[35m【 后 羿 射 日 】[0m\n\n只见满天鞭影密不透风地笼罩着$n[0m\n",
                "dodge":                -30,
                "damage":              150,
                "damage_type":  "刺伤",
                "post_action": (: hurt :),
        ]),
});

void hurt(object me, object victim, object weapon, int damage)
{
        if( me->query("force_factor") > 5 )
        if( random(150) < random(lv))
        {
          victim->receive_damage("kee",lv*age/30);
          message_vision(HIM"$N将真气灌入鞭中射向$n，$n一阵哀嚎，显然受了不小的内伤。\n"NOR,me,victim);
          COMBAT_D->report_status(victim);
        }
}
void bleed(object me, object victim, object weapon, int damage)
{
        if(damage > 40)
        {
          victim->apply_condition("bleeding", random(lv*age)/100);
          message_vision("[1;36m$N落日鞭法的气劲贯穿$n，破体而出！[0m\n",me,victim);
        }
}

void conti(object me, object victim, object weapon, int damage)
{
        int i;
        int lv1 = victim->query_skill("dodge",1);
        if( me->query("force_factor") >= 10 )
        {
          if( random(lv) > random(lv1) && me->query_temp("conti") == 0 )
            {
            me->set_temp("conti",1);
            message_vision("\n[1;33m$N忽然顿悟落日鞭法[1;33m的要诀，手中$w猛往$n身上招呼!![0m\n" ,me);
            for(i=0;  i <=   age/5  ;  i++)
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
            }
        }
}
int valid_learn(object me)
{
        object ob;
        //鞭法是第二专长, 将内力限制在50以上才能学  by hana
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("你必须先装备鞭类武器才行。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("sunwhip", 1);
        limit= (int)(skill_level/9);
        if (limit < 1 )
                return action[random(1)];
        if (limit < 2 )
                return action[random(2)];
        if (limit < 3 )
                return action[random(3)];
        if (limit < 4 )
                return action[random(4)];
        if (limit < 5 )
                return action[random(4)+1];
        if (limit < 6 )
                return action[random(4)+2];
        if (limit < 8 )
                return action[random(4)+3];
        else if (limit < 10)
                return action[random(4)+4];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        //鞭法不是圣火第一专长, 故气与内力限制不必太严  by hana
        if ((int)me->query("kee") < 10)
        {
            return notify_fail("你的气不足，无法练习落日鞭法。\n");
        } else if ((int)me->query("force") < 10)
        {
            return notify_fail("你的内力不够，无法练习落日鞭法。\n");
        }
        me->receive_damage("kee", 10);
        me->add("force", -10);
        write("你按着所学练了一遍落日鞭法。\n");
        return 1;
}

