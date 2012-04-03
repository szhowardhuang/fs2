//·ÙÌìÄ§Íõ eq
inherit EQUIP;
#include <ansi.h>
void create()
{
set_name("[1;37m¡õ[0;37mg[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37my[1;37m¡õ[0;37ma[0m" , ({"wind belt","belt"}));
         set_weight(300);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("value", 70000);
                set("material","leather");
                set("armor_type", "waist");
                set("armor_prop/armor",7);
                set("armor_prop/stabber",3);
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñÊ¹ÓÃ·çÑÒÊ¯Ëù´òÔìµÄÑü´ø¡£\n");
   set("wear_msg", "$N½«$nÊøÉÏ£¬"HIW"¿ñ·çÑü´ø"NOR"µÄ·¢³öµÄ¹âÃ¢×¢Èë$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIW"¿ñ·çÑü´ø"NOR"µÄ¹âÃ¢Á¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
                setup();
        }
}

int query_autoload()
{
 return 1;
}
