//Ğ¡Ê¦ÃÃ
#include <command.h>
 
inherit NPC;
string ask_where()
{
    object who=this_player();
    if(who->query_temp("go_kill",1) )
    {
    who->delete_temp("go_kill");
    who->set_temp("will_kill",1);
    return("ËıÏÖÔÚÒş²ØÉí·İ¶ãÔÚÊ¥»ğ½ÌÖ®ÄÚ..²»¹ıÊÇÔÚÄÇÒ»¸öÖ§ÃÅÎÒ¾Í²»±ãËµÃ÷ÁË...\n
    ËıÉíÉÏºÜÏ²»¶´ø×ÅÒ»Ö§Óñç‡!!\n");
    }
}

void create()
{
    set_name("Ğ¡Ê¦ÃÃ",({"sister"}));
    set("title", "ÇØÒäÊ«µÄ");
    set("gender", "Å®ĞÔ");
    set("age",23);
    set("attitude","friendly");
    set("long",@LONG

        ËıÊÇÓñÅ®½£ÅÉµÄµÜ×Ó, µ±³õÒòÎªÆäÊ¦½ãÂ½ç²Ü½µÄÃÜÄ±¶áÊéÖ®ÊÂ, 
        ÓëÁíÒ»Î»Ê¦½ãÇØÒäÊ«Ô¶±¼Î÷Óò¶ã±Ü.........

LONG);
 
    set("combat_exp",122000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",500);
    set("kee",500);
    set("max_force",500);
    set("force_factor", 10);
    set("force",500);
    set("limbs",({"Í·","ÊÖ","½Å","±³","¸¹","Ñü"}));
    set_skill("dodge",40);
    set_skill("move",40);
    set_skill("parry",40);
    set_skill("sword",40);
    set_skill("henma-steps",40);
    set_skill("girlsword",40);
    set_skill("holy-force",40);
    map_skill("move","henma-steps");
    map_skill("force", "fireforce");
    map_skill("sword", "girlsword");
    map_skill("dodge", "henma-steps");
    map_skill("parry", "girlsword");
    set("chat_chance",30);
    set("chat_msg", ({
        "[36mÎäÁÖÍòÎï¡«½ÔÎªÉú¶øÂÖ»Ø¡«!!\n\n"
        "[36m°Ù¼Ò±øÆ÷¡«¶À±¾½£µÃ¾«Ëè¡«[0m!!\n\n",
    }) );
    set("inquiry",([
    "ÓñÅ®ÅÉ":"ÓñÅ®ÅÉÊÇÖĞÔ­µÄÒ»¸öĞ¡ÃÅÅÉ, ¿ÉÊÇ½£·¨ÄËÊÇ¸ßÈËËù´´!!\n",
    "½£Æ×":"½£Æ×ÎÒ²»ÖªµÀ²ØÔÚÄÇÀï!!²»¹ıÕÆÃÅÅå½£[31m[ºìÔ½£][0mÎÒÖªµÀÊÇ·ÅÔÚÊ¦½ãµÄ·¿¼äÀïà¸!!\n",
    "Â½ç²Ü½":"ºß!!ÄÇ¸öÒõÏÕµÄĞ¡ÈË, º¦ÎÒÃÇÓĞÃÅ»Ø²»µÃ!!ÎÒÖªµÀËıÏÖÔÚÒ²[32m¶ãÆğÀ´[0mÁË..\n",
    "¶ãÆğÀ´":(: ask_where :),
 ]));
    setup();
}


