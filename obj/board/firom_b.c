inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIW"武者巫师讨论板"NOR,({"board"}));
set("location","/u/c/chan/fi_room");
set("board_id","firoom");
set("long","这是让武者系列的巫师群来讨论问题的及研究系统的讨论布告栏\n");
setup();
set("capacity",200);
replace_program(BULLETIN_BOARD);
}
