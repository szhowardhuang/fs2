#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
    set_name("[1;31m□[1;33m□[1;31m□[1;33m□[1;31m□[1;33mP[1;31m□[1;33m□[0m", ({"gold neck","neck"}) );
     set_weight(5000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
   set("long",HIW"这是一件由传说中玄天玉镶上星辉石串上金镂线的项炼。\n"NOR);
   set("wear_msg", "$N将$n戴上，身上发出"HIW"星辉"NOR"般的光芒。\n");
   set("unequip_msg", "$N将$n脱掉，身上的光芒随之逝去。\n");
   set("armor_prop/armor",10);
   set("armor_prop/dodge",3);
            set("unit", "条");
            set("armor_type", "neck");
            set("value", 30000);
     }
}

