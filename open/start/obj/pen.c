//pen.c : 钢笔

#include <weapon.h>

inherit STABBER;

void create()
{
        set_name("钢笔",({"steel pen","pen"}));
        set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "枝");
                set("long","此笔造形奇特, 据说为洋人所爱用。\n");
                set("value",750);
		set("material", "steel");
                set("wield_msg", "$N从胸前口袋里掏出一枝$n, 很文明的样子。\n");
                set("unwield_msg", "$N用一副文明人的姿态将$n收进胸前口袋中。\n");
	}
        init_stabber(30);
	setup();
}
int wield()
{
        if((string)this_player()->query("family/family_name") != "儒门")
           return notify_fail("钢笔只有儒门弟子能用\n");
        else{
              ::wield();
            }
        return 1;
}
