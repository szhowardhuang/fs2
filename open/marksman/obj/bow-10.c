#include <weapon.h>
#include <ansi.h>

inherit BOW;

void create()
{

set_name("养由弓",({"support bow","bow"}));
set("value",6000);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long","一把由五虎将黄忠所持有的弓。\n");
set("material","steel");
        }
        init_bow(60);
set("value",0);
        setup();
}
