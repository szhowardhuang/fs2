// cloth.c
#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name( HIW"踏云靴"NOR  ,({"cloud boot","boot"}));
	set("long","一双带着仙气的银白色布靴，。\n");
	set_weight(2000);
        set("armor_type","boots");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("value",50000);
                set("material","cloth");
		set("armor_prop/armor",4);
		set("armor_prop/magic",5);
        set("gender_only","男性");
        }
        setup();
}
