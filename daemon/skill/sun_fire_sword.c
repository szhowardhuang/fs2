// 连阳七诀剑法
//取代原来的迅雷剑法 && 提高解迷难度
//roger && taifar于 98/8/16

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
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int sp_value;

string *parry_msg = ({
"\n而$n手中的长剑一横，一招"HIB"‘铁锁横江’"NOR"势挟千斤往前一推一送，当的一声碰出了点点火花反把$N手中的$w险些震飞！\n"NOR,
"\n但$n长剑一转，顺着$N的$w以一招"HIC"‘顺流而下’"NOR"往$N的手指削去，$N大惊失色下急忙收招回架\n",
"\n$n剑走轻灵，手中长剑忽削忽刺一连串的兵器撞击声后$n已将$N的快招全部化解！\n",
HIW"\n$n以快制快，$N快但$n更快，连续刺出了七七四十九剑织成一道剑网将$N的招式尽数荡开！\n"NOR,    
        });

string *unarmed_parry_msg = ({
"但是被$n格开了。\n",
"结果被$n挡开了。\n",
});

string *lan_yan = ({
HIW"$N使出烈阳第一式"HIR"‘浩日初升’"HIW"，手中的$w"HIW"快速舞动着，挟着阵阵烈风袭向四周，一时间剑气纵横\n"NOR,
HIW"$N手中$w"HIW"突然嗡嗡巨响，使出烈阳第二式"HIR"‘烈日迫世’"HIW"，手中$w"HIW"，发出霹雳巨响刺向四周的敌人\n"NOR,
HIW"$N手中$w"HIW"急速颤动，瞬间满天剑花闪闪，正是烈阳第三式"HIR"‘千华映日’"HIW"，招如其名，只见敌人的血如落花般飞溅...\n"NOR,
HIW"$N身形急旋，使出烈阳第四式"HIR"‘风沙灼日’"HIW"，只见浑烫的风卷起滚滚尘沙，令人摸不清$N在何方...\n"NOR,
HIW"$N手捏剑诀，忽然手中的$w"HIW"往天空飞去，瞬时间数道剑气往下激射，正是烈阳第五式"HIR"‘虹云过日’\n"NOR,
HIW"$N使出烈阳第六式"HIR"‘升龙旋日’"HIW"身形犹如一条灰龙急旋而上，且散发出灼热的气息袭向四周，好像要一举吞没敌人似的\n"NOR,
HIW"$N大喝一声，使出烈阳第七式"HIR"‘烈日当空’"HIW"，一瞬间已向四周刺出了七七四十九剑!\n"NOR,
HIW"$N手中的$w"HIW"，忽劈忽刺，一招烈阳第八式，"HIR"‘焰日迫雷’"HIW"使将出来，四周响起了隆隆巨响!\n"NOR,
HIW"$N手中的$w"HIW"剑芒忽然一长，使出烈阳第九式"HIR"‘划日飞电’"HIW"，只见剑芒不停的吞吐闪烁，令人眼花撩乱间$w"HIW"，已穿体而出...\n"NOR,
HIW"$N使出绝顶轻功，一招烈阳第十式"HIR"‘蔽雨热日’"HIW"，使将出来，周围敌人纷纷不住地倒退...\n"NOR,
HIW"$N身形一晃，手中$w"HIW"，不绝的向敌人追随而去，正是烈阳第十一式"HIR"‘斜日挂影’"HIW"，令敌人避无可避\n"NOR,
HIW"$N手中的$w"HIW"忽然变成软软绵绵，剑招去势诡异莫测，正是烈阳第十二式"HIR"‘阴云掩日’"HIW"令敌人无从招架起\n"NOR,
HIW"$N手中的$w"HIW"飞射而出，使出烈阳第十三式"HIR"‘刃日飞风’"HIW"，只见$w"HIW"在$N双手真气的控制下以极高的速度刺向周围的敌人。\n"NOR,
HIW"$N使出烈阳第十四式"HIR"‘炎日千印’"HIW"，手中的$w"HIW"忽然飞快的舞动，形成一道道幻影刺向周围的敌人。\n"NOR,
HIW"$N手中的$w"HIW"往外一分，忽然化成成千上万的幻影笼罩着四周的敌人，正是烈阳第十五式"HIR"‘幻日流光’"HIW"，周围敌人纷纷退却...\n"NOR,
HIW"$N将手中的$w"HIW"舞得更急，使出烈阳第十六式"HIR"‘狂日尽蚀’"HIW"，剑法快的连剑的踪影都看不到只听一声惨号$n已被刺伤!。\n"NOR,
HIW"$N使出烈阳第十七式"HIR"‘伪日为真’"HIW"，剑法之快，招式之辣，实已令人匪夷所思，所刺出的每一招皆令敌人受到重创\n"NOR,
});

