inherit ITEM;
#include <ansi.h>
string bname;

void create()
{
        set_name("灵气土珠",({"soil ball","ball"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
	set("long", @LONG
相传如果要进入五行灵塔，就必需要携带的宝物，灵气土珠所散
发出来的灵气，足以克制五行之中的水灵之气，可以减少具有伤害的
灵气所带来之伤害。灵气土珠必需要聚灵之后，才会开启其作用，若
尚未聚灵的灵气土珠是无任何作用的。

聚灵方式： gather ball
散灵方式： scatter ball
LONG);

	set("value",100000);
	set("unit","颗");
	set("magic-manor",1);
        }
	setup();
}

void init()
{
        add_action("do_gather","gather");
        add_action("do_scatter","scatter");
}

int do_gather(string arg)
{
object ob,me;

        me = this_player();
        ob = this_object();

	bname = base_name(environment(me));

        if( !arg )
	return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
	return 0;

	if( ob != this_object() )
	return 0;

	if( bname != "/open/magic-manor/manor53" )
	return notify_fail(""+ob->name(1)+"无法在此聚集灵气。\n");

        if( me->query_temp("magic-manor/gather-soil") )
	return notify_fail(""+ob->name(1)+"已经聚灵完成。\n");

        ob->set("no_put",1);
        ob->set("no_drop",1);
        ob->set("no_get",1);
        ob->set("no_sell",1);
        ob->set("no_auc",1);
        ob->set("no_give",1);

        message_vision(HIW"$N轻轻将$n"+HIW+"放在手掌之中，让$n"+HIW+"开始吸收聚灵池的灵气。\n"NOR,me,ob);
	me->start_busy(5);
	call_out("act1",5,ob);

	return 1;
}

int do_scatter(string arg)
{
	object ob,me;

        me = this_player();
        ob = this_object();

	bname = base_name(environment(me));

        if( !arg )
	return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
	return 0;

        if( ob != this_object() )
	return 0;

	if( bname != "/open/magic-manor/manor53" )
	return notify_fail(""+ob->name(1)+"无法在此散去灵气。\n");

        if( !me->query_temp("magic-manor/gather-soil") )
	return notify_fail(""+ob->name(1)+"尚未聚集任何灵气。\n");

        ob->delete("no_put",1);
        ob->delete("no_drop",1);
        ob->delete("no_get",1);
        ob->delete("no_sell",1);
        ob->delete("no_auc",1);
        ob->delete("no_give",1);

        message_vision("$N将$n的灵气尽数散去，$n回复成一个没有任何作用的珠子。\n",me,ob);
        ob->set("name","灵气金珠");
        me->delete_temp("magic-manor/gather-soil",1);
	me->delete_temp("magic-manor/soil-shield",1);
	return 1;
}

int act1(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act2",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act2(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act3",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act3(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act4",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act4(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act5",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act5(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act6",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act6(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act7",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act7(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act8",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act8(object ob,object me)
{
	me=this_player();
	bname = base_name(environment(me));
	if( bname == "/open/magic-manor/manor53" )
	{
        message_vision(HIW"$N"HIW"正缓缓的吸取灵气中，只见$N"HIW"周身泛起阵阵光芒。\n"NOR,ob);
	me->start_busy(5);
	call_out("act9",5,ob);
	}else{
	message_vision(HIR"$N"HIR"一时失去了灵气的导引，忽然暴为粉碎!!\n"NOR,ob);
	destruct(ob);
	}
	return 1;
}

int act9(object ob,object me)
{
	ob=this_object();
	me=this_player();
	message_vision(HIW"只见$N"HIW"已吸足了灵气，$N"HIW"周身泛起强烈光芒。\n"NOR,ob);
        ob->set("name",HIW"(聚灵) "NOR+YEL"灵气土珠"NOR);
        me->set_temp("magic-manor/gather-soil",1);
	me->set_temp("magic-manor/soil-shield",1);
	return 1;
}