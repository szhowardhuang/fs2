// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name("ÈýÐÇµ¶",({"three-star blade","blade"}));
        set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value",20000);
		set("material", "steel");
	}
	init_blade(65);
	setup();
}
