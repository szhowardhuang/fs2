#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
seteuid(getuid());
set_name(""HIR"日"HIB"月"HIW"神器"NOR"",({"sun_moon_sword","sword"}));
set_weight(7000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("long",
"由朝阳古阙与拜月幽剑两把矿世神器所合铸成的剑.....半边剑身呈深红色
另半边则会为阴蓝色,完全显现出这把神器的特性-刚柔并济-。\n");
set("value",0);
set("material", "crimsonsteel");
set("wield_msg", HIW"$N将$n"HIW"由身后厚重的剑匣中抽出,顿时日月并现于天际,并将其灵气注入$n\n");
set("unwield_msg", HIW"$N将手中$n"HIW"向后一丢...$n似"HIW"乎有灵性一般,自动回归剑匣内。\n");  
}
   set("no_drop", 1);
   set("no_give", 1);
   set("no_get", 1);
   set("no_auc", 1);
init_sword(110);
setup();
}
int query_autoload()
{
   return 1;
}


