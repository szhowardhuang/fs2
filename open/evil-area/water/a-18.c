inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"NOR);
	set("long",@LONG
清风吹拂～你绕着湖面走了一段时间，不自觉的停下了脚步坐在
湖泊一旁长满着翠绿色的青草地上，看着一些人与邪兽安详的生活在
一起，你有种说不出来的感动，回想起刚刚在外面杀戮了不少邪兽，
你不禁猜测起他们是否也想过着这种生活，渐渐地，内心产生了一种
罪恶感。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-19",
"east":__DIR__"a-17",
]));
	setup();
}

 