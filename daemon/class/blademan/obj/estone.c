inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(YEL "土之石" NOR,({"earth-stone"}));
    set("long","一颗奇怪的石头。\n");
    set("unit","颗");
    set("value",0);
    setup();
}
