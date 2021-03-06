inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "雪中小径");
  set ("long", @LONG
前方的小路依旧，刺骨的寒风迎面而来，细细的白雪轻轻地覆盖
了整条小径，一般的草木已经不复见，走到这里，你已经找不到路再
往上走了，你看到一大片的岩石(rock)阻挡了你通往山顶的路，你似
乎必需用爬的才有办法通往山顶，而在你的前方不远处，有一个暗淡
无光的圆点，微微的雾气让你看不清那儿有什么。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pig.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"mon51",
  "south" : __DIR__"mon32",
  "eastdown" : __DIR__"mon27",
]));

  setup();
}
void init()
{
  add_action ("do_climb","climb");
}

int do_climb (string str)

{
  object        me;
  if (!str || (str != "rock" && str != "岩石"))
    return notify_fail("你爬呀爬呀......你爬了半天还是不幸重重的捽了下来.....\n");

  me = this_player();
  message_vision("$N展开绝世轻功，依附着岩石，轻轻松松的登上了攀岩道。\n", me);
  me->move(__DIR__"mon33");


  tell_room(environment(me), sprintf ("%s左足一点，右足一蹬，气定神闲的登上了攀岩道。\n",
        me->short()), me);
  return 1;
}

