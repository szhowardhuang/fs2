// ph_hat.c
#include <armor.h>

inherit EQUIP;

void create()
{
        set_name("ÊÞÆ¤¾üÃ±",({"soldier hat","hat"}) );
	set_weight(1000);
	set("armor_type","head");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("value",400);
		set("material","fur");
		set("armor_prop/armor",3);
        }
        setup();
}
