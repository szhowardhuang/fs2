#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"狂龙刀谱"NOR,({"dragon-blade book","book"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是写着狂龙刀法招式的一本书。\n");
                set("value",800);
                set("material", "paper");
        }
        setup();
}
