//woman
#include "/open/open.h"
#include <ansi.h>
inherit NPC;

string ask_metal()
{
     object who=this_player();
     who->set_temp("metal/where",1);
     return("[36mÎÒÒ²ÊÇÌıÎÒµ±¼ÒËµµÄ!!ºÃÏñÊÇ¡«¡«ÓĞËÄÖÖ½ğÊô°É!![0m\n");
}

void create()
{
    set_name("Î÷ÓòÉÙ¸¾",({"young woman","woman"}));
    set("gender", "Å®ĞÔ");
    set("age",22);
    set("attitude","friendly");
    set("long",@LONG

	Î÷ÓòÉÙ¸¾!!ÕıÔÚ½ÖÉÏĞĞ×ß×Å, Ó¦¸ÃÊÇÒªµ½ÊĞ¼¯²É°ìÊ³Æ·°É.....

LONG);
 
    set("combat_exp",20);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",3);   
    set("chat_msg", ({
     HIC+"ÉÙ¸¾Ëµ: ×î½üÌıËµÓĞÈË·¢ÏÖÒ»¸öµØ·½¿ÉÒÔÍÚµ½½ğÊôÒ®!!\n"+NOR,
    }) );
    set("inquiry",([
    "½ğÊô":(: ask_metal :),
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
