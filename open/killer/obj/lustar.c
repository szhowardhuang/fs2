#include <weapon.h>
#include <ansi.h>
inherit THROWING;
object me;

void create()
{
     set_name("[33;1mÁ÷ĞÇ×¶[0m",({"lu star","star"}));
     set_weight(10);
     if( clonep() )
         set_default_object(__FILE__);
     else {
       set("unit","Ö§");
       set("base_unit","Ö§");
       set("long","ÕâÊÇÉ±ÊÖ²ÅÄÜÄÃµÄ°µÆ÷");
       set("value",1000);
       set("material", "silver");
       set("wield_msg","$NÄÃÆğ[1;31m$n[0m,¸Ğ¾õÆğÀ´ºÜ²»´í¡£\n");
       set("unwield_msg", "$N½«$n·ÅÁËÏÂÀ´\n");
     }
      init_throwing(60);
      set_amount(1);
      setup();
}
int wield()
{
  if(!this_player()) return 0;
 if(this_player()->query_skill_mapped("throwing")!="rain-throwing")
    return notify_fail("ÕâÊÇÉ±ÊÖ×¨ÓÃµÄ¶«Î÷\n");
      else{
      ::wield();
            }
        return 1;
}
