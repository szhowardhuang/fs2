#include <room.h>
#include "../../open.h"
inherit ROOM;

void create()
{
	set("short","独孤愁衣冠陵");
          set("long",@LONG
这里是独孤愁的衣冠陵，所陈放的是独孤愁惯的用的衣服物品，
相传独孤愁生前曾远赴东北太行山，打死千岭邪狼，并取下邪狼的皮
做成一件「邪云霞衣”，是一件珍宝，据闻一般的兵器是无法割开此
衣的，而当年独孤愁乃是靠着雪苍派所流传下的神兵利器「惘剑帐刀
”才制服邪狼，但现今为防此宝衣遭窃，已被藏在某一密秘地带，除
了雪苍派几为辈份较高的人之外，没人知道。

 
LONG);
        set("exits", ([
	"south":__DIR__"ducu_room_in1",
        ]) );
	set("objects",([
	SNOW_OBJ"c_box":1,
	]));
	set("light_up",1);
        setup();
}
