// shadow-kill written by mtl on May 9th, 1996
// Ver 1.02 modified by mtl on Jul 9th, 1996
// 为了避免冲突，规则的enable三项skills的上限，所以加入限制霸雨螫魂的enable
// By Swy 最后修正 QC 98/6/23
// 加强威力以符现今 fs by swy
#include <ansi.h>
#include <combat.h>
inherit SKILL;
void busyk(object me,object victim,object weapon, int damage);
void devour(object me, object victim, object weapon, int damage);
void bloodk(object me, object victim, object weapon, int damage);
void reversek(object me, object victim, object weapon, int damage);
void shadowk(object me, object victim, object weapon, int damage);
void devast(object me, object victim, object weapon, int damage);
void devast2(object me, object victim, object weapon, int damage);
void worldpill(object me, object victim, object weapon, int damage);
void worldkill(object me, object victim, object weapon, int damage);

mapping *action = ({
([ "action":"$N摇来晃去...感到一阵恶心...难道是有了????....还是走火入魔的现象??",
"dodge": 0,
"parry": 0,
"force": 0,
"damage_type": "刺伤",
]),
([ "action":"$N斗然使出"+BLU+"‘停云催雪，地落八荒’"+NOR+"的绝情杀着，气吞万里如虎，银虹流星坠雨般的向$n罩去，让$n避无可避。",
"dodge": -10,
"parry": -10,
"damage": 10,
"force":  10,
"damage_type": "刺伤",
]),
([ "action":"$N喟然叹道：不恨古人吾不见，恨古人、不见吾狂耳～骤然随着那怅然杀意，使出"+YEL+"‘云山千叠，骇浪覆顶’"+NOR+"向$n层层递去，招招指向要害。",
"dodge": -10,
"parry": -10,
"damage": 20,
"force":  20,
"damage_type":  "刺伤",
"post_action": (: devour :),
]),
([ "action":"$N似笑非笑，凄凄唸起"+RED+"‘弃魂散魄’"+NOR+"心诀。只见$N手上的$w一抹紫孽蒸起，不住旋动，激起一道风刃向$n腰间急劈。",
"dodge": -20,
"parry": -20,
"damage": 30,
"force":  30,
"damage_type": "割伤",
"post_action": (: bloodk :),
]),
([ "action":"$N逆走幻星步法，使出"+GRN+"‘乱象错形’"+NOR+"的奥秘，陷$n于五行易位之闇黑空间。剑首寂然指向京房卦之血脉卦位，只见$n正向跌跌撞撞地向$w奔去....",
"dodge": -20,
"parry": -20,
"damage": 40,
"force":  40,
"damage_type": "刺伤",
"post_action": (: reversek :),
]),
([ "action":"$N意念一起一息之间，身形已然"+CYN+"‘如入不动魔地’"+NOR+"，手中$w影如来如去，无声亦无息地递向$n$l....",
"dodge": -25,
"parry": -25,
"damage": 50,
"force":  50,
"damage_type": "刺伤",
"post_action": (: shadowk :),
]),
([ "action":"$N内照形躯、守窍通关，豁然顿悟了"+BLINK+BOLD+"‘一切有形招式，"+YEL+"如梦幻泡影"+WHT+"，"+BLU+"如露亦如电"+WHT+"’"+NOR+"。过去所学的闇影匕首，一时之间融会贯通，源源不断在手中使出，化为不可思量之势涌向$n....",
"dodge": -25,
"parry": -25,
"damage": 60,
"force":  60,
"damage_type": "刺伤",
"post_action": (: devast :),
]),
([ "action":"$N斗然使出"+HIB+"‘停云催雪，地落八荒’"+NOR+"的绝情杀着，气吞万里如虎，银虹流星坠雨般的向$n罩去，让$n避无可避。",
"dodge": -30,
"parry": -30,
"damage": 70,
"force":  70,
"damage_type": "刺伤",
]),
([ "action":"$N喟然叹道：不恨古人吾不见，恨古人、不见吾狂耳～骤然随着那怅然杀意，使出"+HIY+"‘云山千叠，骇浪覆顶’"+NOR+"向$n层层递去，招招指向要害。",
"dodge": -30,
"parry": -30,
"damage": 80,
"force":  80,
"damage_type":  "刺伤",
"post_action": (: devour :),
]),
([ "action":"$N似笑非笑，凄凄唸起"+HIR+"‘弃魂散魄’"+NOR+"心诀。只见$N手上的$w一抹紫孽蒸起，不住旋动，激起一道风刃向$n腰间急劈。",
"dodge": -40,
"parry": -40,
"damage": 90,
"force":  90,
"damage_type": "割伤",
]),
([ "action":"$N逆走幻星步法，使出"+HIG+"‘乱象错形’"+NOR+"的奥秘，陷$n于五行易位之闇黑空间。剑首寂然指向京房卦之血脉卦位，只见$n正向跌跌撞撞地向$w奔去....",
"dodge": -50,
"parry": -50,
"damage": 100,
"force":  100,
"damage_type": "刺伤",
"post_action": (: reversek :),
]),
([ "action":"$N内照形躯、守窍通关，豁然顿悟了"+BLINK+BOLD+"‘一切有形招式，"+YEL+"如梦幻泡影"+WHT+"，"+BLU+"如露亦如电"+WHT+"’"+NOR+"。过去所学的闇影匕首，一时之间融会贯通，源源不断在手中使出，化为不可思量之势涌向$n....",
"dodge": -60,
"parry": -60,
"damage": 110,
"force":  110,
"damage_type": "刺伤",
"post_action": (: devast2 :),
]),
([ "action":HIY"$N体内一阵绝世气力由体内爆发而出，$w"+HIY+"幻化出一阵气劲冲向$n$l...."NOR,
"dodge": -60,
"parry": -60,
"damage": 120,
"force":  120,
"damage_type": "刺伤",
"post_action": (: worldpill :),
]),
([ "action":HIR"$N运起全身气劲灌注到$w"+HIR+"里，使出惊天动地的一击!!"+HIG+" 四 神 爆 走 第 三 式 ～ 四  神  之  怒 ～"NOR,
"dodge": -70,
"parry": -70,
"damage": 130,
"force":  130,
"damage_type": "刺伤",
"post_action": (: worldkill :),
]),
});

