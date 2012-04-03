inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 扬 居 -- 后 院"NOR);
	set("long",@LONG
你正走在砖瓦铺地的道路上，两旁各式一个马厩与大榕树，往南
有一间木制的房屋，隐隐约约中，你可以听到一些哀怨的哭泣声，仿
佛是从木屋内传出来的，往北则通往大厅内。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-24",
"enter":__DIR__"b-47",
]));
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "enter" )
	{
		if( !me->query_temp("evil/water/ask-mission-4") )
			return notify_fail("两旁突然出现了两位邪灵～

邪灵大声喝道：你是谁～竟敢闯此地～活的不耐烦了吗？\n");

		if( !present("evil-foods",me) )
			return notify_fail("两旁突然出现了两位邪灵～

邪灵大声喝道：闲杂人等，不得进入～\n");

		message_vision("两旁突然出现了两位邪灵～

邪灵望了望$N，看着$N手中的食物说道：原来是送饭的...进去吧!!\n",me);
	}
	return 1;
}
 