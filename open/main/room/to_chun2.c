// Room: /open/main/room/to_chun2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "狂风岭");
  set ("long", @LONG
你登上此地, 一股狂风对你迎面吹来, 你站不住脚, 险些便要
摔倒, 只见一个青袍老人坐在山崖边, 独自望这远方, 你看着这个
老人, 突然惊觉, 此人便是段延庆!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"to_chun1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/chun.c" : 1,
]));

  setup();
  replace_program(ROOM);
}
