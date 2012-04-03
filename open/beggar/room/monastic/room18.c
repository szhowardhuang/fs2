inherit ROOM;

void create()
{
 set("short","大厅");
 set("long",@LONG
  寺庙外面虽然看起来破破旧旧的，不过里面的木板却挺
  结实的，丝毫没有损坏的痕迹，左右两边各通往西厢房
  与东厢房，前方便是丐帮帮主聚集帮众的「降龙堂”了。

LONG);
 set("exits",([
 "east" : __DIR__"room19.c",
 "west" : __DIR__"room17.c",
 "north" : __DIR__"room09.c",
 "out" : "/u/l/list/area/room08.c"
 ]));
 setup();
}
