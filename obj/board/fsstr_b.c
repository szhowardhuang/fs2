inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIC"意见发表处"NOR,({"means board","board"}));
set("location","/open/wiz/fsroom");
set("board_id","fsstr_b");
set("long","若对狂想空间有任何的建议,可以来这里post");
setup();
set("capacity",300);
  }
