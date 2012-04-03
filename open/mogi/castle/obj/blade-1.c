
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	seteuid(getuid());
	set_name("ÁúÂŞµ¶",({"long-lo-blade","blade"}));
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long","´ËÄËÄ§ÓòÖ®µ¶--ÁúÂŞµ¶\n");
		set("value",50000);
		set("material", "steel");
	}
	init_blade(60);

	setup();
}
