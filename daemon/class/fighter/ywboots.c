inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("[1;31m□[1;33m□[1;31m□[1;33m□[1;31m□[1;33m□[1;31m□[1;33mu[0m",({"gold boots","boots"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"这是一件由传说中玄天玉加上金镂线所编成的靴子。\n"NOR);
   set("wear_msg", "$N将$n穿上，"HIY"金镂玉靴"NOR"神的力量使$N脚上发出强大的光芒。\n");
   set("unequip_msg", "$N将$n脱掉，"HIY"金镂玉靴"NOR"的力量随之逝去。\n");
        set("unit", "双");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
          set("armor_prop/armor",6);
        set("armor_prop/move",3);
        set("armor_prop/dodge", 3);
        }
        setup();
}
