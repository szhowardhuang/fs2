//woman
#include <command.h>
#include <ansi.h>

inherit NPC;

string ask_metal()
{
    object who=this_player();
    if( who->query_temp("metal/where") >= 3 )
    { 
    who->set_temp("metal/where",4);
    return("[36m»¹²»ÊÇÄÇÌì¸úÀîÉ©ÁÄÌìµÄÊ±ºòÌáµ½µÄ!!Ëıµ±¼ÒµÄÑ½, ¾ÍÔøÍÚÁË¿éÌú»ØÀ´¸øËıÇÆÇÆÄØ!!\n
    ÌıËµÊÇÔÚÄ³×ùÉ½ÉÏÍÚµ½µÄ!![0m\n");
    }
    else
    {
    return("[35mÀ´À´À´, ÎÒÃÇÒ»ÆğÈ¥ÕÒÀîÉ©ÁÄÁÄÈ¥!![0m\n");
    }
}

void create()
{
    set_name("Î÷Óò¸¾Å®",({"westarea woman","woman"}));
    set("gender", "Å®ĞÔ");
    set("age",42);
    set("attitude","friendly");
    set("long",@LONG

	Î÷Óò¸¾Å®!!ÏĞ×ÅÃ»ÊÂµ½ÅóÓÑ¼ÒÈ¥{¿ª½²}, ÕâÖÖ³¤ÉàµÄÈË
	ÖªµÀµÄÃûÌÃÓ¦¸ÃºÜ¶à²Å¶Ô.....

LONG);
 
    set("combat_exp",70);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"¸¾Å®Ëµ: ×ß†ª!!½ñÌìÑ½Ã»ÓĞÊ²Ã´ÊÂ×ö, È¥ÕÒÈËÁÄÁÄÌì¶ù!!\n"+NOR,
    }) );
    set("inquiry",([
    "½ğÊô":(: ask_metal :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
