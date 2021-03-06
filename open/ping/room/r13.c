// Room: /u/m/moner/open/room/r13.c 
inherit ROOM;
#include <room.h>
#include <ansi.h>
 
void create ()
{
  set ("short", "大门口");
  set ("long", @LONG

    你正处于风行山寨大门前, 隔着镂花白滨铁大门, 你可以看到
院子里花木扶疏, 绿油油的大草坪随地展开, 有喷泉流水, 蝶蜂飞舞,
稍远处老树拔地而起, 形成处处的绿阴, 正是庭院深深, 好景处处,
滨铁大门是关着的, 你可以试着打开它(open door).


LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r15.c",
  "north" : __DIR__"r12.c",
]));
create_door("north",HIW"白铁滨花门"NOR,"south",DOOR_CLOSED);

  setup();
  replace_program(ROOM);
}
