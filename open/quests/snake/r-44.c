inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","蛇寨 地下室");
	set("long",@LONG
墙上的火把将这里给照亮了许多，你身后有一座蛇型雕刻的门扇
，不过门扇已经关闭了，而眼前又有一个绳索，由上垂吊而下，似乎
是通往地面唯一的方法。
LONG);
	set("no_transmit",1);
	set("exits",([
"up":__DIR__"r-45",
]));
	setup();
}
