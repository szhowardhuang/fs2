inherit ROOM;

void create ()
{
  set ("short", "南堂土");
  set ("long", @LONG
不知是不是迷信的关系，总觉得有感到一粒粒的感觉，难道书本
化成砂，还是只是自己的多虑，是那些书让我有这种想法的吗？这里
的书本可真奇妙。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"land.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_land.c" : 1,
]));

  setup();
}
