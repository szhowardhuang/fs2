#include <ansi.h>
#include <armor.h>
inherit CAPE;
void create()
{
	set_name("冥蝠披风",({"bat_surcoat","surcoat"}));
	set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
	set("value",7000);
	set("material","leather");
        set("long","将冥蝠之翼的皮取下制成。\n");
// Swy QC 98/3/16
	set("armor_prop/armor",4);
        set("armor_prop/dodge",2);
        set("armor_prop/stabber",3);
        }
        setup();
}
