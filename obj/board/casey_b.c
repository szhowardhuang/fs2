//casey's board
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"清风石碑"NOR, ({"board"}));
    set("location","/u/c/casey/workroom");
        set("board_id","casey_b");
        set("long","可以在上面刻字的石碑\n");
    setup();
    set("capacity", 999);
        set("master",({"casey"}));
}
