//天子 eq
inherit EQUIP;
#include <ansi.h>
void create()
{
        set_name(HIG"宝莲靴"NOR, ({ "king boots" ,"boots" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","王母赐给天子的宝靴，由天池中的莲花编织而成。\n");
                set("unit", "双");
                set("value", 80000);
                set("material","leather");
                set("material", "boots");
                set("armor_type", "boots");
                set("armor_prop/armor",6);
                set("armor_prop/dodge",6);
                set("armor_prop/move",6);
                setup();

        }
}
