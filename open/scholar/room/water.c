inherit ROOM;

void create ()
{
  set ("short", "水室图书馆");
  set ("long", @LONG
这里是存放大自然中有关水之奥秘的书房，记载医学，算命，文
学，逻辑．．等，你想知道或解决的疑难问题，在这里似乎都可以找
到满意的答案，许多儒门弟子也常来此翻阅书籍。由于书籍繁多此地
又分东南西北四堂，以便寻查。
LONG);

  set("exits", ([ /* sizeof() == 5 */
  "northeast" : __DIR__"r23.c",
  "north" : __DIR__"water_n.c",
  "south" : __DIR__"water_s.c",
  "west" : __DIR__"water_w.c",
  "east" : __DIR__"water_e.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar3.c" : 1,
]));

  setup();
}
