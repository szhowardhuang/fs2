#include <room.h>
inherit ROOM;
 void create()
{
  set("short", "杀手报报室");
  set("long", @LONG
           -------  给我报报，我给你全世界  --------
       杀手总坛，目前扩建中。如果有任何虫虫，请尽速回报。
       如果虫虫够大只的话，天才小渡会透露一些总坛资料。
       呵。。。总坛是为杀手设计的。请好康的，不要乱说出去。
       不然被迫改掉，我可不管。大家请在此留言.....

LONG);
        set("exits", ([ /* sizeof() == 1 */
            "north":__DIR__"r0.c",
            "south":__DIR__"floorm.c",
  ]));
       setup();
        call_other("/obj/board/killerwiz_b","???");
}
int valid_leave(object me, string dir)
{
  if (me->query("class")!="killer" && dir=="north")
 return notify_fail("这是杀手的禁地!由于你没练霸雨螫魂,故你无法进入!\n");

return ::valid_leave(me,dir);
}
void init()
{
  add_action("do_pass","pass");
}
int do_pass()
{
  object me;
  me = this_player();
  me->move("/open/center/room/inn");
  return 1;
}