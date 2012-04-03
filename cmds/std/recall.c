// recall.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int no_transmit,evil;
	object ob,where;
	string filep;
	seteuid(getuid());
	ob=this_player();

//    filep=ob->query("startroom")+".c";
	filep = "/open/common/room/inn.c";

    where = environment(ob);
    no_transmit = where->query("no_transmit",1);
    evil = where->query("evil",1);

	if( CLAN_D->what_clan_area(me) != "NULL" )
		return notify_fail( "无法在帮派区域内使用。\n" );

    if(no_transmit)
    {
     write("似乎天神听不到你的呼唤声...\n");
     return 1;
    }
    if(evil)
    {
     write("似乎天神的力量无法将你从魔界救出....\n");
     return 1;
    }
      if(me->query_temp("不准走")) return notify_fail("你现在不能移动!!\n");
        if( me->is_fighting() ) return notify_fail("你正在战斗中！\n");

     if(ob->query("kee") < 50)
       return notify_fail("你的气不够了, 无力来使用 recall..\n");
       ob->add("kee",-50);

	if(file_size(filep)==-1){
	  return notify_fail("程式有问题喔！请通知大神处理～\n");
	          }

	message_vision(HIC"$P请求着天神将$P传送回起点！\n"
HIW"突然由空中降下一道耀眼的光，罩住$P后消失不见了...\n"NOR,ob);

	            ob->move(filep);
message_vision(HIW"突然由天上降下一道耀眼的光！\n"
	            HIY"$N由光芒内缓缓的走出来....\n"NOR,ob);
	              return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : recall


这个指令可以让你(妳)迅速回到开始点，将会耗费你的精五十点。

HELP
    );
    return 1;
}
