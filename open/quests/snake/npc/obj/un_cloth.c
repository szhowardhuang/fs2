#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(MAG+"幻"+YEL+"。"+GRN+"蛇袍"NOR, ({ "unreal robe","robe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "fur");
                set("armor_prop/armor", 30);
		set("armor_prop/parry",10);
		set("armor_prop/force",3);
		set("long","蛇神君才有的奇幻蛇袍，制作与出处均是一个迷。\n");
        }
        setup();
}
