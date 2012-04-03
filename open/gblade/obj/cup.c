// waterskin.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"Ê®½õ·©ÀÅ±­" NOR, ({"ten-cup","cup"}));
	set_weight(50);
	set("unit", "¸ö");
	set("value", 2000);
	setup();
}