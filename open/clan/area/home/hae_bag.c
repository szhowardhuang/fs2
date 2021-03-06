// hae_bag.c 乾坤袋 by babe

#include <ansi.h>

inherit ITEM;

//#define	GET	"/cmds/std/get"

void create()
{
	set_name( HIW"卍乾坤袋卍"NOR, ({ "universal bag", "hae_bag", "bag" }) );
	set( "long", @LONG
	一个又小又轻的袋子, 似乎轻轻一丢(throw)就会飞走的样子。

LONG);
        set_weight(1);
	set_max_encumbrance( 100000 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set( "unit", "个" );
		set( "value", 100000 );
	}
	setup();
}

void init()
{
	if( !present( this_object(), this_player() ) ) {
//		add_action( "do_get", "get" );
		return;
	}
	add_action( "do_throw", "throw" );
}

/*
int do_get( string str )
{
	int	i;
	object	target, *inv;
	object	me	= this_player();
	object	bag	= this_object();

	target = present( "hae_bag", me );
	if( target && target!=bag ) {
		inv = all_inventory(bag);
               	for( i=0; i<sizeof(inv); i++ )
			inv[i]->move(target);
	}
	GET->main( me, str );
	destruct(bag);
	return 1;
}
*/

int do_throw( string str )
{
	object	me	= this_player();
	object	bag	= this_object();
	object	target;

    if(wizardp(me) && wiz_level(me) <7)
		return 0;

	if( me->query("force")<10 ) {
		write( "你感觉全身软绵绵地, 竟然连一点力气也使不出来...\n" );
		return 1;
	}

	me->add( "force", -random(10)-1 );
	message_vision( YEL"$N"HIY"取出$n"HIY", 朝着天空奋力一掷...\n"NOR, me, bag );
	message_vision( HIY"只见$n"HIY"以极快的速度, 又高又远地飞了出去, 刹那间已没入了云端。\n"NOR, me, bag );

	if( !str )
		str = me->query("id");
     target=find_player(str);
     if( !target || target->query("ghost")==1)
		target = me;
     if(wiz_level(target)==7)
        target=me;
       if(target->query("id")=="cgy" || target->query("env/隐身","YES"))
	    target = me;
	message_vision( HIC"\n突然间... 一道激烈的破空之声, 由远而近地朝"CYN"$N"HIC"而来...\n"NOR, target );
	message_vision( HIC"砰... 一个$n"HIC"将"CYN"$N"HIC"撞倒在地...\n"NOR, target, bag );
	bag->move( environment(target) );
	if( target->query("gin") > 10 )
		target->add( "gin", -random(10)-1 );
	if( target->query("kee") > 10 )
		target->add( "kee", -random(10)-1 );
	if( target->query("sen") > 10 )
		target->add( "sen", -random(10)-1 );
	COMBAT_D->report_status( target, 0 );

	return 1;
}
