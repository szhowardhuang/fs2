#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" : "$N使出绝情神掌第一招"+HIY+"【亢龙有悔】"+NOR+"，右掌划了个圈圆，向$n的$l推去",
                "dodge"      :    -25,
                "parry"      :    -20,                                      
                "damage"     :    100,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N使出绝情神掌第二招"+HIG+"【飞龙在天】"+NOR+"，犹如飞龙般跃起半空，居高下击，向$n
的$l击出",
                "dodge"      :     -50,
                "parry"      :     -10,
                "damage"     :     110,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N使出绝情神掌第三招"+HIR+"【突如其来】"+NOR+"，于迅雷不及掩耳的速度，让$n攻其不备",
                "dodge"      :    -30,
                "parry"      :    -45,
                "damage"     :    130,
                "damage_type":   "瘀伤",
            ]),
([ "action" : "$N使出绝情神掌第四招"+HIB+"【双龙取水】"+NOR+"，左右分使绝情神掌，令$n无法敌挡，内
外皆受到极大的伤害", 
                "dodge"      :   -50,
                "parry"      :   -50,
                "damage"     :   150,
                "damage_type":   "瘀伤",
            ]),
   });


void create()
{
  set_name("绝情门弟子", ({ "trainee" }) );
  set("long","他在这个广场操练中，看来很强壮，不好对付的样子。\n");
  set("race", "人类");
  set("gender","男性");
  set("combat_exp",400000);
  set("age",18);
  set("cor",30);
  set("cps",30);
  set("str",20);
  set("kee",1000);
  set("max_kee",1000);
  set("force",700);
  set("max_force",700);
  set("force_factor",2);
  set("chat_chance",25);
  set("bellicosity",1000);
  set("attitude","aggressive");
  set_skill("dodge", 40);
  set_skill("linpo-steps",40);
  set_skill("force",40);
  set_skill("unarmed", 60);

  map_skill("dodge","linpo-steps");
  set("chat_chance_combat", 25);
  set_temp("apply/armor",40);
  set_temp("apply/damage",20);
  set("chat_msg", ({
       (: this_object(),"random_move" :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__,"query_action" :));
  add_money("coin",100);

  reset_action();
}
mapping query_action()
{
        return action[random(sizeof(action))];
}
