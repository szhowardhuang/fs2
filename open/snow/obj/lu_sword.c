// short_sword.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIY "π·»’Ω£" NOR,({"sun sword","sword"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∞—");
		set("value",10000);
		set("material", "iron");
	}
           init_sword(75, SECONDARY);
	setup();
}
