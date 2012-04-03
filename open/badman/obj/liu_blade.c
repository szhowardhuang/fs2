// liu_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("柳叶刀", ({ "thin blade", "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 800);
		set("material", "steel");
		set("long", "这是一柄十分细长的刀，平时可以藏在袖中，以发挥出绝佳的奇袭效果。\n");
		set("wield_msg", "$N暗暗的握紧了袖中的$n。\n");
		set("unwield_msg", "$N将手中的$n收回袖中。\n");
	}
	init_blade(40);
	setup();
}
