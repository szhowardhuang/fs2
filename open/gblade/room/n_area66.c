// n_area66.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "Ãñ·¿");
        set("long",
             n_area(66)
);

        set("exits", ([
            "east"  : __DIR__"n_area26",
      ]));

        set("objects", ([
      ]));

        setup();
}
