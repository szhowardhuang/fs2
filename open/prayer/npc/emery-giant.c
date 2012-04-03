//emery-giant

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("[30mºÚÉ°¾ÞÈË[0m", ({ "emery-giant","giant" }) );
        set("race", "ÈËÀà");
	set("age", 160);
	set("long", ",È«Éí·ººÚµÄ¾ÞÐÍÒ°ÈË£¬¼¡·ôÓÐÈçÑÒÊ¯Ò»°ãµÄ¼áÓ²¡£\n");
	set("str", 85);
        set("max_kee", 8000);
        set("max_force", 10000);
        set("force",10000);
        set("force_factor",5);
       set("kee", 8000);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å" , "ºó½Å" , "Î²°Í" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",1100000);
	set_temp("apply/armor", 100);
        set_temp("apply/attack", 100);
        set("attitude","aggressive");
	set_skill("dodge",100);
	setup(); 
        carry_object("/open/gsword/obj/ff_item");
        carry_object("/open/gsword/obj/f_item");
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
       message_vision(HIM+"¾ÞÈË´ÓÉíÉÏ³¶ÏÂÊ¯¿éÈÓÁË¹ýÀ´£¬»÷ÖÐÁË$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",350,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIC+"×¥×¡ÁË$N£¬ºÝºÝµØ³¯¶´±ÚË¦ÁË¹ýÈ¥!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",160,me);
      COMBAT_D->report_status(enemy[i], 0);
      me->receive_curing("kee",200);
      me->receive_heal("kee",200);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
