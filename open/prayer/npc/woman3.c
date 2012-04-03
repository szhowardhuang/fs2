//woman
#include "/open/open.h"
#include <ansi.h>

inherit NPC;

string ask_metal()
{
    object who=this_player();
    if( who->query_temp("metal/where") >= 4 )
    { 
     who->set_temp("metal/where",5);
     return("[36m¶ÔÑ½!!ÎÒ¼ÒÄÇ¸öÄĞÈËÑ½, ¾¹È»´øÁË¿éÌú»ØÀ´, »¹ÒªÎÒÄÃÈ¥´òÁË°ÑÌúÇÂÄØ!![0m\n");
    }
    else
    {
     return("[35mß×!!ÇëÎÊÄúÊÇ¹Ù¸®µÄÈËÂğ??[0m\n");
    }
}
void create()
{
    set_name("ÀîÉ©",({"lee woman","lee","woman"}));
    set("gender", "Å®ĞÔ");
    set("age",41);
    set("attitude","friendly");
    set("long",@LONG

	ÀîÉ©ÊÇÎ÷½ÖµÄ³¤Éà¸¾Ö®Ò», ËıµÄÏÈÉúÊÇÒ»Î»¿ó¹¤, ÔÚ¹Ù
	¼Ò×öÊÂ!!

LONG);
 
    set("combat_exp",25);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"ÀîÉ©Ëµ: ºÇºÇ!!ÎÒÑ½, ×òÌìÌıµ½³Â¼ÒÏ±¸¾¶ù¸úËıµ±¼ÒµÄÔÚÈö½¿Á¨!!\n"+NOR,
    }) );
    set("inquiry",([
    "½ğÊô":(: ask_metal :),
    "µ±¼ÒµÄ":"[36mÎÒµ±¼ÒµÄÑ½, ËûÏÖÔÚÔÚÊ¥»ğ½ÌµÄ×ÜÌ³ÀïÃæÕÒÅóÓÑºÈ¾ÆÄÄ!![0m\n",
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
