// Room: /open/gsword/room/g2-1.c
inherit ROOM;

void create()
{
  set ("short", "药圃");
  set ("long", @LONG
一片广阔的药圃 ,规划的很完整 ,各式各样的药材 ,分门别类 ,毫不
混杂 ,东南方即为一片峭壁 ,空气中满是药香 .

LONG);

  set("light_up", 1 );
  set("outdoors", "/open/gsword/room" );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"g2-4",
]) );

  setup();
}
