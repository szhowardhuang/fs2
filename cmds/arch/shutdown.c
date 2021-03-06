// shutdown.c 修正 by babe

#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob, pal;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status!="(manager)" && wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

//message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		if( pal=user[i]->query_temp("pal") )
			pal->save();
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(0);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : shutdown
指令说明 :
    本命令会让系统马上停止一切动作, 当然, 正常情况下是
    跟当机不一样, 而是先将玩家的资料存档, 然后再关机.
其他参考 :
    reboot
HELP
  );
  return 1;
}
