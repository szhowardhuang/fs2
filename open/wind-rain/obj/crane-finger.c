inherit EQUIP;
#include <ansi.h>
void create()
{
        seteuid(getuid());
        set_name(HIM"千华鹤指饰"NOR , ({ "crane finger","finger" }) );
       	set("long","金风细雨楼主花忆妍带在手指的指套，镶以碎钻，光彩夺目。\n");
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 25000);
                set("material", "cloth");
                set("armor_type", "finger");
		set("armor_prop/armor",6);
                set("armor_prop/parry",2);
              }



}
