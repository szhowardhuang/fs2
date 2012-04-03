#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("[1;37m¡õ[0;37mg[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[0m",({"wind neck","neck"}));
   set_weight(5000);
   if ( clonep() )
       set_default_object(__FILE__);
   else {
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñÊ¹ÓÃ·çÑÒÊ¯Ëù´òÔìµÄÏîÁ¶¡£\n");
   set("wear_msg", "$N½«$nÔØÉÏ£¬"HIW"¿ñ·çÕ½Á¶"NOR"µÄ·¢³öµÄ¹âÃ¢×¢Èë$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIW"¿ñ·çÕ½Á¶"NOR"µÄ¹âÃ¢Á¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/armor",7);
   set("armor_prop/stabber",3);
   set("unit", "Ìõ");
   set("armor_type", "neck");
   set("value", 30000);
   set("no_sell",1);
   set("no_auc",1);
   set("no_drop",1);
     }
   setup();
}
int query_autoload()
{
 return 1;
}
