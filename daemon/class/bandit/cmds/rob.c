// rob.c by Oda
#include <ansi.h>
inherit F_GUILDCMDS;
void pre_rob();
void do_rob(object bandit,object ob);
int main(object me, string arg)
{
	object env;
	object *inv;
	int i;
	env = environment(me);
	if( arg=="cancel" ) {
		if( !me->query_temp("抢劫中") )
		return notify_fail("干嘛？你又没在抢劫。\n");
		tell_object(me, "你决定停止拦路抢劫。\n");
		me->delete("greeting_msg");
		me->set("id", me->query("old_id"));
		me->set("name", me->query("old_name"));
		me->set("nickname", me->query("old_nick"));
		me->set("title", me->query("old_title"));
		me->delete("old_id");
		me->delete("old_name");
		me->delete("old_nick");
		me->delete("old_title");
		me->delete_temp("抢劫中");
		me->delete_temp("不准走");
                env->delete("have_bandit");
		return 1;
	}
	if( me->query_temp("抢劫中") )
		return notify_fail("你已经准备好拦人了啦，别急。\n");
	if( env->query("no_fight") || env->query("no_kill") )
		return notify_fail("这里不是你可以随便拦路抢劫的地方。\n");
	if( me->is_fighting() )
		return notify_fail("把敌人打死了钱自然是你的，抢什么抢。\n");
        if( env->query("have_bandit") )
        return notify_fail("此处以有强盗，再另找一处埋伏吧。\n");
	inv = all_inventory(env);
	for( i=0; i<sizeof(inv); i++ ) {
		if( userp(inv[i]) && inv[i]!=me )
			return notify_fail("这里还有别人在，现在蒙面会被发现吧。\n");
	}

	tell_object(me,"你把脸蒙住，躲在路旁准备抢劫。\n");
	if( !me->query("old_id") ) {
		me->set("old_id", me->query("id"));
		me->set("old_name", me->query("name"));
		me->set("old_nick", me->query("nickname"));
		me->set("old_title", me->query("title"));
		me->set("id", "bandit");
		me->set("name", "蒙面强盗");
		me->set("title", "通缉要犯");
		me->delete("nickname");
	}
	me->set_temp("抢劫中", 1);
	me->set_temp("不准走", 1);
        env->set("have_bandit",1);
	me->set("greeting_msg", ({
(: pre_rob :),
	}) );
	return 1;
}

void pre_rob()
{
	int i;
	object *inv, bandit;
	object ob = this_player();

	if( wizardp(ob) ) return;

	inv = all_inventory(environment(ob));
	for( i=0; i<sizeof(inv); i++ ) {
		if( inv[i]->query_temp("抢劫中") )
			bandit = inv[i];
	}

	if( ob->query_temp("被抢过") ) return;
	ob->set_temp("不准走", 1);
        call_out("do_rob",1,bandit, ob);
}

