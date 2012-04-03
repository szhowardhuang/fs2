#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name("[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33mY[1;31m¡õ[1;33ma[0m", ({"gold helmet", "helmet"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"ÕâÊÇÒ»¼şÓÉ´«ËµÖĞĞşÌìÓñ¼ÓÉÏ½ğïÎÏßËù±à³ÉµÄÍ·´ø¡£\n"NOR);
   set("wear_msg", "$N½«$n´øÉÏ£¬"HIY"½ğïÎÍ·´ø"NOR"µÄÁ¦Á¿Ê¹ÄãĞÄÁéÍ¨Ã÷¡£\n");
   set("unequip_msg", "$N½«$nÄÃÏÂ£¬"HIY"½ğïÎÍ·´ø"NOR"µÄĞÄÖĞ»¤³ÖµÄÁ¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/armor",15);
   set("armor_prop/force",2);
        set("unit", "¶¥");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
