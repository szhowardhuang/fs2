inherit ROOM;
#include <ansi.h>
#include <room.msg>

void create () {
        set ("short","–˛Œ‰ª√’Û");
        set ("long",
        (: print_room_msg :)
        );
    
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "±±√≈" : __DIR__"room39",     
        ]));

        setup();
}
