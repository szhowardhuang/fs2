// ph_hat.c
#include <armor.h>

inherit EQUIP;
			
void create()
{
        set_name("ÊÞÆ¤¾üÑ¥",({"soldier boots","boots"}) );
	set_weight(7000);
	set("armor_type","boots");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
		set("value",600);
		set("material","fur");
		set("armor_prop/armor",3);
		set("armor_prop/dodge",2);
        }
        setup();
}
