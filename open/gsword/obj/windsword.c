// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("旋风之剑",({ "windsword","sword" }) );
        set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","这就是大将军 左正心爱的宝剑,将军常带着它去东征北讨.\n");
                set("value", 1000);
		set("material", "steel");
	}
        init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg","只见一股阴风袭来,在$N手中聚成一把利剑.\n");
        set("unwield_msg","$N手中一放,旋风剑化做清风消逝.\n");

// The setup() is required.

	setup();
}
