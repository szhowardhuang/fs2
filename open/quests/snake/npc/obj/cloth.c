#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("蛇袍", ({ "snake robe","robe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
		set("long","一件稍有防御作用的衣服。\n");
        }
        setup();
}
