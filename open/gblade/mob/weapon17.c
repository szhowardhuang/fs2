#include <weapon.h>

inherit STICK;

void create()
{
        set_name("罗汉棍", ({ "lohan stick","stick" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "
玄铁铸成，棍身长一丈又六尺，通体乌黑且带着墨色的光泽，虽不耀眼却
黯然内敛。
\n");
                set("value", 1000);
                set("material", "ironsteel");
                set("wield_msg", "$N将$n紧紧握在手中.\n");
                set("unwield_msg", "$N将手中的$n放下.\n");
        }
	init_stick(50);
        setup();
}
