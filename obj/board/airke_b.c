//roger's board
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("电脑留言机",({"board"}));
	set("location","/u/a/airke/workroom");
	set("board_id","airke_b1");
   set("long","高科技的椭圆形乳白银幕,显示魔界一切的状态。\n");
   setup();
   set("capacity", 100);
	set("master",({"airke"}));
}
