// enable-archery.c
// by airke
// By Swy 最后修正 QC 98/6/23
#include <combat.h>
#include <ansi.h>
inherit SKILL;

void god_att(object me, object victim, object  weapon, int damage);
void shooting_att(object me,object victim, object weapon,int damage);

// 有箭时的叙述 $w是弓 $c 是箭
//应玩家要求.增加连击 by poloer
mapping *arrow_action = ({
        ([      "action":
"$N心中一急，迅速将$c搭于$w之上，使出流星箭法第一式"HIC"「一泄千里”"NOR"，箭势如洪水狂泄般朝$n$l飞射而去",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射伤",
        ]),
([        "action":
"$N将手上$c迅速搭于$w分为两次射出，使出流星箭法第二式"HIG"「双龙出海”"NOR"，分射出之$c如双龙狂噬般朝$n而去",
                "dodge":        -100,
                "damage":       130,
                "force" :       130,
                "damage_type": "射伤",
                "parry":        -100,
        ]),
        ([      "action":
"$N霸气突涨，将手中$c迅速搭于$w三箭齐发，使出流星箭法第三式"HIB"「三分鼎足”"NOR"，射出的$c似含三国鼎立之霸气分三处向$n急射而去",
                "dodge":        -100,
                "damage":       130,
                "force":         130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
        ([      "action":
"$N被$n攻势所惊吓，将手中$c迅速搭于$w之上分射四箭，使出流星箭法第四式"HIY"「四面楚歌”"NOR"，射出的$c似有灵性般由$n前后左右四面飞射而去",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
        ([      "action":
"$N心中杀气突涨，将手中$c迅速搭于$w上五箭齐射，杀气融合于$c使出流星箭法第五式"HIW"「五马分尸”"NOR"，$c朝$n头及双手双脚齐射而去",
                "dodge":        -100,
                "damage":       110,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
        ([      "action":
"$N将手中$c迅速搭于$w，射出之际融入旋转气劲使出流星箭法第六式"HIG"「六道轮回”"NOR"，$c急速旋转朝着$n急射而去",
                "dodge":        -100,
                "damage":       115,
                "foece":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
        ([      "action":
"$N将手中$c迅速搭于$w连续射出七箭，使出流星箭法第七式"HIM"「七星连线”"NOR"，$c七箭一箭接着一箭形成一线朝$n急射而去",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
        ([      "action":
"$N将手中$c迅速搭于$w缓缓射出，使出流星箭法第八式"HIC"「八仙过海”"NOR"，$c如同仙人过海般缥缈般令$n不知所措",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
                "post_action":  (: god_att :),
        ]),
        ([      "action":
"$N将手中$c迅速搭于$w缓缓射出九箭，使出流星箭法第九式"HIR"「九九归元”"NOR"，射出九箭合一，令$n无法招架",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射伤",
                "post_action":  (: shooting_att :),
        ]),

});

// 下面是没箭时的攻击叙述

mapping *bow_action = ({
        ([      "action":               "$N举起$w狠狠地往$n$l砸去",
                "dodge":        -10,
                "damage":       10,
                "parry":        -10,
                "damage_type":  "瘀伤",

        ]),
        ([      "action":               "$N吃力地挥舞$w试着打伤$n",
                "dodge":        -5,
                "damage":       15,
                "parry":        -10,
                "damage_type":    "瘀伤",

        ]),
});

int valid_learn(object me)
{
        object ob;

if(me->query_skill("archery",1)<15)
                return notify_fail("要练流星箭法要先有相当的弓箭基础。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type")!="archery")
                return notify_fail("你手上要有弓箭才能练流星箭法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="archery" || usage=="parry";
}


mapping query_action(object me, object weapon)
{
  int skill_level, limit;
  object wpn = me->query_temp("weapon");
  int i;
//以下几行都是必须的..
//-----------------------------------------------------
//
// i = 目前弓上的箭数
  i=wpn->query("arrow/amount");
if ( !userp(me) )
        i ++;

//战斗中射完也必须将弓初始化
// 1的时候就可以初始化....因为初始化完还会攻击一次

 if(i==1) {
        tell_object(me, "\n你的" + wpn->query("arrow/name") + "用完了！\n\n");
        wpn->set("arrow/id","none");
        wpn->set("arrow/name","空的");
        wpn->set("weapon_prop/damage",wpn->query("bow/attack"));

  }
  if (i > 0) {
        i--;
        wpn->set("arrow/amount",i);
                // 呼叫有箭时的叙述
        return arrow_action[random(sizeof(arrow_action))];
  }

  if( i <= 0) {
                //呼叫没箭的攻击叙述
        return bow_action[random(sizeof(bow_action))];
  }
//----- under by poloer from --------------------------------------------


        skill_level=(int)me->query_skill("god-shooting", 1);
       if (skill_level < 10)
                return arrow_action[random(2)];
        else if (skill_level < 20 )
                return arrow_action[random(3)];
        else if (skill_level < 30 )
               return arrow_action[random(4)];
                else if (skill_level < 50 )
                return arrow_action[random(5)];
               else if (skill_level < 70 )
                       return arrow_action[random(6)];
               else if (skill_level < 80 )
                      return arrow_action[random(6)+1];
        else if(skill_level<90)
return arrow_action[random(6)+2];
        else
return arrow_action[random(6)+3];


}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，不能练流星箭法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("marksman")+"/god-shooting/"+action;
}

void god_att(object me, object victim, object  weapon, int damage)
{
if((random(80)<me->query_skill("iceforce",1))&&!me->set_temp("break"))
{
victim->start_busy(1);
message_vision(HIB"$N暗使冰心诀之阴寒内劲，将$n受内劲所困动弹不得。\n"NOR, me, victim);

}
}

void shooting_att(object me, object victim, object  weapon, int damage)
{
        int lose, i;
int bellpower = (int)me->query("cps")/3;
        // modify by oda
        // combat_exp 之比较在自身之 exp 加上 random
        // lose = skill/10 + 1 改为 random(skill/10) + 3
        // 增加连击完毕 busy 一回合
if(random(100)<70)
        {
        if(bellpower > 5) bellpower=5;
        lose=random(10);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
       message_vision(HIR"$N拿起数支箭使劲的往$n连射过去。\n"NOR, me,victim);
                       }
                victim->add("kee",-50);
                me->delete_temp("berserk");
                message_vision(HIW"一阵混乱后，$N用劲过度，赶紧趁机调息。\n"NOR,me);

        }
}
