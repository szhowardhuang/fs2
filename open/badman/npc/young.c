#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
  set_name("ÉÙÄê",({"young"}) );
  set("long","ËûµÄÁ³ÉÏÓÐµÀ´ÓÑÛ½Çµ½×ì½ÇµÄµ¶°Ì£¬\nÂúÍ·ºÚ·¢Ò²Ã»ÊáºÃ£¬Ö»´òÁË¸ö½á¡£\n");
  set("race", "ÈËÀà");
  set("gender","ÄÐÐÔ");
  set("combat_exp",12345678);
  set("age",18);
  set("no_kill",1);
  set("kee",987654);
  set("max_kee",987654);
  set("force",77777);
  set("max_force",77777);
  set("force_factor",999);
  set_skill("unarmed",150);
  set_skill("badstrike",150);
  map_skill("unarmed","badstrike");
  
  setup();
}
void init()
{
    object ob;
    ::init();
  if( interactive(ob = this_player())&& !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting",1 , ob);   }
}
void greeting(object ob)
{
  if (ob->query("quests/karup",1))
  {
   message_vision("[1;37màÅ£¿ÔõÃ´»¹²»Àë¿ªÀÕ£¿£¿[0m\n",ob);
  }
  else {
  message_vision("[1;32màÅ£¬Ã»ÊÂ°É£¿»¹ºÃÎÒ¼°Ê±¸Ïµ½£¬²»È»Äã¾ÍÎ£ÏÕÁË¡£
Õâ±ß¿ÉÊÇ¶ñÈË¹ÈµÄ½ûµØ£¬ÒÔºó»¹ÊÇ±ðÂÒ´³µÄºÃ¡£[1;36m
ÕâÊÇÄãÒªÕÒµÄ¶«Î÷Âð£¿Îû£¬¸øÄã°É£¬ÒÔºóÒªÐ¡ÐÄµã°¡¡£[1;37m
´ÓÕâ±ßÍùÉÏÅÀ¿ÉÒÔÅÀµ½¹È¶¥£¬±ðÔÙ¶ºÁôÁË£¬Î£ÏÕ°¡£¡[0m\n",ob);
  new("/data/autoload/badman/ste.c")->move(ob);
  ob->set("quests/karup",1);
  ob->set("marks/fish",1);
  }
}
