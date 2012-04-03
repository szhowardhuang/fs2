// Room: /u/p/poloer/dragon/dr3
inherit ROOM;

void create ()
{
  set ("short", "乱葬岗");
  set ("long", @LONG
  这里是村外的郊区，四周人烟稀少，只有一大片的坟墓
  一不小心还会踩到尸骨，莫非这里是人常说的乱葬岗，不时
  还有鬼火出现，在身旁绕啊绕，恐怖极了。

LONG);

  set("no_transmit", 1);
  set("outdoors", "/u/p");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr4",
  "north" : __DIR__"dr2",
]));

  setup();
}
