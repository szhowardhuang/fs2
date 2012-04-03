inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀束腰"NOR,({"rose finch's belt","belt"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火红色的一条腰带，于扣环处有朱雀浮雕的铜扣。\n");
		set("unit","条");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N套上$n"HIR"，扣环上的朱雀浮雕变红了。\n"NOR);
		set("unequip_msg",HIR"$N解开了$n"HIR"，红色的朱雀浮雕缓缓消逝了。\n"NOR);
		set("armor_prop/force",2);
		set("armor_prop/armor",-8);
	        set("armor_type","waist");
	}
	setup();
}