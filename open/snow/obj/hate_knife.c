// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
	set_name(HIR "Ç§¹ÅºÞ" NOR,({"hate knife","knife"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("base_unit","°Ñ");
		set("base_value",1000);
		set("value",10000);
		set("material", "steel");
	}
	init_throwing(80);
	set_amount(1);
	setup();
}
