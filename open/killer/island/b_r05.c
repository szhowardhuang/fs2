#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
船身的摇晃加大了，仿佛在警告入侵者赶快离开，底板则大多已经腐朽，看样
子，这艘船真的快要崩溃掉了。
LONG);
set("exits",([
"north":__DIR__"b_r04",
"south":__DIR__"b_r06",
]));
setup();
}