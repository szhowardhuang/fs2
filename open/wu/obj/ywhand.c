inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m@[1;31m¡õ[1;33m¡õ[0m",({"gold hands","hands"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIW"ÕâÊÇÒ»¼şÓÉ´«ËµÖĞĞşÌìÓñ¼ÓÉÏ½ğïÎÏßËù±à³ÉµÄÊÖÌ×¡£\n"NOR);
        set("wear_msg", "$N½«$n´÷ÉÏ£¬"HIY"½ğïÎÊÖÌ×"NOR"µÄÁ¦Á¿´ÓÊÖÉÏÒ«ÑÛ¹âÃ¢¡£\n");
        set("unequip_msg", "$N½«$nÍÑµô£¬"HIY"½ğïÎÊÖÌ×"NOR"µÄÁ¦Á¿´ÓÊÖÉÏÊÅÈ¥¡£\n");
        set("unit", "Ë«");
        set("value",90000);
        set("material","cloth");
        set("armor_type", "hands");
        set("armor_prop/armor",15);
        set("armor_prop/unarme",2);
        set("armor_prop/attack",10);
        }
        setup();
}
