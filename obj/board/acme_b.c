#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name("[0;1;5;33m°ı[1;5mq[1;5m°ı[1;5ml[1;5m°ı[1;5mO[1;5m°ı[1;5m°ı[1;5m°ı[1;5m°ı[0m", ({"board"}));
  set("location","/u/a/acme/workroom.c");
  set("board_id","acme_b");
  set("long", "’‚ «acmeµƒ∏ﬂø∆ºº…Ë±∏\n");
    setup();
   set("capacity", 100);
  set("master",({"acme"}));
}

