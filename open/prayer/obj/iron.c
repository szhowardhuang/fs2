//生铁()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("生铁", ({ "iron" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "块");
          set("long",@LONG
	这是一块刚从坑中挖掘出来的铁矿!!铁矿是制作武器时所必须
	的材料之一, 因为它的密度够, 硬度佳, 延展性也适中!!所以
	是武器最常见的主要材质!!
LONG);
          set("value", 800);
          set("material", "iron");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


