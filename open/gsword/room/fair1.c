#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "林中空地");
        set("long", @LONG
不知为什么在茂密的树林中，这儿竟然寸草不生，使劲的朝地上踏去,发现
这儿的土地坚硬的很，也难怪植物难以在这生根了。
LONG
        );

        set("exits", ([
"west":__DIR__"plain6",
"south":__DIR__"plain4",
"east":__DIR__"fair"
        ]) );
setup();

}
