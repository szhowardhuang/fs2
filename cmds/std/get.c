// get.c babe
// fix 地上东西只捡部分就会消失的 bug
// 增加捡尸体告知主人

#include <ansi.h>
#include <carry.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

int main(object me, string arg)
{
  string from, item;
  object obj, *inv, env, obj2;
  int i, amount;

	seteuid(getuid());

	if (!NATURE_D->vision(me))
		write ( "四周乌漆妈黑的, 你随处摸啊摸.........\n");

	if( !arg ) return notify_fail("你要捡起什么东西？\n");

	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
    		if(!env || living(env))
      			return notify_fail("你找不到 " + from + " 这样东西。\n");
		// by acky
		if( env->is_corpse() && env->query("victim_id") ) {
			if( obj = find_player(env->query("victim_id")) )
				tell_object( obj, HIB"你突然有阵怪怪的感觉, " + me->name(1) + "(" + getuid(me) + ")正在挖你的尸体。\n"NOR );
		}
	}
  	else
  		env = environment(me);

	if(sscanf(arg, "%d %s", amount, item)==2) {
    		if( !objectp(obj = present(item, env)) )
      			return notify_fail("这里没有这样东西。\n");
    		if( !obj->query_amount() )
      			return notify_fail( obj->name() + "不能被分开拿走。\n");
    		if( amount < 1 )
      			return notify_fail("东西的个数至少是一个。\n");
    		if( amount > obj->query_amount() )
      			return notify_fail("这里没有那么多的" + obj->name() + "。\n");
    		else if( amount == (int)obj->query_amount() ) {
      			return do_get(me, obj);
    			}
    		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->move( environment(me) );
			return do_get(me, obj2);
    		}
  	}

  if(arg=="all") {
    if( !env->query_max_encumbrance() )  return notify_fail("那不是容器。\n");

    if( env->query("id")=="corpse" && env->query("killer") && wizardp(env->query("killer")) && !wizardp(me) )
      return notify_fail("不要趁机捡便宜。\n");

    inv = all_inventory(env);
    if( !sizeof(inv) )
      return notify_fail("那里面没有任何东西。\n");

    for(i=0; i<sizeof(inv); i++) {
  if( userp(inv[i]) || inv[i]->is_character() || inv[i]->query("no_get") )
        continue;
      do_get(me, inv[i]);
    }
    write("Ok。\n");
    return 1;
  }

  if ( !objectp(obj = present(arg, env)) )
    return notify_fail("你附近没有这样东西。\n");

  if( userp(obj) || living(obj) )
    return notify_fail("你不能拿起活物。\n");

  if ( obj->query("no_get") )
    return notify_fail("这个东西拿不起来。\n");

  return do_get(me, obj);
}

int do_get(object me, object obj)
{
  object old_env;
  int equipped;
  int carry = sizeof(all_inventory(me));
  if( carry >= MAX_CARRY ) return notify_fail("你身上的东西太多了。\n");

  old_env = environment(obj);

	if( obj->query("equipped") )
		equipped = 1;
	if( me->query("id")!=obj->query("boss") && obj->query("boss") )
		return notify_fail( "此物品只有本人才能拿。\n" );
	if( obj->query("id")=="degu sa" )
		return notify_fail( "还想做弊吗，真 ooxx 。\n" );
	if( obj->move(me) ) {
		if( me->query("food") > 1 )	me->add( "food", -1 );
		if( me->is_fighting() && userp(me) ) me->start_busy(1);
		if( obj->is_character() )
			message_vision( "$N将$n扶了起来揹在背上。\n", me, obj );
		else
			message_vision( sprintf("$N%s一%s$n。\n",
				old_env==environment(me)? "捡起":
					(old_env->is_character() ?
						"从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
						"从" + old_env->name() + "中拿出" ),
						obj->query("unit")), me, obj );
		return 1;
	}
	else
		return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : get <物品名称> [from <容器名>]
指令说明 :
           这个指令可以让你捡起地上或容器内的某样物品。
其他参考 :
           drop，give
HELP);
    return 1;
}

