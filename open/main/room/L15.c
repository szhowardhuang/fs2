// Room: /open/main/room/L15.c

#include "/open/open.h"
inherit ROOM;

void create()
{
	set("short", "台地");
	set("long", @LONG
    这是一块微微高起的台地，稀稀疏疏的长了起几丛杂草，
几块石块杂乱分部，更显得这里的荒凉.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r42",
  "west" : __DIR__"L14",
  "north" : __DIR__"s25",
  "east" : __DIR__"r39",
]) );

  set("outdoors", "/open/main" );

  setup();
}

void init()
{
  object me=this_player();

  if (!me->query("quests/help_water_god") &&
       me->query_temp("quests/help_water_god") >= 3)
    me->move(MAIN_ROOM"L15_q");
  else if (!me->query("quests/badman_license") &&
       me->query_temp("quests/badman_license") >= 3)
    me->move(MAIN_ROOM"L15_q");
}
