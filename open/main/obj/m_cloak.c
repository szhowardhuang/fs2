// ph_hat.c
#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
    set_name(HIB"ÑÖ"+HIY"ÔÂ"+HIW"Åû·ç"NOR,({"Dark Moon Cloak","cloak"}));
	set_weight(1000);
	set("armor_type","cape");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
	set("value",10000);
		set("material","leather");
	 set("armor_prop/armor",10);
         set("armor_prop/force",5);
         set("armor_prop/move",5);
        }
        setup();
}
