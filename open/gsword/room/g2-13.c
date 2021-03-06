// Room: /open/gsword/room/nghouse2.c
inherit ROOM;

void create ()
{
  set ("short", "广场");
  set ("long", @LONG
这广场是仙剑门徒练剑的场所，只见广场中间一个颇大的太极图，在
太极图上依照着八卦的方位满布木桩。在广场的左边的一块大石头上有着
几行字(words)。
 
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc/trainee1.c" :1,
     "/daemon/class/swordsman/tengyu": 1,
]));

set("item_desc", ([
"words" : "爱落红尘心已死....
罗严塔尔.........于98/4/24\n",
]));
  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/gsword/room/g2-8.c",
  "west" : "/open/gsword/room/g2-10.c",
  "south" : "/open/gsword/room/g2-12.c",
  "east" : "/open/gsword/room/g2-6.c",
]));

  setup();
}
