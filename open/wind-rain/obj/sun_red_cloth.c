#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        seteuid(getuid());
        set_name(HIR"夕霞红纱"NOR , ({ "sun_red_cloth","cloth" }) );
        set("long","一件华美的红色衣裳，上面似乎残留着夕霞之余晖。\n");
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 80000);
                set("material", "cloth");
                set("type", 1); 
                set("armor_prop/armor",25);
                set("armor_prop/force",10);
                set("armor_prop/attack",5);
                set("armor_prop/magic",3);
                set("armor_prop/spells",3);
                set("wear_msg", HIR"$N穿起了$n"HIR"一身的华丽尽在不言中，足以比美夕阳的残晖。\n"NOR);
                set("unequip_msg", HIR"$N轻轻的卸下$n"HIR"，夕阳的残晖也随即消失。\n"NOR);
              }
        setup();
}
