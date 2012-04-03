inherit ROOM;

void create ()
{
  set ("short", "¿Ó√Œ’Ì∑ø");
  set ("long", @LONG

°£

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "1" : "/open/capital/room/r70.c",
  "2" : "/open/main/room/r5.c",
  "3" : "/open/main/room/L19.c",
  "4" : "/open/port/room/r2-2.c",
  "5" : "/open/prayer/room/westarea/road19",
  "6" : "/open/wind-rain/room3.c",
  "7" : "/open/capital/room/tower.c",
  "8" : "/open/main/room/m6.c",
  "9" : "/open/main/room/s27.c",
  "10" : "/open/start/room/s5",
  "11" : "/open/mogi/village/room/room-50.c",
  "12" : "/open/mogi/mountain/entrance.c",
  "13" : "/open/gblade/room/g1-1.c",

]));

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  "//open/gsword/npc2/lee.c" :1, ]));
  setup();
}
