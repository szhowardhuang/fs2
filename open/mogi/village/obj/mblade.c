#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name("妖火刀",({"daemon blade","blade"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",50000);
                set("material", "steel");
                set("wield_msg", "$N从腰间抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(40);
        setup();
}  
                        
