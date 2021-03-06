// charge.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || arg=="" ) {
		if( ob = me->query_charge_target() ) {
			write("你现在以" + ob->name() + "为首要攻击目标。\n");
			return 1;
		}
		write("你现在并没有选定首要攻击目标。\n");
		return 1;
	}

	if( arg=="cancel" ) {
		write("Ok.\n");
		me->remove_charge();
		return 1;
	}

	ob = present(arg, environment(me));
	if( !ob ) return notify_fail("这里没有这个人。\n");

	if( !me->is_fighting(ob) )
		return notify_fail("你现在并没有在跟" + ob->name() + "战斗。\n");

	me->charge_ob(ob);
	
	if( userp(me) )
		message_vision( "$N以$n为首要攻击目标。\n", me, ob );
	
	return 1;
}

int help(object me)
{
	write(@TEXT
指令格式：charge [<战斗目标>|cancel]

这个指令让你选定一个正在和你战斗中的敌人为首要攻击目标，所谓首要攻击
目标是指当这个目标还在跟你战斗的时候，会忽略其他敌人而专挑这个目标攻
击，如此一来你可以先集中全力消灭比较可怕的敌人，但是相对的，你对其他
敌人的攻击防御率就只有平常的 2/3。

要取消 charge 模式，可以用 charge cancel，不加任何参数则显示你目前集
中攻击的对象。
TEXT
	);
	return 1;
}
