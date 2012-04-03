// Room: /open/gsword/room/g2-12.c
inherit ROOM;

void create ()
{
  set ("short", "广场");
  set ("long", @LONG
这是仙剑派众弟子们平时练剑的场所 ,你看到数百位仙剑弟子们正挥汗练剑 ,
整齐一致的呼喝声 ,响遍全山 ,近年来仙剑何以如此兴盛 ,光看这气势 ,你就
明白八九成了 .西北一条小径连往仙剑后花园 .

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc/trainee2" : 1,
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/gsword/room/g2-10.c",
  "east" : "/open/gsword/room/g2-8.c",
  "northwest" : "/open/gsword/room/g4-7.c",
]));

  setup();
}
