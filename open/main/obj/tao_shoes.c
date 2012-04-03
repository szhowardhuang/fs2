// ph_hat.c
#include <armor.h>

inherit EQUIP;

void create()
{
	set_name("ÂéÐ¬",({"linen shoes","shoes"}) );
	set_weight(700);
	set("armor_type","boots");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("value",600);
		set("material","linen");
		set("armor_prop/armor",3);
                set("armor_prop/dodge",1);
        }
        setup();
}
