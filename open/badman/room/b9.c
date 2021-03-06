// Room: /open/badman/room/b9
inherit ROOM;

void create ()
{
  set ("short", "恶人谷北道街");
  set ("long", @LONG
你发现北街上人群来来往往，似乎比南街热闹的多，因为这边
是恶人谷日常生活的重心，包管全恶人谷的吃喝玩乐。看到人们脸
上轻松的表情，你紧绷的神经也稍稍舒缓的下来。或许你可以放松
心情好好的逛一逛。
    你听到东边的房间传来阵阵吆喝声，好像有很多人聚集在那。
    大街往西方和南方延伸。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/rogue" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b10",
  "south" : __DIR__"b8",
  "east" : __DIR__"r5",
]));

  setup();
}
