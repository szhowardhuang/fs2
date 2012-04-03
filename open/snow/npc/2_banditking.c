#include <ansi.h>

inherit NPC;

void create()
{
        set_name("É½ÔôÍ·Í·", ({ "bandit king", "bandit", "king"}) );
        set("long",
             "[CÉ½ÔôµÄÍ·Í·,ÔÚÏÂÉ½ÇÀ½ÙÐÐ¶¯ÖÐÊ§°ÜÁË,»ØÉ½Õ¯µÄÊ±ºò,ÎÞÒâ¼ä×ßµ½´Ë´¦È´ÃÔÂ·ÁË,ËäÈ»ÅÉÈËÈ¥ÕÒ³öÂ·,¿ÉÊÇÄÚÐÄµÄ½ôÕÅ»¹ÊÇÍêÈ«µÄ±íÂ¶ÔÚÁ³ÉÏ¡£\n");
        set("attitude", "heroism");

	set("combat_exp", 12975);
        set("chat_chance",6);
	set_skill("sword",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	set("random_move",4);
       set("chat_msg",({
          (:this_object(),"random_move":),
}));
        setup();
	carry_object("/obj/longsword")->wield();
}
