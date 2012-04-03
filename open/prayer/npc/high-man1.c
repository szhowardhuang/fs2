//´óÍ½µÜ
#include <command.h>
#include "/open/open.h"
 
inherit NPC;

void create()
{
    set_name("Î÷ÓòÄĞ×Ó",({"man"}));
    set("gender", "ÄĞĞÔ");
    set("age",40);
    set("attitude","peaceful");
    set("long",@LONG

	ËûÊÇ¹ã³ÉÅÉµÄµÜ×Ó, ÅÅĞĞÊ×Î»!!¾«Í¨µ¶·¨!!

LONG);
 
    set("combat_exp",10000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",700);
    set("kee",700);
    set("max_force",500);
    set("force_factor", 10);
    set("force",500);
    set("limbs",({"Í·","ÊÖ","½Å","±³","¸¹","Ñü"}));
    set_skill("dodge",60);
    set_skill("move",60);
    set_skill("parry",60);
    set_skill("force",60);
    set_skill("fireforce",60);
    set_skill("blade",60);
    set_skill("dragon-blade",60);
    map_skill("force", "fireforce");
    map_skill("blade", "dragon-blade");
    setup();
    carry_object("/open/port/obj/ghost_blade")->wield();
    
}

int accept_kill(object ob)
{
	if( ob->query("kill_high1") )
        {
        write("[36mÉÙÏÀÒÑ¾­Ê¤¹ıÔÚÏÂ,  Ë¡ÔÚÏÂ²»ÉÔ·îÅã!![0m\n");
	return 0;
        }
	else
	{
        tell_object( ob ,"[36m·îÊ¦×ğÖ®ÃüÓëÉÙÏÀÇĞ´è¼¸ÕĞ!![0m\n");
        return 1;
	}
}

void die()
{
    object ob;
    ob= this_object()->query_temp("last_damage_from");
    if( ob && userp(ob) ) 
    {
    ob->add("potential", 10000);
    ob->set("kill_high1", 1);
    write("[36mÉÙÏÀÎäÑ§½øÕ¹Ö®¿ì, ÁîÔÚÏÂ¿É¾´¿ÉÅå!![0m\n");
    }
    ::die() ;
}


