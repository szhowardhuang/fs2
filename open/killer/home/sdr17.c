#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
set("short","秘密之间");
          set("long",@LONG
在你眼前的就是传说中黑白两道所尊崇的寰宇一奇---欧阳不空，据说他以经消失在武林
没想到居然在此又出现了！或许他是为了黑血神针才到此处吧。
因为在传说中，他与飘花宫有很深的渊源，然而黑血神针本来就是出自于飘花宫。


LONG);
        set("exits", ([
"up":__DIR__"sdr2.c",
        ]) );
set("objects",([
    "/open/killer/npc/oyang.c":1,
]));
set("light_up",1);
        setup();
}