// Room: /open/capital/room/r43.c

inherit ROOM;

void create()
{
        set("short", "日升驰道");
        set("long",@LONG
城东的车马大道。为了便于军队快速通行而设。地面铺的石板相当
考究，听说是把从蜀山采得的大石块加以研磨成一块块的石板，再由雕
刻匠在上面雕制花纹，然后再平铺而成。

LONG);



  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r44",
  "south" : __DIR__"r42",
]) );

  set("gopath", "south" );

  setup();
}
