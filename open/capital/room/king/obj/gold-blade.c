#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("锻金刀", ({ "gold blade","blade" }));
        set_weight(9500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把由纯金锻铸而成的刀，刀口纤薄而刀背厚实，刀柄一端系着一束金丝
带，通体金黄耀眼，夺目欲炫。
\n");
		set("value", 5000);
                set("material", "gold");
                set("wield_msg", "金光一闪，$N从刀鞘中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背后的刀鞘里。\n");
        }
        init_blade(40);

	set("ski_type1", "blade");
	set("ski_type2", "gold-blade");
	set("ski_level1", 40);
	set("ski_level2", 30);
        setup();
}

