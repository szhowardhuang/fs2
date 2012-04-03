inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",BBLU+YEL"震邪道"NOR);
	set("long",@LONG
你正站立于这房内西边的木制踏板上, 底下不时的传来高温, 仿
佛是在提醒你〔小心脚底下的热油锅〕, 油锅上, 还漂浮着熊熊的火
焰, 若是一不小心掉下去, 可能会尸骨无存, 正当你烦恼着如何渡过
火海去到东边那块闪烁着耀眼金黄色的踏板时, 你突然发觉到在你脚
旁的铁链...

	地上放置着一条延伸至东边的粗大铁链。
LONG);
	set("no_transmit",1);
	set("item_desc",([
"铁链":"链子的另一端似乎锁死在金黄色的踏板下...\n",
]));
	setup();
}

void init()
{
add_action("do_climb","climb");
}

int do_climb(string arg)
{
object me=this_player();

	if(!arg)
		return 0;
	if(arg!="铁链")
		return 0;
	if(me->query_temp("evil/f_enter"))
	{
		message_vision(HIR"$N握着铁链，却被铁链上传来的炙热高温给烫的松手放开铁链。\n"NOR,me);
		me->receive_damage("kee",100);
		COMBAT_D->report_status(me,1);
		return notify_fail("你心中暗喊疼～\n");
	}
	else
	{
		message_vision(HIY"$N的手掌突然浮现〔火〕的字样～

$N有持无恐的握着铁链，爬着爬着，仿佛丝毫不受铁链的炙热高温所影响...

$N爬到了黄金色的踏板，走进了门后。\n"NOR);
		me->move(__DIR__"e05");
		return 1;
	}
}