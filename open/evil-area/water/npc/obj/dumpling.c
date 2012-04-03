inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"水晶包"NOR, ({ "crystal dumpling","dumpling" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "
一个包含数十种材料的精致包子，十分的昂贵，不过却份量十足又美味，
是邪灵界琰扬湖的特产之一。\n");
                set("unit", "笼");
                set("value", 10000);
                set("食物", ([
                        "剩" : 10,
                        "供应": 100,
                ]) );
        }
        setup();
}
