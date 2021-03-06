#include <combat.h>
#include <ansi.h>
inherit SKILL;
void hurt(object me, object victim, object weapon, int damage);
void block(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);

mapping *action = ({

//1
([ "action":
"$N拇指一拈，体内真气流转，使出"HIW"‘少商剑’"NOR"中的"HIY"‘穿云裂石’"NOR"，其雄劲的剑路，霸道的向$n$l激射而去，颇有石破天惊，风雨大至之势",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  50,
        "damage_type":  "刺伤",
        "weapon": "拇指剑气",
]),

//2
([ "action":
"$N劲透指尖，使出一招"HIG"‘岳峙渊渟’"NOR"，一道雄浑剑气直刺$n$l，其严谨中正之姿，正符合"HIW"‘少商剑’"NOR"大开大阖，气派雄伟的剑意",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  70,
        "damage_type":  "刺伤",
        "weapon": "拇指剑气",
]),

//3
([ "action":
"$N双指齐出，两股无形剑气互相激荡，直奔$n$l而去，正是"HIW"‘商阳剑’"NOR"中的绝招"HIR"‘日月同耀’"NOR,
        "dodge": -40,
        "parry": -15,
        "damage": 100,
        "force": 90,
        "damage_type": "刺伤",
        "weapon": "食指剑气",
]),

//4
([ "action":
"$N身形斗转，一招"HIC"‘雾卷云涌’"NOR"幻化出无数身影，$n顿时笼罩在"HIW"‘商阳剑’"NOR"无形剑气之下",
        "dodge": -40,
        "parry": -15,
        "damage": 200,
        "force": 120,
        "damage_type": "刺伤",
        "weapon": "食指剑气",
]),

//5
([ "action":
"$N坦然地弹出中指，使出"HIW"‘中冲剑’"NOR"中的"CYN"‘千古人龙’"NOR"，其剑势大开大阖，有如天外飞龙般，剑气凌厉地朝向$n$l而去",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 140,
        "damage_type": "刺伤",
        "weapon": "中指剑气",
        "post_action": (: block :),
]),

//6
([ "action":
"$N伸出中指，一招"HIW"‘中冲剑’"BLU"‘雷震九重天’"NOR"射向$n$l，其声势如落雷惊天，叫人不敢逼视",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 160,
        "damage_type": "刺伤",
        "weapon": "中指剑气",
        "post_action": (: block :),
]),

//7
([ "action":
"$N缓缓的伸出无名指，「丝丝”声起，正是"HIW"‘关冲剑’"NOR"中的"HIY"‘壮志凌云’"NOR"，其拙滞古朴的剑势笼罩住$n全身，直直的撞向其$l  ",
        "dodge": 25,
        "parry": 0,
        "damage": 200,
        "force": 180,
        "damage_type": "刺伤",
        "weapon": "无名指剑气",
]),

//8
([ "action":
"$N潜运内力，以静制动，一招"HIG"‘时雨春风’"NOR"指向$n正面三十六大穴，其势古朴，正是"HIW"‘关冲剑’"NOR"里的高招",
        "dodge": 25,
        "parry": 0,
        "damage": 150,
          "force": 200,
        "damage_type": "刺伤",
        "weapon": "无名指剑气",
]),

//9
([ "action":
"$N小指灵巧的转动，一招"HIW"‘少冲剑’"HIR"‘雪泥鸿爪’"NOR"刁钻的朝$n$l飞去，其势诡奇，叫人捉模不定",
        "dodge": -50,
        "parry": -20,
        "damage": 150,
        "force": 220,
        "damage_type": "刺伤",
        "weapon": "小指剑气",
        "post_action": (: hurt :),
]),

//10
([ "action":
"$N一招"HIW"‘少冲剑’"NOR"刺向$n胸口，尚有许尺，一斜身，小指回转，向$n$l削落，正是六脉神剑里的妙招"HIM"‘分花拂柳’"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 230,
        "damage_type": "割伤",
        "weapon": "小指剑气",
]),

//11
([ "action":
"$N轻巧的转动小指，使出一招"HIC"‘飞雁回翔’"NOR"，只见"HIW"‘少泽剑’"NOR"忽来忽去，有如灵蛇般的斜射$n$l",
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 250,
        "damage_type": "刺伤",
        "weapon": "小指剑气",
]),

//12
([ "action":
"$N展开架式，身法轻灵，无形剑气左一拐，右一弯，越转越急，鹜然间一剑刺向$n$l，正是"HIW"‘少泽剑’"NOR"中的奇招"HIW"‘非假非空’"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 250,
        "damage_type": "刺伤",
        "weapon": "小指剑气",
        "post_action": (: hurt :),
]),

//13
([ "action":
HIW"$N大喝一声，鼓动全身真气，内劲流转，双手六剑齐发，十指分弹，霎时剑气纵横，似有无数迅雷疾风互冲激荡向$n而去"NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 250,
        "damage_type": "刺伤",
        "weapon": "无形剑气",
        "post_action": (: conti :),
]),

//14奥义(一)
([ "action":
HIY"\n$N眼中精光大盛，大喝:\n\n"
HIW"             ‘\n"
HIR"                夺命"HIW"～"HIG"连环"HIW"～"HIM"六绝剑"HIW"!!\n"
"                                     ’\n"
"$N突然急运‘一阳心法’，气劲满盈，一个箭步，向$n纵身飞去\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
        "force": 300,
        "damage_type": "创伤",
        "post_action": (: sp1 :),
]),

//15奥义(二)
([ "action":
HIY"\n$N缓缓念道:\n\n"NOR
GRN"                   ‘ 两脚踏翻尘世路，一肩担尽古今愁 ’\n\n"
HIW"配合‘凌波微步’的精妙步法，幻化成无数人影包围$n，双手疾射，六剑齐发，霎时
间$n陷入无形剑气的狂乱剑网之中，剑气激荡，竟是要将$n全身撕裂，此招正是
大理段氏的禁用杀招\n\n"
"                         ～ "HIY" 无"HIM" 常"HIW" ．"RED" 恨"HIC" 苍"BLU" 天 "HIW" ～\n\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
          "force": 300,
        "damage_type": "刺伤",
        "post_action": (: sp2 :),
]),


//16奥义(三)
([ "action":
HIY"\n$N回身收步长吟道:\n\n"NOR
YEL"                   ‘ 明月浮云相半掩，七星不落耀长空 ’\n\n"
HIW"忽然间高高跃起，身形掩空，左掌抚胸，右手连发七道无形剑气，疾向$n周身要穴而
去，昏暗之中，只见七道剑芒金光耀眼，乃是大理段氏六脉神剑中的绝学\n\n"
"                           ～"HIM" 七"HIY" 星"HIC" 落"HIG" 长"HIR" 空"HIW" ～\n\n"NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
          "force": 300,
        "damage_type": "刺伤",
        "post_action": (: sp3 :),
]),
});

