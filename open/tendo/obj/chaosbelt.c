// chaos-belt by Airke 
// QC by Anmy (98/2/25)

#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name( YEL"混沌腰带"NOR  ,({"chaos belt","belt"}));
	set("long","绣工精细的土黄色腰带，上面泛着日月形状的萤光。\n");
	set_weight(600);
        set("armor_type","waist");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("value",6000);
                set("material","cloth");
		set("armor_prop/armor",7);
                set("armor_prop/spells",5);
	set("armor_prop/force",8);
        }
        setup();
}
