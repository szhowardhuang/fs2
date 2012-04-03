// ph_hat.c
#include <armor.h>

inherit EQUIP;

void create()
{
	set_name("µÀ¹Ú",({"taoist hat","hat"}) );
	set_weight(1000);
	set("armor_type","head");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("value",400);
		set("material","steel");
		set("armor_prop/armor",5);
        }
        setup();
}
