#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
set_name("[1;37m□[0;37mg[1;37m□[0;37m□[1;37m□[0;37m□[1;37m□[0;37ma[0m" , ({"wind helme","helme"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","这是一件由天上诸神使用风岩石所打造的战带。\n");
   set("wear_msg", "$N将$n套上，"HIW"狂风战带"NOR"的发出的光芒注入$N身中。\n");
   set("unequip_msg", "$N将$n脱掉，"HIW"狂风战带"NOR"的光芒力量随之逝去。\n");
   set("armor_prop/stabber",3);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
      set("armor_prop/armor",7);
        set("unit", "顶");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
int query_autoload()
{
 return 1;
}
