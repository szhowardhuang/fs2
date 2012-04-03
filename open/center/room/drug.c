// Room: /open/center/room/drug.c

inherit ROOM;

void create ()
{
  set ("short", "药店");
  set ("long", @LONG
当你一踏进这个药店, 一股浓厚的药材味立即扑鼻而来, 在店里的右边
堆放了一堆堆尚未经过处理的药材, 左边的店老板与伙计们正忙着招呼客人,
店后则隐约传来些奇怪的声音, 可能是学徒们正操作着机器在处理药材吧!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/center/room/road2",
]));

  set("light_up", 1);

  setup();
}
