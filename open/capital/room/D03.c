// Room: /open/capital/room/D03.c
#include </open/capital/capital.h>

inherit ROOM;

void create ()
{
  set ("short", "镇南门");
  set ("long", @LONG
这里是京城的三个出入口之一「镇南门”, 由于京城乃是王朝的中
心, 圣上的住所所在，所以守卫的盘查也特别严格，如果随便让身份不
明的人进城闹事，那可是吃不玩兜着走了。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/gate_soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/main/room/s17",
  "north" : "/open/capital/room/r35",
]));

  setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (!objectp (guard=present ("gate soldier",this_object())))
	  return 1;

        if (dir=="north" && !me->query_temp("有向城门守卫报告"))
	 if(!guard->query_temp("unconcious"))
          if(!wizardp(me))
           return notify_fail("城门卫军伸手拦着你说：[1;31m完成身份确认才可以进城。[0m\n");

	return 1;
}
