#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name("六合乾坤枪",({"universe_lance","lance"}));
           set_weight(2000);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
                   set("unit", "把");
           set("long","这是一把轻巧无比的神兵利器.\n");
                   set("value",40000);
                   set("material", "gold");
           set("wield_msg", "$N身子一侧$n瞬间飞出,你握起了$n几乎感觉不出它的
            重量。 .\n");
           set("unwield_msg", "$N将$n向天空抛去,霎时$n消失无踪.\n");
           }
           init_lance(60);
           setup();
           }






