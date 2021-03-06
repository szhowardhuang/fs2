//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N"HIB"凶性大发 ,锐利的龙爪向$n狠狠的抓了过去 ,水劲汹涌的把$n围绕"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  290,
             "damage_type":  "抓伤",
           ]),
([ "action" :"$N"HIB"迅速扑至$n面前 ,龙爪如巨滔般攻势朝$n直抓下去 ,$n当场鲜血飞溅"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  280,
             "damage_type":  "抓伤",
            ]),
([ "action" :"$N"HIB"身形忽退 ,取而代之的是一波波的巨浪朝着$n袭去 ,狂猛的来势好不吓人"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -25,
             "damage"     :  285,
             "damage_type":  "内伤",
            ]),
([ "action" :"$N"HIB"朝$n狂抓了过去 ,挟带着水劲的双爪 ,力道之猛 ,令人发指"NOR"。",
             "dodge"      :  -40,
             "parry"      :  -15,
             "damage"     :  295,
             "damage_type":  "抓伤",
            ]),
([ "action":"$N"HIB"狂吼长啸 ,水面不停的翻搅 ,生成数个大漩涡 ,$n的身体整个都被吞噬掉"NOR"。",
             "dodge"      : -10,
             "parry"      :  -20,
             "damage"     : 285,
             "damage_type":  "内伤",
           ]),
       });

void create()
{
     set_name(HIB"水龙"NOR ,({"water dragon", "dragon"}) );
     set("race", "野兽");
     set("title", "守护者");
     set("age",2529);
     set("cor", 30);
     set("long","四条巨龙之一 ,是传说中上古时代的龙族\n");
     set("attitude","aggressive");   
     set_temp("apply/attack",130);
     set_temp("apply/damage",110);
     set_temp("apply/move",70);
     set("max_kee",7500);
     set("kee",7500);
     set("force",4900);
     set("max_force",4900);
     set("force_factor",35);
     set("max_gin", 7000);
     set("max_sen", 7000);
     set("combat_exp",2700000);
     set_skill("dodge",400);
     set_skill("parry",400);
     set_skill("unarmed",200);
 set("limbs", ({ "龙首", "龙身", "前肢" , "后足" , "龙尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);
 add_money("gold",45);
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
  message_vision(HIB+"水面波滔忽起 ,强劲的水流形成无数漩涡 ,$N全身惨被卷入!!!\n"NOR,enemy[i]);
      
      enemy[i]->receive_damage("kee", 100,me);
      COMBAT_D->report_status(enemy[i], 1);
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   :: heart_beat();
}

 void die()                                                                 
{
    object winner = query_temp("last_damage_from");        

    new("/open/mogi/dragon/obj/water")->move(environment(winner));
    new("/open/mogi/dragon/obj/water-1")->move(environment(winner));

   tell_object(winner,HIY"\n\n经过一番血战后 ,水龙终于被你收服了\n\n"NOR);            
   tell_object(winner,HIC"\n水龙自口中吐出一块宝玉\n\n\n"NOR);
               destruct(this_object());
                                                                    
            ::die();                                                           
      }                    






