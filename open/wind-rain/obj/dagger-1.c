
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	seteuid(getuid());
	set_name("Ï¸Ø°Ê×",({"thin-dagger","dagger"}));
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");

		set("value",5000);
		set("material", "steel");
	}
	init_dagger(45);

	setup();
}
