#include <ansi.h>
inherit BULLETIN_BOARD;

#include <ansi.h>
void create()
{
  set_name(HIC"小希希的梳妆台"NOR, ({"board"}));
  set("location","/u/c/cccc/workroom.c");
   set("board_id","cccc_b1");
  set("long","
   书要读 , 女友要顾 , MUD也要玩~~~~~\n
  欢迎大家来灌水....CC..");
    setup();
    set("capacity", 30);
  set("master",({"cccc"}));
}
