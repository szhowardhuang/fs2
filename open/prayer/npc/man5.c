//man--copper
#include <command.h>
#include <ansi.h>

inherit NPC;

string ask_metal()
{
	object who=this_player();
        if( who->query_temp("metal/where") >= 6 )
        {
	who->delete_temp("metal/where");
	who->set_temp("metal/where",7);
        return("[36mÅ¶!!ÄãÌıÀÏÀîËµ¹ıÀ²!!ÎÒÃÇ¿ó¹¤Ñ½, ¶¼ÊÇºÜ»áÕÒ½ğÊô¿óµÄÀ²!!\n
	ÔÚ¶«±±±ßÁ½¸öÖ§ÃÅÖ®¼ä¸½½üµÄµØ·½¿ÉÒÔÕÒµ½[Í­¿ó]à¸!!ÔÚ¶´¿ßÀïÒ²¿ÉÒÔÕÒµ½[Í­¿ó]à¸!![0m\n");
        }
	else
	{
	return("[35mÀ´À´À´, Ô¸Òâ¸úÎÒÃÇÒ»ÆğºÈ¾ÆÂğ??[0m\n");
	}
}   

void create()
{
    set_name("Î÷ÓòÄĞ×Ó",({"man"}));
    set("gender", "ÄĞĞÔ");
    set("age",63);
    set("attitude","friendly");
    set("long",@LONG

	ÕâÎ»ÀÏĞÖÏÖÔÚÊÇ¹Ù¼ÒµÄ¿ó¹¤, ´ÓÊÂ¹Ù·½½ğÊôµÄ¿ª²É¹¤×÷!!

LONG);
 
    set("combat_exp",500);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"ÄĞ×ÓµÀ: À´À´À´, ½ñÌìºÈ¸ö²»×í²»¹éÑ½!!\n"+NOR,
    }) );
    set("inquiry",([
    "½ğÊô":(: ask_metal :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
