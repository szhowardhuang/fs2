#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"龙涎"NOR, ({ "dragon-medal","medal" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","散发阵阵灵气的菱形纹章，从特殊的角度还可以看到龙的影像。\n");
                set("unit", "个");
                set("no_drop",1);
                set("no_sell",1);
        }
        setup();
}
