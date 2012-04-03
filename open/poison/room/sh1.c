// Room: /u/r/ranko/room/sh1.c
inherit ROOM;

void create ()
{
  set ("short", "面店");
  set ("long", @LONG
此村一家口碑不错的面店，店里卖着各式各样的面食，老板不
时熟练地将面条放入锅中用沸水煮熟，并加上独家的调味料，阵阵
的香味不时从锅中飘出，令人闻了不觉食指大动。这里已有不少村
民在此大快朵颐了，或许你该找张桌子坐下来加入他们。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/mer1.c" : 1,
]));
  set("light_up", 1);

  setup();
}
