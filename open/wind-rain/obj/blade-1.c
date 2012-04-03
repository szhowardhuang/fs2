// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name("´óµ¶",({"blade"}));
        set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value",100);
		set("material", "steel");
	}
	init_blade(45);
	setup();
}
