inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIG"竹林中的落叶"NOR,({"board"}));
set("location","/u/s/sueplan/workroom");
set("board_id","sueplan_b");
set("long","竹林中的一片落叶...\n");
setup();
set("capacity",100);
}
