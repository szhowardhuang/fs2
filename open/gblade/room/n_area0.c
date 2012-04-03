// n_area0.c by konn
#include </open/gblade/room/n_area.h>
inherit ROOM;

void create()
{
	set("short", "Î÷´ó½Ö");
	set("long", 
             n_area(0) 
);

        set("exits", ([
            "east"  : "/open/port/room/r4-1",
            "south" : __DIR__"n_area1",
      ]));
	    
	set("objects", ([
      ]));

	setup();
}
