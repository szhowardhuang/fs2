//血战十式 by bss
//皇城mob专用，不开放
#include <ansi.h>
#include <combat.h>
void sp_attack(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":
HIC"$N手中刀身前探，使出"HIR"血战十式"HIC"的起手式"BLINK+HIY"「两军对垒”"NOR""HIC"，一道道如热风般的刀气由$w"HIC"散出，
$N脚下一动，向$n狂奔而至，手中$w"HIC"毫无花巧的砍向了$n的$l，其招意在于以稳固之阵式
喝阻敌方，使敌方不敢轻举妄动。"NOR,
        "damage":       100,
        "force":        100,
        "damage_type" : "砍伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
HIC"$N忽然冷笑一声，手中$w"HIC"化作一道黄芒，砍向$n的$l，正是"HIR"血战十式"HIC"的第二式"BLINK+HIY"「烽芒毕露”"NOR""HIC"，
其招意在以全军最强之攻势攻击敌方，使敌方陷于被动之状态，使主动权在我方，$n受到
$N那一声冷笑的影响，稍微迟疑了一下，黄芒却已经逼近了。"NOR,
           "damage":           300,
           "force":            100,
        "damage_type" : "砍伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
        "post_action":          (: sp_attack:),
]),
(["action":
HIC"$N身形展开，脚下一快，$w"HIC"有如一道利刃般刺向了$n的$l，正是"HIR"血战十式"HIC"的第三式"BLINK+HIY"「轻骑突出”"NOR""HIC"，
其招意在以快速准确的攻击，攻破对方防线，使敌方自乱阵脚，因招式所带起的刀气，如旋
风般已先一步的攻向$n。"NOR,
           "damage":      300,
           "force":       100,
        "damage_type" : "刺伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
HIC"$N手中$w"HIC"向前一探，刀尖挑向$n左腋下的渊腋穴，正是"HIR"血战十式"HIC"中的第四式"BLINK+HIY"「探囊取物”"NOR""HIC"，
因招式所引起的刀气牢牢锁定着$n，$n见刀势猛烈，忙展开身形，务必要躲开这致命的一
刀。"NOR,
        "damage":       300,
        "force":        100,
        "damage_type" : "刺伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
HIC"$N眼中精光大放，将气势升高至最顶点，刀身前放，忽地大喊"BLINK+HIW"「必杀一击”"NOR""HIC"，身子疾往前
冲，$n被$N那一去无回的气势所吓了一大跳，此招正是"HIR"血战十式"HIC"中的第五式"BLINK+HIY"「一战功成”"NOR""HIC"，
其招意在以此一招达到致敌于死地的效果，毕其功于一役。"NOR,
        "damage":       300,
        "force":        100,
        "damage_type": "劈伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
HIC"$N手中$w"HIC"忽然脱手，正当$n以为有机可乘之际，$N以右手的中指及食指连着刀柄，忽然快
速的劈出上六路，中六路，下六路，共十八刀，正是"HIR"血战十式"HIC"中的第六式"BLINK+HIY"「批亢捣虚”"NOR""HIC"，
其招意在不论敌方攻势如何，皆以此猛烈之形式击出，以吓退敌人，达到不战而驱人之兵
的兵法最高境界。"NOR,
        "damage":       300,
        "force":        100,
        "damage_type": "劈伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
HIC"$N手中$w"HIC"忽然开始随意的晃动，越晃越快，渐渐地失去了$w"HIC"的影子，$n只觉得$w"HIC"随时有可
能从任何一个地方砍向自己，此招正是"HIR"血战十式"HIC"中的第七式"BLINK+HIY"「兵无常势”"NOR""HIC"，其招意在以绝
快的行动奇袭敌方，攻其不备，使敌方重创。"NOR,
        "damage":       300,
        "force":        100,
        "damage_type": "砍伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
HIC"$N忽然暴喝一声："BLINK+HIG"「狗贼！！今日不是你死就是我亡”"NOR""HIC"，双手将$w"HIC"高举过头，猛力向下一
劈，其刀气大有可以开山断海的气势，此招正是"HIR"血战十式"HIC"中的第八式"BLINK+HIY"「死生存亡”"NOR""HIC"，其招
意在以全身劲力劈出这惊天一刀，以此惊天刀势歼杀敌方。"NOR,
        "damage":       300,
        "force":        100,
        "damage_type": "劈伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
        "post_action":          (: sp_attack:),
]),
(["action":
HIC"$N向前大跨一步，杀气忽然由$N的身旁涌出，$N眼中血光一现，霍地旋身而起，刀随身转，
旋风般攻向$n，此招正是"HIR"血战十式"HIC"中的第九式"BLINK+HIY"「强而避之”"NOR""HIC"，其招意在以自身为穿透敌方
防阵的凿子，破入敌方阵地，以收里外挟攻，事半功倍之用。"NOR,
        "damage":       300,
        "force":        100,
        "damage_type": "割伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
HIC"$N握紧手中$w"HIC"，将全身真力贯入$w"HIC"内，霎那间狂风大作，四周激起了因招式而产生了飓风，
$n不敢相信世上竟有如此惊人之招式，一时间无法动作，$N眼看时机成熟，大喝一声：
"BLINK+HIM"「天降大任于我，～君～临～天～下～”"NOR""HIC"，刀势如雪花般飘向$n，此招正是"HIR"血战十式"HIC"中的
第十式"BLINK+HIY"「君临天下”"NOR""HIC"，其招意在以惊人攻势使敌方畏惧，使我方可以不费吹灰之力的取得
绝对的胜利。"NOR,
        "damage":       300,
        "force":        100,
        "damage_type": "砍伤",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
});
int valid_learn(object me)
{
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="blade");
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
void sp_attack(object me,object victim, object weapon,int damage)
{
 int i,j;
   if(40 > random(100) && !me->query_temp("conti")){
message_vision(HIY"\n$N杀的兴起，手中$n"HIY"忽然绽放金光，$n"HIY"有如神龙般使出连击技。\n"NOR,me,weapon);
victim->start_busy(random(4));
  me->set_temp("conti",1);
    switch(random(4)){
        case 1:
                j=1;
                break;
        case 2:
                j=2;
                break;
        case 3:
                j=3;
                break;
        case 0:
                 j=4;
                break;
        default:
                j=1;
                break;
     }
   for(i=0;i<j;i++)

    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

  me->delete_temp("conti");
    me->start_busy(1);
                     }
}
