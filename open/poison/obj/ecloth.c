#include <ansi.h>
inherit EQUIP;
void create()
{
	set_name("乌蚕丝衣", ({"black cloth", "cloth"}) );
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "件");
		set("long","
冥蛊教取其乌蚕所吐之丝而织成的丝衣，质轻，但却异常坚韧。\n");
 
		set("value", 1000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 10);
            }
          setup();
}   







