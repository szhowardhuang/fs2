// blade.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
set_name(HIY"鱼龙"NOR,({"ublade","blade"}));
set_weight(10000);
if(clonep())
set_default_object(__FILE__);
else {
set("unit", "把");
set("value",20000);
set("long", @LONG

这是把失传的名刀‘鱼龙刀’，刀芒一直四射，使你的眼睛无法张开。
LONG
);
set("weapon_prop/dodge",5);
set("weapon_prop/parry",5);
set("weapon_prop/move",5);
set("material", "steel");
set("wield_msg","$N装备$n，瞬时鱼龙刀芒四射。\n");
set("unwield_msg","$N小心亦亦的，将鱼龙宝刀收好。\n");
}
init_blade(90);
set("ski_type1","blade");
set("ski_type2","dragon-blade");
set("ski_level1", 90);
set("ski_level2", 90);
setup();
}
