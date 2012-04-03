#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("Ô°¶¡",({"gardener"}));
    set("gender", "ÄÐÐÔ");
    set("age",68);
    set("attitude","peaceful");
    set("long",@LONG

	Ê¥»ð½ÌµÄ½ÌÍ½,!!¸ºÔðËÇÑùÃÅÖ÷Ëù´ø»ØÀ´µÄÆæÒìÒ°ÊÞ.

LONG);
 
    set("combat_exp",2000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("max_kee",310);
    set("kee",310);
    set("limbs",({"Í·","ÊÖ","½Å","±³","¸¹","Ñü"}));
    set_skill("universe",5);
    set_skill("force",20);
    set_skill("superforce",20);
    set_skill("move",20);
    set_skill("shift-steps",20);
    set_skill("unarmed",20);
    set_skill("parry",20);
    set_skill("dodge",20);
    set("chat_chance",30);   
     set("chat_msg", ({
     "[36mÀÏÈËËµ: Õâ¸ö»¨Ô°ÊÇ½ÌÖ÷·Ô¸ÀÎÒÕÕ¹ËµÄ!!ºÜ¿Ö²ÀÂð??²»»áÀ²[0m!!\n",
             "[36mÀÏÈËËµ: ½ÌÖ÷ºÜÏ²»¶µ½ÕâÀïÀ´Á·¹¦à¸[0m!!\n",
             "[36mÀÏÈËËµ: ³£³£»áÌýµ½ÀàËÆÊ¯Í·°á¶¯µÄÉùÒô!!²»ÏþµÃÊÇÎªÊ²Ã´??[0m\n",
        }) );
 
    setup();
    add_money("silver",1);
    carry_object("/open/prayer/obj/communion-cloth")->wear();

}