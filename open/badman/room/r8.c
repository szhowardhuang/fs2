// Room: /open/badman/room/r8

#include </open/open.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "金库");
  set ("long", @LONG
一进到这个房间，立刻就有人围了上来阻止你继续前进，从他
们脸上严肃的表情，就可以知道这里必定就是恶人谷中戒备最森严
的藏宝库了。以十大恶人当年的武功及威名，想必捞了不少金银财
宝，一想到这里，你的口水就情不自禁的流了出来。
    你注意到南边有一个大铁门，后面应该就是金库了吧。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r9",
  "north" : __DIR__"b6",
]));
  set("objects", ([
  BAD_NPC"gguard" : 2,
]));

  set("light_up", 1);
  create_door("south", "铁门", "north", DOOR_LOCKED);

  setup();
}
