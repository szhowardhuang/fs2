inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIC"司徒秘笈"NOR,({"board"}));
set("location","/u/d/dhk/workroom");
set("board_id","dhk");
set("long","有事找dhk,请在此版上post,thx\n");
setup();
set("capacity",50);
replace_program(BULLETIN_BOARD);
}
