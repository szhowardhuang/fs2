// 仙剑二转sk ..(限"仙剑"且不能当官)by appo
// 为魔剑招式..版权所有...翻印前请先通知
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void at_head(object me, object victim, object  weapon, int damage);
void at_hand(object me, object victim, object  weapon, int damage);
void at_foot(object me, object victim, object  weapon, int damage);
void at_miss(object me, object victim, object  weapon, int damage);
void at_wind(object me, object victim, object  weapon, int damage);
void at_quick(object me, object victim, object  weapon, int damage);
void new_1(object me, object victim, object  weapon, int damage);
void new_2(object me, object victim, object  weapon, int damage);
void new_3(object me, object victim, object  weapon, int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int con=this_player()->query("con",1);
int sp_value;
string *ghost = ({
HIY+HBBLU"魔剑奥义  第一式  －＝≡ "HIC"幻魔"HIM"血杀"HIY" ≡ ＝－"NOR,
HIB+HBMAG"魔剑奥义  第二式  －＝≡ "HIC"魔魂"HIM"噬血"HIB" ≡ ＝－"NOR,
HIR+HBBLU"魔剑奥义  第三式  －＝≡ "HIC"魔杀"HIM"无极"HIR" ≡ ＝－"NOR,
HIG+HBRED"魔剑奥义  第四式  －＝≡ "HIC"魔魂"HIM"长啸 "HIG"≡ ＝－"NOR,
HIR+HBYEL"魔剑奥义  第五式  －＝≡ "HIC"魔寒"HIM"极冰 "HIR"≡ ＝－"NOR,
HIM+HBCYN"魔剑奥义  第六式  －＝≡ "HIC"魔啸"HIR"九天 "HIM"≡ ＝－"NOR,
HIC+HBMAG"魔剑奥义  第七式  －＝≡ "HIB"万魔"HIM"归宗 "HIB"≡ ＝－"NOR,
HIM+HBBLU"魔剑奥义  第八式  －＝≡ "HIR"天魔"HIG"怒吼 "HIM"≡ ＝－"NOR,
YEL+HBRED"魔剑奥义  第九式  －＝≡ "HIM"天降"HIG"魔威 "YEL"≡ ＝－"NOR,
});
mapping *action = ({
             ([ "action":"$N双手微抬，脚步缓缓移动，不断积蓄内劲，只见$N双眼放射出惨绿的光茫，突地平地一声响，$N大喝一声"HIR"【血气方刚】"NOR+"$n只觉脑中一震，全身呆滞，而$N称此机会, 手中长剑幻化出无数剑影, 向$n的全身罩下．",
                "dodge"      :               -105,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "damage_type":               "瘀伤"
        ]),
             ([  "action":"$N将手中长剑暗藏于后，侧身横移数步，地下深印出数个脚印，口中唸唸有词，随着长剑的挥舞，数道剑气由剑中射出，正是"HIR"‘血魔’"NOR+"杀招之一"HIM"【血肉横飞】"NOR+"霎时满天剑气纵横在$n身上划去．",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                330,
                "force"      :                330,
                "damage_type":               "割伤"
        ]),
             ([  "action" :"$N脸部青丝暴露，浓烈的杀气从$N的双眼透出，只见$N不停挥舞佩剑，劲气中夹带着令人闻之丧胆的杀气，正是"HIW"‘血魔’"NOR+"绝学之一"CYN"【血染江湖】"NOR+"天空倏然一片血红，$n也受到血气包围．",
                "dodge"      :                -110,
                "parry"      :                -120,
                "damage"     :                360,
                "force"      :               350,
                "post_action":               (: at_head :),
                "damage_type":               "刺伤"

        ]),
             ([  "action" : "$N将"HIR"血魔剑招"NOR+"发挥到极限，瞻之在前，忽焉在后，如鬼魅般穿梭在$n四周，只见$N身形一弓，长剑，一道半月形的劲气猛然像$n涌去，",
                "dodge"      :               -120,
                "parry"      :                -120,
                "damage"     :                380,
                "force"      :               350,
               "post_action":               (: at_hand :),
                "damage_type":               "劈伤",
 
        ]),
             ([  "action" : "$N屈体弓身，将长剑插入地中，全身笼罩在一片蓝光中，地面宛如波涛般浮动，随着蓄积的内劲，蓝光不断增加，倏然蓝光一瞬，一道骇人蓝箭以由地底向$n疾射而去",
               "dodge"       :               -130,
                "parry"      :                -140,
                "damage"     :               390,
                "force"      :                380,
              "post_action":               (: at_foot :),
                "damage_type":               "刺伤",
 
        ]),

([  "action" :HIB"$N使出一招"HIM"魔 光 "HIC"耀 九 天"HIB""HIR"，手中魔剑散发出无比的光茫，忽然间魔剑脱手而出升至九天吸收日月精华\n"HBBLU"幻化成万道光茫从$n四面八方急射而至，令$n根本无从招架。"NOR,

        "dodge"      :                -150,
        "parry"      :                -160,
        "damage"     :                 380,
        "force"      :                 500,
        "post_action":                (: new_3 :),
        "damage_type":               "剑伤"

]),
([  "action" :HBBLU"$N大喝一声，狂啸动地，灭绝八方，凌厉剑势急旋怒颳，不断层叠递增蓄势待发"NOR"
"+HIR"＿＿▁▂▃▄▅▆▇█ "HIC"魔杀"HIY"无极 "HIW"… "HIM"炽血"HIC"凌空 "HIR"█▇▆▅▄▃▂▁＿＿\n"HIW"大地仿佛被此招所牵引呈现一遍赤红血色，$n亦被此招所吓面如土色，动弹不得．"NOR,

        "dodge"      :                -160,
        "parry"      :                -160,
        "damage"     :                 410,
        "force"      :                 380,
        "post_action":                (: new_1 :),
        "damage_type":               "剑伤"

]),
 ([  "action" :HIY"$N眼中忽露凶光"HIW+HBBLU"ζ "HIR"魔  "HIG"～  "HIC"道  "HIG"～  "HIG"无  "HIG"～  "HIM"极 "HIW"ζ"NOR"\n"HIY"此招正是魔字诀无上之招，只见无数剑气盘旋$n四周，瞬息间$n全身血流不止。"NOR,

        "dodge"      :                -150,
        "parry"      :                -170,
        "damage"     :                 380,
        "force"      :                 400,
        "post_action":                (: new_2 :),
        "damage_type":               "剑伤"

]),
             ([ "action"     :HIW"$N使出血魔杀第一式"NOR"
             "+HIY"----万魔无尽血剑魔杀----"NOR"
"+HIW"$N感受四面八方的魔气，无穷无尽的劲力由四周涌入$N体内，只见$N长剑吸食万魔魔气，早已渴望血的滋味.忽然见到$n.仿佛天赐干霖似的....朝$n直奔而去"NOR"
"+HIC"$N瞬间消失在空间中..."NOR,
                 "dodge"     :              -170,
                 "parry"     :              -160,
                 "damage"    :               430,
                 "force"     :              300,
                 "post_action":               (: at_miss :),
                 "damage_type":               "割伤",
        ]),
//10
             ([ "action"     :HIW"$N使出血魔杀之第二式"NOR"
             "+HIR" ----血染红尘----"NOR"
"+HIW"$N将长剑抛往上空...随着魔气不断上扬...剑身也渐渐转化为红色.只见血气以罩满剑身."NOR"
"+HIR"忽然间.血剑一个跳耀..瞬间杀至$n眼前...."NOR,

                "dodge"      :                -180,
                "parry"      :                -180,
                "damage"     :                 450,
                "force"      :                 500,
                "post_action":               (: at_wind :),
                "damage_type":               "割伤",
        ]),

             });

int valid_learn(object me)
{


       if(me->query("bloodsword")!=2){
        tell_object(me,"你还不够资格练血魔剑呢。\n");
        return 0;
}
       if( !me->query_temp("weapon")){
        tell_object(me,"练血魔剑必需先拿把剑。\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 15 ) {
        tell_object(me, "你的潜能不到十五点，无法练此剑法。\n");
        return 0;
 }
        me->add("potential", -15);
  return   1;
}

mapping query_action(object me, object weapon)
{
       int skill_level, limit;
        skill_level = (int)(me->query_skill("bloods_sword", 1));
        limit= (int)(skill_level/10);
        if (limit < 2 )
                return action[random(3)];
        if (limit < 3 )
                return action[random(4)];
        else if (limit < 4)
                      return action[random(5)+1];
        else if (limit < 5) 
                  return action[random(5)+2];
        else if (limit < 7) 
                  return action[random(6)+2];
        else if (limit < 9)
                 return action[random(7)+3];
        else
           return action[random(6)+4];
}
int valid_enable(string usage)
{
   return ( usage=="sword" || usage=="parry" );
   
}
void at_head(object me, object victim, object  weapon, int damage)
{
  sp_value =2*(str+cor)+cps+kar+spi;
   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->report_status(victim);
}
void at_hand(object me, object victim, object  weapon, int damage)
{
  sp_value =2*(str+cor)+cps+kar+spi;
   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void at_foot(object me, object victim, object  weapon, int damage)
{
  sp_value =3*(str+cor)+cps+kar+int1;
   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void at_miss(object me, object victim, object  weapon, int damage)
{
  sp_value =random(150)+4*cps+4*cor;

message_vision(sprintf(HIR"$N以血剑幻出一道无比巨大的剑芒，瞬间破碎为无数剑气射向$n..$n无法闪避四面八方的攻击而惨遭血光吞噬\n"NOR),me,victim);
         victim->add("kee",-sp_value);
//          if(!me->query_temp("conti"))
         victim->start_busy(1);
   COMBAT_D->report_status(victim);
}

//第一skill判断式  (me->query("swordskill/sword1")==1)
void new_1(object me, object victim, object  weapon, int damage)
{
  int i;
  message_vision(HIC"\n"HBBLU"$N翻身一跃而上九空之中，大喝一声∶‘"HIR"血杀四方"HIC"’\n"NOR,me,victim);
  message_vision(sprintf(HIR"$N身上血魔斗气随之鼓动，配合血魔霸剑转而使出"HIC"‘"HIR"血杀四方圣佛灭"HIC"’，身上霸气无极，招式无穷无尽，当真神阻杀神，佛祖杀佛！！"HIR"\n"NOR),me,victim);
   for(i=1;i<=4;i++)
   {
         switch(i)
     {
      case 1:
       message_vision(sprintf(HIR"＿＿▁▂▃▄▅▆▇█"HIM"魔"HIW"˙"HIB"杀"HIR"█▇▆▅▄▃▂▁＿＿\n"NOR),me,victim);
      break;
      case 2:
       message_vision(sprintf(HIR"＿＿▁▂▃▄▅▆▇█"HIG"无"HIW"˙"HIC"极"HIR"█▇▆▅▄▃▂▁＿＿\n"NOR),me,victim);
      break;
      case 3:
       message_vision(sprintf(HIR"＿＿▁▂▃▄▅▆▇█"HIG"炽"HIW"˙"HIC"血"HIR"█▇▆▅▄▃▂▁＿＿\n"NOR),me,victim);
      break;
      case 4:
       message_vision(sprintf(HIR"＿＿▁▂▃▄▅▆▇█"HIY"凌"HIW"˙"HIB"空"HIR"█▇▆▅▄▃▂▁＿＿\n"NOR),me,victim);
      break;
     }
     if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIB"强大魔杀挟带无穷火劲如利刃般刺进$n体中，令$n痛不欲生！\n"NOR),me,victim);
     victim->receive_wound("kee",180+random(50));
     victim->apply_condition("hellfire",random(3));
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
    else
     {
        message_vision(sprintf(HIR"千钧一发之际$n"+HIR"避开了$N"+HIR"的杀着！\n"NOR),me,victim);
     }
  }
 }
// 第二skill 判断式 (me->query("swordskill/sword2")==1)
 void new_2(object me, object victim, object  weapon, int damage)
{
  int i;
   message_vision(HBBLU"$N运起浑身血魔斗气，发动全身五大魔剑剑魂，瞬间由身上窜出五道不同颜色的剑魂！\n"NOR,me);
   message_vision(HIC"瞬间五大魔剑剑魂，爆然而出，"+HIB"蓝糜"+HIR"红爓"+HIC"青岚"+HIG"绿魅"+HIW"白魂"+HIC"五魂连星化成一招极杀之招‘魂剑五魄’\n\n"NOR,me);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIC"魂剑五魄所发出的杀招如鬼怪般无情的吞噬$n！\n"NOR),me,victim);
     victim->receive_wound("kee",700+random(300),me);
    }
  else
    {
     message_vision(sprintf(HIR"千钧一发之际$n"+HIR"避开了魂剑五魄"+HIR"的杀招！\n"NOR),me,victim);
    }

 }

