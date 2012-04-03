// yensword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("穿肠剑", ({ "yen sword", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 3600);
		set("material", "steel");
		set("long",
			"这就是江湖人称「穿肠剑”司马烟所使用的剑，死在这把剑下的人多的不计其数。\n");
	}
	init_sword(60);
	setup();
}
