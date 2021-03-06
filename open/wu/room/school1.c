// Room: /open/wu/room/school1.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "正晴武馆大门");
  set ("long", @LONG
你正站在一座建筑宏伟的宅第之前, 左右两座石坛中各竖一根两丈
来高的旗杆, 杆顶飘扬着青旗, 旗上绣着"正晴武馆"四个黑字,大宅生
漆大门,门上茶杯大小的金环闪闪发光,门顶匾额写着"拳倾天下"四个金
漆大字．也许你可以试着打开大门(open door).
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/ping/room/inn",
  "east" : __DIR__"school2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  create_door("east", HIR"镂花红桧大门"NOR, "west", DOOR_CLOSED);
  set("light_up", 1);
  setup();
}
