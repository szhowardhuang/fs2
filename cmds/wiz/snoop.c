// snoop.c
// snoop 取消所有限制, 但是对方也会看到你 snoop 他
// 如果对方抗议, 请勿 snoop....除非对方违法....
// 注意, 玩家有权知道巫师的监听, 请勿任意拿掉这部份功能
// by wade (10/7/1995)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
        me=this_player();
	seteuid(geteuid(me));
	if( !arg ) {
	  	if( objectp(ob = query_snooping(me)) )
			write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
		return 1;
	} else if( arg=="none" ) {
		if( objectp(ob = query_snooping(me)))
        	message_vision (HIW + "$N停止监听$n所收到的讯息。\n"+ NOR,me,ob);
		snoop(me,);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if (!ob) ob = find_player(arg);
	if(!ob || (!ob->visible(ob))) return notify_fail("没有这个人。\n");
        if (!interactive(ob))
           return notify_fail("不能监听断线中的使用者所收到的讯息。\n");
	if(wizhood(ob)=="(admin)"||wizhood(ob)=="(manager)")
		return notify_fail("你不能窃听大神。\n");
	if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
		
	snoop(me, ob);
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
	write (HIW"你开始监听"+ob->name()+"所收到的讯息。\n" + NOR);
	tell_object(ob, HIW + me->name(1) + "开始监听你所收到的讯息。\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
指令格式：snoop [<某人>|none]

    监听其他使用者所收听的讯息，snoop none 则取消监听。

    注意: snoop 是用来帮助玩家或其他巫师解决问题的，
          不是用来窃取别人隐私权用的，在 snoop  他人之前最好知会对方一下
	  除了抓违法玩家或巫师, 否则侵害他人隐私者，将予以适当处份

TEXT
	);
	return 1;
}
