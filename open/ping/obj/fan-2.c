// made by ccat
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("精钢铁扇",({"steal fan","fan"}) );
        set_weight(25000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long",".\n");
        set("unit","件");
        set("value", 500);
	set("material","iron");
	}
        init_stabber(20);
        set("wield_msg", "$N从怀中掏出一把铁扇.\n");
        set("unwield_msg", "$N将手中的铁扇放入怀中.\n");
        setup();
}