void busyk(object me, object victim, object weapon, int damage)
{
if(random(1000) < me->query("bellicosity"))
if((random(150)<me->query_skill("shadow-kill",1))&&!me->query_temp("devast")&&!me->query_temp("devast2")) 
{
  victim->start_busy(1);
  message_vision(sprintf(HIB"趁着$n忙于招架这密如繁星般的攻击之际，$N见机不可失，剑势疾回，意欲再进一招....\n"NOR),me,victim);
  COMBAT_D->report_status(victim, 1);
}
}

void devour(object me, object victim, object weapon, int damage)
{
int my_bell = (int) (me->query("bellicosity")/20);
if( my_bell > 60 ) my_bell = 60;

if( random(30) < my_bell )
if(random(150)<me->query_skill("shadow-kill",1)&&!me->query_temp("devast")&&!me->query_temp("devast2"))
{
  victim->receive_damage("kee", 250 + random( my_bell ) );
  message_vision(sprintf(HIC"$N 匕首上枉死的冤魂，受不住$N阵阵杀气的催动，从匕首脱出，向$n扑噬而去。\n"NOR),me,victim);
  COMBAT_D->report_status(victim, 1);
}
}
void bloodk(object me, object victim, object weapon, int damage)
{
if( random(250) < me->query_skill("force")+me->query_skill("shadow-kill",1) )
if( damage > 10 && !me->query_temp("devast")&&!me->query_temp("devast2"))
{
  victim->receive_damage("sen",100);
  victim->receive_damage("kee", 250 +random( (int)me->query_skill("rain-throwing",1)/2 ) );
  message_vision(sprintf(HIM"只见从$n伤口喷洒而出的鲜血，突然凝成无数血柱，如灵蛇般向$n窜去，摄走$n的魂魄。\n"NOR),me,victim);
  COMBAT_D->report_status(victim, 1);
}
}

