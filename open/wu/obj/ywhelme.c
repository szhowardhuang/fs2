#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name("[1;31m□[1;33m□[1;31m□[1;33m□[1;31m□[1;33mY[1;31m□[1;33ma[0m", ({"gold helmet", "helmet"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"这是一件由传说中玄天玉加上金镂线所编成的头带。\n"NOR);
   set("wear_msg", "$N将$n带上，"HIY"金镂头带"NOR"的力量使你心灵通明。\n");
   set("unequip_msg", "$N将$n拿下，"HIY"金镂头带"NOR"的心中护持的力量随之逝去。\n");
   set("armor_prop/armor",15);
   set("armor_prop/force",2);
        set("unit", "顶");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
