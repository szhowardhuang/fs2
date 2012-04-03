#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name("[1;32mÂÌÁÖ·ÉÔôÊé[0m",({"bandit board","board"}));
set("location","/u/s/skyer/room/workroom");
set("board_id","skyer_b");
setup();
set("capacity",555);
set("master",({"skyer"}));
}
