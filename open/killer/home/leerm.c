#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "近战武器贩卖处");
  set ("long", @LONG
这是叶秀杀特地引进的贩卖处，以免杀手在没有武器的情形下离开总坛而遇害
如果想补充长期作战所需的装备，倒是不错的选择。

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"foodrm.c",
   ]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/lee.c" : 1,]));
  setup();
}