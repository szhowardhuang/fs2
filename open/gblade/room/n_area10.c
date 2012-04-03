// n_area10.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "Ê÷ÁÖ");
        set("long",
             n_area(10)
);

        set("exits", ([
            "east"  : __DIR__"n_area9",
      ]));

        set("objects", ([
      ]));

        setup();
}
