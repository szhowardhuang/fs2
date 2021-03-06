// by ACKY
#include <ansi.h>
inherit F_CLEAN_UP;
int main( object me, string str )
{
	int num;
	if( me->query("clan/rank") > 3 )
		return notify_fail("您无权使用此指令。\n");
	if( !str )
		return notify_fail("指令格式：c_prestige <基金>\n");
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail("此处并非贵帮之地盘。\n");
	num = atoi(str);
	if( num > 10 )
		return notify_fail("建立帮派威望的经费不得超过十万两黄金。\n");
	num = num*10000;
	if(CLAN_D->clan_query(me->query("clan/id"),"gold") < num)
		return notify_fail("目前帮内并无那么多钱。\n");
	CLAN_D->clan_set(me->query("clan/id"),"prestige",num);
	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 - "HIW+me->query("clan/title")+HIY
		"郑重地宣布\n\t将投注"HIC+CHINESE_D->chinese_number(num)+HIY"两黄金, 用来建立本帮之威望。"NOR);
	return 1;
}

int help( object me )
{
	write(
"\n\tc_prestige: 设定用于建立帮派威望的经费。
\n\t单位: 万两黄金
\n\t帮派威望愈高, 能占领的地盘愈大。\n\n"
	);
	return 1;
}
