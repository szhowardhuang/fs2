// Room: /open/gsword/room/su-
inherit ROOM;

void create()
{
  set ("short", "杂草路");
  set ("long", @LONG
由此往北就是蜀中密林了,往南则通往蜀中城,东西两侧皆是
峭壁夹道,高耸而不可攀爬,北方森林极密,听说盛产药材,然而猛
兽邪怪,亦非少数,你可要小心才是.
LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 1 */
  "north" : "open/main/room/F5",
  "south" : __DIR__"froad0",
]));
  setup();
}
