// by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({

([ "action" :"$N"HIG"兽性一起 ,前爪向$n强劲的抓了过去 ,眼看猛烈的一击就要打到$n了"NOR"。",
          
                "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "抓伤",

           ]),
([ "action" :"$N"HIG"迅速往$n的方向冲了过去 ,用厚重的甲壳撞击着$n ,扬起了满天沙尘"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "内伤",
            ]),
([ "action" :"$N"HIG"伸出长长的尾巴 ,对准$n身上狠狠的扫去 ,$n被吓得措手不及"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "内伤",
            ]),
([ "action" :"$N"HIG"朝$n撞了过去 ,数千斤重的身体 ,挟着万均之势 ,像要把$n压进土里"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "撞伤",
            ]),
       });

void create()
{
     set_name(HIG"盘古真龟"NOR ,({"penku turtle", "turtle"}) );
     set("race", "野兽");
     set("title", "万年神兽");
     set("no_kill", 1);
     set("no_fight", 1);
     set("age",33972);
     set("long","长年躲居在壳中的大龟 ,和龙 ,凤 ,麟并称为四神兽
看起来似乎不容易杀死它 ,除非使用特殊的道具...\n");
     set("attitude","peaceful");   
     set_temp("apply/attack",120);
     set_temp("apply/damage",120);
     set_temp("apply/move",170);
     set("max_kee",129000);
     set("kee",129000);
 set("max_gin",120000);
     set("gin",120000);
 set("max_sen",120000);
     set("sen",120000);
     set("force",9000);
     set("max_force",9000);
     set("force_factor",10);
     set("max_gin", 100000);
     set("max_sen", 100000);
     set("combat_exp",3900000);
 set("chat_chance_combat", 25);         
     set_skill("dodge",400);
     set_skill("parry",400);
     set_skill("unarmed",0);
 
 set("limbs", ({ "龟首", "龟腹", "前肢" , "后足" , "龟尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);
 add_money("gold",100);                      
}
mapping query_action()
{
   return action[random(sizeof(action))];
}

void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_player();
  if( me->is_fighting() )
  {
    if( 80 > random(120) )
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
      message_vision(HIG+"盘古真龟"HIY"躲进了壳中 ,深深的吸了一口气!!!\n"+NOR,enemy[i]);
      me->receive_curing("kee",100000);
      me->receive_heal("kee",100000);
      me->receive_curing("sen",100000);
      me->receive_heal("sen",100000);
      me->receive_curing("gin",100000);
      me->receive_heal("gin",100000);
      me->clear_condition();
      COMBAT_D->report_status(enemy[i], 1);
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   :: heart_beat();
}
void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,turtle;
 ob=this_object();
 turtle=present( "turtle",environment(ob) );
 if(str=="askgod turtle" || str=="askgod penku turtle"){
 write(HIC"龟乃是神兽 ,不可逆天行事\n"NOR);
 return 1;                                                 
                  }
}




