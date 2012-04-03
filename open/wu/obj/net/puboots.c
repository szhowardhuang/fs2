inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
set_name("[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mR[1;33m¡õ[1;37mc[0m" , ({"purple boots","boots"}));
         set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "Ë«");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
          set("armor_prop/armor",6);
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñ²É¼¯ÏÈÌìÁéÆøËùÁ¶Ôì¶ø³ÉµÄÎèÑ¥¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô,$NÉíÉÏµÄ$nËùÉ¢·¢µÄÁéÆøËæÖ®ÊÅÈ¥¡£\n");
   set("wear_msg", "$N½«$n´©ÉÏ£¬$NÉíÉÏµÄ$nÉ¢·¢µÄÁéÆø½«$N°üÎ§¡£\n");
   set("armor_prop/dodge",2);
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
