// blade.c
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ÆÆµ¶",({"poor blade","blade"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
     set ("unit","±ú");
          set("value", 10000);
		set("material", "iron");
	}
          set("armor_prop/blade",10);
	init_blade(10);
	setup();
}
