// n_area8.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "É½ÆÂ");
        set("long",
             n_area(8)
);

        set("exits", ([
            "east"  : __DIR__"n_area7",
      ]));

        set("objects", ([
      ]));

        setup();
}
