inherit ROOM;
#include <ansi.h>
#include <tree.c>

void create()
{
	set("short",HIG"琰 扬 居 -- "NOR+YEL"大 松 树"NOR);
	set("long",@LONG
大松树的树干充满的许多的坑洞，看到此景的你，忍不住的替这
棵树感到哀痛，不过，却也因为有了这些树洞，你才能顺利的爬上树
上去，真是令人无法去评断这事情的好坏。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"up":__DIR__"b-29",
"down":__DIR__"b-20",
]));
	setup();
}