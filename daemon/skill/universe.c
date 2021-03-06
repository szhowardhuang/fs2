#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void attack(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);
void sp4(object me, object victim, object weapon, int damage);
void sp5(object me, object victim, object weapon, int damage);
void create() { seteuid(getuid()); }

mapping *action = ({

//1
([ "action":
"$N运起"HIW"‘先天乾坤功’"NOR"第一绝"HIG"‘乾坤无定’"NOR", 双手隐含太极阴阳之势, 向$n$l击去,其掌力吞吐不定, 另人难以捉摸!!",
        "damage": 90,
        "force":  90,
        "damage_type":  "内伤",
        "weapon": "双手",
        "post_action": (: attack :),
]),

//2
([ "action":
"$N运起"HIW"‘先天乾坤功’"NOR"第二绝"HIM"‘震惊百里’"NOR", 双掌蓄劲, 鹜然间向$n$l发劲击去, 只见四周生物受到$N强大气劲压迫, 皆受重伤!!",
        "damage": 120,
        "force":  120,
        "damage_type":  "震伤",
        "weapon": "双掌",
        "post_action": (: attack :),
]),

//3
([ "action":
"$N使出"HIW"‘先天乾坤功’"NOR"第三绝"HIR"‘天火燎原’"NOR", 只见$N全身透出天火飞扬之状, 如九天烈火般扫向$n, 其势浩大, 令人心惊!!",
        "damage": 150,
        "force":  150,
        "damage_type": HIR"天火灼身"NOR"之伤",
        "weapon": HIR"天火"NOR,
        "post_action": (: attack :),
]),

//4
([ "action":
"$N运起"HIW"‘先天乾坤功’"NOR"第四绝"HIY"‘天道循环’"NOR", 双手合抱太极之势, 强劲内力产生一股真空漩涡, 将$n攻势尽数击溃, 气劲笼罩$n全身!!",
        "damage": 170,
        "force":  170,
        "damage_type": "绞伤",
        "weapon": HIW"真空气旋"NOR,
        "post_action": (: attack :),
]),

//5
([ "action":
"$N忽地高高跃起, 击出"HIW"‘先天乾坤功’"NOR"第五绝"HIB"‘雷动九天’"NOR", 其双掌隐含先天八卦之形, 如天网般罩住$n全身, $n心中一寒, 只有祭出十成功力勉力一挡!",
        "damage": 200,
        "force":  200,
        "damage_type": HIW"经断脉绝"NOR"之伤",
        "weapon": HIB"雷霆卦象"NOR,
        "post_action": (: conti :),
]),

//6
([ "action":
"$N掌含无限卦象, 击出"HIW"‘先天乾坤功’"NOR"之"HIW"‘乾坤无量’"NOR", 你登时被散发出的$N浑厚掌力激的真气一滞, 只见$N手中的乾坤气劲不断的袭向$n, 其势锐不可挡!",
        "damage": 200,
        "force":  200,
        "damage_type": HIY"无量"NOR"之伤",
        "weapon": HIY"乾坤气劲"NOR,
        "post_action": (: attack :),
]),

//先天乾坤功究极绝招----天惊地动----共五招
//7
([ "action":HIM"
                                ～～"HBBLU+HIY"天惊地动"NOR+HIM"～～"HIW"

                                第一击  "BCYN+HIW"风"BWHT+HIC"兮"BCYN+HIW"破"BWHT+HIC"地"NOR"

                $N全身发出凛冽无匹的罡\气, 令人气息窒碍,割面生痛,
                只见$N身形如风, 气劲如尖锐铁锥般疾击$n$l!!\n",
        "damage": 220,
        "force":  220,
        "damage_type": "内伤",
        "weapon": HIW"天地之气"NOR,
        "post_action": (: sp1 :),
]),

//8
([ "action":HIM"
                                ～～"HBBLU+HIY"天惊地动"NOR+HIM"～～"HIW"

                                第二击  "HBBLU+HIC"水"HBCYN+HIB"兮"HBBLU+HIC"滔"HBCYN+HIB"天"NOR"

                霎时间, 只见$N浑身气劲如海涛巨浪, 汹涌澎湃, 双拳
                隐含巨啸狂浪吞天袭地之势, 向$n$l攻去!!\n",
        "damage": 240,
        "force":  240,
        "damage_type": "内伤",
        "weapon":HIB"怒"HIC"涛"HIB"狂"HIC"浪"NOR,
        "post_action": (: sp2 :),
]),


//9
([ "action":HIM"
                                ～～"HBBLU+HIY"天惊地动"NOR+HIM"～～"HIW"

                               第三击  "HBRED+HIY"火"HBYEL+HIR"兮"HBRED+HIY"焚"HBYEL+HIR"野"NOR"

                 $N四肢狂舞, 卦像如虹, 对$n引动无数火焰, 只见
                 $N形如火龙, 凌空打出无数火爪, 火影连连, $n试
                 图躲避, 但$N身形飘忽无定, 瞬息间烈火向$n周身
                 卷去!!\n",
        "damage": 260,
        "force":  260,
        "damage_type": HIR"业火"NOR"之伤",
        "weapon":HIR"焚"HIY"天"HIR"火"HIY"爪"NOR,
        "post_action": (: sp3 :),
]),


//10
([ "action":HIM"
                                ～～"HBBLU+HIY"天惊地动"NOR+HIM"～～"HIW"

                               第四击  "BYEL+HIY"山兮鬼神惊"NOR"

              $N身形凝重, 山势磅礴, 一股强大的气流压迫着$n, $N凭
              藉着五岳山神之力, 意在拳先, 朝$n$l轰去,!!\n",
        "damage": 280,
        "force":  280,
        "damage_type": "压伤",
        "weapon":YEL"五岳"HIG"灵气"NOR,
        "post_action": (: sp4 :),
]),


//11
([ "action":HIM"
                                ～～"HBBLU+HIY"天惊地动"NOR+HIM"～～"HIW"

                               第五击  "HBBLU+HIC"雷"HBCYN+HIB"兮"HBBLU+BLINK+HIW"天地碎"NOR"

               $N双手结印对天, 将聚集的天地之气回射, 鹜然一股真气自
               $N手中冲出, 将层层云雾破开一个大洞, 直冲天际, 一阵沈
               默之后, 一团狂雷自天际坠落, 直奔$n, 势如破竹!!\n",
        "damage": 300,
        "force":  300,
        "damage_type": HIC"天"HIB"雷"NOR"之伤",
        "weapon":HIC"九天"HIB"狂雷"NOR,
        "post_action": (: sp5 :),
]),
});

