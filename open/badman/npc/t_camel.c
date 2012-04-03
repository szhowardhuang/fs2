#include </open/open.h>
#include <ansi.h>

inherit NPC;
void create()
{
  set_name("[1;33mÂæÍÕ[0m", ({ "desert camel","desert","camel"}));
  set("title", "[33m³¾É³[0m");
  set("gender", "Ò°ÊŞ");
  set("long","Ò»Ö»µ¥·åÂæÍÕ£¬ÍÁ»ÆÉ«µÄÆ¤·ô£¬´ôÖÍµÄÑÛÉñ£¬Õ§¿´Ö®ÏÂ²¢²»Ïñ
Ê²Ã´ÁË²»ÆğµÄÕäÊŞ¡£µ«×ĞÏ¸Ò»¿´£¬ÑÛÉñÖĞÎ¢Î¢Í¸³öÒ«ÑÛ¹â²Ê£¬»ÆÉ³
»º»ºµØ´ÓÕıÔÚ¾×½À²İÁÏµÄ×ì°ÍÖĞÁ÷³ö¡£¿´Ñù×ÓÕâ¼Ò»ï²¢²»ºÃÈÇ£¡
");
  set("combat_exp",1000000);
  set("max_kee",3000);
  set("max_gin",1870);
  set("max_sen",2150);
  set("max_force",3500);
  set("force",3500);
  set("force_factor",60);
  
setup();
}

void die()
{
  object killer;
  killer=query_temp("last_damage_from");
  killer->set_temp("marks/k_camel",1);
  message_vision("[1;31m$N´òµÃĞËÆğ£¬³¾É³ÂæºöÈ»¿ÚÍÂÏÊÑª£¬ËÄ½Å³¯Ìì£¬ËÀÁË£¡[0m\n",killer);
  ::die();
}

void unconcious()
{
  object killer;
  killer=query_temp("last_damage_from");
  killer->set_temp("marks/f_camel",1);
  message_vision("[1;36m$N³É¹¦µØÑ±·şÁËÂæÍÕ£¡[0m\n",killer);
  ::unconcious();
}
