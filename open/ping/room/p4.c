// Room: /open/ping/room/p4
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "寝居");
  set ("long", @LONG
这里是段王府里的东边厢房, 里头有床椅等家具, 布置的温暖舒适
地上都打扫的干干净净的, 令人感到十分温馨。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p3",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan7" : 1,
]));

  setup();
}