void attack(object me, object victim, object weapon, int damage)
{
       int a,lv=me->query_skill("universe",1);
       if ( lv >= 80) { a=7;}
       else a=5;
       if(!lv) lv=2;
       switch(random(a)+1)
       {
          case 1:
                    message_vision("$N突使奇招, 却被看破反击, 不得不回身防御!!\n",me,victim);
                    break;
          case 2:
                    damage = 200 + random(100);
                    message_vision(HIY"
$N觑中$n旧力已尽, 新力未生之际, 双掌接连拍出"HIG"「地雷复”"HIR"「剥地山”"HIW"「泽风破”"HIY"等招, $n闪无可闪, 登时元气大伤!!"NOR"\n",me,victim);
                    victim->receive_damage("kee",damage,me);
                    COMBAT_D->report_status(victim);
                    break;

          case 3:
                    message_vision("$N双掌蓄力, 却被$n看破抢攻, 只好弃攻为守!!\n",me,victim);
                    break;

          case 4:
                    message_vision(HIC"
$N双掌一错, 突然使出先天乾坤功的变招"HIW"～"BLINK+HIY"以腿代掌势"NOR+HIW"～"HIC", $n被此妙招一扰, 登时闹了个手忙脚乱"NOR"\n",me,victim);
                    victim->start_busy(1);
                    COMBAT_D->report_status(victim);
                    break;

          case 5:
                    message_vision("$N突使奇招, 却被看破反击, 不得不回身防御!!\n",me,victim);
                    break;

          case 6:
                    damage = victim->query("force_factor",1)*20+100;
                    message_vision(HIR"

               $N突然逆转气劲, 借$n之力合并本身内力一起回击$n自身,
               此招正是"HIW"‘先天乾坤功’"HIR"第六绝

                                   "BCYN+BLINK+HIY"‘逆转乾坤’"NOR"\n\n"NOR,me,victim);

                   victim->receive_damage("kee",damage,me);
                   COMBAT_D->report_status(victim);
                   break;

          case 7:
                    message_vision("$N逆转气劲, 却无法气随意转, 不得不暂缓攻势!!\n",me,victim);
                    break;
       }
}

void conti(object me, object victim, object weapon, int damage)
{
      int a,lv=me->query_skill("universe",1)/10;
if(50>random(100)) {
      for( a=1;a<=lv;a++)
      {
           message_vision(HBBLU+HIW"$N掌含"HBWHT+HIY"天地"HIC"风"HIB"雷"HBBLU+HIW"之威, 不断向$n周身破绽击去!"NOR"\n",me,victim);
           victim->receive_damage("kee",60,me);
           COMBAT_D->report_status(victim);
      }
}
}

void sp1(object me, object victim, object weapon, int damage)
{
// 因为改成能自选出招大家一定都用第五招那跟只写一招有什分别呢?
// 所以修正威力都差不多让大家有选则的意愿 by swy
if(me->query("env/天惊地动")==1) {
      damage = me->query_temp("tengin_power");
      damage = damage + random(300);
      message_vision("
      "BCYN+HIW"面对着$N如此惊心动魄地一击, $n竟不知道要如何应付, 只有照单全收!!"NOR"\n       ",me,victim);
      victim->receive_wound("kee",damage,me);
      COMBAT_D->report_status(victim);
      me->add("force",-500);
      message_vision(NOR"\n",me,victim);

}
}
void sp2(object me, object victim, object weapon, int damage)
{
if(me->query("env/天惊地动")==2) {
      damage = me->query_temp("tengin_power");
      damage = damage + random(400);
      message_vision("
       "HBBLU+HIC"$n提起全身劲力欲和袭来的滔天巨浪一拼, 甫一接触才发觉其势大之不可"NOR"
       "HBBLU+HIC"挡, 但已后悔莫及,顿时被源源不绝的拳势所吞没～～"NOR"\n  "NOR,me,victim);
      victim->receive_wound("kee",damage,me);
      victim->apply_condition("tsunami",5);
      me->add("force",-600);
      COMBAT_D->report_status(victim);
      message_vision(NOR"\n",me,victim);
}
}

void sp3(object me, object victim, object weapon, int damage)
{
if(me->query("env/天惊地动")==3) {
      damage = me->query_temp("tengin_power");
      damage = damage + random(500);
      message_vision("
           "HBRED+HIY"此时天上火云片片, 地上亦燃起无数烈火, 天地融合, 威力更增数倍, "NOR"
           "HBRED+HIY"$n深陷火海之中, 发出骇人的惨叫声"NOR"\n           "NOR,me,victim);
      victim->receive_wound("kee",damage,me);
      victim->apply_condition("skyfire",5);
      me->add("force",-700);
      COMBAT_D->report_status(victim);
      message_vision(NOR"\n",me,victim);
}
}

void sp4(object me, object victim, object weapon, int damage)
{
if(me->query("env/天惊地动")==4) {
      int i;
      damage = me->query_temp("tengin_power");
      damage = damage + random(600);
      for(i=1;i<=5;i++)
      {
         switch(i)
         {
            case 1:
message_vision("              "HBGRN+HIW"$N借动"HIG"‘东岳．泰山’"HIW"睥睨天下的气势，直击$n!!"NOR"\n              ",me,victim);
            break;
            case 2:
message_vision("              "HBGRN+HIW"$N显现"HIC"‘南岳．衡山’"HIW"云雾飘忽之姿, 往$n击去!!"NOR"\n              ",me,victim);
            break;
            case 3:
message_vision("              "HBGRN+HIW"$N引动"HIM"‘西岳．华山’"HIW"的浩然正气，双拳击向$n!!"NOR"\n              ",me,victim);
            break;
            case 4:
message_vision("              "HBGRN+HIW"$N使出"HIY"‘北岳．恒山’"HIW"绵中续劲之象，对$n攻去!!"NOR"\n              ",me,victim);
            break;
            case 5:
message_vision("              "HBGRN+HIW"$N拳含"HIR"‘中岳．嵩山’"HIW"严谨中正之态，向$n发劲!!"NOR"\n              ",me,victim);
            break;
         }
         victim->receive_wound("kee",(int)(damage/5),me);
         COMBAT_D->report_status(victim);
      }
      if(damage>=2600)
      {
         message_vision("

              "HBBLU+HIW"你豁然领悟了‘"BLINK+HIG"五"HIY"岳"HIC"合"HIR"一"NOR+HBBLU+HIW"’的真意, 拳含五岳灵气, "NOR"
              "HBBLU+HIW"向$n击出石破天惊的一击!!!!"NOR"\n\n              ",me,victim);
         victim->receive_wound("kee",1000,me);
         me->add("force",-1000);
         COMBAT_D->report_status(victim);
      }
      else
      {
         me->add("force",-800);
      }
      message_vision(NOR"\n",me,victim);
}
}

void sp5(object me, object victim, object weapon, int damage)
{
if(me->query("env/天惊地动")==5) {
      int i;
      object *enemy;
      enemy = me->query_enemy();
      i = sizeof(enemy);
      damage = me->query_temp("tengin_power");
      damage = damage + random(700);
      while(i--)
      {
         enemy[i]->receive_wound("kee", damage,me);
         message_vision("
            "HBMAG+HIW"面对犹如‘天劫’般的落雷不断, $n挡无可挡, 登时片体鳞伤!!!!"NOR"\n            ",me,enemy[i]);
         COMBAT_D->report_status(enemy[i]);
      }
      me->add("force",-900);
      message_vision(NOR"\n",me,victim);
}
}

mapping query_action(object me, object weapon)
{
      int level=(int)(me->query_skill("universe",1));

      if ( me->query_temp("tengin") == 1)
      {
         me->delete_temp("tengin");
         return action [6];
      }
      else if ( me->query_temp("tengin") == 2 )
      {
         me->delete_temp("tengin");
         return action [7];
      }
      else if ( me->query_temp("tengin") == 3 )
      {
         me->delete_temp("tengin");
         return action [8];
      }
      else if ( me->query_temp("tengin") == 4 )
      {
         me->delete_temp("tengin");
         return action [9];
      }
      else if ( me->query_temp("tengin") == 5 )
      {
         me->delete_temp("tengin");
         return action [10];
      }
      else if ( level < 20 )
         return action [random(2)];
      else if ( level < 40 )
         return action [random(4)];
      else if ( level < 80 )
         return action [random(5)];
      else
         return action [random(6)];
}

int valid_learn(object me)
{
      if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
         return notify_fail("练先天乾坤功需要空手演练..\n");
      if(me->query("max_force")/10<=me->query_skill("universe"))
         return notify_fail("你的内力太差, 无法将功力更进一步。\n");
      return 1;
}

int valid_enable(string usage)
{
      return (usage=="unarmed"||usage=="parry");
}

int practice_skill(object me)
{
      if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
         return notify_fail("练先天乾坤功还是要空手吧....\n");
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
      return CLASS_D("prayer")+"/universe/"+action;
}
