inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"光之明羽"NOR,({"light-feather"}));
	set("long","一根带着些微光彩的羽毛，隐约透出各种颜色光彩，名为光之明羽，\n"
		  +"任你如何的细看和研究，却也不知它有何作用，也许和传说中的天灵\n"
		  +"地界有关。\n");
	set("unit","根");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set_weight(1000);
        setup();
}
