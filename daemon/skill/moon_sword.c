// 月影幻式剑法
//连阳副剑
//由连阳剑修改而来
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int sp_value;
mapping *action = ({
//1
        ([
                "action"     :               BLK"$N收光为晕敛刚成柔，手中的长剑消失于黑暗中，四周剑芒顿时消失，不由自主使出月影幻式‘阴月’，瞬间$n完全无法见光，只觉疾风扶向$n$l"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                330,
                "force"      :                330,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺伤"
        ]),
//2
        ([
                "action"     :               BLK"一片昏暗中突见一阵光亮，只见$N身若游光使出月影幻式‘新月’，剑气四窜，一流宏大的剑压曲地逼近$n"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                340,
                "force"      :                340,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "刺伤"
        ]),
//3
        ([
                "action"     :               BLK"$N飞身高跃倏然使出了月影幻式‘满月’，剑光如圆月照亮黑暗，直指$n眉心"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                350,
                "force"      :                350,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "刺伤"
        ]),
//4
        ([
                "action"     :               BLK"$N抚剑如静，心静剑宁，月影幻式‘月缺’泛起波波杀意如刃向$n绕流而去"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                370,
                "force"      :                370,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "割伤"
               ]),
//5
        ([
                "action"     :               BLK"如月之上弦$N手里的长剑画出一道半圆，月影幻式‘上弦’剑影破空而下落$n身上"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                380,
                "force"      :                380,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "割伤"
        ]),
//6
        ([
                "action"     :               BLK"如月之下弦$N将手中长剑峰回路转由下而上画出半圆剑影，月影幻式‘下弦’，剑影犹如万马奔腾由下而上直奔$n心口"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                390,
                "force"      :                390,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "刺伤"
        ]),
//7
         ([     "action"     :               BLK"$N将佩剑收入鞘中，身影消失于黑暗中，月影幻式‘蚀’，无数道无形杀气质直逼$n"NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack6 :),
                "damage_type":               "割伤",
]),
//8
 (["action":"$N叛离仙剑无法体会月影幻式奥义。",
  "force":10,
  "damage":10,
  "damage_type":"白痴伤",
]),
});

int valid_learn(object me)
{
       if(!me->query("quest/moon_sword",1)){
        tell_object(me,"你还不够资格练月影幻式。\n");
        return 0;
                                               }
       if( !me->query_temp("weapon")){
        tell_object(me,"练月影幻式必需先拿把剑。\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "你的潜能不到五点，无法练此剑法。\n");
        return 0;
                                                           }
        me->add("potential", -5);
        return   1;
}
int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
}
mapping query_action(object me, object *weapon)
{

 int skill_level,limit,i;
 skill_level = (int)(me->query_skill("moon_sword",1));
 limit= skill_level;
if(me->query("family/family_name")!="仙剑派")
return action[7];
        if (limit < 15)
                return action[random(1)];
        else if (limit < 30)
                return action[random(2)];
        else if (limit < 45)
                return action[random(3)];
        else if (limit < 60)
                return action[random(4)];
        else if (limit < 75)
                return action[random(5)];
        else if (limit < 90)
                return action[random(6)];
        else
          return action[random(7)];
}
void sp_attack0(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(str+cor)+cps+kar+spi+int1;
    message_vision(BLK"
剑压流动，随着$N的心念越发强烈，月影幻式‘阴月无影’压得$n无从反动，完完全全受到剑压的控制，瞬间已被黑暗吞没\n"NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
 //  COMBAT_D->report_status(victim);
}
void sp_attack1(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(str+cor)+cps+kar+spi+int1;
    message_vision(BLK"
受到剑压的控制，月影幻式‘新月画眉’激出的剑虹在空中不停地聚合盘旋，刹那间!!天地变色风起云涌，一轮明月在空气之间现形而生$n被此情景所震慑，瞬间已被吞没于黑暗中\n"NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
// COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void sp_attack2(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(spi+int1)+cps+kar+str+cor;
    message_vision(BLK"
就在同时，$N身后出现一轮明月，周围气息全部遭明月吸收，$N与明月仿佛结合为一，四周的一切仿佛完全停止，月影幻式‘圆月杀招’迅如雷光落向$n\n"NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",2);
//   COMBAT_D->report_status(victim);
COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void sp_attack3(object me, object victim, object  weapon, int damage)
{
  sp_value =4*(cps+kar)+str+cor+spi+int1;
    message_vision(BLK"
$N内劲顿转使出月影阴寒之招，瞬时间一股寒气笼罩身旁，只见剑上薄冰渐起幻成冰柱，$N愈使愈快，宛若汹涌巨浪瞬时压力遽增霎时四周水波云气变化万千，$n瞬间分不清剑在何方, 就在迟疑之际，$N一式‘月殒影缺’卷起四周水气直攻$n心口\n"NOR,me,victim);

    victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);}
void sp_attack4(object me, object victim, object  weapon, int damage)
{
  sp_value =4*(cps+kar)+str+cor+spi+int1;
    message_vision(BLK"
眨眼间，剑锋似水，缓缓月光微微射向$n，$N如化月影全身不经意使出月影幻式之‘月牙上弦’，手中长剑在半空中画出一道道半月形剑芒，剑幻千幻弯刀一瞬间$n已完全半月形剑芒吞噬"NOR,me,victim);
    victim->receive_damage("kee",sp_value+40,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);}
void sp_attack5(object me, object victim, object  weapon, int damage)
{
  sp_value =5*(cps+kar)+str+cor+spi+int1;
    message_vision(BLK"
$N趁势翻身飞跃，斜回剑尖，念转灵动使出‘月牙下弦’，霎时杀意狂奔，欲噬血腥无法自制，剑鼓风旋，连锁成无数无形风刃，削肉刮骨欲罢不能"NOR,me,victim);
victim->receive_damage("kee",sp_value+80,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);}
void sp_attack6(object me, object victim, object  weapon, int damage)
{
    int i;
  sp_value =5*(str+cor+cps)+spi+int1+kar;
   if( weapon->query("id")=="moon_sword" || "sun_moon_sword"){
    message_vision(BLK"
瞬间，$N收剑回鞘，心凝一式‘月蚀刻痕’，回身飞旋，消失于一片黑暗中，瞬间长剑已离鞘直划，随着‘刻痕月蚀’这一式散发出潜藏的灵气，刹那间剑身似成无比巨大的黑洞将光芒完全吸收，只见$n当场目瞪口呆，一阵晕眩以无法分辨东南西北\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(2);
    victim->set_temp("no_power",1);
victim->apply_condition("no_power",2);
//    COMBAT_D->report_status(victim);
}
   else{
    victim->receive_wound("kee",sp_value,me);
    victim->start_busy(1);
    COMBAT_D->report_status(victim);
       }
       }
string perform_action_file(string action)
{
          return CLASS_D("swordsman")+"/moon_sword/"+action;
}
