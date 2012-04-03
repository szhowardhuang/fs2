// n_area35.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "©му╩");
        set("long",
             n_area(35)
);

        set("exits", ([
            "west"  : __DIR__"n_area33",
      ]));

        set("objects", ([
      ]));

        setup();
}
