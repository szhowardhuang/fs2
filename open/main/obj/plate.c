
#include <ansi.h>

inherit EQUIP;

void create()
{
     set_name(HIW"圣灵战甲"NOR,({"Holy Ghost Plate","plate"}) );
     set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
else	{
     set("meterial","steel");
	set("unit","件");
	set("value", 1000);
	set("armor_type","cloth");
	set("armor_prop/armor", 45);
      set("armor_prop/dodge", 8);
      set("armor_prop/parry", 8);
      set("armor_prop/move", 8);
      set("armor_prop/attack", 3);
	set("armor_prop/force", 3);
	set("long","
这套战甲是由波斯王国所制，受过波斯勇者鲜血的灌溉，上下都散发出
一股霸气，据说穿上之人可以横扫战场，所向披靡。\n");
	}
	setup();
}