void reversek(object me, object victim, object weapon, int damage)
{        
int my_shadow=me->query_skill("shadow-kill",1);
if(random(250)<me->query_skill("shade-steps",1)+my_shadow
&&!me->query_temp("devast")&&!me->query_temp("devast2"))
{
  victim->apply_condition("bleeding",(int)me->query_skill("cure")/5 +
  random( (int)my_shadow/10 + (int)me->query_skill("parry")/10 ) );
  message_vision(sprintf(HIR"$N双手倒握匕首，往自己胸口送去－－却见到$n胸口一道血柱如飞泉般喷出。\n"NOR),me,victim);
}
}

void shadowk(object me, object victim, object weapon, int damage)
{
int my_shadow=me->query_skill("shadow-kill",1);
if((random(500)<me->query_skill("force")+me->query_skill("shade-steps",1)+my_shadow)&&!me->query_temp("devast")&&!me->query_temp("devast2"))
{           
   victim->recieve_damage("kee",300+random( (int)my_shadow/2 ) );
   message_vision(sprintf(HIG"$N召唤风影化身与$n厮杀。$N的法身迳向$n背后绕去，双手提剑往$n天灵直落。\n"NOR),me,victim);
   COMBAT_D->report_status(victim, 1);
}
}

void devast(object me,object victim, object weapon, int damage)
{
int i;
int my_shadow=me->query_skill("shadow-kill",1);
int time=(int) my_shadow/10+2;
if( me->query("force_factor") >= 10 && me->query_temp("devast")!=1&&!me->query_temp("devast2")!=1)
{
  if( me->query_temp("devast") == 0 )
  {
    me->set_temp("devast",1);
    for(i=0;i<time;i++)
    {
      if( random(1600) < me->query("bellicosity")+200)
      if( random(100) < my_shadow )
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }       
    me->start_busy(1);
    message_vision(sprintf(HIY"你仰天一叹～明白这并非招式之极致，正所谓「飘风不终朝，骤雨不终日”。于是气归元牝，周流六虚....\n"NOR),me,victim);
    COMBAT_D->report_status(victim, 1);
    me->delete_temp("devast");
  }
}
}
void devast2(object me,object victim, object weapon, int damage)
{
int i;
int my_shadow=me->query_skill("shadow-kill",1);
int time=(int) my_shadow/10+2;
if( me->query("force_factor") >= 10 &&!me->query_temp("devast")&&!me->query_temp("devast2")&& me->query("bellicosity") > 2500)
{
  if( me->query_temp("devast2") == 0 )
  {
    me->set_temp("devast2",1);
    for(i=0;i<time;i++)
    {
      if( random(4000) < me->query("bellicosity")+200)
      if( random(100) < my_shadow )
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }       
    message_vision(sprintf(HIY"你仰天一叹～明白这并非招式之极致，正所谓「飘风不终朝，骤雨不终日”。于是气归元牝，周流六虚....\n"NOR),me,victim);
    COMBAT_D->report_status(victim, 1);
    me->delete_temp("devast2");
    if (random(8)==3) me->start_busy(1);
  }
}
}

