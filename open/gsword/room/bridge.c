#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "小拱桥");
	set("long", "一做最简单不过的小桥，窄的仅能容纳数人通过，桥下一流清溪穿过，带来
阵阵水气，使你精神又为之一振，再往前面走就属仙剑派的后山了。
");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"alley3",
  "north" : __DIR__"alley4",
]) );

  set("outdoors", "/open/gsword/room" );


  setup();
}
