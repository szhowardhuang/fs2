// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

	inherit STABBER;

void create()
{
	set_name(HIW "天诛笔" NOR,({"ten pen","pen"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","支");
		set("value",10000);
		set("material", "steel");
		set("long",@LONG
这把是独孤世家的家宝之一，名曰「天诛”
相传此笔不须任何油墨即可写字，且写出来的字
呈金黄色，此外，又可用来作为攻击武器，但是
一般的人若不知道方法，是无法发挥出真正的效
果的。
LONG);
		set("wield_msg",@LONG
$N从怀间抽出一支$n，闪闪发光，照得四周都变成金黄颜色！
LONG);
	}
	init_stabber(50,SECONDARY);
	setup();
}
