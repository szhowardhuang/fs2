inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"水之流羽"NOR,({"water-feather"}));
	set("long","一根泛着些微水气的羽毛，滋润的气息，带给你无限的舒适，名为\n"
		  +"水之流羽，任你如何的细看和研究，却也不知它有何作用，也许和\n"
		  +"传说中的天灵地界有关。\n");
	set("unit","根");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set_weight(1000);
        setup();
}
