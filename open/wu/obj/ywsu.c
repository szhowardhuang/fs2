#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
        set_name("[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[0m",({"gold surcoat","surcoat"}));
        set_weight(10000);
        set("armor_type","cape");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "¼ş");
        set("material","leather");
        set("value",100000);
   set("long",HIW"ÕâÊÇÒ»¼şÓÉ´«ËµÖĞĞşÌìÓñ¼ÓÉÏ½ğïÎÏßËù±à³ÉµÄÅû·ç¡£\n"NOR);
   set("wear_msg", "$N½«$nÅûÉÏ£¬"HIY"½ğïÎÅû·ç"NOR"µÄÉñµÄÁ¦Á¿¹á×¢ÔÚ$NÉíÖĞ£¬Ê¹$NĞÅĞÄ±¶Ôö¡£\n");
   set("unequip_msg", "$N½«$n³ıÈ¥£¬"HIY"½ğïÎÅû·ç"NOR"µÄÁ¦Á¿ËæÖ®ÏûÊÅ¡£\n");
   set("armor_prop/armor",20);
   set("armor_prop/parry",3);
        }
        setup();
}
