// Room: /u/f/fire/room/room1-31.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  seteuid(getuid());
  set ("short",HIY"射手派广义堂"NOR);
  set ("long", @LONG
漫长的道路，终于来到了这里。你似乎可以感觉到这里的气氛比
其他地方不一样。你发现你的眼前似乎站着一位十分高人的人物，他
就是射日派第二代掌门人--->李广。他的眼中散发出刚强不拔之气息
坚定的目光使你突然严肃。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room1-24",
  "west" : __DIR__"room1-30.c",
  "east" : __DIR__"room1-29.c",
"up" : __DIR__"eq-room",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/master_t.c" : 1,
]));
  set("valid_startroom", 1);
set("light_up",1);

call_other("/obj/board/marksman_b","???");
  setup();
}
