// pnx_needle.c by nike
#include <weapon.h>
#include <ansi.h>
inherit STABBER;
void create()
{
        set_name(HIW"ξ"HIR"赤焰"HIW"ξ"HIY"凤羽针"NOR, ({"pnx_needle", "needle"}) );
        set_weight(3000);
        if( clonep() )
        set_default_object(__FILE__);
        else
         {
        set("unit", "柄");
        set("no_put",1);
        set("no_get",1);
        set("no_auc",1);
        set("no_drop",1);
        set("no_give",1);
        set("no_sell",1);
        set("material", "steel");
        set("wield_msg", "$N双手紧紧握起$n，一阵火光闪炽在$N的周围...\n");
        set("unwield_msg", "$N慢慢放下手中的$n，闪炽的火光也随之渐渐消逝...\n");
        set("long","此把针是由「火凤凰”的尾羽所炼化而成的神兵！\n");
        set("value", 1000000);
         }
        init_stabber(120);
        setup();
}



