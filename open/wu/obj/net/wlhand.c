inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
set_name("[1;37m¡õ[0;37mg[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[0m",({"wind hands","hands"}));
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "Ë«");
        set("value",90000);
        set("material","cloth");
        set("armor_type", "hands");
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñÊ¹ÓÃ·çÑÒÊ¯Ëù´òÔìµÄ»¤ÊÖ¡£\n");
   set("wear_msg", "$N½«$nÔØÉÏ£¬"HIW"¿ñ·çÕ½ÊÖ"NOR"µÄ·¢³öµÄ¹âÃ¢×¢Èë$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIW"¿ñ·çÕ½ÊÖ"NOR"µÄ¹âÃ¢Á¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/armor",9);
   set("armor_prop/stabber",3);
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
