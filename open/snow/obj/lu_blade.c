// short_sword.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIC "Õ¶ÔÂµ¶" NOR,({"moon blade","blade"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value",10000);
		set("material", "iron");
	}
	init_blade(75,SECONDARY);
	setup();
}