string *shasword = ({
"$N手捏剑诀，长剑一挺，使出一招"HIC"‘泉鸣芙蓉’"NOR"，姿态悠雅，颇有天上仙人下凡间之意\n",
"$N一个旋身，手中的$w在空中闪过一道光芒直刺向$n的$l，姿态潇洒一气呵成，正是一招"HIY"‘金雁横空’\n"NOR,
"$N左肩微沉，左手剑诀斜引，右肘一缩，使出一招"HIM"‘有凤来仪’"NOR"剑势迅速凌厉直往$n的$l刺去\n",
"$N剑势一改往常的飘逸绝伦，使出一招"HIW"‘"HIY"玉碎仙冈"HIW"’"NOR"直削横劈、气势威猛的往$n身上大力斩去\n",
"$N剑势大开大阖，使出一招"HIC"‘劈竹扫影’"NOR"狂风暴雨般的招式使$n感到难以招架\n",
"$N剑尖连划出几个剑花，一招"HIW"‘飘云穿雪’"NOR"如浮云般飘逸，化成片片白雪缓缓落于$n的身上\n",
"$N将手中的$w斜引，使出一招"HIW"‘峭壁断云’"NOR"，剑势雄伟精奇气势纵横使$n感到左支右拙难以招架\n",
"$N真气灌于手中的$w，使出一招"HIR"‘飞虹横江’"NOR"顿时剑尖冲出半尺来长的红色剑芒，吞吐闪烁，嗤嗤声响处往$n疾刺而去\n",
"$N手中的$w一闪出鞘，寒芒吞吐，电闪星烁，一招"HIB"‘寒芒冲霄’"NOR"剑气化成点点寒芒往$n身上飞去\n",
"$N一声清啸，手中长剑抖动处数以百计的玉色光芒从$N的剑尖疾飞而出，灿烂如银河飞溅，正是一招"HIW"‘"HIY"尽倾银河"HIW"’\n"NOR,
"$N使出仙剑派之绝招"HIG"‘隔纸断树’"NOR"，手中的$w虚划，$n愕然不明所以之际不知自己筋脉已被斩断...\n",
"$N剑泛仙气，聚精会神地使出了仙剑剑术中的最高境界"HIY"‘仙倾霜天’"NOR"！剑由仙化，使剑若仙，金光闪耀下$n全身已被割伤多处...\n",
});



mapping *action = ({
//1
        ([      
                "action"     :               HIC"$N收光为晕敛刚成柔，使出了仙剑禁断之连阳七诀第二式"HIY"‘残阳’"HIC"，瞬间身化残影落步，剑尖分指$n$l"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                380,
                "force"      :                330,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺伤"
        ]),
//2
        ([     
                "action"     :               HIC"$N步若游光使出仙剑禁断之连阳七诀第四式"HIY"‘暖阳’"HIC"，剑气烘燃，一流宏大的剑压曲地逼近$n"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                350,
                "force"      :                340,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "刺伤"
        ]),
//3
        ([   
                "action"     :               HIC"$N飞身高跃倏然使出了仙剑禁断之连阳七诀第三式"HIY"‘艳阳’"HIC"，剑光如浩日辉煌，笔直落在$n眉心"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                350,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "刺伤"
        ]),
//4
        ([  
                "action"     :               HIC"$N抚剑如静，心若止水剑光潋艳，仙剑禁断之连阳七诀第五式"HIY"‘冬阳’"HIC"泛起波波杀意如刃向$n绕流而去"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                420,
                "force"      :                370,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "割伤"
        ]),
//5
        ([ 
                "action"     :               HIC"$N手里的$w"HIC"泛出阵阵如暮色般的剑气，仙剑禁断之连阳七诀第七式"HIY"‘夕阳’"HIC"犹如霞光满天尽落$n身上"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                430,
                "force"      :                380,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "割伤"
        ]),
//6
        ([
                "action"     :               HIC"$N峰回路转内劲猛然上窜使出仙剑禁断之连阳七诀第一式"HIY"‘烈阳’"HIC"，剑光如烈阳狂焰直奔$n心口"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                440,
                "force"      :                390,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "刺伤"
        ]),
//7
         ([     "action"     :               HIC"$N将$w"HIC"收鞘而入，聚精凝神使出仙剑禁断之连阳七诀第六式"HIY"‘朝阳’"HIC"，只见剑光如晨光乍现划向$n"NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                450,
                "force"      :                400,
                "post_action":                (: sp_attack6 :),
                "damage_type":                "割伤",
           ]),
//8 叛离仙剑不能用 by swy
(["action":"$N叛离仙剑所以不能将连阳剑使出。",
  "force":10,
  "damage":10,
  "damage_type":"白痴伤",
]),
});

