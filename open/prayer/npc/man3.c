//man--iron
#include <command.h>
#include <ansi.h>

inherit NPC;

string ask_metal()
{
	object who=this_player();
        if( who->query_temp("metal/where") >= 5 )
        {
	who->delete_temp("metal/where");
	who->set_temp("metal/where",6);
        return("[36mÅ¶!!ÄãÌıÎÒ¼ÒÄÇÅ®ÈËËµÀ²!! ÎÒÃÇ¿ó¹¤Ñ½, ¶¼ÊÇºÜ»áÕÒ½ğÊô¿óµÄÀ²!!\n
        ÎÒ»¹ÓĞÒ»Ğ©¸öÅóÓÑÒ²¶¼ÔøÍÚ¹ıÆäËüµÄ½ğÊôÁ¨!![0m\n");
        }
	else
	{
	return("[35mÀ´À´À´, Ô¸Òâ¸úÎÒÃÇÒ»ÆğºÈ¾ÆÂğ??[0m\n");
	}
}   

string ask_friend()
{
	object who=this_player();
	if( who->query_temp("metal/where") >= 6 )
        {
	who->set_temp("metal/where",7);
	return("[36m[Ìú¿ó]Ñ½, ÊÇÎÒÔÚ¶«±±½ÇÍÚµ½µÄ!!\n
         ÎÒ¸æËßÄãà¸!!ÎÒÄÇĞ©ÅóÓÑ°¡, ¶¼ºÜÏ²»¶ÔÚÊ¥»ğ½ÌÀïÍ·ÕÒÈËÁÄÌì!!\n
	 µ½¸÷¸öÖ§ÃÅÈ¥ÕÒÕÒ°É!!»áÕÒµ½ËûÃÇµÄ!![0m\n");
	}
        else
	{
	return 0;
	}
}

void create()
{
    set_name("Î÷ÓòÄĞ×Ó",({"man"}));
    set("gender", "ÄĞĞÔ");
    set("age",43);
    set("attitude","friendly");
    set("long",@LONG

	Àî¼Ò¹ÙÈË, ÏÖÔÚÊÇ¹Ù¼ÒµÄ¿ó¹¤, ´ÓÊÂ¹Ù·½½ğÊôµÄ¿ª²É¹¤×÷!!

LONG);
 
    set("combat_exp",600);
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
    "ÅóÓÑ":(: ask_friend :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
