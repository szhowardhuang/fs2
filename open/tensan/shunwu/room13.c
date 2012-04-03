inherit ROOM;
#include <ansi.h>
#include <room.msg>

void create () {
        set ("short","ĞşÎä»ÃÕó");
        set ("long",
        (: print_room_msg :)
        );
    
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */    
        "ÄÏÃÅ" : __DIR__"room7",       
        ]));
 
        setup();
}
