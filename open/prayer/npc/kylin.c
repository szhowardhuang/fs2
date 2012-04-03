#include <ansi.h>
inherit NPC;
void create()
{
	set_name("[31mÑª÷è÷ë[0m", ({ "red-kylin","kylin" }) );
	set("race", "Ò°ÊÞ");
	set("age", 200);
	set("long", "ÆÆÐ°¶´¿ßÖÐ×î¿Ö²ÀµÄ¹ÖÊÞ,È«ÉíÈç»ðÑ×°ãÍ¨ºì.\n");
	set("str", 100);
	set("max_kee", 10000);
	set("kee", 10000);
	set("max_force", 10000);
	set("gin",10000);
	set("max_gin",10000);
	set("sen",10000);
	set("max_sen",10000);
	set("force",10000);
	set("force_factor",5);
	set("limbs", ({ "Í·²¿", "¸¹²¿","ÉíÌå", "Ç°½Å" , "ºó½Å" , "Î²°Í" }) );
	set("verbs", ({ "bite"}));
	set("combat_exp",1500000);
	set_temp("apply/armor", 300);
	set_temp("apply/attack", 100);
	set("attitude","aggressive");
	set_skill("dodge",130);
	set("chat_chance",3);
	set("chat_msg",({				   
	(: random_move :), }));
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
       message_vision(HIR+"Ñª÷è÷ëÍÂ³öºìÉ«µÄ¶¾Îí,³¯$NµÄ·½ÏòÏ®¾í¶øÀ´!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",450,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIC+"Ñª÷è÷ëÕÅ¿ªÑªÅè´ó¿ÚÒ§×¡ÁË$NµÄÍ·,´óºÈÒ»Éù:¨Ï¨á ¨É¨Ú  ¨Ì¨Ú~~ !!!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",200,me);
      COMBAT_D->report_status(enemy[i], 0);
      me->receive_curing("kee",500);
      me->receive_heal("kee",500);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}			      

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;

        if(!winner)
	{
	::die();
	return ;
        }

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj7/kylin_order")->move(environment(winner));
	  message_vision(HIM"\n´ÓÑª÷è÷ëµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/kylin_order",sprintf("%s(%s) ÈÃÑª÷è÷ëµôÏÂÁË÷è÷ë½áÁîÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj7/kylin_order")->move(environment(winner));
	  message_vision(HIM"\n´ÓÑª÷è÷ëµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/kylin_order",sprintf("%s(%s) ÈÃÑª÷è÷ëµôÏÂÁË÷è÷ë½áÁîÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}

