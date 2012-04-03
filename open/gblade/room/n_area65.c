// n_area65.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "Ãñ·¿");
        set("long",
             n_area(65)
);

        set("exits", ([
            "west"  : __DIR__"n_area7",
      ]));

        set("objects", ([
      ]));

        setup();
}
