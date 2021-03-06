//shun.c
#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N大叫：‘星  云  锁  炼’，刹那间锁炼已经把$n的全身包住了！！！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    180,
                "force"      :    200,
                "damage_type":   "内伤",
           ]),
([     "action"     :   "$N大叫：‘星  云  锁’，不知从那冒出来的锁炼将$n的全身上下刺成血肉
糢糊的一团。",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    200,
                "force"      :    200,
                "damage_type":   "刺伤",
           ]),
([    "action"     :   "$N将圣衣脱下来，集中了全身的小宇宙，使出了‘星  云  气  流’，渐渐的
$n的呼吸感到困难，只见一股强大的气流把$n带上天空随着风到处乱撞！！！",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    180,
                "damage_type":   "撞伤",
            ]),
   });

void create()
{
        set_name("瞬", ({"shun"}));
        set("age",15);
        set("long","他是属于青铜级的圣斗士，在三大圣战中一直是护卫着雅典娜女神\n"
        "而现在的实力是远超过黄金圣斗士，是雅典娜忠心的护卫。\n");
        set("title",HIM"仙女座"NOR+ HIG"圣斗士"NOR);
        set("gender","男性");
        set("class","圣斗士");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("max_gin",1000);
        set("max_kee",3000);
        set("max_sen",1000);
        set("gin",1000);
        set("kee",2000);
        set("sen",1000);
        set("combat_exp",1370000);
        set("max_force",10000);
        set("force",10000);
        set("max_atman",5000);
        set("max_mana",5000);
        set("atman",5000);
        set("mana",5000);
        set("force_factor",30);
        set_skill("dodge",200);
        set_skill("unarmed",200);
        set("chat_chance_combat",45);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/armor",380);
        set_temp("apply/damage",78);
        setup();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
	reset_action();
}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void do_special()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];

                message_vision(
HIW "\n瞬把圣衣脱下，燃烧了自己的小宇宙，大喝一声：看我的‘星　云　风　暴’～～～
\n",target);
                message_vision(
HIY "\n瞬的身边突然传来一道道的飓风，刹那间就将$N身影全部给卷进去了！！
\n"NOR,target);
                target->receive_wound("kee",random(200+250));
                COMBAT_D->report_status(target);

  }