void hurt(object me, object victim, object weapon, int damage)
{
        int force;
        if( random(100)>50 && !me->query_temp("conti",1) && 
            me->query("family/family_name")=="段家" )
        {
          force = me->query_skill("sunforce",1);
          if(force > 250) force=250;
          victim->receive_damage("kee", 50+force );
          message_vision(sprintf(HIM"$N六脉神剑诡异的气劲钻入$n体内，$n脸上突然一阵青白，看来已受了不小的内伤。\n"NOR),me,victim);
          COMBAT_D->report_status(victim);
          me->add("force",-force);
        }

        else
        {
          message_vision(sprintf(HIW"$n狼狈地闪过了$N的诡异气劲, 但已大大出糗。\n"NOR),me,victim);
        }
}
void block(object me, object victim, object weapon, int damage)
{
        if( random(100)>50 && !me->query_temp("conti",1) &&
            me->query("family/family_name")=="段家" )
        {
          victim->apply_condition("blockade",3);
          message_vision(sprintf(HIY"$N六脉神剑暗藏一阳指手法，反手点中$n的膻中大穴。\n"NOR),me,victim);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
        }
        else
        {
          message_vision(sprintf(HIW"$N试图以一阳指封锁$n, 但是被$n躲了开来。\n"NOR),me,victim);
        }
}
void conti(object me, object victim, object weapon, int damage)
{
         int i,time = 3;
        if( me->query("force_factor") >= 10 && 
            me->query("family/family_name")=="段家" && 70>random(100) )
        {
          if( me->query_temp("conti") == 0 )
          {
            me->delete_temp("super");
            me->set_temp("conti",1);
      message_vision(sprintf("\n[1;33m$N忽然顿悟六脉神剑[1;5;36m气游百穴[0m、[1;5;36m连绵不绝[0m[1;33m的要诀, 剑气自然而然的破体而出, 欲罢不能!![0m\n"),me);
              for(i=1;i<=time;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
          }
        }
}

void sp1(object me, object victim, object weapon, int damage)
{
int i;
if(me->query("env/六绝剑","YES")&&!me->query_temp("conti",1))
{
  for(i=1;i<=6;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$N领悟了"HIW"‘少商剑’"HIY"‘气涌如山，席卷天下’"NOR"的真意，向$n当头斩下!\n"),me,victim);
     break;
     case 2:
message_vision(sprintf("\n$N领悟了"HIW"‘商阳剑’"HIG"‘身形灵动，势若流云’"NOR"的真意，对$n四肢砍落!\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("\n$N领悟了"HIW"‘中冲剑’"HIC"‘剑气冲天，盈不可久’"NOR"的真意，往$n胸前疾刺!\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("\n$N领悟了"HIW"‘关冲剑’"HIM"‘气凝丹田，以静制动’"NOR"的真意，鹜然间刺向$n!\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("\n$N领悟了"HIW"‘少冲剑’"NOR""CYN"‘应左则右，虚幻不定’"NOR"的真意，剑影包围住$n!\n"),me,victim);
     break;
     case 6:
message_vision(sprintf("\n$N领悟了"HIW"‘少泽剑’"BLU"‘云谲波诡，亦幻亦真’"NOR"的真意，剑气疾射向$n!\n"),me,victim);
     break;
     }
message_vision(sprintf(HIR"$N确实命中$n要害，$n顿时血流满地。\n"NOR),me,victim);
          victim->receive_damage("kee",110);
          COMBAT_D->report_status(victim, 1);
          me->add("force",-20);
   }
message_vision(sprintf(HIW"\n你使力过度,一时之间无力再战!\n"NOR),me,victim);
me->start_busy(1);
 }
}
void sp2(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int six, force;
        six = me->query_skill("six-fingers",1);
        force = me->query_skill("sunforce",1);
        if(force>200) force=200;
          message_vision(sprintf(HIG"$N纵声长啸，双手混元归一中宫直入，无数道剑气在$n身上对穿而过!!\n"NOR),me,victim);
          victim->receive_damage("kee",six+force);
          victim->apply_condition("bleeding",5);
          COMBAT_D->report_status(victim);
}
}
void sp3(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int force;
        force = me->query_skill("sunforce",1);
        if(force > 300) force=300;
          message_vision(sprintf(HIC"$n先前内伤受到$N无形剑气牵引，$n的伤势更加重了!!\n"NOR),me,victim);
          victim->receive_damage("kee",force);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
}
}

mapping query_action(object me, object weapon)
{
        int level=(int)(me->query_skill("six-fingers",1));

        if ( level < 10 )
           return action [random(3)];
        else if ( level < 20 )
           return action [random(5)];
        else if ( level < 30 )
           return action [random(7)];
        else if ( level < 40 )
           return action [random(9)];
        else if ( level < 50 )
           return action [random(11)];
        else if ( level < 60 )
           return action [random(13)];
        else if ( level < 70 )
           return action [random(9)+4];
        else if ( level >= 70 && me->query_temp("super",1))
           return action [12];
        else if ( level == 100 && me->query("marks/six_sp")==3 &&
                  me->query("family/family_name") == "段家")
           return action [random(12)+4];
        else
           return action [random(8)+5];
}

int vlid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("练六脉神剑还是要空手吧....\n");
        if(me->query_skill("force")*3<=me->query_skill("six-fingers",1))
          return notify_fail("你的基本内力技能不足, 无法练六脉神剑。\n");
        if(me->query_skill("literate")*3<=me->query_skill("six-fingers",1))
          return notify_fail("你的知识不足，无法体会六脉神剑里，全身经脉运行之道的精要变化。\n");
        return 1;
}

int valid_enable(string usage)
{
      if(this_player()->query_skill("six-fingers",1) >= 45)
         {
            return (usage=="unarmed"||usage=="stabber")||(usage=="parry");
         }
          return (usage=="unarmed");
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("练六脉神剑还是要空手吧....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不够，无法练习。\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("体力不够啰,休息一下再继续练吧.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前内力不足,休息一会儿再练吧.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("scholar")+"/six-fingers/"+action;
}
