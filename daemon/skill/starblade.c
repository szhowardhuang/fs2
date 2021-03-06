//星夜艳梦刀法 by roger

#include <combat.h>
#include <ansi.h>
void sp_attack(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":HIG"$N轻舞手中的$w，刀光悠远，像美丽的女子在情人的诗句下圈下一道眉批；刀色淡淡，如远山之望眉，夕照之依稀；刀亦未尽，轻盈若诗，优美如梦"NOR,
        "damage":       30,
        "dodge":        200,
        "parry":         5,
        "force":        200,
        "damage_type":  "砍伤",
        ]),
(["action":HIY"$N一动，刀光突至，轻的就像一阵微风，柔得就像一抹月色。$n遇上这么轻、这么柔、这么曼妙的刀法，一时不知如何抵御。刀光倏没。"NOR,
           "damage":           200,
           "dodge":            20,
           "parry":            10,
           "force":            200,
           "damage_type":  "割伤"
          ]),
(["action":HIC"$N拔刀，刀声优美，像美丽女子的一声清吟，像一串风过时的铃铛，荡人心魄。刀挥动时还带着一种音韵一般的声响，掠起微微香气，一种令人失魂的刀法。"NOR,
           "damage":      200,
           "dodge":       -5,
           "parry":       15,
           "force":       200,
        "damage_type":  "砍伤"
           ]),

(["action":HIW"$N拔出$w，刀光惊艳般的亮起，如流星自长空划过，仿佛是初燃的灯影、处子的眼波；依稀是情人的美靥，犹似是落花醉楼人。那样的不可抗拒，犹似身处艳梦中。"NOR,
        "damage":       200,
        "dodge":        -20,
        "parry":        20,
        "force":        200,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤"
            ]),
(["action":HIG"$N叹息一声，随叹息而出刀，刀像一首优美的诗，刀像梦。梦，梦里花落，梦里花落知多少？‘梦里花落’正是这一刀的名称"NOR,
        "damage":       200,
        "dodge":        -20,
        "parry":        25,
        "force":        200,
        "damage_type": "劈伤"
        ]),
(["action":HIY"$N一刀挥出，像一道岁月的梦痕，带着三分惊艳、三分潇洒、三分惆怅，和一分的不可一世。"NOR,
        "damage":       200,
        "force":        200,
        "parry":        30,
        "dodge":        -10,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤"
        ]),
(["action":HIG"刀荡刀风，美丽的刀影，如情人的倩影；刀略起时，带着微微的香气与呻吟，刀弯处像美人的柔肩，刀落时还带着些许美丽的风华。刀清艳。"NOR,
        "damage":       200,
        "parry":        20,
        "dodge":        -10,
        "force":        200,
        "post_action":          (: sp_attack:),
        "damage_type": "砍伤"
        ]),
(["action":HIY"$N出刀，劈出‘细雨黄昏’，刀美如梦，彩色缤纷，尤其是血也似的溅红。刀回转，带出残酷的现实；刀过处，黑里溅出厉红。每一刀挥出，$N的生命凄艳亮烈、优美如梦"NOR,
        "damage":       200,
        "force":        200,
        "parry":        30,
        "dodge":        0,
        "post_action":          (: sp_attack:),
        "damage_type":  "砍伤"
        ]),

});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 50)
        return notify_fail("你的内力不够，没有办法练星夜艳梦刀法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade")
                return notify_fail("你必须先找一把刀才能练刀法。\n");
        return 1;
}

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
 if(random(100) > 50){
message_vision(HIM"\n那么惊艳的刀法，看来，谁都愿意为这一刀而死，为这一刀而生，为这一刀而不顾生死\n"NOR,me);
  me->set_temp("conti",1);
   for(i=0;i<3;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
  me->delete_temp("conti");
                     }
}

