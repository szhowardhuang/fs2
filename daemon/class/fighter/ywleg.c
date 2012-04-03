#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
        set_name("[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[0m",({"gold legging","legging"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"ÕâÊÇÒ»¼şÓÉ´«ËµÖĞĞşÌìÓñ¼ÓÉÏ½ğïÎÏßËù±à³ÉµÄ»¤Ï¥¡£\n"NOR);
   set("wear_msg", "$N½«$n´©ÉÏ£¬"HIY"½ğïÎÕ½Ï¥"NOR"µÄÉñÆæÁ¦Á¿Ê¹$N¸Ğ¾õ¼´½«·ÉÏè¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIY"½ğïÎÕ½Ï¥"NOR"µÄÉñÆæÁ¦Á¿´Ó$NÉÏÊÅÈ¥¡£\n");
        set("unit","¼ş");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
      set("armor_prop/armor",6);
        set("armor_prop/move",3);
        }
        setup();
}
