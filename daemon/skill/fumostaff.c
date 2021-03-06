//fumostaff.c
#include <combat.h>
#include <ansi.h>
inherit SKILL;

mapping *action = ({
      ([      "action":         HIW"$N气凝丹田 ,一式"+HIC"「青龙出洞”"HIW+" ,手中的$w挟着呼呼风声向$n$l横扫过去"NOR,
        "damage":       40,
        "dodge":        10,
        "parry":        -20,
        "damage_type":  "击伤",
        ]),
   ([      "action":      HIW"$N一个纵跃 ,手中$w斜引 ,一招"+HIR"「伏虎势”"HIW+",似有千钧之力,从半空中直捣而下"NOR,
        "damage":           50,
           "dodge":           20,
             "parry":          -30,
        "damage_type":  "击伤"
          ]),
        ([         "action":         HIW"$N双目精光四射 ,口呼佛号,一招"+HIB"「苦海无涯”"HIW+",手中$w迅捷无伦的迎向$n$l"NOR,
           "damage":      70,
           "dodge":          0,
            "parry":         -50,
             "force":          100,
        "damage_type":  "击伤"
           ]),
        ([     "action":     HIW"$N口中念念有辞,运起"+HIM"「般若忏”"HIW+",手中的$w鸣声大作,嗡嗡地震的$n心中一颤"NOR,
           "damage":          80,
        "dodge":        -30,
        "parry":        10,
        "damage_type": "击伤"
            ]),
     ([      "action":      HIW"$N略一吐劲 ,力透经脉,全身骨骼爆起轻响 ,一招"+HIY"「破魔障”"HIW+",$w游龙似的往$n$l卷去"NOR,
        "damage":       100,
        "force":        100,
        "parry":        -30,
        "dodge":        -10,
        "damage_type": "击伤"
        ]),
      ([      "action":      HIW"$N力随意转 ,意守气海 ,一招"+HIC"「降妖伏魔”"HIW+",将手中的$w舞成一片"NOR,
        "damage":       130,
        "force":        130,
        "parry":        -20,
        "dodge":        0,
        "damage_type": "击伤"
        ]),
});
int valid_learn(object me)

{
                object ob;

                if( !(ob = me->query_temp("weapon"))

                ||     (string)ob->query("skill_type") != "staff" )

                       return notify_fail("你必须先找一根禅杖才能练杖法\n");

        return 1;
}
int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

/*void movedown(object me,object target, object weapon,int damage)
{
        if(random(3)>1)
               return;
        if(me->query("force")<20) return;
        me->add("force",-20);
          message_vision(
        HIG "$N使出「横扫六合” ,刀光四面铺开 ,把$n的整个身形笼罩在刀光之下 !\n"NOR,me,target);
        if (random(target->query("combat_exp"))<random(me->query("combat_exp")))
          {
                message_vision( GRN "结果$n气息一岔 ,登时动弹不得 !\n" NOR,me,target);
                target->start_busy(me->query_skill("gold-blade",1)/20);
          }
           else
                message_vision(   GRN "结果$n往后一跃 ,躲了过去。\n" NOR,me,target);
}*/
int practice_skill(object me)
{
        object weapon;

        if(me->query("max_force")/10<me->query_skill("gold-blade",1))
        return notify_fail("你内力不足 ,强自练习 ,只会受害。\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type")!="blade")
        return notify_fail("你要有适合的武器才能练习紫金六阳刀法。\n");

        if((int)me->query("kee")<30)
                return notify_fail("气不够啰 ,修息一下再练吧。\n");
        me->receive_damage("kee",30);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("bonze")+"/fumostaff/"+action;
}
