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
                "damage"     :    150,
                "damage_type":   "瘀伤",
            ]),
([ "action" : "$N使出绝情神掌第四招"+HIB+"【双龙取水】"+NOR+"，左右分使绝情神掌，令$n无法敌挡，内
外皆受到极大的伤害", 
                "dodge"      :   -50,
                "parry"      :   -50,
                "damage"     :   100,
                "damage_type":   "瘀伤",
            ]),
   });

void create()
{
        set_name("上官琳",({"lin"}));
        set("title","绝情门三弟子");
        set("nickname","火护法");
        set("long","她是绝情门的护法，是一位女性，非常的美，
但不要被她弱小的样子给骗了，她可是高手中的高手。\n");
        set("gender","女性");
        set("combat_exp",650000);
        set("age",20);
        set("max_kee",1000);
        set("kee", 1000);
        set("str", 24);
        set("cor", 24);
        set("cps", 45);
        set("per", 30);
        set("int", 32);
        set("force",1000);
        set("max_force",1000);
        set("force_factor", 10);
        set_skill("dodge", 80);
        set_skill("linpo-steps",80);
        set_skill("force",60);
        set_skill("unarmed", 80);

        map_skill("dodge","linpo-steps");
        set("chat_chance_combat", 25);
        set_temp("apply/armor",80);
        set_temp("apply/damage",40);
        set("chat_msg", ({
             (: this_object(),"random_move" :),
        }) );
        setup();
carry_object("/open/love/obj/hands.c")->wear();
carry_object("/open/love/obj/claw.c")->wield();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
        add_money("silver",10);

        reset_action();
 
}


mapping query_action()
{
        return action[random(sizeof(action))];
}
void greeting(object ob)
{
    int exp,lv_1;
    string skill;
    object weapon;
    exp =ob->query("combat_exp",1);
      weapon = ob->query_temp("weapon");
      if( weapon ) skill = weapon->query("skill_type");
      else skill = "unarmed";
      lv_1 =(int) 1.8 * ob->query_skill(skill, 1);
    return;
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i,kee;
 mapping exit;
 string *exit_name;

 mob = this_object();
 env = environment(mob);

  if( random(70) < 15)
 {
    enemy=mob->query_enemy();
	if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    kee = target->query("max_kee") * 0.2;
    if( env == environment(target) )
    {
     message_vision(HIW+"$N看见上官琳，祭起"+HIY+"「绝情诀”"+HIW+"以精化气，以
气御神，以神聚力，只见上官琳的"+HIR+"手臂通红"+HIW+"，
直向$N的"+HIR+"心脏"+HIW+"抓来，你顿时"+HIR+"血液完全被抽干\n"+NOR,target);
     target->receive_damage("kee",(int)kee,mob);
     COMBAT_D->report_status(target,0);
    }
	}
 }
 set_heart_beat(1);
  ::heart_beat();

}

