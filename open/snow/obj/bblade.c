// blade.c
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ÎÚ¸Öµ¶",({"black blade","blade"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
     set ("unit","±ú");
	set("value", 5000);
		set("material","steel");
	}
          set("armor_prop/blade",10);
	init_blade(30);
	setup();
}
