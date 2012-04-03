#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
    set_name("[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33mP[1;31m¡õ[1;33m¡õ[0m", ({"gold neck","neck"}) );
     set_weight(5000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
   set("long",HIW"ÕâÊÇÒ»¼şÓÉ´«ËµÖĞĞşÌìÓñÏâÉÏĞÇ»ÔÊ¯´®ÉÏ½ğïÎÏßµÄÏîÁ¶¡£\n"NOR);
   set("wear_msg", "$N½«$n´÷ÉÏ£¬ÉíÉÏ·¢³ö"HIW"ĞÇ»Ô"NOR"°ãµÄ¹âÃ¢¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬ÉíÉÏµÄ¹âÃ¢ËæÖ®ÊÅÈ¥¡£\n");
      set("armor_prop/armor",7);
   set("armor_prop/dodge",3);
            set("unit", "Ìõ");
            set("armor_type", "neck");
            set("value", 30000);
     }
}

