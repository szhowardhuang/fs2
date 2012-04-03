// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	mapping my;
	string status_desc="";
	 
	seteuid(getuid(me));
 
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
        } else
                return notify_fail("只有巫师能察看别人的状态。\n");


	my = ob->query_entire_dbase();

	printf(HIG+""+ob->name()+"目前的替身上限为"HIY"%d"HIG"个\n"HIC+
                      ""+ob->name()+"已经用掉的替身上限为"HIR"%d"HIC"个剩下"HIM"%d"HIC"个能用\n"HIW+
		      ""+ob->name()+"目前有"HIB"%d"HIW"个替身..\n"NOR,
		my["max_standby"],
		my["t_standby"],
		my["max_standby"] - my["t_standby"],
		my["standby"],);
	
	return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : ch-stdby
指令说明 : 
           这个指令可以显示你(妳)目前替身的使用状况
   其中最后一项目前拥有的替身数是已经算在已
   使用替身上限中..用掉他并不会增加已使用替
   身上限..而是当你换取替身时此数值才会增加
其他参考 :
          
HELP
    );
    return 1;
}
