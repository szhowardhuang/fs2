// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "学识厅");
  set ("long", @LONG
这是儒门高级儒生们学习学识的厅房，此地你可看到许多高
级儒生正坐在桌上研读着四书五经，厅房的南边是学识厅长老休
息及读书的厢房，北边是学识厅老师的厢房，东边是通往中堂东
侧。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"e3_s.c",
  "north" : __DIR__"e3_n.c",
  "west" : __DIR__"e2.c",
  "east" : __DIR__"r18.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/trainer.c" : 2,
]));

  setup();
}
