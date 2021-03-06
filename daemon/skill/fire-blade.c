#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack(object me, object victim, object weapon, int damage);
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
"$N足地一点，身形一变，使出"HIR"「入木三分”"NOR"，手中$w往$n横劈过去。",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       110,
             "force"  :       160,
             "damage_type": "砍伤",
        ]),
//2
       ([    "action" :
"$N运气于$w，一招"HIR"「移花接木”"NOR"趁$n接招之时，左手翻掌对准$n弱点一击。",
             "dodge" :   -10,
             "parry" :   -30,
             "damage" :  120,
             "force"  :  160,
             "post_action":  (: attack :),
             "damage_type" :   "掌伤",
         ]),
//3
        ([   "action" :
"$N运起内劲，将真气贯注$w，一招"HIG"「木已成舟”"NOR"刀气雄霸直劈$n。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         130,
             "force"  :         160,
             "damage_type":  "砍伤",
        ]),
//4
        ([   "action" :
"$N踿跃而起，凌空聚气，一招"HIG"「一刀二断”"NOR"刀锋冷凛直劈$n。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         140,
             "force"  :         160,
             "post_action":  (: attack :),
             "damage_type":  "砍伤",
        ]),
//5
        ([   "action" :
"$N一招"HIY"「星火燎原”"NOR"手中$w有如闪电般快速砍下，周边空气有如燃烧般爆出火光。",
             "dodge"  :        -10,
             "parry"  :        -30,
             "damage" :        150,
             "force"  :        160,
             "damage_type":  "砍伤",
        ]),
//6
        ([   "action" :
"$N挥动手中$w使出"HIY"「缘木求鱼”"NOR"只见$w像一道刀网把$n封闭在其中。",
             "dodge"  :       -10,
             "parry"  :       -30,
             "damage" :       160,
             "force"  :       160,
             "post_action":  (: attack :),
             "damage_type":  "砍伤",
        ]),
//7
        ([   "action" :
"$N使出"HIB"「釜底抽薪”"NOR"，只见$w刀刀相连直砍$n，$N再顺势移转至$n背后补上一刀。",
             "dodge"  :         -10,
             "parry"  :         -30,
             "damage" :         170,
             "force"  :         160,
             "damage_type":  "骨断之伤",
        ]),
//8

        ([      "action":
"$N持$w一扬，使出"HIB"「燃木生火”"NOR"，刀刀皆带炙热刀气，气劲直劈$n。",
                "dodge":  -10,
                "parry":  -30,
                "damage": 180,
                "force":  160,
                "damage_type":  "灼伤",
        ]),
//9
        ([      "action":HIW
"$N内劲一吐，使出"HIM"「朽木可雕”"HIW"，把所有真气贯注于$w"HIW"，往$n飞射而去\n"
"$n知此招不能硬挡，避重就轻就要闪过此招，却不知鬼影幻形，$N早就在一旁等候\n"
"逮住机会双掌相并而下，造成$w"HIW"拦腰贯体而过。"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       190,
                "force":        160,
                "post_action":  (: attack :),
                "damage_type":  "破体之伤",
        ]),
//10
       ([      "action" :HIW
"$N内劲狂吐，使出"HIM"「披荆斩蕀”"HIW"，运转了十成功力，分别注于左掌与$w"HIW"，眼见\n"
"$n抢攻过来，$N不徐不避，左掌一挥硬是把攻势给挡了下来，就在同时，右手$w"HIW"横劈\n"
"而去，$n无从遁形被深深的砍及要害。"NOR,
               "dodge":         -10,
               "parry":         -30,
               "damage":        200,
               "force":         160,
               "post_action":  (: attack :),
               "damage_type":   "血肉之伤",
        ]),
//11
       ([      "action" :HIC
"$N加运内息，逆转筋脉，使出"HIB"「杯水车薪”"HIC"，只见出招无一顺序，由后而前，由下而上\n"
"$n顿时反应不及硬是吃了$w"HIC"一记。"NOR,
                "dodge" :       -10,
                "parry" :       -30,
                "damage":       220,
                "force" :       160,
                "post_action":  (: attack :),
                "damage_type":  "砍伤",
        ]),
//12
       ([ "action" :HIC
"$N使出燃木刀法精华，一招"HIW"「火树银花”"HIC"，以慢制快，以轻驭重，以柔克刚，加上雄厚的内劲\n"
"使$n招招不敌，$N见机加快攻势，$w"HIC"直挺而出直捣$n。"NOR,
"dodge": -10,
"parry": -30,
"force": 160,
"post_action":  (: attack :),
"damage": 220,
"damage_type": "砍伤",
]),

});
mapping query_action(object me, object weapon)
{
int skill, limit, f;
skill=(int)(me->query_skill("fire-blade", 1));
limit=(int)(skill/10);
if(limit<3)
{
return action[random(2)];
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
return action[random(8)];
}
if(limit<10)
{
return action[random(10)];
}
else
{
return action[random(12)];
}
}

int valid_learn(object me)
{
        object ob;
        if((int)me->query("max_force",1)<1000)
        return notify_fail("你的内力不够，不能练燃木刀法。\n");
        if((string)me->query_skill_mapped("force")!= "woodforce")
        return notify_fail("燃木刀法必需配合木诀心法才能用。\n");
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
        return CLASS_D("bonze") + "/fire-blade/" + action;
}

void attack(object me, object victim, object weapon, int damage)
{
int a,lv=me->query_skill("fire-blade",1);
if ( lv >= 80) { a=7; }
else a=4;
switch(random(a))
{
          case 0:
                    damage = 4*(str+cor)+cps+kar+spi+int1;
message_vision(sprintf(HIW"\n$N确实命中$n要害，$n顿时血流满地。\n"NOR),me,victim);
                    victim->receive_damage("kee",damage);
                    COMBAT_D->report_status(victim);
                    break;

          case 1:
message_vision("$N暗运丹田急欲抢攻，却被$n看破，只好弃攻为守。\n",me,victim);
                    break;

          case 2:
message_vision(sprintf(HIW"\n$N的一记强攻使$n攻势慢了下来。\n"NOR),me,victim);
                    victim->start_busy(random(2)+1);
                    COMBAT_D->report_status(victim);
                    break;

          case 3:
message_vision("$N见$n气息错乱，见机抢攻，却被$n看破，无攻而反。\n",me,victim);
                    break;

          case 4:
damage=4*(cps+int1)+str+cor+kar+spi;
message_vision(HIW"\n$N故作破绽，让$n抢攻，趁抢攻之时，左指反伸而点，化去了$n大半真气。\n"NOR,me,victim);
if(victim->query("force",1)>0)
{ victim->add("force",-(victim->query("force",1)/2)); }
                   victim->add("kee",-damage);
                   COMBAT_D->report_status(victim);
                   break;

          case 5:
message_vision("$N运转气劲，却无法即时吐呐，不得不暂缓攻势。\n",me,victim);
                    break;
          case 6:
message_vision(sprintf(HIW"\n$N运起十成功力，运行于身上各大穴，准备伺机给$n极大伤害。\n"NOR),me,victim);
me->set_temp("addpower",1);
          break;
       }
}
