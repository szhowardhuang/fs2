// golden_sword.c

#include <weapon.h>

	inherit UNARMED;

void create()
{
	set_name("∆ﬂœ“«Ÿ", ({ "king chin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set ("material", "gold");
	}
	init_unarmed(60);
	setup();
}
