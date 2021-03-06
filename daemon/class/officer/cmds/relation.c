#include <ansi.h>
inherit F_GUILDCMDS;
string *status = ({
	HIR "你死我亡" NOR,
	HIR "水火不容" NOR,
	RED "意见不合" NOR,
	RED "印象不好" NOR,
	BLU "初探门路" NOR,
	HIB "些微交往" NOR,
	HIB "略有往来" NOR,
	CYN "交情尚可" NOR,
	CYN "往来频繁" NOR,
	HIC "关系非凡" NOR,
	HIC "非比寻常" NOR,
	HIW "不可告人" NOR,
	});
string get_status(int value);
int main(object me,string arg)
{
	string msg;
	string *name;
	object ob;
	int i;
        if(!arg)
                ob = me;
        else{
		if(!wizardp(me))
			return notify_fail("只有巫师才能查看玩者的关系状况。\n");
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的关系状态 ?\n");
        }

	if(!ob->query("relation"))
		return notify_fail((ob==me ? "你":ob->name())+"并没有和任何官员建立任何关系。\n");
	name=keys(ob->query("relation"));
msg = (ob==me ? "你" : ob->name() ) + "目前和各个官员之间的关系：\n\n";
	for(i=0;i<sizeof(ob->query("relation"));i++)
		msg+=sprintf("  %-45s- %10s - (%d)\n",
	ob->query("relation/"+name[i]+"/name")+"("+name[i]+")",
	get_status(ob->query("relation/"+name[i]+"/value")),
	ob->query("relation/"+name[i]+"/value"));
	msg+="\n";
	write(msg);
	return 1;
}
string get_status(int value)
{
	if(value>-40&&value<70) return status[value/10+4];
	else if(value>=70) return status[11];
	else return status[0];
}
int help(object me)
{
  write(@HELP
指令格式： relation

说明：这个指令让你可以查看你和其它官员间的关系。
HELP
  );	
  return 1;
}
