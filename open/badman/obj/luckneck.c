#include <ansi.h>
#include <armor.h>
inherit NECK;
inherit F_SAVE;
inherit F_AUTOLOAD;
object user;
void create()
{
  set_name( "ÐÒÔËÁ¶Ìõ",({"lucky neck","lucky","neck"}));
  set_weight(3000);
  if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long","Ò»Ìõ·º×ÅÀ¶¹â£¬¿´À´ÓÐ²»¿ÉË¼ÒéÁ¦Á¿µÄÏîÁ¶¡£\n");
  set("unit", "Ìõ");
  set("material","steal");
  set("value",10000);
  set("no_sell", 1);
  set("no_auc",1);
  set("no_give",1);
  set("no_drop",1);
  set("no_get",1);
  set("armor_prop/armor", 10);
 }
  
  setup();
}

void init()
{
  add_action("do_wear","wear");
  add_action("do_remove","remove");
}

int do_wear(string str)
{

     ::wear();
     if( query("equipped") )
     {
      user = this_player();
      message_vision("[1;36mÒ»µÀÀ¶¹âÁýÕÖ×ÅÄã£¬Äã¸Ðµ½½«ÓÐÐÒÔËµÄÊÂÇé·¢Éú£¡[0m\n",user);
      user->add("kar",5);
      user->add("max_force",-500);
     }
}

int do_remove(string str)
{
   if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
   message_vision("[1;37mÄã³ýµôÁË¾±ÉÏµÄÏîÁ¶£¬ÄÇÖÖÐÒÔËµÄ¸Ð¾õÒÑ²»ÔÙ£¡[0m\n",user);
      user->add("kar",-5);
      user->add("max_force",500);
     }
}
