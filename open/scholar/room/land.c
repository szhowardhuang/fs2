inherit ROOM;

void create ()
{
  set ("short", "土室图书馆");
  set ("long", @LONG
这里是存放大自然中有关土之奥秘的书房，记载医学，算命，文
学，逻辑．．等，你想知道或解决的疑难问题，在这里似乎都可以找
到满意的答案，许多儒门弟子也常来此翻阅书籍。由于书籍繁多此地
又分东南西北四堂，以便寻查。
LONG);

  set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"land_n.c",
  "south" : __DIR__"land_s.c",
  "west" : __DIR__"land_w.c",
  "east" : __DIR__"land_e.c",
  "northwest" : __DIR__"r25.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar4.c" : 1,
]));

  setup();
}
