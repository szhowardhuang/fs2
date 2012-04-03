// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
	set_name("¥Ú—®÷È",({"throw pearl","pearl"}));
        set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∞—");
		set("base_unit","ø≈");
		set("value",10);
		set("material", "steel");
	}
	init_throwing(45);
	set_amount(1);
	setup();
}
