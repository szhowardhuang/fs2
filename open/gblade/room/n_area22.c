// n_area22.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long",
             n_area(22)
);

        set("exits", ([
            "north" : __DIR__"n_area19",
            "east"  : __DIR__"n_area23",
            "west"  : __DIR__"n_area21",
            "south" : __DIR__"n_area30",
      ]));

        set("objects", ([
      ]));

        setup();
}
