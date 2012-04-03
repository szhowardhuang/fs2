#include </open/open.h>
#include <ansi.h>

inherit NPC;

string do_want();
string do_ask();
void create()
{
  set_name("É³ÀÏ",({ "desert elder","desert","elder"}));
  set("title","ÈûÍâÄ®Ãñ");
  set("gender", "ÄÐÐÔ");
  set("age",65);
  set("attitude", "peaceful");
  set("no_kill",1);
  set("no_fight",1);
  set("long","Ò»¸öÔÚÑ×ÈÈµÄÉ³Ä®ÖÐ¶À×ÔÉú»îµÄÀÏÍ·¡£ËûÕýÔÚÈ÷É¨¶Ñ»ý
ÔÚÕÊÅñÇ°µÄ´µÉ³¡£´ÓËûµÄ·ôÉ«¼°Îå¹Ù·Ö²¼À´¿´£¬Ó¦¸ÃÊÇ
À´×ÔÈû±±´óÄ®µÄ×¡Ãñ¡£\n");
  set("chat_chance",6);
  set("chat_msg", ({
  "°¦£¬ÓÖ´µÁËÕâÃ´¶àÉ³×Ó£¬ÕæÊÇ¸ÃËÀµÄÂæÍÕ£¡\n",
  }) );
  set("inquiry",([
  "ÂæÍÕ" : (: do_ask :),
  ]));

setup();
}

string do_ask()
{
  int me;
  object who;
  who = this_player();
  if (who->query("quests/r_camel",1)) {
  return "[1;37mÕæ¸ÐÐ»Äã°ïÎÒÑ±ÁËÂæÍÕ£¡[0m\n"; 
  }
  else if (who->query("quests/w_camel",1)) {
  return "[1;33mÄãÒª¸úÎÒÒª£¨want£©ÂæÍÕÂð£¿[0m\n";
  }
  else if (who->query_temp("marks/f_c",1)) {
  return "[1;33mÎÒ²»ÊÇ¸úÄã½²¹ýÁËÂð£¿[0m\n";
  }
  else {
  who->set_temp("marks/f_c",1);
  who->set_temp("marks/f_c_ent",1);
  return "[1;33mÊ²Ã´ÂæÍÕ£¿°¦£¬ÕâËµÀ´»°³¤°¡
£¡ÀÏÐàÔÝ²»½«Ô­ÓÉ¸æËßÄã£¬ÔÚÀÏÐàÉíºóÕÊ
ÅñµÄÄ¾°å´²ÖÐ£¬ÄãÈ¥½«Ä¾°åÏÆ¿ª¡£ÀïÍ·ÓÐ
Ìõ°µµÀ£¬°µµÀ¾¡Í·´¦ÀÏÐàÑø×ÅÒ»Æ¥ÂæÍÕ¡£
ÕâÂæÍÕ¿ÉÀ÷º¦ÁË£¡±ðµÄÂæ»áÍÂÍÂ¿ÚË®¾Í°Õ
ÁË£¬ÎÒÕâÂæÓÖ½Ð³¾É³Âæ£¬¿ÉÊÇ´ÓÎ÷·½´«À´
µÄÕäÆæÖÁ±¦£¡ ­É¶²»»á£¬¾Í´µÉ³´µµÃ½ô£¡
Å¼¶øÄØ£¬Ò²»áÍÂÍÂÉ°Á££¬É°Á£Ò»¶à£¬¾Í³É
ÁËµÀÇ½¡£ÕâÇ½¿ÉÎ½µ¶Ç¹²»Èë£¬ÄÜµ²Éñ±ø£¡
µ«ÕâÂæ¾ÍÊÇ²»Ìý»°¡£ÉÙÏÀ¿´ÄãÄê¼ÍÉÐ¿É£¬
µ«Á³É«Òì³£ºìÈó£¬Ïë±Ø¹¦·òÊ®·Öµ½¼Ò¡£Ïë
À´ÕâÒ²ÊÇ¸öÔµ·Ý£¬Äú¾Í½øÈ¥ÅîÖÐ£¬ÏÆ¿ª°å
×Ó£¬ÈëÁË°µµÀ£¬¿´ÄÜ·ñÑ±ÁËÕâÆ¥ÂæÍÕ°É£¡[0m\n";
  }
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
  if (ob->query("quests/r_camel",1))
  {
   message_vision("[1;37mÉÙÏÀÕæÊÇ±¾ÊÂ¸ß°¡£¡[0m\n",ob);
  }
  else if (ob->query("quests/w_camel",1))
  {
   message_vision("[1;33mÉÙÏÀÏëÒª£¨want£©ÆïÂæÂð£¿[0m\n",ob);
  }
  else if( ob->query("class")==!"bandit" && ob->query_temp("marks/f_camel",1))
  {
   message_vision("[1;35mÉÙÏÀ±¾Áì¹ûÈ»×ã¹»£¡
ÀÏÐàÃ»É¶Ã´ºÃËÍµÄ£¬ÕâÓÐ¼¸Ê®Á½Òø×Ó£¬ÉÙÏÀ¾ÍÊÕÏÂ°É£¡[0m\n",ob);
   ob->add_money("gold",25);
   ob->set("quests/r_camel",1);
  }
  else if (ob->query("class")=="bandit" && ob->query_temp("marks/f_camel",1))
  {
   message_vision("[1;33mÃ»Ïëµ½ÉÙÏÀ¹ûÕæÑ±ÁËÕâÂæÍÕ£¡
¿´Ñù×ÓÕâÒ²ÊÇ¸öÔµ·Ý£¬ÀÏÐàÕâÓÐ¸ö²»ÖÐÌýµÄ½¨Òé£¬ÍûÇëÉÙÏÀ²ÉÄÉ£¬
ÀÏÐàÕâÂæÈ¡»ØÀ´ÒÑ¹ýÏàµ±Ê±ÈÕ¡£±¾À´ÄØ£¬ÕâÂæÊÇÀÏÐàÒªÆïµÄ£¬ÎÞ
ÄÎÎä¹¦²»¼Ã£¬Ñ±²»µÃÕâÂæ¡£Èç½ñÉÙÏÀ¼ÈµÃÕâÔµ·Ý£¬¾ÍËãºÍÀÏÐà½á
Ê¶Ò»³¡£¬ÉÙÏÀÏëÆïÂæÄØ£¬±ãÀ´¸úÀÏÐà½²Ò»Éù£¨want£©£¬×Ô²»»á¸ú
ÉÙÏÀ×öºÎÎªÄÑµÄ£¡ºÃ°Õ£¿[0m\n",ob);
  ob->set("quests/w_camel",1);
  }
  else if (ob->query_temp("marks/k_camel",1))
  {
   message_vision("[1;31m°¦Ó´£¡ÉÙÏÀ¾ÓÈ»°Ñ ­É±ÁË£¡[0m\n",ob);
   message_vision("[1;31mÄã....ÄãÕâÑù×ÓÎÒ¸ÃÔõÃ´°ì°¡£¿[0m\n",ob);
   this_object()->kill_ob(ob);
  }
}

void die()
 {
  object killer;
  killer=query_temp("last_damage_from");
  message_vision("[1;35m°¡£¬ÉÙÏÀÎä¹¦¹û¡£¡£¡£¹ûÈ»¸ßÇ¿°¡¡£¡£¡£¡£[0m\n",killer);
  killer->delete_temp("marks/k_camel");
  ::die();
 }
