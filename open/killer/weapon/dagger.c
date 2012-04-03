#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC "灭神匕首" NOR,({"god dagger","dagger"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是叶秀杀与庄静柔与柴荣三人之间的信物，\n
当年的事件之后，这把匕首就不知去向，如今居然出现在你的手上。\n");
                set("value",50000);
                set("material", "steel");
        }
        init_dagger(70);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n藏入怀中。\n");

// The setup() is required.
        setup();
}