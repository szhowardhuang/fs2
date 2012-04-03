// blade.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

int damage_down( object me , int power )
{
	message_vision("附在$N身上的幽灵魔力消失了。\n",me);
	me->add_temp("apply/damage",-power);
	delete("in_using");
	return 1;
}
void create()
{
	set_name(HIB"幽灵魔刀"NOR,({"ghost blade","blade"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
     set ("unit","柄");
          set("value", 10000);
		set("material", "iron");
	set("long","这是一把传说中的魔刀，相传只要在战斗中使用(use)，就能产生怨灵魔气。\n");
	set("no_drop",1);
	set("no_give",1);
          set("wield_msg", "$N装备$n。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
          set("armor_prop/blade",10);
	init_blade(60);
	setup();
}
void init()
{
	add_action("do_use","use");
}
int do_use( string arg )
{
	object me = this_player() , ob = this_object();
	int power;
	if( !arg || arg != "blade" ) return 0;
	if( query("in_using") ) return notify_fail("你已经在用了。\n");
	if( !this_player()->is_fighting() )
		return notify_fail("这把刀必须在战斗中才能使用。\n");
	if( me->query("force") < 100 )
		return notify_fail("你的内力不够。\n");
	message_vision( HIB + @LONG
$N将幽灵魔刀向着天空一举～～～～～～～
顿时一阵狂风卷沙、山崩地摇 .......
只见数十道幽灵的影子聚集在魔刀之上～～～
LONG + NOR,me);
	power = me->query("force") / 20;
	me->add_temp("apply/damage", power );
	me->add("force",-100);
	set("in_using",1);
	call_out("damage_down",30,me,power);
	return 1;
}
int query_autoload() { return 1; }
