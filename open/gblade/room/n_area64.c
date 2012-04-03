// n_area64.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
        set("short", "Æ«Æ§Ð¡µÀ");
        set("long",
             n_area(64)
);

        set("exits", ([
            "north" : __DIR__"n_area58",
      ]));

        set("objects", ([
      ]));

        setup();
}
