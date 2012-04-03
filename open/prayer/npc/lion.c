//three_eye lion.c

#include <ansi.h>
inherit NPC;
void create()
{
      set_name("[36mÈýÑÛÒíÊ¨[0m",({"three_eyes lion","lion"}));
        set("long","ÓÐÊ¨×ÓµÄÉíÌå,ðÕµÄÁ³,Í¬Ê±ÓÖÓµÓÐ³á°òµÄÔ¶¹ÅÉñ»°¹ÖÎï¡£\n"    );
        set("race", "Ò°ÊÞ");
        set("age", 140);
        set("attitude","aggressive");    
        set("max_kee",6000);
        set("max_force",6000);
        set("force",6000);
        set("force_factor",5);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å" , "ºó½Å" , "Î²°Í" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",700000);
	set_temp("apply/armor", 100);
        set_temp("apply/attack", 80);
        set("attitude","aggressive");
	set_skill("dodge",90);
	setup(); 
//        carry_object("/open/gsword/obj/ff_item");
        set_heart_beat(1);
}
void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_object();
  if( me->is_fighting() )
  {
    if( 50 > random(200) )
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
      if(environment(me) == environment(enemy[i]))
      if( random(10) > 7)
      {
       message_vision(HIG"ÒíÊ¨Õ¹¿ª³á°òÒýÆðÁË¾Þ´óµÄÉ°·ç±©¹¥»÷$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",300,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIM+"±¬ÁÑµÄÒô²¨³¯$N³å»÷¶øÀ´,$N±»ÕðµÄÍ·»èÑÛ»¨!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",150,me);
      COMBAT_D->report_status(enemy[i], 0);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
