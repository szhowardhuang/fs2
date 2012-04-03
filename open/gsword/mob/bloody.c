#include <ansi.h>

inherit NPC;
int tt=0;
void create()
{
	set_name("ÑªÑı", ({ "Bloody","bloody" }) );
	set("race", "Ò°ÊŞ");
	set("age", 30);
	set("long", "È«ÉíÁ÷¶¯×ÅºìÉ«ÒºÌåµÄ¹ÖÎï,ºö¶øÅòÕÍ,ºö¶øËõĞ¡,ÍğÈçÒª½«ÄãÍÌÏÂÈ¥.\n");
	set("str", 40);
	set("cor", 40);
        set("limbs", ({ "Í·²¿", "ÉíÌå", }) );
        set("verbs", ({ "poke"}));
	set("combat_exp", 4000);
	set_temp("apply/armor", 30);
        set_temp("apply/attack", 20);
	set("attitude","aggressive");
	set("random_move",2);
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	    (: this_object(),"add_att" :), 
	   "[1;33m      ¡«ÑªÑı·¢³öÕóÕóĞ°¶ñµÄÆøÏ¢¡«   \n[0m",      
	         }) );
	set_skill("dodge",35);
	setup();               
	 add_money("silver",10);

}
 
int add_att() 
{  int att ;
   att=random(3);
   if (tt <1) { 
     this_object()->add_temp("apply/attack",att);
     message_vision ("[1;34m²»ÖªµÀÊÇ²»ÊÇ´í¾õ , "
	"Äã·¢ÏÖÑªÑıµÄÉíÇûÍ»È»±äµÃ´Ö×³Ğí¶à\n"NOR,this_object());
   }
   tt++;
   return 1;
}

void die()
{
 
  object me;
  me=this_object()->query_temp("last_damage_from");
  if( me&& userp(me) )  {
   me->add("bounds",20);
     tell_room(environment(),sprintf("%s´ÓÑªÑıÉíÉÏ³ıÏÂ20¸ùÂÌÃ«·Å½ø¿Ú´ü\n",me->name()));
    }
 :: die();
 } 
      
