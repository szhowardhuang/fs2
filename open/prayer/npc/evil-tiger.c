//evil-tiger.c

#include <ansi.h>
inherit NPC;
void create()
{
      set_name("[36mÐ°»¢[0m",({"evil-tiger"}));
        set("long","ÆÆÐ°¶´¿ßÖÐÐ°¶ñµÄÒ°ÊÞ£¬Ã«Ó²ÈçÌú£¬ÐÐ¶¯¿ìËÙ¡£³£¶ãÔÚÑÒ±ÚÖ®ÖÐ£¬ÔÚËÅ»ú³öÀ´¹¥»÷µÐÈË¡£\n"    );
        set("race", "Ò°ÊÞ");
        set("age", 160);
        set("attitude","aggressive");    
        set("max_kee",7000);
        set("max_sen",7000);
        set("max_gin",7000);
        set("max_force", 10000);
        set("force",10000);
        set("force_factor",5);
        set("kee",7000);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å" , "ºó½Å" , "Î²°Í" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",900000);
	set_temp("apply/armor", 100);
        set_temp("apply/attack", 90);
        set("attitude","aggressive");
	set_skill("dodge",90);
	setup(); 
        carry_object("/open/gsword/obj/ff_item");
        add_money("gold",20);
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
       message_vision(HIY"Ð°»¢ÕÅ¿ª´ó¿Ú,¼âÈñµÄÑÀ³ÝÒ§×¡ÁË$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",300,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIM+"Ð°»¢ÒÔ¸ßËÙÏò$N³å»÷¶øÀ´,$N±»×²µÄ·ÉÁËÊ®¶àÕÉ!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",160,me);
      COMBAT_D->report_status(enemy[i], 0);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
