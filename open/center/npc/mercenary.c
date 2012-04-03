// rewriten from bully.c
// mercenary.c by powell

inherit NPC;
int do_say();
void create()
{
        set_name("ïÚÊ¦", ({ "Mercenary","mercenary" }) );
        set("race", "ÈËÀà");
        set("gender", "ÄĞĞÔ");
        set("age", 25);
        set("long","ÎäÍşïÚ¾ÖµÄïÚÊ¦,Èô·ÇÓĞÒ»µã±¾ÊÂ,ÆÕÍ¨ÈËÔÚÕâÊÇÌÖ²»µ½·¹³ÔµÄ.\n"+
        "ËûÕıÎªÁËÔö½ø×Ô¼º±¾ÉíÎäÑ§¶øĞÁÇÚµÄÓë±ğÈË¶ÔÕĞ.\n");
        set("cps", 5);
        set("str", 28);
        set("cor", 20);
        set("kar",10);
        set("spi", 1);

        set( "inquiry", ([
             "here" : "Õâ¶ùÊÇÎäÍşïÚ¾ÖµÄ×ÜĞĞ,ÈôÃ»Ê²Ã´ÊÂ¾Í²»ÒªÔÚ´Ë¶ºÁô."
             ]));               
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: this_object(),"do_say" :),
        "ïÚÊ¦ËµµÀ : Õâ¼Ò»ï½»¸øÎÒ¾ÍºÃÁË, ÄãÃÇ¶¼±ğ²åÊÖ¡£\n",
         }) );
                
        set_temp("apply/attack", 1);
           set_skill("unarmed",40);
        set("combat_exp",280);
        setup();
        add_money("silver",3);
}

int do_say()
{
        object me=this_player();
        tell_room(environment(this_object()),
        "ïÚÊ¦ºÈµÀ£º¿É¶ñ!! "+RANK_D->query_rude(me)+"ÄãÊÇ»îµÄ²»ÄÍ·³ÁËÂğ? ¾¹¸ÒÀ´ÎäÍşïÚ¾ÖÀ´ÈöÒ°¡£\n");
}
        
void defeated_enemy(object ob)
{
        say("[36mïÚÊ¦ÀäĞ¦Ò»ÉùµÀ : Ã»±¾ÊÂÒ²¸Òµ½ÕâÀ´ÈöÒ°¡£[0m\n");
        remove_killer(ob);
}        
