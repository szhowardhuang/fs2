// n_area11.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "Ê÷ÁÖ");
        set("long",
             n_area(11)
);

        set("exits", ([
            "north" : __DIR__"n_area9",
            "west"  : __DIR__"n_area12",
      ]));

        set("objects", ([
      ]));

        setup();
}
