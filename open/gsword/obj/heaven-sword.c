// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
  set_name(HIB"玄铁剑" NOR,({"heaven sword","sword"}));
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
set("long","一把黑黝黝的宝剑 ,似乎颇为沉重 .\n");
		set("value",10000);
		set("material", "steel");
	set("wield_msg", "$N从背后抽出$n,顿时全身充满力量。\n");
	set("unwield_msg", "$N将手中$n收回。\n");
	}
	init_sword(80);
	setup();
}
