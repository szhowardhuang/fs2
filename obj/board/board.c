#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
   set_name(HIC"心情石板"NOR, ({"board"}));
set("location","/u/h/happy/room/workroom.c");
set("board_id","happy_b");
set("long",HIC"温情浓厚的石板,可以让你尽情留言...\n"NOR);
    setup();
set("capacity", 80);
set("master",({"happy"}));
}


