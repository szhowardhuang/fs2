// ph_hat.c
#include <armor.h>

inherit EQUIP;
			
void create()
{
        set_name("°×ôá¾üÑ¥",({"soldier boots","boots"}) );
	set_weight(700);
	set("armor_type","boots");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
		set("value",600);
		set("material","fur");
		set("armor_prop/armor",3);
		set("armor_prop/dodge",5);
        }
        setup();
}
