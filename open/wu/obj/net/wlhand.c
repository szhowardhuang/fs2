inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
set_name("[1;37m□[0;37mg[1;37m□[0;37m□[1;37m□[0;37m□[1;37m□[0;37m□[0m",({"wind hands","hands"}));
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "双");
        set("value",90000);
        set("material","cloth");
        set("armor_type", "hands");
   set("long","这是一件由天上诸神使用风岩石所打造的护手。\n");
   set("wear_msg", "$N将$n载上，"HIW"狂风战手"NOR"的发出的光芒注入$N身中。\n");
   set("unequip_msg", "$N将$n脱掉，"HIW"狂风战手"NOR"的光芒力量随之逝去。\n");
   set("armor_prop/armor",9);
   set("armor_prop/stabber",3);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        }
        setup();
}
int query_autoload()
{
 return 1;
}
