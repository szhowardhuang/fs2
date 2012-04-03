inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
set_name("[1;37m¡õ[0;37mg[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37mu[0m" , ({"wind boots","boots"}));
         set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "Ë«");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
          set("armor_prop/armor",6);
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñÊ¹ÓÃ·çÑÒÊ¯Ëù´òÔìµÄÕ½Ñ¥¡£\n");
   set("wear_msg", "$N½«$n´©ÉÏ£¬"HIW"¿ñ·çÕ½Ñ¥"NOR"µÄ·¢³öµÄ¹âÃ¢×¢Èë$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIW"¿ñ·çÕ½Ñ¥"NOR"µÄ¹âÃ¢Á¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/stabber",2);
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