void do_rob(object bandit, object ob)
{
	int face, money, kee;

	tell_object(bandit,HIW"\n突然之间你从路旁跳了出来对着"+ob->name()+"大喊：\n\n‘此路是我开，此树是我哉！要从此路过，留下买路财！’\n\n"NOR);

	face =( bandit->query_skill("change",1)+bandit->query("kar") < random(ob->query("combat_exp")/10000)+ob->query("int") );
	if( face )  tell_object(bandit,HIG"不妙，你的蒙面被识破了。\n"NOR);

	tell_object(ob,HIW"\n突然之间"+(face?bandit->query("old_name"):"一个蒙面人")+"从路旁跳了出来对着你大喊：\n\n‘此路是我开，此树是我哉！要从此路过，留下买路财！’\n\n"NOR);

	money = ( ob->query("combat_exp")/5000 + 1 ) * 10000;

	if( bandit->query("kar")*bandit->query("combat_exp")/10 > ob->query("cor")*ob->query("combat_exp")/20 ) {
		tell_object(bandit,"于是你们一言不合大打出手，经过一阵厮杀之后，"+ob->name()+"由于技不如人，只有俯首称臣的份，乖乖的奉上过路费啦。\n");
		tell_object(ob,"于是你们一言不合大打出手，经过一阵厮杀之后，由于你技不如人，只有俯首称臣的份，乖乖的奉上过路费啦。\n");
		if( ob->can_afford(money) ) {
			ob->pay_money(money);
			bandit->pay_player(money);
			tell_object(ob,HIC"你付给"+(face?bandit->query("old_name"):"蒙面人")+"一些过路费。\n"NOR);
			tell_object(bandit,HIC""+ob->name()+"付给你一些过路费。\n"NOR);
			tell_object(ob,HIY""+(face?bandit->query("old_name"):"蒙面人")+"嚣张的说道：给了钱还不快滚？小心老子扁你喔！\n"NOR);
			tell_object(bandit,HIY"你嚣张的说道：给了钱还不快滚？小心老子扁你喔！\n"NOR);
		} else {
			tell_object(ob,(face?bandit->query("old_name"):"蒙面人")+"在你身上搜刮了半天，竟然一点值钱的金子都没有，气的痛扁你一顿。\n");
			tell_object(bandit,"你在"+ob->name()+"身上搜刮了半天，竟然一点值钱的金子都没有，只好将对方痛扁一顿出气。\n");
			kee = ob->query("eff_kee")*3/4;
			ob->set("eff_kee", kee);
			tell_object(ob,HIC""+(face?bandit->query("old_name"):"蒙面人")+"将你狠狠地揍了一顿。\n"NOR);
			tell_object(bandit,HIC"你将"+ob->name()+"狠狠地揍了一顿。\n"NOR);
			tell_object(ob,HIY""+(face?bandit->query("old_name"):"蒙面人")+"对着你大吼：以后没钱不准在街上乱走，省得老子动手！\n"NOR);
			tell_object(bandit,HIY"你对着"+ob->name()+"大吼：以后没钱不准在街上乱走，省得老子动手！\n"NOR);
		}
	} else {
		if( bandit->can_afford(money) ) {
			tell_object(({ob,bandit}),"于是你们一言不合大打出手，经过一阵厮杀之后，没想到当强盗的反而抢不过人家，被修理的屁滚尿流，连蒙面都被识破，只好乖乖认错，花钱赔罪啦。\n");
			bandit->pay_money(money);
			ob->pay_player(money);
			tell_object(ob,HIC""+bandit->query("old_name")+"付给你一些过路费。\n"NOR);
			tell_object(bandit,HIC"你付给"+ob->name()+"一些过路费。\n"NOR);
		} else {
			tell_object(({ob,bandit}),"于是你们一言不合大打出手，经过一阵厮杀之后，没想到当强盗的反而抢不过人家，被修理的屁滚尿流，连蒙面都被识破，只好乖乖认错，跪地求饶啦。\n");
			kee = bandit->query("eff_kee")*3/4;
			bandit->set("eff_kee", kee);
			tell_object(ob,HIC"你将"+bandit->query("old_name")+"狠狠地揍了一顿。\n"NOR);
			tell_object(bandit,HIC""+ob->name()+"将你狠狠地揍了一顿。\n"NOR);
		}
		tell_object(ob,HIY"你狂笑着说：就凭你"+bandit->query("old_name")+"这根葱也敢在太岁爷头上动土，不想活啦？下次别再被我碰到！哈哈哈哈....\n"NOR);
		tell_object(bandit,HIY""+ob->name()+"狂笑着说：就凭你"+bandit->query("old_name")+"这根葱也敢在太岁爷头上动土，不想活啦？下次别再被我碰到！哈哈哈哈....\n"NOR);
	}
	ob->delete_temp("不准走");
	ob->set_temp("被抢过", 1);
}

int help(object me)
{
	write(@HELP

指令格式： cmd rob [cancel]

说明：此指令能让你就地开始对每一个路过的行人自动进行抢劫，抢劫未取消前
      自己不能移动。
      加上 cancel 参数会停止抢劫。

HELP);
	return 1;
}
