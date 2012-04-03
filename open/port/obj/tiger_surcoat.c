// ph_hat.c
#include <armor.h>
inherit EQUIP;

void create()
{
	set_name("»¢ÎÆÅû·ç",({"tiger surcoat","surcoat"}));
	set_weight(1000);
	set("armor_type","cape");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
	set("value",10000);
		set("material","leather");
	 set("armor_prop/armor",10);
        }
        setup();
}
