#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("[1;33m□[1;37m□[1;33m□[1;37m□[1;33m□[1;37mP[1;33m□[1;37my[0m",({"purple legging","legging"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","这是一件由天上诸神采集先天灵气所炼造而成的仙巾。\n");
   set("unequip_msg", "$N将$n脱掉,$N身上的$n所散发的灵气随之逝去。\n");
   set("wear_msg", "$N将$n穿上，$N身上的$n散发的灵气将$N包围。\n");
        set("unit","件");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
        set("armor_prop/armor",6);
        set("armor_prop/dodge",2);
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