int valid_learn(object me)
{
       if(!me->query("quest/sun_fire_sword",1)){
        tell_object(me,"你还不够资格练连阳七诀剑法。\n");
        return 0;
}
        if(!me->query("get_sha_sp",1)){
        tell_object(me,"你还不够资格练连阳七诀剑法。\n");
        return 0;
                                               }

       if( !me->query_temp("weapon")){
        tell_object(me,"练连阳七诀剑法必需先拿把剑。\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "你的潜能不到五点，无法练此剑法。\n");
        return 0;
                                                                         }
        me->add("potential", -5);
        return   1;
}

int valid_study(object me)
{
       if(!me->query("quest/sun_fire_sword",1)){
        tell_object(me,"你还不够资格练连阳七诀剑法。\n");
        return 0;
}
        if(!me->query("get_sha_sp",1)){
        tell_object(me,"你还不够资格练连阳七诀剑法。\n");
        return 0;
                                               }

       if( !me->query_temp("weapon")){
        tell_object(me,"练连阳七诀剑法必需先拿把剑。\n");
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

 skill_level = (int)(me->query_skill("sun_fire_sword",1));
 limit= skill_level;
if(me->query("family/family_name")!="仙剑派"  || me->query("killyao")==1)
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
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;
  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));
//出现率 1/2*1/7=~7%

  if( random(2) == 0 && me->query("force") > 360 && !me->query_temp("conti",1)) {
  
message_vision(HIY"
就在$n被击中的瞬间，$N心转"HIR"‘残阳千意’"HIY"，乱步分影遮光为幻
一心千切，同一把剑，舞的却是不同的招式，招招朝着$n的要穴窜去
\n"NOR,me,victim);
          
    for(j=0; j < 12; j++) {
       do_action = shasword[j];
       actionn = "\n";
       actionn += do_action;
     
       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       if(i>=sizeof(enemy)) i=0;
       if(!sizeof(enemy)) return ;
       if(!enemy[i]) i=0;
       if(!enemy[i] && !i) return;
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\n但是$N闪躲不及，身上顿时多出了一道血淋淋的剑痕。\n" , enemy[i]);
        enemy[i]->receive_damage("kee",45,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N人比剑快, 惊险地闪过了这一招。\n" , enemy[i]);
                             }

     if( random(me->query("cps")) < 4 ) {
        me->add("force",-100);
        message_vision("\n$N使完"HIY"‘残阳千意’"NOR"后，由于定力不足，体内真气一时无以为继\n",me);
        me->start_busy(1);
                                        }
                                                          }
 
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
  sp_value =6*(str+cor)+cps+kar+spi+int1;

    message_vision(HIW"
剑压流动，随着$N的心念越发强烈，$n无从反动，完完全全
受到剑压的控制，衍生一式"HIY"‘暖阳印境’"HIW"激出的剑虹在空中不停地聚
合盘旋，刹那间!!天地变色风起云涌，一轮暖日在空气之间现形而生
$n被此情景所震慑，一瞬间已被吞没于光芒之中
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->report_status(victim);
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
  sp_value =6*(spi+int1)+cps+kar+str+cor;  

    message_vision(HIY"
就在同时，$N心扩天地，怀若宇宙，狂奔的戾气瞬间平息，$N与
天地仿佛结合为一，瑞光艳丽光彩夺目，凝止住全部的的动作 
一式"HIW"‘艳阳三剑--天地人’"HIY"迅如雷光落向$n
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value,me);
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",2);
   COMBAT_D->report_status(victim);
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
  sp_value =6*(cps+cor)+kar+cor+spi+int1;

    message_vision(HIW"
$N内劲顿转使出连阳唯一阴寒之招，瞬时间一股寒气笼罩身旁，只见
剑上薄冰渐起幻成冰柱，$N愈使愈快，宛若汹涌巨浪瞬时压力遽增
霎时四周水波云气变化万千，$n瞬间分不清剑在何方, 就在迟疑之
际，$N一式"HIC"‘冬阳天冰’"HIW"卷起狂霜乱雪直捣$n心口
\n"NOR,me,victim);

    victim->receive_damage("kee",sp_value,me);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->report_status(victim);
}

void sp_attack4(object me, object victim, object  weapon, int damage)
{
    int i;
    message_vision(HIR"
$N趁势翻身飞跃，斜回剑尖，念转灵动使出"HIW"‘红染夕阳’"HIR"，霎时
杀意狂奔，欲噬血腥无法自制，剑鼓风旋，连锁成无数无形风刃，削
肉刮骨欲罢不能
"NOR,me,victim);

    me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");
}

void sp_attack5(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;
  
  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));
  if(i>=sizeof(enemy)) i=0;
    if(!enemy[i]) i=0;
    if(!enemy[i]) return ;
  
//出现率 1/2*1/7=~7%

   if( random(2) == 0 && me->query("force") > 510 && !me->query_temp("conti",1) && enemy[i]) {
message_vision(HIR"
眨眼间，剑锋泛火，火光渐如焰日逼人，$N如化祝融全身火红
蓦地一声大喝"HIW"‘[31;1m□[37;1mP[31;1m□[37;1m□[31;1m□[37;1mQ[31;1m□[37;1mC[31;1m□[37;1m﹛z"HIR"，手中长剑犹似火龙摧天，剑幻千万火
炬只在一瞬间$n已完全火龙被吞没


                               ▁▎
                                 ▌▎
                                ▉  ▎                       ▎
                                 █  ▎                     ▁▎
                                ██  ▎                      █
       ▁▎                    █ █▌ ▎                   ███
        ▌ ▎               ██ ██▌                ▎ ██ █
        ▌ ▎               ██ ██▌                ▎ ██ █
       ▉ ▎               ██   ███              ▊███  █
     ██ ▊▌            ███    ████           ███  ████
     ██ █▌▊         █████  █████        ███    ████
    ██  ████    ██████  █████       █████    ████
  ███    ██    ██████    ██████  ███████    ████
███    ████   █████    ██████     ███████    ███
"NOR,me,victim);
message_vision(HIR" ███  █████ ██████    █████       ██████    ████
  ███  ████   ██████    ████     ██████      ████
   ███    ███   █████    ███     ████████      ███
     ███  ██████████    ███    ██████      █████
   ████    ███  ██████  ████ ██████    ██████
    ████      ███  ████  ████  █████    ███████
   ██████    ███  ███▍  ███ ████▌   ██████◤
       █████    ██████◣    ◥█████  █████◤
           ◥███◣      ◥██◤      ◥█◤◢█████◤
                ▔             ▔                 ▔▔▔
"NOR,me,victim);            
    for(j=0; j < 17; j++) {
       do_action = lan_yan[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
       if( random(me->query("combat_exp")) > random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\n但是$N闪躲不及，身上顿时多出了一道血淋淋的剑痕。\n" , enemy[i]);
        enemy[i]->receive_damage("kee",55,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N人比剑快，惊险地闪过了这一招。\n" , enemy[i]);
                             }

     if( random(me->query("cps")) < 3 ) {
        me->add("force",-100);
        message_vision("\n$N使完"HIR"‘烈阳十七式’"NOR"后，由于定力不足，体内真气一时无以为继\n",me);
        me->start_busy(1);
                                        }
                                                  }
 
}


void sp_attack6(object me, object victim, object  weapon, int damage)
{
    int i;
  sp_value =6*(str+cor+cps)+spi+int1+kar;

    message_vision(HIY"
瞬间，$N再收剑入鞘，心凝一式"HIW"‘朝阳再现’"HIY"，回身飞旋，几乎是
同时，长剑已离鞘直划$n的咽喉
\n"NOR,me,victim);
   if( weapon->query("id")=="sun_fire_sword" ||  weapon->query("id")=="sun_moon_sword"){
    message_vision(HIY"
灵剑连阳随着‘朝阳再现’这一式散发出开天潜藏的灵气，刹那间!剑泛金光
完全照亮了暗影，如千百个太阳在$N的手中，一齐射出无与伦比的金光，令
$n根本无法逼视
\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(2);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->report_status(victim);
                                             }
   else{
    victim->receive_wound("kee",sp_value,me);
    victim->start_busy(1);
    COMBAT_D->report_status(victim);
       }
}


string query_parry_msg(string limb)
{
 object me=this_player();
 object weapon=me->query_temp("weapon");

  if(weapon && weapon->query("skill_type")=="sword")
      return parry_msg[random(sizeof(parry_msg))];
  else 
      return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
          return CLASS_D("swordsman")+"/sun_fire_sword/"+action;
}   
        
