inherit ROOM;
#include <ansi.h>
void create()
{
set("short", "松林");
set("long", @LONG
渐渐地你可以感觉到前方，阳光从树射落到地上，不在令人感到
黑暗，松树林也渐渐稀疏了，这里似乎已是松林的尽头，你可以看到
前方有个小山丘。
LONG
);
set("exits",([ /* sizeof() == 2*/
"down" : __DIR__"tree2.c",
"north" : __DIR__"tomb.c",
]));
set("outdoors",1);
setup();
}

