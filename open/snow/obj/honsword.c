// short_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
           set_name("青虹剑",({"hon sword","sword"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
          set("value",30000);
		set("material", "iron");
		set("long",
         "这是当年曹操赐给夏侯恩的一把宝剑。\n");
	}
           init_sword(75, SECONDARY);
	setup();
}
