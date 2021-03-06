//降龙绝学 v1.00 by Santo
//增加连击招式 by Dico 1999,6,18

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me, object victim, object weapon, int damage);
void attack2(object me, object victim, object weapon, int damage);
void attack3(object me, object victim, object weapon, int damage);
void again1(object me, object victim, object weapon, int damage);


mapping *action = ({
//0
(["action":"$N左腿微曲，右臂内弯，右掌画了个圆圈，起手「"+HIY"亢龙有悔"NOR+"”，呼的一声向外推去，
掌劲直直的扫向$n的$l。",
"dodge":-60,
"parry":50,
"force":60,
"damage":325,
"damage_type" : "瘀伤",
]),
//1
(["action":"$N凝神提气，双脚一蹬，身体不住高跃，双掌如刀似剪，一招「"+HIY"飞龙在天"NOR+"”，掌掌往
$n的$l削去。",
"dodge":-60,
"parry":50,
"force":70,
"damage":330,
"damage_type" : "瘀伤",
]),
//2
(["action":"$N的掌势万马奔腾，有若开天辟地般，「"+HIY"战龙在野"NOR+"”如一条狂龙般扑向$n，势不可档。",
"dodge":-90,
"parry":80,
"force":100,
"damage":335,
"damage_type" : "瘀伤",
]),
//3
(["action":"$N右手屈起食中两指，半拳半掌，向$n的$l打去，「"+HIY"潜龙勿用"NOR+"”招意蜒曲不穷，左手
同时向里钩拿，右推左钩，极难闪避。",
"dodge":-90,
"parry":80,
"force":100,
"damage":340,
"damage_type" : "瘀伤",
]),
//4
(["action":"$N右掌一开，左掌跟着一握，力聚于掌，「"+HIY"利涉大川"NOR+"”气势大开大阖，掌劲尽透刚气，
向$n不断推去。",
"dodge":-90,
"parry":80,
"force":100,
"damage":345,
"damage_type" : "瘀伤",
]),
//5
(["action":"$N双掌一提，双臂内弯真气随之一吐，「"+HIY"鸿渐于陆"NOR+"”掌势由隐而明，平平的推向$n。",
"dodge":-90,
"parry":80,
"force":100,
"damage":350,
"damage_type" : "瘀伤",
]),
//6
(["action":"$N身形缓慢推动，倏地间双掌顺势一推，「"+HIY"突如其来"NOR+"”仿如暴雨骤至，掌劲如狂风般地
袭向$n。",
"dodge":-100,
"parry":80,
"force":100,
"damage":355,
"damage_type" : "瘀伤",
]),
//7
(["action":"$N掌势大开大阖，体内真气不断向外放射，招式亦随着真气向$n攻去，「"+HIY"震惊百里"NOR+"”如
爆雷般惊人。",
"dodge":-100,
"parry":80,
"force":100,
"damage":360,
"damage_type" : "瘀伤",
]),
//8
(["action":"$N瞬时吸一口气，左掌前探，右掌倏地从左掌底下穿了出去，强招「"+HIY"或跃在渊"NOR+"”直击
向$n的$l。",
"dodge":-100,
"parry":80,
"force":110,
"damage":365,
"damage_type" : "瘀伤",
]),
//9
(["action":"$N形如猛虎出栅，狠招「"+HIY"神龙摆\尾"NOR+"”呼之欲出，随即反手一劈，击向$n的$l。",
"dodge":-100,
"parry":90,
"force":110,
"damage":370,
"damage_type" : "瘀伤",
]),
//10
(["action":"$N掌收于胸，招式璞\而不华，双手撒掌一合，「"+HIY"见龙在田"NOR+"”笔直的击向$n的$l。",
"dodge":-100,
"parry":90,
"force":110,
"damage":375,
"damage_type" : "瘀伤",
]),
//11
(["action":"$N双掌同时一举，跟着背脊往前一挺，双掌齐发，一招「"+HIY"双龙取水"NOR+"”攻向$n。",
"dodge":-100,
"parry":90,
"force":110,
"damage":380,
"damage_type" : "瘀伤",
]),
//12
(["action":"$N掌劲一松，力透黏劲，左掌一带，牵动$n四方气流，「"+HIY"群龙无首"NOR+"”双掌如狂雨击出，
掌劲虚幻飘渺令$n眼花撩乱。",
"dodge":-100,
"parry":90,
"force":110,
"damage":385,
"damage_type" : "瘀伤",
]),
//13
(["action":"$N身形不断晃动，步移$n六方，突然间，六方掌影同时狂袭而至，「"+HIY"时乘六龙"NOR+"”如群龙
逆噬，尽击向$n。",
"dodge":-100,
"parry":100,
"force":200,
"damage":390,
"damage_type" : "瘀伤",
]),
//14
(["action":"$N掌影守住全身，并不抢攻，$n却反被$N繁密的掌影所退，守招「"+HIM"密云不雨"NOR+"”如大雨欲
来，一掌又一掌环绕$n。",
"dodge":-110,
"parry":100,
"force":200,
"damage":395,
"damage_type" : "瘀伤",
]),
//15
(["action":HIW"                $N使出降龙失传绝学第一式\n"
"             －＝"HIG"「□损－则－有－孚□”"HIW"＝－\n"
"          内息不断提升，突然真气爆吐，内劲反由双掌蕴生\n"
"            招意被"HIG"洗髓劲"HIW"所激发，由里而外不断侵袭$n。\n"NOR,
"dodge":-110,
"parry":100,
"force":220,
"damage":400,
"damage_type" : "内伤",
"post_action" : (: attack1 :),
]),
//16
(["action":HIW"                $N使出降龙失传绝学第二式\n"
"             －＝"HIC"「□履－霜－冰－至□\”"HIW"＝－\n"
"$N稍稍吐了一口气，逆运体内洗髓经，将"HIR"阳刚之气"HIW"转化为"HIB"阴柔之劲\n"HIW
"   两肘往上微抬，将阴柔之劲运至双臂，右拳左掌，直击横推\n"
"     幻化出两道"HIC"冰龙"HIW"，刚柔并济，一快一慢的打向$n的$l。\n"NOR,
"dodge":-120,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "冻伤",
"post_action" : (: attack2 :),
]),
//17
(["action":HIW"                $N使出降龙失传绝学第三式\n"
"             －＝"HIM"「□羝－羊－触－藩□”"HIW"＝－\n"
"          $N运起洗髓经十成功力，将真气运至双手，凝气为剑\n"
"连剑带掌，无数"HIY"光芒"HIW"有如"YEL"迅"HIY"雷"BLU"疾"HIB"风"HIW"向$n相互激荡而去，掌意剑意同时击向$n。\n"NOR,
"dodge":-150,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "刺伤",
"post_action" : (: attack3 :),
]),
//18
(["action":HIW"$N向后翻身一跃，退后数尺，全力鼓催体内的"HIY"降龙劲"HIW"，内劲如潮暴涌，牵动四方气流，浑身冒出阵阵白烟。\n"
"白烟缭绕，身后幻化出如真似假的"HIC"龙形气劲"HIW"，四周气流相互激荡，震的$n血脉紊乱。\n"
"只见$N傲然耸立，状甚平静，但其身后的"HIB"龙形气劲"HIW"，却如箭在弦，有飞龙在天之威。\n\n"NOR
"       霎时$N"HIY"豪光"NOR"暴现，体内降龙劲破体而出，使出降龙最终奥义。\n"NOR
HIW"            ─＝"HIR"□ 龙  啸  九  天 □"HIW"＝─"NOR,
"dodge":-100,
"parry":100,
"force":150,
"damage":400,
"post_action":  (: again1 :),
"damage_type" : "瘀伤",
]),

});