void new_3(object me, object victim, object  weapon, int damage)
{
  string aaa;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string ghost2;
  int i,j,force,damage1;
  force=me->query("force",1);
  enemy = me->query_enemy();
  damage1=60;
  i=random(sizeof(enemy));
// 1/3 机率
  if( random(2) == 0 && me->query("force") > 510 && !me->query_temp("conti",1)) {
  message_vision(sprintf(HIC"$N杀的兴起，眼漏红光突然大喝《"HIR"魔天奥义--葬神九杀"HIC"》，一个转身杀到$n身边.\n"NOR),me,victim);
    for(j=0; j < 9; j++) {
     aaa = ghost[j];
       ghost2 = "\n";
       ghost2 += aaa;

       if( weaponn=me->query_temp("weapon") )
       ghost2 = replace_string(ghost2, "$w", weaponn->name());
       message_vision(ghost2, me, enemy[i]);
      if( random(me->query("combat_exp")) > random(enemy[i]->query("combat_exp"))/6 )
       {
        message_vision("\n但是$N闪躲不及，身上顿时多出了一道血淋淋的剑痕。\n" , enemy[i]);
//全中威力约为500
        enemy[i]->receive_damage("kee",damage1+random(30));
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
       }
   else message_vision("\n$N人比剑快，惊险地闪过了这一招。\n",enemy[i]);
                    }

    }
 
}
// 第四skill 判断式 (me->query("swordskill/sword4")==1)
// 将解迷未完成的攻击力降低而解迷完成则增加攻击力

