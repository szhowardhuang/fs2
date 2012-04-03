
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	seteuid(getuid());
	set_name(HIM"·Ò·¼Ø°"NOR,({"fragant-dagger","dagger"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");

		set("value",5000);
		set("material", "steel");
                set("weapon_prop/dagger",10);
	}
	init_dagger(80);

	setup();
}
