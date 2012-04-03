// Room: /open/gsword/room/g2-2.c
inherit ROOM;

void create ()
{
  set ("short", "药房");
  set ("long", @LONG
这是一间小小的药房 ,一个檀香木做成的大木柜摆在东侧 ,木柜画分
成许多抽屉 ,分别存放着各种药材 ,种类之齐全 ,令人咋舌 ,真是麻雀虽
小 ,五脏俱全 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room/g2-4",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
   "/open/gsword/npc/boy-1":1,
   "/open/gsword/npc/doctor":1,
]));

  setup();
}
