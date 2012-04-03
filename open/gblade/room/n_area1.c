// n_area1.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "Î÷´ó½Ö");
        set("long",
             n_area(1)
);

        set("exits", ([
            "north" : __DIR__"n_area0",
            "south" : __DIR__"n_area2",
      ]));

        set("objects", ([
      ]));

        setup();
}
