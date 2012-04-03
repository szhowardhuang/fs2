// Room: /u/u/unfinished/room/is13.c
inherit ROOM;

void create ()
{
  set ("short", "沙滩");
  set ("long", @LONG
小岛的东北角. 海风不强, 沙滩上有许多螃蟹及贝壳, 景致十分和谐, 是一
个休息的好地方. 除了螃蟹贝壳之外, 此处并没有其他特别的事物. 西边已不是
沙滩地形, 是遍地岩石的沿岸, 西边高耸直立的岩壁显得相当险峻.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"is8.c",
  "west" : __DIR__"is12",
]));

  setup();
}