void at_wind(object me, object victim, object  weapon, int damage)
{
   int sp_value;
   if (me->query("swordskill/sword4")==1) sp_value =3*(cor+int1+str+spi+cps+kar);
   else sp_value =3*(cor)+int1+str+spi+cps+kar;
   if(victim->query_temp("conti")!=1  && random(me->query_skill("sword")*2) > random(victim->query_skill("dodge") ))
        {
    message_vision(sprintf(HIC"$N趁长剑杀到$n面前，脚踩七星，悄悄的来到$n身后手中顿时又冒出另一把长剑....此时$n眼前长剑瞬时血化,$n此时已经无法防御后方来的攻势了...\n"NOR),me,victim);
       victim->set_temp("conti",1);
       me->set_temp("conti",1);
     call_out("wind",1,me,victim);
        }
   else if(damage > 0 && !victim->query_temp("conti") && random(10) > 5){
{
     message_vision(sprintf(HIC"$N趁长剑杀到$n面前，脚踩七星，悄悄的来到$n身后手持长剑...直刺$n..\n"NOR),me,victim);
     victim->receive_wound("kee",sp_value);
}
    message_vision(sprintf(HIC"$N趁长剑杀到$n面前，脚踩七星，悄悄的来到$n身后手上另一把长剑直刺$n\n"NOR),me,victim);
    victim->recieve_wound("kee",sp_value);
         victim->start_busy(1);
   COMBAT_D->report_status(victim);
message_vision(sprintf(HIC"$N逆转的真气一滞，反而使的身形一滞，$n趁势攻击\n"NOR),me,victim);
// 让对手有出招机会
 COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"),  TYPE_REGULAR);
           }
}
int wind(object me,object victim)
{
if(!me || !victim) return 1;
if(environment(victim) && victim->query_temp("conti") ==1 && (me->query_skill("sword",1) + me->query_skill("move",1)) > random(victim->query_skill("dodge")) && me->is_fighting())
{
message_vision(sprintf(BCYN"$N随血染红尘剑招无情的砍杀着毫无防备的$n\n"NOR),me,victim);
   if (me->query("swordskill/sword4")==1) victim->add("kee",-1*me->query("max_kee")/12);
   else victim->add("kee",-1*me->query("max_kee")/16);
   me->add("force",-40);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
    if(victim->query_temp("conti")==1 && environment(me) == environment(victim))
     call_out("wind",1,me,victim);
  if(random(me->query_skill("sword",1)+me->query_skill("move",1)) < random(victim->query_skill("dodge",1)))
{
      victim->delete_temp("conti");
      me->delete_temp("conti");
}
return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("swordsman")+"/blood_sword/"+action;
 }