mapping query_action(object me, object *weapon)
{
   int skill;

   skill=me->query_skill("dragonfist", 1);

   if( me->query("family/family_name")!="丐帮" || !me->query("read_page_1",1)
       || !me->query("read_page_2",1) || !me->query("read_page_3",1)
       || !me->query("read_dragonfist",1) )
   {
    if( skill < 50)
       return action[random(7)];
    else if( skill < 60)
       return action[random(10)];
    else if( skill < 70)
       return action[random(12)];
    else if( skill < 80)
       return action[random(14)];
    else
       return action[random(15)];
   } else {if (random(100) > 80 )
       return action[random(10)+9];
    else 
       return action[random(9)+9];
   }
}
void attack1(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist", 1);
 att_value = random(2*skill);
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIG"$N双掌蕴含的洗髓劲有如厉雷疾风的向$n飞奔而去，$n硬挡之下洗髓劲已穿体而过，震伤了$n的心脉\n"NOR,me,victim);
   victim->add("force",-att_value);
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("hart",random(15));
  }
}
void attack2(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("dragonfist", 1);
 busy_value = skill / 50;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIC"两道阴柔冷冽劲气窜入$N的体内，奇寒蚀骨使$N一时无法行动。\n"NOR,victim);
   victim->start_busy( random(busy_value) );
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("cold",random(15));
  }
}


void attack3(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist",1);
 att_value=random(2*skill);
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
 {
  message_vision(HIM"$N低喝一声，将掌中剑气射向$n，无数剑茫激射而去，$n避无可避，惨遭剑气穿体。\n"NOR,me,victim);
  victim->add("kee",-att_value);
  COMBAT_D->report_status(victim,1);
  victim->apply_condition("swordkee",random(15));
 }
}

