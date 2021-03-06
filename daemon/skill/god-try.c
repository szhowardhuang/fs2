// enable-archery.c
// by airke
// By Swy 最后修正 QC 98/6/23
#include <combat.h>
#include <ansi.h>
inherit SKILL;

void god_att(object me, object victim, object  weapon, int damage);
void shooting_att(object me,object victim, object weapon,int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
int cps=this_player()->query("cps",1);
int sp_value;

string *lan_yan = ({
"$N使出流星箭法第一式‘一泄千里’，射出的$w化成一道星芒，挟着阵阵沙浪，一时间烟尘四起\n",

"$N使出流星箭法第二式‘双龙出海’，射出的$w化成两道星芒，一左一右，如双龙抢珠般\n",

"$N使出流星箭法第三式‘三分鼎足’，射出的$w化成三道星芒，如三国鼎立般，朝头 腹 及喉咙疾射而去\n",

"$N使出流星箭法第四式‘四面楚歌’，射出的$w化成四道星芒，似有灵性，朝手足四处关节疾射过去\n",

"$N使出流星箭法第五式‘五马分尸’，射出的$w化成五道星芒，似有灵性，朝头及四肢疾射而去\n",

"$N使出流星箭法第六式‘六道轮回’，射出的$w化成六道星芒，六道星芒不断的旋转着朝前疾速飞去\n",

"$N使出流星箭法第七式‘七星连线’，射出的$w化成七道星芒，七道星芒排成一线疾飞而去\n",

"$N使出流星箭法第八式‘八仙过海’，射出的$w化成八道星芒，八道星芒去势忽左忽右，缥缈不定\n",

"$N使出流星箭法第九式‘九九归元’，射出的$w化成九道星芒，九道星芒又合而为一，去势十分凶猛\n",
});

// 有箭时的叙述 $w是弓 $c 是箭
//应玩家要求.增加连击 by poloer
mapping *arrow_action = ({
//1
        ([      "action":
"$N看见$n招势已尽，迅速将$c搭于$w之上，使出流星箭法第一式「一泄千里”，箭势如洪水狂泄般朝$n$l飞射而去[m",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射伤",
        ]),
//2
([        "action":
"$N将手上$c迅速搭于$w分为两次射出，使出流星箭法第二式"HIG"「双龙出海”"NOR"，分射出之$c如双龙狂噬般朝$n而去",
                "dodge":        -100,
                "damage":       130,
                "force" :       130,
                "damage_type": "射伤",
                "parry":        -100,
        ]),
//3
        ([      "action":
"$N霸气突涨，将手中$c迅速搭于$w三箭齐发，使出流星箭法第三式"HIB"「三分鼎足”"NOR"，射出的$c似含三国鼎立之霸气分三处向$n急射而去",
                "dodge":        -100,
                "damage":       130,
                "force":         130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
//4
        ([      "action":
"$N被$n攻势所惊吓，将手中$c迅速搭于$w之上分射四箭，使出流星箭法第四式"HIY"「四面楚歌”"NOR"，射出的$c似有灵性般由$n前后左右四面飞射而去",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
//5
        ([      "action":
"$N心中杀气突涨，将手中$c迅速搭于$w上五箭齐射，杀气融合于$c使出流星箭法第五式"HIW"「五马分尸”"NOR"，$c朝$n头及双手双脚齐射而去",
                "dodge":        -100,
                "damage":       110,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
//6
        ([      "action":
"$N将手中$c迅速搭于$w，射出之际融入旋转气劲使出流星箭法第六式"HIG"「六道轮回”"NOR"，$c急速旋转朝着$n急射而去",
                "dodge":        -100,
                "damage":       115,
                "foece":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
//7
        ([      "action":
"$N将手中$c迅速搭于$w连续射出七箭，使出流星箭法第七式"HIM"「七星连线”"NOR"，$c七箭一箭接着一箭形成一线朝$n急射而去",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
        ]),
//8
        ([      "action":
"$N将手中$c迅速搭于$w缓缓射出，使出流星箭法第八式"HIC"「八仙过海”"NOR"，$c如同仙人过海般缥缈般令$n不知所措",
                "dodge":        -100,
                "damage":       130,
                "force":        130,
                "parry":        -100,
                "damage_type": "射伤",
                "post_action":  (: god_att :),
        ]),
//9
        ([      "action":
"$N将手中$c迅速搭于$w缓缓射出九箭，使出流星箭法第九式"HIR"「九九归元”"NOR"，射出九箭合一，令$n无法招架",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射伤",
                "post_action":  (: shooting_att :),
        ]),
//10
        ([      "action":
"        $N领悟到流星箭法之各式奥妙，将九式箭法连续使出，化为一式\n"
"            ‘～～～～凤～～～舞～～～九～～～天～～～～’      \n"
"        九式箭法看似同时射出般，$c化为无数流星朝着$n$l各处射去",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射伤",
                "post_action":  (: sp_attack1 :),
        ]),
//11
        ([      "action":
"        $N将冰心诀之内劲暗运于$c上，将手中$c搭于$w射出，化为一式\n "
"            ‘～～～～十～～～万～～～火～～～急～～～～’      \n"
"        箭势看似柔弱无力，$c去势缥缈不定的朝着$n身体疾速飞去。    ",
                "dodge":        -100,
                "damage":       130,
                "parry":        -100,
                "force":        130,
                "damage_type": "射伤",
                "post_action":  (: sp_attack2 :),
        ]),
});

// 下面是没箭时的攻击叙述

mapping *bow_action = ({
        ([      "action":               "$N举起$w狠狠地往$n$l砸去",
                "dodge":        -10,
                "damage":       10,
                "parry":        -10,
                "damage_type":  "瘀伤",

        ]),
        ([      "action":               "$N吃力地挥舞$w试着打伤$n",
                "dodge":        -5,
                "damage":       15,
                "parry":        -10,
                "damage_type":    "瘀伤",

        ]),
});

int valid_learn(object me)
{
        object ob;

if(me->query_skill("archery",1)<15)
                return notify_fail("要练流星箭法要先有相当的弓箭基础。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type")!="archery")
                return notify_fail("你手上要有弓箭才能练流星箭法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="archery" || usage=="parry";
}


mapping query_action(object me, object weapon)
{
  int skill_level, limit;
  object wpn = me->query_temp("weapon");
  int i;
//以下几行都是必须的..
//-----------------------------------------------------
//
// i = 目前弓上的箭数
  i=wpn->query("arrow/amount");
if ( !userp(me) )
        i ++;

//战斗中射完也必须将弓初始化
// 1的时候就可以初始化....因为初始化完还会攻击一次

 if(i==1) {
        tell_object(me, "\n你的" + wpn->query("arrow/name") + "用完了！\n\n");
        wpn->set("arrow/id","none");
        wpn->set("arrow/name","空的");
        wpn->set("weapon_prop/damage",wpn->query("bow/attack"));

  }
  if (i > 0) {
        i--;
        wpn->set("arrow/amount",i);
                // 呼叫有箭时的叙述
        return arrow_action[random(sizeof(arrow_action))];
  }

  if( i <= 0) {
                //呼叫没箭的攻击叙述
        return bow_action[random(sizeof(bow_action))];
  }
//----- under by poloer from --------------------------------------------


        skill_level=(int)me->query_skill("god-shooting", 1);

       if (skill_level < 10)
                return arrow_action[random(2)];
        else if (skill_level < 20 )
                return arrow_action[random(3)];
        else if (skill_level < 30 )
               return arrow_action[random(4)];
                else if (skill_level < 50 )
                return arrow_action[random(5)];
               else if (skill_level < 70 )
                       return arrow_action[random(6)];
               else if (skill_level < 80 )
                      return arrow_action[random(6)+1];
        else if(skill_level<90)
return arrow_action[random(6)+2];
        else
return arrow_action[random(6)+3];


}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，不能练流星箭法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("marksman")+"/god-shooting/"+action;
}

void god_att(object me, object victim, object  weapon, int damage)
{
if((random(80)<me->query_skill("iceforce",1))&&!me->set_temp("break"))
{
victim->start_busy(1);
message_vision(HIB"$N暗使冰心诀之阴寒内劲，将$n受内劲所困动弹不得。\n"NOR, me, victim);

}
}

void shooting_att(object me, object victim, object  weapon, int damage)
{
        int lose, i;
int bellpower = (int)me->query("cps")/3;
        // modify by oda
        // combat_exp 之比较在自身之 exp 加上 random
        // lose = skill/10 + 1 改为 random(skill/10) + 3
        // 增加连击完毕 busy 一回合
if(random(100)<70)
        {
        if(bellpower > 5) bellpower=5;
        lose=random(10);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
       message_vision(HIR"$N拿起数支箭使劲的往$n连射过去。\n"NOR, me,victim);
                       }
                victim->add("kee",-50);
                me->delete_temp("berserk");
                message_vision(HIW"一阵混乱后，$N用劲过度，赶紧趁机调息。\n"NOR,me);

        }
}

void sp_attack1(object me, object victim, object  weapon, int damage)
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
if( me->query("family/family_name")=="射日派"){
message_vision(HIY"
giggle
\n"NOR,me,victim);

  if( me->query("max_force") > 1000) {
    for(j=0; j < 9; j++) {
       do_action = lan_yan[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\n但是$N闪躲不及，身上插了一只只的利箭。\n" ,enemy[i]);
        enemy[i]->receive_damage("kee",50,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N看准箭的来势，不慌不忙的轻易闪避。\n" ,enemy[i]);
     if( random(me->query("cps")) < 10 && random(me->query("combat_exp",1)) < 1000000) {
        me->add("force",-100);

message_vision("\n$N使出"HIR"‘～～～～风～～～舞～～～九～～～天～～～～’"NOR"后，由于定力或经验不足，体内真气一时无以为继\n",me);
        me->start_busy(1);
                                        }
                                                  }
                                             }

}
}