void worldpill(object me,object victim, object weapon, int damage)
{
        int i;
        int my_shadow=me->query_skill("shadow-kill",1);
        int time=(int) my_shadow/10;

        time=random(time)+2;
        if( me->query("force_factor") >= 5)
        {
                 message_vision(HIC"\n======  "HIW"$N 使 出 闇 影 匕 首 奥 义 "HIR"绝 世 幻 气 "HIC" ====== 
                 \n\n"NOR,me);
                 message_vision(HIW"$N发出的气劲幻化出数条残影, 令$n无法捉摸!!\n\n"NOR,me,victim);
            for(i=0;i<time;i++)
            {
        if (    random(100) < 70 )
             {
//         if( !me->is_fighting() )
//      return ;
                 message_vision(sprintf(NOR"气劲化成"+HIR+"朱雀"+NOR+"，"+HIG+"青龙"+NOR+"，"+HIC+"白虎"+NOR+"，"+HIY+"玄武"+NOR+"，四色气劲将敌人团团包围!!\n"NOR),me,victim);
                 if (random(100)>30)
                 {    
                 victim->receive_wound("kee",150 +  random( (int)my_shadow ));
                 COMBAT_D->report_status(victim, 1);
                 }
                 else message_vision(HIR"$N手忙脚乱, 惊险地闪过了这来势汹汹的气劲。\n"NOR , victim);
             }
            }       
        //  me->start_busy(1);
        }
}
void worldkill(object me,object victim, object weapon, int damage)
{
        int i;
        int my_shadow=me->query_skill("blackforce",1);
        int time=me->query("max_s_kee",1);
        int gin=victim->query("max_gin",1);
        int kee=victim->query("max_kee",1);
        int sen=victim->query("max_sen",1);
        time=(int) time/50;
        if (time < 1) time=1 ;
        gin=(int)gin*(5+random(5))/100+200;
        kee=(int)kee*(5+random(10))/100+350;
        sen=(int)sen*(5+random(5))/100+200;
        if(gin>400) gin=400;
        if(kee>600) kee=600;
        if(sen>400) sen=400;
        {
                 message_vision(HIY"\n======  "+BLINK+BOLD+"～～    四     神     之     怒    ～～ "+NOR+HIY+" ====== 
                 \n\n"NOR,me);
            for(i=0;i<time;i++)
            {
        if ( random(100) < 75 )
             {
                 message_vision(sprintf("$N分身成"+HIR+"朱雀"+NOR+"，"+HIG+"青龙"+NOR+"，"+HIC+"白虎"+NOR+"，"+HIY+"玄武"+NOR+"，四神幻影，将$n陷入虚无的幻象之中!!\n"NOR),me,victim);
                 if (random(100)<40)
                 {    
                 victim->receive_wound("kee",kee);
                 victim->receive_wound("gin",gin);
                 victim->receive_wound("sen",sen);
                 victim->start_busy(1);
                 COMBAT_D->report_status(victim, 1);
                 }
                 else message_vision(HIR"$N集中意志力, 识破了眼前的幻影。\n"NOR , victim);
             }
            }}
}
mapping query_action(object me, object *weapon)
{
//int skill_level=(int)(me->query_skill("shadow-kill",1)/10);
int skill_level=(int)(me->query("functions/manakee/level")/10);
object wea=me->query_temp("weapon");
int x=0;
weapon=me->query_temp("weapon");
x=me->query("quest/worldpill");
if (me->query("class") != "killer")
return action[0];
if (skill_level<= 5)
return action[(random(skill_level)+1)];
if ((skill_level>=6) && (skill_level <10))
return action[(5+random(6))];
if (skill_level>=10 && base_name(weapon)!="/open/killer/headkill/obj/world_dag")
{
if (x)
{
if ( 90 < random(100))
return action[12];
}
return action[(random(5)+7)];
}
if (skill_level>=10 && base_name(weapon)=="/open/killer/headkill/obj/world_dag")
{
if (x)
{
if ( 90 < random(100))
return action[13];
}
return action[(random(5)+7)];
}
}
int valid_learn(object me)
{
  object wea;

if ( me->query_skill_map("rain-throwing") == 1)
  return notify_fail("阎影匕首与霸雨螫魂内劲相冲，请勿装备霸雨螫魂\n");

if( !(wea = me->query_temp("weapon"))
  || (string)wea->query("skill_type") != "dagger" )
  return notify_fail("你必须先找一把匕首才能练招式。\n");
if( (int)me->query("max_force") < 700)
  return notify_fail("你的内力上限不足, 不可以练闇影匕首。\n");
if(me->query_skill("blackforce",1)*3 <= me->query_skill("shadow-kill",1))
  return notify_fail("你的黑牙神功技能不足，无法练闇影匕首。\n");
if(me->query_skill("shade-steps",1)*2 <= me->query_skill("shadow-kill",1))
  return notify_fail("你的幻星步法技能不足，无法体会闇影匕首里，移形换位之精义。\n");
return 1;
}

int valid_enable(string usage) 
{
return usage=="dagger"  || usage=="parry";
}

int practice_skill(object me)
{

object wea;

if( !(wea = me->query_temp("weapon"))
  || (string)wea->query("skill_type") != "dagger" )
  return notify_fail("练闇影匕首还是要有把匕首吧....\n");
if( (int)me->query("kee") < 30 )
  return notify_fail("体力不够啰,休息一下再继续练吧.\n");
me->receive_damage("kee", 30);
return 1;
}