void again1(object me, object victim, object weapon, int damage)
{
 int skilv,maxlv,i,j,mydamage;
 skilv=random(me->query_skill("dragonfist",1));
 maxlv=me->query_skill("dragonfist",1);
 j=skilv/10;
 if(j>9) {j=9;}
 for(i=0;i<=j;i++)
 {
  switch(i)
  {
  case 0:
  message_vision("$N左腿微曲，右臂内弯，右掌画了个圆圈，起手「"+HIY"亢龙有悔"NOR+"”，呼的一声向外推去，掌劲直直的扫向$n。\n",me,victim);
  break;
  case 1:
  message_vision("$N凝神提气，双脚一蹬，身体不住高跃，双掌如刀似剪，一招「"+HIY"飞龙在天"NOR+"”，掌掌往$n四肢剪去。\n",me,victim);
  break;
  case 2:
  message_vision("$N的掌势万马奔腾，有若开天辟地般，「"+HIY"战龙在野"NOR+"”如一条狂龙般扑向$n，势不可档。\n",me,victim);
  break;
  case 3:
  message_vision("$N右手屈起食中两指，半拳半掌，向$n打去，「"+HIY"潜龙勿用"NOR+"”招意蜒曲不穷，左手同时向里钩拿，右推左钩，极难闪避。\n",me,victim);
  break;
  case 4:
  message_vision("$N形如猛虎出栅，狠招「"+HIY"神龙摆\尾"NOR+"”呼之欲出，随即反手一劈，击向$n。\n",me,victim);
  break;
  case 5:
  message_vision("$N掌收于胸，招式璞\而不华，双手撒掌一合，「"+HIY"见龙在田"NOR+"”笔直的击向$n。\n",me,victim);
  break;
  case 6:
  message_vision("$N双掌同时一举，跟着背脊往前一挺，双掌齐发，一招「"+HIY"双龙取水"NOR+"”攻向$n。\n",me,victim);                                             break;
  case 7:
  message_vision("$N掌劲一松，力透黏劲，左掌一带，牵动$n四方气流，「"+HIY"群龙无首"NOR+"”双掌如狂雨击出，掌劲虚幻飘渺令$n眼花撩乱。\n",me,victim);
  break;
  case 8:
  message_vision("$N身形不断晃动，步移$n六方，突然间，六方掌影同时狂袭而至，「"+HIY"时乘六龙"NOR+"”如群龙逆噬，尽击向$n。\n",me,victim);
  break;
  }
   if( ((int)victim->query_skill("move",1)
        + random((int)victim->query_skill("dodge",1))*5)
        < skilv+random((int)me->query_skill("dodge",1)*i
        + (int)victim->query_skill("move",1)) )
    {
     message_vision(HIC"$N的劲力澎湃汹涌，$n一时招架不住，被$N一掌轰中，「哇！”一声吐出一口鲜血！！\n"NOR,me,victim);
     victim->receive_damage("kee",(skilv*i/10));
     COMBAT_D->report_status(victim,1);
     me->add("force",-(skilv*maxlv/100));
     mydamage = mydamage+(skilv*i)/10;
   } else
   {
    message_vision(HIW"$n在掌影的包围之下，看出$N的破绽，左闪右躲的躲过了$N凌厉的杀招\n"NOR,me,victim);
     me->add("force",-skilv*maxlv/100);
     mydamage = mydamage+(skilv*i)/10;
   }
 }
 if(i>=9)
 {
  message_vision(HIR"$N使出龙啸九天后内力耗损过巨，气息大乱，呼吸沉重四肢酸痛难奈，不得不赶紧运气调息。\n"NOR,me);
        me->start_busy((skilv+maxlv)/50);
        COMBAT_D->report_status(victim,1);
 } else {
 message_vision(HIR"$N击出"+chinese_number(i)+"掌后，真气一散，内力无以为继，反被降龙劲所伤，吐出一口鲜血！\n"NOR,me);
 me->start_busy((skilv+maxlv)/100);
 me->receive_damage("kee",mydamage);
 COMBAT_D->report_status(victim,1);
 }
}

int practice_skill(object me)
{
  if ((int) me->query("max_force")<1000)
  return notify_fail("你武学知识不足，无法参透降龙绝学的精妙之处\n");
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/dragonfist/"+action;
}
int valid_learn(object me)
    {
        if( me->query("max_force") < 1500 ) {
            tell_object(me, "你的内力修为不够, 最少要有一千五百点。\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "只有丐帮弟子才能学降龙绝学。\n");
            return 0;
        }
        if(!(me->query("beggar/quests 10") == 1 )) {
            tell_object(me, "丐帮弟子要完成任务十才能学。\n");
            return 0;
        }
        if( me->query("str") < 20) {
            tell_object(me, "你的臂力不够不能学降龙绝学。\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "你目前的内力不到五百点, 无法练此绝学。\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 3 ) {
            tell_object(me, "你的潜能不到三点, 无法练此绝学。\n");
            return 0;
        }
       if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
       return   notify_fail("学降龙十八掌必须空手。\n");

        tell_object(me, "学此绝学需扣潜能三点。\n");
        me->add("potential", -3);
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="unarmed" )||(usage=="parry");
}


