#include <ansi.h>
inherit ROOM;
void create ()
{
	set("short",YEL"幽冥道"NOR);
	set("long",@LONG
脚底踏的很不实在，仿佛站在稀松的土壤上面，
一点厚实感也没有，四周偶尔总是会传来阵阵血腥的
恶臭味，你无法搞清楚自己身处何处，南边偶尔传来
些吵杂声，似乎有某些生物在那边活动着。
LONG);
	set("exits",([
	"west":__DIR__"g-r01",
	"south":__DIR__"g-r03",
	"east":__DIR__"g-r10",
	]));
	set("no_transmit",1);
	setup();
}
