#include </open/open.h>
inherit NPC;
int do_say();
string do_thief();
void create()
{
	set_name("ÎäÁÖºÀ¿Í", ({ "fighter" }) );
	set("race", "ÈËÀà");
	set("gender", "ÄĞĞÔ");
	set("age", 33);
	set("class","fighter");
	set("long","ËûÊÇÒ»Î»ÎäÁÖÀïµÄºÀ¿Í, ÉíĞÎ¿ıÎà, Á³ÉúºáÈâ, ×ì´ó´½ºñ, Ìú÷ÚÈç·äÎÑ, "+
        "ËûÎªÁË´³³öÒ»·¬¹¦Ãû¶øµ½¾©³ÇÀ´ÅöÅöÔËÆø¡£\n");
	set("cps", 5);
	set("str", 30);
	set("cor", 20);
	set("kar",10);

        set( "inquiry", ([
       	  "name"  : "´ıÎÒ´³³öÒ»·¬ÊÂÒµÀ´ÔÙËµ°É¡£",
       	  "here"  : "ÕâÀïÊÇ¾©³Ç°¡, ÎÒÒ²ÎªÁËÇ°Í¾¶øÀ´µ½Õâ¶ù, ÄãÄØ?",
	  "thief" : (: do_thief :),
        ]));	 	
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	(: this_object(),"do_say" :),
	 }) );
		
        set_temp("apply/attack", 50);
        set_skill("dodge",30);
        set_skill("parry",40);
        set_skill("blade",60);
	set_skill("her-blade",50);
	map_skill("blade","her-blade");
        set("combat_exp",5000);
	setup();
        add_money("silver",1);
        carry_object(CAPITAL_OBJ"Bblade")->wield();
}

string do_thief()
{
	object ob=this_object();
	object me=this_player();
	if( ob->query_temp("show_mark")==getuid(me) )
	{
	  command("say ¼ÈÈ»´óÈËÎª°ì°¸¶øÀ´, Ğ¡µÄÕâ¾ÍÔ­Ô­±¾±¾µÄ¸æËßÄãÁË¡£");
command("say ´ËÃû´óµÁµÄÎä¹¦ËÆºõÊÇÆ½ÄÏ³Ç¶Î¼ÒÒ»ÅÉµÄÁùÂöÉñ½££¬ÇÒ´ËµÁµÄÓÒ¶úºóÓĞĞ¡ÉËºÛ(scar)¡£");
	  me->set_temp("thief",3);
	  return("ÎÒ¾ÍÖªµÀÕâÃ´¶àÁË");
	}
	else
	  return("¹ş¹ş¹ş!!ÓĞÌìÒ¹ÀïÎÒÆğÀ´Ğ¡½âÊ±Ç¡ÇÉÅöµ½ÄÇÃû´óµÁ, ²ÅÁ½ÈıÕĞ±ã°ÑËû´òµÄÂä»Ä¶øÌÓ, ÖÁÓÚËûµÄ³¤ÏàÎÒ¿É¾Í²»ÄÜ¸úÄãËµÁË, ÎÒÒª×Ô¸ö°ÑËû×¥À´ÁìÉÍ, ¹ş¹ş¹ş....");
}

int do_say()
{
	object ob=this_player();
	tell_room(environment(this_object()),
	"ºÀ¿ÍºÈµÀ£º¿É¶ñ!!ÄãÕâ"+RANK_D->query_rude(ob)+", ÈÃ´óÒ¯ÎÒÀ´½ÌÑµÄã!!\n");
}
	
void defeated_enemy(object ob)
{
	say("[36mºÀ¿ÍÀäĞ¦Ò»ÉùµÀ : Ã»±¾ÊÂÒ²¸Òµ½¾©³ÇÈöÒ°¡£[0m\n");
        remove_killer(ob);
}        
