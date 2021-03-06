// 灵刀 by swy, 精简 by babe
#include <ansi.h>
inherit F_FUNCTION;

int perform( object me )
{
	int	damage;
	object	ob;

	damage	= me->query_skill("blade");

	if( me->query("class") != "blademan" )
		return notify_fail( "此术只限刀客使用。\n");
	if( !me->query("mk-blade") )
		return notify_fail( "无此能力使用特攻。\n" );
	if( me->query("combat_exp") < 5000000 )
		return notify_fail( "江湖历练不足。\n" );
	if( me->query("max_force") < 4000 )
		return notify_fail( "内力不足。\n" );
	if( me->query("force") < 3500 )
		return notify_fail( "真气不足。\n" );
	if( me->query("bellicosity") < 25 )
		return notify_fail( "杀气不足。\n" );
	if( me->query("potential") - me->query("learned_points") < 60 )
		return notify_fail( "潜能不足。\n" );
	if( me->query_temp("del")==1 && !wizardp(me) )
		return notify_fail( "真气不足, 请休息一会儿。\n" );
	if( damage > 350 )
		damage = 350;
        ob = new("/daemon/class/blademan/obj/mkblade.c");
        ob->set_name( HIM"魄邪"HIC"魂冰"NOR, ({ "mk-blade" }) );
	ob->set( "weapon_prop/damage", damage );
	ob->move(me);
	message_vision( HIY"$N大喝一声:‘"BLINK""HIG"邪灵制刀术"NOR""HIY"’\n"BLU"只见阴风徐徐, 无数的阴灵从地表窜出。\n", me );
	message_vision( MAG"$N运起真气, 配合体内的杀气, 运劲往手掌一送, 无数阴灵往$N的手上聚集。\n", me );
	message_vision( HIW"顿时一把由阴灵所汇成的刀已在$N手上。\n"NOR, me );
	me->add( "force", -3000 );
        me->add( "potential", -50 );
	me->add( "bellicosity", -20 );
	me->set_temp( "del", 1 );
	call_out( "del", me->query("functions/mk-blade/level")+20, me );
	return 1;
}

int del( object me )
{
	if( !me )
		return 0;
	me->delete_temp("del");
	if( me->query("functions/mk-blade/level") < 100 )
		function_improved( "mk-blade", random(1000) );
	return 1;
}
