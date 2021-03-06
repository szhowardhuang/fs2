// Room: /open/gsword/room/nghouse2.c
inherit ROOM;

void create ()
{
  set ("short", "广场");
  set ("long", @LONG
这广场是仙剑门徒练剑的场所，只见广场中间一个颇大的太极图，
在太极图上依照着八卦的方位满布木桩。在广场的所边的一块大石头上
有着几行字(words)。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/mob/trainee.c" : 2,
  "/open/gsword/mob/fanson.c" : 1,
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/nghouse3.c",
  "south" : "/open/gsword/room/nghouse1",
]));

  setup();
}
