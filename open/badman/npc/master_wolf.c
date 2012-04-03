#include <ansi.h>
inherit NPC;
void create()
{
  set_name("¹^òH",({"wolf master","wolf","master"}));
set("long","Õâ¸öÈË¿´À´Ð×ºÝ²Ð±© ,µ«ÑÛÖÐÈ´Í¸Â¶³öÐ©ÐíºÍ°ªµÄÑÛÉñ¡£
´ÓËû×¢ÊÓÉíÅÔÄÇÖ»°×ÀÇµÄÑÛ¹âÀ´¿´£¬ËûËÆºõ·Ç³£Ï²°®Õâ
Æ¥¾ÙÊÀÎÞË«µÄ°×ÀÇ¡£\n");
  set("nickname","¾ø°ÔÀÇÍõ");
  set("str",40);
  seteuid(getuid());
  set("age",47);
set("bellicosity",1000);
  set("combat_exp",430000);
  set("max_force",1000);
  set("force",1000);
  set("force_factor",10);
  set("max_gin",500);
  set("max_kee",600);
  set("max_sen",250);

  set_skill("badforce",50);
  set_skill("badstrike",75);
  set_skill("ghost-steps",38);
  set_skill("dodge",55);
  set_skill("unarmed",85);
  set_skill("parry",70);
  set_skill("move",30);
  set_skill("force",60);
  map_skill("force","badforce");
  map_skill("unarmed","badstrike");
  map_skill("parry","badstrike");
  map_skill("dodge","ghost-steps");
  map_skill("move","ghost-steps");
  set("functions/evil-blade/level",20);

  set("chat_chance_combat", 35);
  set("chat_msg_combat", ({
  (: perform_action, "unarmed.evil-blade" :),
  }));
  set("inquiry",([
    "¶ÅÉ±µÄ×óÊÖ" : "×óÊÖ...?ÕâÎÒ¿É²»ÏþµÃ ,µ«²»ÖªµÀÎÒÄÇÆ¥°®ÀÇÇ°¼¸Ìì´ÓÉ­ÁÖÖÐ´ø»ØÀ´µÄÊÖÊÇ²»ÊÇ ?É¶...?ÄãÏëÒª ?ÄÇ¿É²»ÐÐ ,ÕâÖ»ÊÖ¿ÉÊÇÎÒÕâÆ¥¾ÙÊÀÎÞË«µÄ°×ÀÇµÄÊ³Îï!!ÏëÒª ,¾Í×Ô¼ºÀ´ÇÀ !\n",
  ]));

  setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player())&& !is_fighting() )
 {
        remove_call_out("greeting");
        call_out("greeting",1 , ob);
 }
}

void greeting(object ob)
{
  if( ob->query("class")=="bandit")
  {
  if( ob->query("marks/ride_wolf",1))
  {
  }
else if( ob->query("quests/badroar",1) && ob->query("combat_exp") > 600000)
   {
    message_vision("[1;32mÄã²»¾ÍÊÇÄÇ¸ö´ò°ÜÎÒµÄÐ¡»ï×ÓÂð£¿\n
ÔõÑù£¬×î½ü»ìµÃ²»´í°É£¿¹ûÕæÓ¢ÐÛ\n
³öÉÙÄê°¡£¡À´°É£¬È¥¸ú¹ÜÀÇµÄÐíÀÏ\n
½²Ò»Éù£¬ÒªÖ»ÀÇÆïÆï°É£¡[0m\n",ob);
    ob->set("marks/ride_wolf",1);
   }
  }
}
int accept_kill(object me)
{
  object ob,wolf;
  ob=this_object();
  wolf=present( "wolf",environment(ob) );
  if( !present( "wolf",environment(ob))||!living(wolf)) return 1;
  else {
  tell_room(environment(me),"¾ÓÈ»¸Ò¶¯ÎÒ!?ÄãËÀ¶¨ÁË !\n"),
  message_vision(RED"\n°×ÀÇ¿´µ½Ö÷ÈË±»Ï® ,ÂíÉÏÏò$NÆËÁË¹ýÈ¥ !\n"NOR,me
  );
  wolf->kill_ob(me);
  return 1;
  }
}
int accept_fight(object me)
{
  object ob,wolf;
  ob=this_object();
  wolf=present( "wolf",environment(ob) );
  if( !present( "wolf",environment(ob))||!living(wolf)) return 1;
  else {
  tell_room(environment(me),"¾ÓÈ»¸Ò¶¯ÎÒ!?ÄãËÀ¶¨ÁË !\n"),
  message_vision(RED"\n°×ÀÇ¿´µ½Ö÷ÈË±»Ï® ,ÂíÉÏÏò$NÆËÁË¹ýÈ¥ !\n"NOR,me
  );
  wolf->kill_ob(me);
  return 1;
  }
}
