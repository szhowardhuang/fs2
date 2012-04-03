#include <ansi.h>
#include <weapon.h>

inherit WHIP;
void create()
{
	set_name("绳索",({"rope"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","
一条捆绑物品所用的绳子，你也可以勉强将它视作鞭子来使用，它还有另
外一项特殊的用处---用来上吊(hang)。\n");
		set("material","iron");
		set("value",50);
		set("unit","条");
		set("wield_msg","$N将绳索抽出，握在手上当武器。\n");
		set("unwield_msg","$N将绳索放下。\n");
	}
	init_whip(5, SECONDARY);
	setup();
}
void init()
{
	add_action("do_hang","hang");
}
int do_hang(string str)
{
	object me=this_player();
	if( !str || str!="myself")
	return notify_fail("你只能帮助自己(myself)上吊!\n");
	{
	message_vision(
"$N随便找了一个地方，将绳子绑好，往脖子一套准备自杀，但却不小心绊
到石头跌了一交，跌个眼冒金星，看来$N是自杀不成啦。\n",this_player() );
	tell_object(me,"你跌了一交，受了点伤。\n");
	me->add("kee", -5);
	return 1;
	}
}

	
