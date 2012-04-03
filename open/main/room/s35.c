// Room: /open/main/room/s35.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
  set ("long", @LONG
这里是一片草原，割人的野草凌乱的长着，高高低低的芒
穗随着风起伏，这里应该有不少动物躲藏.
LONG);

set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
//  "/open/main/npc/gao-shion.c" : 1,
// "/open/main/npc/secret_man.c" : 1, 神秘小贩关掉
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"s34",
  "north" : __DIR__"L25",
  "east" : __DIR__"s36",
]));

  setup();
  replace_program(ROOM);
}
