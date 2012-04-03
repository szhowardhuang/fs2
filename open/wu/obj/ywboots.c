inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33mu[0m",({"gold boots","boots"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"ÕâÊÇÒ»¼şÓÉ´«ËµÖĞĞşÌìÓñ¼ÓÉÏ½ğïÎÏßËù±à³ÉµÄÑ¥×Ó¡£\n"NOR);
   set("wear_msg", "$N½«$n´©ÉÏ£¬"HIY"½ğïÎÓñÑ¥"NOR"ÉñµÄÁ¦Á¿Ê¹$N½ÅÉÏ·¢³öÇ¿´óµÄ¹âÃ¢¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIY"½ğïÎÓñÑ¥"NOR"µÄÁ¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
        set("unit", "Ë«");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
        set("armor_prop/armor",15);
        set("armor_prop/move",3);
        set("armor_prop/dodge", 3);
        }
        setup();
}
