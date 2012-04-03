// vagabond.c by oda

#include </open/open.h>

inherit NPC;

void create()
{
	set_name("ÊÐ¾®ÎÞÀµ", ({ "vagabond" }) );
	set("gender", "ÄÐÐÔ");
	set("age", 20);
	set("attitude", "badman");
	set("long", "ËûÈ«ÉíÔàÙâÙâµÄ£¬»¹ÊÇ±ðÌ«¿¿½ü±È½ÏºÃ¡£\n");
	set("combat_exp", 500);
	set_skill("dodge", 10);

	set("chat_chance", 4);
	set("chat_msg", ({
	}));

	setup();
	//carry_object(BAD_OBJ"short_sword")->wield();
}

void greeting(object who)
{
	object ob = this_object();

        if( !who || environment(who)!=environment() ) return;

	tell_object(who, "ÊÐ¾®ÎÞÀµµøµø×²×²µÄÏòÄã×ßÀ´£¬ÏñÊÇÃ»³¤ÑÛ¾¦ËÆµÄ×²ÁËÄãÒ»ÏÂ¡£\n");
	tell_room(environment(ob),"ÊÐ¾®ÎÞÀµÒ»²»Ð¡ÐÄÔÚ$NµÄÉíÉÏ×²ÁËÒ»ÏÂ¡£\n",who);
	command("say ¶Ô²»Æð£¬¶Ô²»Æð£¡"+RANK_D->query_respect(who)+"ÇëÄúÔ­ÁÂ¡£");
	if( random(5)>2 ) {
		if( who->can_afford(1000) ) {
			who->pay_money(1000);
			message_vision("ÊÐ¾®ÎÞÀµ»Å»ÅÕÅÕÅµÄ¶ãµ½Ò»ÅÔÈ¥¡£\n", who);
			ob->pay_player(1000);
		}
	}
    if (who->query("quests/steal",1))
    {
   if (!present("lucky-neck",who))
     {
      new("/data/autoload/badman/ste.c")->move(who);
      message_vision("[1;36m°¥Ñ½£¬ÄãÊÇ"+who->query("name")+"°É£¿
ÓÐ¸öÉÙÄêËµÄãµôÁËÕâÁ¶Ìõ£¬½ÐÎÒÄÃ¸øÄã£¡[0m\n",who);
     }
    }
    if (who->query("marks/kardie",1))
    {
     message_vision("[1;36m°¥Ñ½£¬ÄãÊÇ"+who->query("name")+"°É£¿
ÓÐ¸öÉÙÄêËµÄãµôÁË¶«Î÷£¬ÒªÎÒ°ÑÕâÁ¶Ìõ»¹¸øÄã£¡[0m\n",who);
     new("/data/autoload/badman/ste.c")->move(who);
     who->delete("marks/kardie");
    }
    if (who->query("kar")==30 && who->query("quests/steal",1))
    {
    if (who->query("marks/fish",1))
    {
    }
   else {
     message_vision("[1;36m°¦Ñ½!ÄãÊÇ"+who->query("name")+"°É?
ÓÐ¸öÉÙÄê½ÐÎÒ°ÑÕâ¶«Î÷¸øÄã.[0m\n",who);
     new("/data/autoload/badman/ste.c")->move(who);
     who->set("marks/fish",1);
    }
    }
}
