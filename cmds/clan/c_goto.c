// c_goto.c by ACKY 03/22/00

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
	object obj, room;
	if( me->query("clan/rank") > 3 )
		return notify_fail("您无权使用此指令。\n");
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail("此处并非贵帮之地盘。\n");
	if( me->is_fighting() )
		return notify_fail("您正忙于战斗。\n");
	if( CLAN_D->clan_query(me->query("clan/id"),"gold") < 100000 )
		return notify_fail("帮派存款至少要有拾万两黄金。\n");
	if( !arg )
		return notify_fail("使用方式：c_goto <帮众ID>\n");
	sscanf(arg, "%s", arg);
	obj = find_player(arg);
         if(obj && wizardp(obj))
        return notify_fail("这位帮众目前不在线上喔。\n");


//	if(!obj) obj = find_living(arg);
//	if (!obj) obj=LOGIN_D->find_body(arg);
	if(!obj)
		return notify_fail("这位帮众目前不在线上喔。\n");
	if( CLAN_D->what_clan_area(obj)!=me->query("clan/id") )
		return notify_fail("帮众所在之处并非贵帮之地盘。\n");
	room = environment(me);
	tell_room(room,HIC"只见一阵烟雾过后，"+me->query("name")+"的身影已经不见了。\n"NOR, me);
	if( obj && wizardp(obj))	{
		write("轰～～"+obj->query("name")+"用神力将你反弹回来。");
		return 0;
	}
	me->move(environment(obj));
	room = environment(me);
	tell_room(room,HIC""+me->query("name")+"的身影突然出现在一阵烟雾之中。\n"NOR, me);
	return 1;
}

int help( object me )
{
	write("
   c_goto         ：立刻移动到帮众身边。

                                                         by ACKY 2000/03/22
");
	return 1;
}
