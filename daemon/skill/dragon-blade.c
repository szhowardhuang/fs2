// 由于加上 killup 所以付出的也要大 by swy
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void movedown(object me, object victim, object weapon, int damage);
void sp_att3(object me, object victim, object  weapon, int damage);
void dragon(object me, object victim, object weapon, int damage);
void suck(object me, object victim, object weapon, int damage);
void sp_att1(object me, object victim, object  weapon, int damage);
void sp_att2(object me, object victim, object  weapon, int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int i;
mapping *action = ({
//1
       ([    "action" :
"$N纵身而上，身形一转，使出"HIW"狂龙八斩"NOR"之"HIR"「回龙逆斩”"NOR"，手中$w往$n横劈过去。",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       200,
             "force"  :       200,
             "damage_type": "砍伤",
        ]),
//2
       ([    "action" :
"$N运气于$w，一招"HIW"狂龙八斩"NOR"之"HIR"「江山易手”"NOR"刀气雄霸，直逼$n。",
             "dodge" :   -10,
             "parry" :   -30,
             "damage" :  200,
             "force"  :  200,
             "damage_type" :   "砍伤",
         ]),
//3
        ([   "action" :
"$N运起元功，将真力贯注$w，一招"HIW"狂龙八斩"NOR"之"HIG"「呼龙啸天”"NOR"直劈$n。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         200,
             "force"  :         200,
             "damage_type":  "砍伤",
        ]),
//4
        ([   "action" :
"$N手中$w连划，一招"HIW"狂龙八斩"NOR"之"HIG"「夜龙一炬”"NOR"忽地挺出直砍$n。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         250,
             "force"  :         250,
             "damage_type":  "砍伤",
        ]),
//5
        ([   "action" :
"$N一招"HIW"狂龙八斩"NOR"之"HIY"「万劫尽舍”"NOR"手中$w舞成一片刀网，笼罩$n。",
             "dodge"  :        -10,
             "parry"  :        -30,
             "damage" :        250,
             "force"  :        250,
             "damage_type":  "砍伤",
        ]),
//6
        ([   "action" :
"$N挥动手中刀刃，使出"HIW"狂龙八斩"NOR"之"HIB"「一字刀法”"NOR"只见$w像一道闪电，直劈而下。",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       250,
             "force"  :       250,
             "damage_type":  "砍伤",
        ]),
//7
        ([   "action" :
"$N使出"HIW"狂龙八斩"NOR"之"HIM"「离刀旋斩”"NOR"，只见$w像白雪般纷纷落下。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         300,
             "force"  :         300,
             "damage_type":  "砍伤",
        ]),
//8

        ([      "action":
"$N持$w一扬，使出"HIW"狂龙八斩"NOR"之"HIC"「亢龙有悔”"NOR"，刀势万钧，劈向$n。",
                "dodge":  -10,
                "parry":  -30,
                "damage": 300,
                "force":  300,
                "damage_type":  "劈伤",
        ]),
//9
        ([      "action":
"$N使出狂龙必杀技，"HIM"【蟠龙锁关】"HIY"‘忌天～～～恨地～～～鱼龙再现’\n"NOR
"抛起$w，空中转体三周半，气势磅礴。",
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "post_action":  (: sp_att3 :),
                "damage_type":  "砍伤",
        ]),
//10
       ([      "action" :
"$N使出狂龙连舞击，"HIM"【魔性六斩】"HIY"‘惊天～～～灭地～～～血花纷飞’\n"NOR
"手中$w在炙空下舞动，织成一道刀网。",
               "dodge":         -10,
               "parry":         -30,
               "damage":        350,
               "force":         350,
               "post_action":  (: movedown :),
               "damage_type":   "砍伤",
        ]),
//11
       ([      "action" :
"$N突然陷入疯狂，口中大喊，"HIM"【苍天已死～魔刀当立～看摄魂屠仙大法】"NOR"只见$N\n"
"以$w指向$n的伤口，凌空吸取$n的鲜血！",
                "dodge" :       -10,
                "parry" :       -30,
                "damage":       350,
                "force" :       350,
                "post_action":  (: suck :),
                "damage_type":  "砍伤",
        ]),
//12
       ([ "action" :
"$N聚集九天之气，使出[35m【三斩归元～邪龙斩元】[0m\n"
"[1;32m．．．[1;37m‘"HIY"魔"HIC"龙"HIY"嗜"HIC"血"HIW"～～"HIR"焚"HIW"天"HIB"邪"HIC"月"HIW"’[1;32m．．．[0m\n"
"$n惊愕之于，只见$N把$w插于地上，唸起秘咒，瞬时火焰歕张\n"
"淹漫整个天际。",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: dragon :),
"damage": 400,
"damage_type": "烧伤",
]),
//13
([ "action" :
"$N运用九地之气，使出[35m【三斩归元～鱼龙嗜元】[0m\n"
"[1;32m．．．[1;37m‘"HIY"鱼"HIC"龙"HIY"毒"HIC"鸩"HIW"～～"HIY"煌"HIM"岚"HIG"丛"HIR"灭"HIW"’[1;32m．．．[0m\n"
"秘咒语音犹在耳，霎那间，从$w窜出九彩烟雾，瞬时边旁周围的生物死之殆尽。",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: sp_att1 :),
"damage": 400,
"damage_type": "毒伤",
]),
//14
([ "action" :
"$N施展九人之气，使出[35m【三斩归元～雪影化元】[0m\n"
"[1;32m．．．[1;37m‘"HIY"狂"HIC"龙"HIY"怒"HIC"震"HIW"～～"HIC"雪"HIM"影"HIB"寒"HIC"霜"HIW"’[1;32m．．．[0m\n"
"$N运起真元，手持$w往天一挥，顿时，山摇地动，风云变色，以扰乱了\n"
"四季的运转，苍天突然地飘下漫天雪彩。",
"dodge": -10,
"parry": -30,
"force": 400,
"post_action": (: sp_att2 :),
"damage": 400,
"damage_type": "冻伤",
]),
});
mapping query_action(object me, object weapon)
{
int skill, limit, f;
object victim;
skill=(int)(me->query_skill("dragon-blade", 1));
limit=(int)(skill/10);
f=random(6);
victim=offensive_target(me);
if(random(100)>=70&&me->query("combat_exp")>200000 && victim) {
message_vision(HIW+@LONG

                    ◥▇◣                        ◥▇◣
                      ◥▇◣========================◥▇◣
========================◥▇◣========================◥▇◣
==========================▇▇==========================▇▇
========================◢▇◤========================◢▇◤
                      ◢▇◤========================◢▇◤
                    ◢▇◤                        ◢▇◤

LONG +NOR,me);
message_vision(HIY"$N大喝一声发出双刀气，刀气雄霸贯穿$n而过。\n"NOR,me,victim);
victim->receive_wound("kee",300,me);
COMBAT_D->report_status(victim);
}
if((me->query("family/family_name")=="魔刀门"||me->query("family/family_name")=="魔刀莫测")&&
me->query("m_blade")&&me->query("env/get_mblade")&&me->query("combat_exp")>3000000)
{
if(limit=12)
{
if(me->query_temp("mblade")==1) {
return action[13];
}
if(me->query_temp("mblade2")==1) {
return action[12];
}
if(me->query_temp("mblade3")==1) {
return action[11];
}
if((int)me->query("force")>2000)
{
if(f>3) return action[random(3)+11];
return action[random(3)+8];
}
if((int)me->query("force")>1500)
{
if(f>3) return action[random(2)+11];
return action[random(3)+8];
}
if((int)me->query("force")>1000)
{
if(f>3) return action[random(1)+11];
return action[random(3)+8];
}
}
}
if(limit<4)
{
return action[random(3)];
}
if(limit<5)
{
return action[random(4)];
}
if(limit<6)
{
return action[random(5)];
}
if(limit<7)
{
return action[random(6)];
}
if(limit<8)
{
return action[random(7)];
}
if(limit<9)
{
return action[random(9)];
}
if(limit<10)
{
return action[random(10)];
}
if(limit<11)
{
return action[random(10)];
}
if(limit<12)
{
return action[random(11)];
}
else
{
return action[random(11)];
}
}
void suck(object me, object victim, object weapon, int damage)
{
if(70>=random(100)&&me->query("force_factor",1)>=10&&me->query_temp("conti")==0
   && me->query("bellicosity")>11)
  {
     victim->receive_wound("kee",400,me);
     me->receive_curing("kee",400);
     me->receive_heal("kee",400);
     me->add("bellicosity",-10);
     victim->apply_condition("blade",3);
     COMBAT_D->report_status(victim);
     me->add("force",-70);
  } else
message_vision(sprintf("结果$N的妖术被$n破解。\n"),me,victim);
}
void movedown(object me, object victim, object weapon, int damage)
{
int i,bell;
bell=me->query("bellicosity",1)/300;
if(bell < 1) bell=1;
if(bell > 6) bell=6;
if(70>=random(100)&&me->query("force_factor",1)>=5&&me->query_temp("conti")==0
   && me->query("env/魔性六斩")&& me->query("bellicosity")>11)
{
  for(i=1;i<=bell;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$N使出魔性六斩之"HIR"‘快’"NOR"，手中刀刃斩向$n的胸膛。\n"),me,victim);
     break;
     case 2: 
message_vision(sprintf("$N使出魔性六斩之"HIG"‘狠’"NOR"，手中刀刃斩向$n的下阴。\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("$N使出魔性六斩之"HIY"‘准’"NOR"，手中刀刃斩向$n的眼睛。\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("$N使出魔性六斩之"HIM"‘空’"NOR"，手中刀刃斩向$n的手腕。\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("$N使出魔性六斩之"HIB"‘破’"NOR"，手中刀刃斩向$n的足踝。\n"),me,victim);
     break;
     case 6: 
message_vision(sprintf("$N使出魔性六斩之"HIC"‘灭’"NOR"，手中刀刃斩向$n的颈子。\n"),me,victim);
     break;
     }
message_vision(sprintf(HIW"$N确实命中$n要害，$n顿时血流满地。\n"NOR),me,victim);
          victim->receive_wound("kee",140,me);
          COMBAT_D->report_status(victim);
   }
if(!me->query_temp("six-hurt")) {
   me->start_busy(1);
}
   me->add("force",-70);
   me->add("bellicosity",-10);
   victim->apply_condition("blade",3);
} else
message_vision(sprintf("结果$N的魔性不够使不出来。\n"),me,victim);
}

int valid_learn(object me)
{
        object ob;
        if((int)me->query("max_force")<100)
        return notify_fail("你的内力不够，不能练狂龙刀法。\n");
        if((string)me->query_skill_mapped("force")!= "powerforce")
        return notify_fail("狂龙刀法必需配合玄阳神功才能用。\n");
 if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="blade")
        return notify_fail("你必须有刀才能练刀法。\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
}
string perform_action_file(string action)
{
        return CLASS_D("blademan") + "/dragon-blade/" + action;
}
void dragon(object me, object victim, object weapon, int damage)
{
if(me->query_temp("mblade3")==1) {
me->set_temp("mblade3",0); }
if(me->query("bellicosity")<21) return;
if(me->query("env/邪刀连击")) {
if(weapon->query("id")=="shi-blade" || (weapon->query("id")=="evil-mblade" &&
weapon->query("mblade-mark")))
{
string acti;
mapping do_action;
object enemy,weaponn;
int j,force,bell,dak,das,dag;
force=me->query("force",1);
enemy=offensive_target(me);
bell=me->query("bellicosity",1);
if(bell>=9000&&force>700&&me->query_temp("conti")==0)
{
message_vision(sprintf(HIM"
$N运起三斩归元功，只见$N整个人充满戾气，举刀向$n连砍而来！\n"NOR),me,enemy);
me->set_temp("conti",1);
for(j=0; j < 14; j++) {
do_action=action[j];
acti = "\n";
acti += do_action["action"];
if(weaponn=me->query_temp("weapon") )
acti=replace_string(acti, "$w", weaponn->name());
message_vision(acti, me, enemy);
if(random(me->query("combat_exp"))>random(enemy->query("combat_exp"))/10) {
message_vision(HIR"\n$N闪躲不过，身上顿时多了一道伤及见骨的刀痕。\n"NOR,enemy);
dak=enemy->query("max_kee")/30;
if(dak > 160) dak=160;
das=enemy->query("max_sen")/30;
if(das > 100) das=100;
dag=enemy->query("max_gin")/30;
if(dag > 100) dag=100;
enemy->receive_wound("gin",dag,me);
enemy->receive_wound("kee",dak,me);
enemy->receive_wound("sen",das,me);
me->add("force",-20);
COMBAT_D->report_status(enemy);
}
else message_vision("\n$N运功一跃，惊险地闪过了这一刀招。\n" , enemy);
}
if(random(me->query("cps")) < 6 )
{
message_vision("\n$N体内杀气涌上膻中无以聚力，只好释放些许。\n",me);
me->start_busy(1);
me->add("bellicosity",-20);
}
me->delete_temp("conti");
}
} else {
int sp_1=4*(cps+kar)+str+cor+spi+int1;
int bell=me->query("bellicosity")/500;
if(bell < 1) bell=1;
if(bell > 8) bell=8;
for(i=1;i<=bell;i++)
{
message_vision(HIW"你祭起刀刃，气沉丹田，流畅快意的施展狂龙刀法！\n"NOR,me,victim);
switch(i)
{
case 1:
message_vision(sprintf("$N使出第一式‘"HIC"回龙逆斩"NOR"’斩向$n。\n"),me,victim);
break;
case 2:
message_vision(sprintf("$N使出第二式‘"HIC"江山易手"NOR"’斩向$n。\n"),me,victim);
break;
case 3:
message_vision(sprintf("$N使出第三式‘"HIC"呼龙啸天"NOR"’斩向$n。\n"),me,victim);
break;
case 4:
message_vision(sprintf("$N使出第四式‘"HIC"夜龙一炬"NOR"’斩向$n。\n"),me,victim);
break;
case 5:
message_vision(sprintf("$N使出第五式‘"HIC"万劫尽舍"NOR"’斩向$n。\n"),me,victim);
break;
case 6:
message_vision(sprintf("$N使出第六式‘"HIC"一字刀法"NOR"’斩向$n。\n"),me,victim);
break;
case 7:
message_vision(sprintf("$N使出第七式‘"HIC"离刀旋斩"NOR"’斩向$n。\n"),me,victim);
break;
case 8:
message_vision(sprintf("$N使出第八式‘"HIC"亢龙有悔"NOR"’斩向$n。\n"),me,victim);
break;
}
victim->receive_wound("kee",sp_1/2,me);
message_vision(sprintf(HIR"$n露出破绽，被刀刃直斩要害，鲜血直流。\n"NOR),me,victim);
COMBAT_D->report_status(victim);
}
me->add("force",-50);
me->add("bellicosity",-20);
me->start_busy(1);
}
}
victim->apply_condition("blade",5);
}

void sp_att1(object me, object victim, object weapon, int damage)
{
int sp_2 = 4*(str+cor)+cps+kar+spi+int1;
if(me->query_temp("mblade2")==1) {
me->set_temp("mblade2",0);
me->set_temp("mblade3",1); }
if(me->query("bellicosity")<21) return;
if(weapon->query("id")=="ublade" || (weapon->query("id")=="evil-mblade" &&
weapon->query("mblade-mark")))
{
message_vision(HIY"你吸收满天毒雾运气于刀，霎那间手中刀刃散发出惊人骇毒，笼罩四方。\n"NOR,me,victim);
message_vision(sprintf(HIB"$n脸色发黑，似乎中了剧毒。\n"NOR),me,victim);
         victim->receive_wound("kee",sp_2*2,me);
         victim->apply_condition("blade",7);
         victim->apply_condition("u-stial",7);
         victim->start_busy(1);
         COMBAT_D->report_status(victim);
         me->add("force",-120);
}
       else
{
if(me->query_temp("conti")==0) {
message_vision(HIY"你运气于刀，暗使真元，只见刀腾空飞出，直奔$n的胸膛。\n"NOR,me,victim);
          victim->receive_wound("kee",sp_2,me);
          victim->apply_condition("blade",7);
          COMBAT_D->report_status(victim);
          me->add("force",-60);
 }
 }
 me->add("bellicosity",-20);
 }
void sp_att2(object me, object victim, object weapon, int damage)
{
int sp_3 = 4*(kar+int1)+2*str+cor+cps+spi;
if(me->query_temp("mblade")==1) {
me->set_temp("mblade",0);
me->set_temp("mblade2",1); }
if(me->query("bellicosity")<21) return;
if(weapon->query("id")=="iceblade" || (weapon->query("id")=="evil-mblade" &&
weapon->query("mblade-mark")))
{
message_vision(HIC"手中刀刃，似有似无，编织漫天雪彩，只见$n困在其中。\n"NOR,me,victim);
    victim->start_busy(1);
    victim->receive_wound("kee",sp_3*2,me);
    victim->apply_condition("blade",9);
    COMBAT_D->report_status(victim);
    me->add("force",-150);
}
    else
{
if(me->query_temp("conti")==0) {
message_vision(HIC"漫天雪彩，只见$n看的失魂，已被刀刃所伤。\n"NOR,me,victim);
    victim->receive_wound("kee",sp_3,me);
    victim->apply_condition("blade",9);
    COMBAT_D->report_status(victim);
    me->add("force",-75);
} }
me->add("bellicosity",-20);
}
void sp_att3(object me, object victim, object  weapon, int damage)
{
int sk_lv;
sk_lv = me->query_skill("dragon-blade",1);
if(sk_lv>=105&&me->query_temp("conti")==0&&me->query("bellicosity")>11
&&70>=random(100)&&me->query("force",1)>70&&me->query("have_book",1))
{
message_vision(sprintf(HIR"
突然$N眼露红光向天怒吼，狂暴运起元功，使出魔刀失传之奥义"HIW"‘卢山不动一剑痕’\n"NOR),me,victim);
message_vision(sprintf(HIB"$N挥着刀刃，顺着四季的运转，向$n砍出‘春雨’‘夏夜’"+
"‘秋风’‘冬雪’\n"HIY"$n被这股狂霸刀气震吓住，一瞬间$n身上已留下深及见骨的四道伤痕\n\n"NOR),me,victim);
         victim->receive_wound("kee",400,me);
         victim->start_busy(1);
         victim->apply_condition("blade",3);
         COMBAT_D->report_status(victim);
         me->add("force",-50);
         me->add("bellicosity",-10);
}
}
