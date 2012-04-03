// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name("ÅÌ¹Å¿ªÌì",({"open-sky blade","blade"}));
        set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value",60000);
		set("material", "steel");
	}
	init_blade(75);
	setup();
}
