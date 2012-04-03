#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "魔教冥蛊魔殿");
  set ("long", @LONG
这里便是令武林中人闻风丧胆的冥蛊魔教总地，殿内按
五行八卦立了数根飞龙云柱，地上铺有大红地毯，中间则摆
有九龙太座，冥蛊魔教便高坐其上，太座后石壁上刻有巨幅
的圣火像，像征此魔教圣洁的精神。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"eqroom.c",
  "west" : __DIR__"room17",
  "south" : __DIR__"room7",
  "east" : __DIR__"room18",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 3 */
  "/open/poison/npc/jadegirl" : 1,
  "/open/poison/npc/masterl" : 1,
  "/open/poison/npc/goldchild" : 1,
]));
  set("valid_startroom", 1);

  setup();
call_other("/obj/board/poisoner_b","???");
}
void reset()
{
 set("been_get",0);
 :: reset();
}
void init()
{
  add_action("do_steal","steal");
}
int do_steal(string str)
{
  object me = this_player();
  object pearl, guard;
  int lv = me->query_skill("dodge");
  if( str != "pearl" )
	return notify_fail("你想偷些什么?\n");
  if(query("been_get"))
        return notify_fail("魔教此时戒备森严，你没有下手机会。\n");
  if( random(lv) > random(50))
    {
      tell_object(me,"你顺利拿到一颗夜明珠。\n");
      pearl = new("/open/poison/obj/pearl");
      pearl->move(me);
      set("been_get",1);
      return 1;
    }
  else
    {
     set("been_get",1);
      tell_object(me,"啊! 你不小心失手啦。\n");
      message_vision("$N行窃不小心被发现，引来守卫们。\n",me);
      guard = new(POISON_NPC"guard1");
      guard->move(POISON_ROOM"room1");
      guard->kill_ob(me);
      guard->set_leader(this_player());
      guard = new(POISON_NPC"guard1");
      guard->move(POISON_ROOM"room1");
      guard->kill_ob(me);
      guard->set_leader(this_player());
      return 1;
    }
  return 1;
}
int valid_leave(object me, string dir)
{
if (dir == "up" && me ->query("class") != "poisoner")
     return notify_fail("喂 ,进去干麻 ?想被毒啊。\n");
     return :: valid_leave(me, dir);
}

