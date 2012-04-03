// golden_sword.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("¾ÞÁé¸«", ({ "huge axe" }) );
	set_weight (200000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("material", "gold");
	}
	init_axe(98);
	setup();
}
