// n_area12.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "Ê÷ÁÖ");
        set("long",
             n_area(12)
);

        set("exits", ([
            "east"  : __DIR__"n_area11",
            "south" : __DIR__"n_area13",
      ]));

        set("objects", ([
      ]));

        setup();
}
