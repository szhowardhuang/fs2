#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name(HIB "千兽魂" NOR,({"ghost lance","lance"}));
           set_weight(8000);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
                   set("unit", "把 ");
           set("long","这是十几年前某个村庄,因为要消灭千年血妖,而集结千头野兽
          的魂魄,所铸成的魔枪 .\n");
                   set("value",30000);
                   set("material", "gem");
           set("wield_msg", "$N拿起了$n,身边顿时充满了妖气。 .\n");
           set("unwield_msg", "$N将$n收了起来,$n顿时妖气消失无形。.\n");
           }
           init_lance(80);
           setup();
           }






