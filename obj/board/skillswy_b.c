inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIY"上诉申请板"NOR,({"skills board","board"}));
set("location","/open/wiz/skroom");
set("board_id","skillswy_b");
set("long","若对skills and funcs有意见，可以来这post");
setup();
set("capacity",300);
}
