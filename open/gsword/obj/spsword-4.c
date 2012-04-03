// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
	set_name("[1;32m□[1;33mH[1;32m□[1;33m□[1;32m□[1;33mC[0m",({"han_thon_sword","sword"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",20000);
		set("material", "steel");
                set("wield_msg", "拿着$n,$N脸上诡异的笑了笑\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(110);
	setup();
}
