// Room: /open/badman/room/r4

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "病房");
  set ("long", @LONG
一走进这里，你就闻到一股刺鼻的药味，原来这里是万春流试
验新药材的房间。你看到一旁的炉子上正煮着各式各样的药草，每
样都是你没看过的新药材，让你大开眼界。自从当年万春流躲入恶
人谷以后，便潜心研究更高深的医术，二十多年来也陆续发现了许
多新的药方，无一不是弥足珍贵。不过在这间房间中最吸引你注意
的，还是放在墙角边的一个大药缸。
    东边有一扇木制的门。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"r2",
]));
  set("light_up", 1);

  create_door("east", "木门", "west", DOOR_CLOSED);
  setup();
}
