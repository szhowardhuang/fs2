#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "仙剑派前山");
	set("long", "          
你的眼前尽是垂直的峭壁，光滑的连一根草也无法在上面着根，维独在峭壁(cliff)的
左侧，颜色较趋暗色，好奇心使你想看的清楚些，不过那高度实在太高你再怎么努
力，也无法瞧个仔细。        

");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lroad2",
  "east" : __DIR__"road1",
]) );

  set("outdoors", "/open/gsword/room" );

  setup();
}
