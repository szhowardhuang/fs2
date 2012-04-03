#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("ÁÒ»ðîø" ,({"fire_cloth","cloth"}));
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
		set("value",19000);
                set("long","ÄË¾­ÁÒ»ð¶ÍÁ·³öÖ®îø¼×¡£\n");
                set("material","cloth");
// Swy QC 98/3/16
		set("armor_prop/armor",13);
                set("armor_prop/dodge",3);
                set("armor_prop/parry", 2);
                set("armor_prop/move", 2);
                set("armor_prop/literate", 5);
        }
        setup();
}
