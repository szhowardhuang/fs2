// Room: /open/marksman/room/room3-1
inherit ROOM;

void create ()
{
  set ("short", "客栈客房");
  set ("long", @LONG
这是一间普通的客房，里面的装设并不豪华，不过一样也不缺，
可谓麻雀虽小，却五脏具全呀。里面摆着一张床，和一套木制的桌倚
客房的墙上摆满了雕功一流的弓，椅子上正坐着一位白发苍桑的老人
。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/old_man" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"room1-18",
]));

  setup();
}
